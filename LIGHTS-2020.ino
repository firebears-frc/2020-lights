#include <Adafruit_NeoPixel.h>
#include <PixelStrip.h>
#include <Animation.h>
#include <Wire.h>
#include "celebrate.h"
#include "teamColor.h"
#include "rev.h"
#include "rainbow.h"
#include "numBall.h"


const int MAX_ANIMATIONS = 10;
const int MAX_PIXELSTRIPS = 1;
const int BRIGHTNESS = 60;
const int I2C_ADDRESS = 4;

const int BLUE_ANIMATION = 0;
const int RED_ANIMATION = 1;
const int CELEBRATE_ANIMATION = 2;
const int SHOOTING_ANIMATION = 3;
const int DEFAULT_ANIMATION = 4;
const int ONEBALL_ANIMATION = 5;
const int TWOBALL_ANIMATION = 6;
const int THREEBALL_ANIMATION = 7;
const int FOURBALL_ANIMATION = 8;
const int FIVEBALL_ANIMATION = 9;


const int PIXEL_STRIP = 0;

PixelStrip *strip[MAX_PIXELSTRIPS];
Animation *animation[MAX_ANIMATIONS];
int wireTimeout = 0;

/**
   Change animations when I2C messages are received.
*/
void setup() {
  Wire.begin(I2C_ADDRESS);
  Wire.onReceive(receiveEvent);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // set up all Animations

  animation[BLUE_ANIMATION] = new teamColor();
  ((teamColor*)animation[BLUE_ANIMATION])->setColor (0, 0x0900FF);
  ((teamColor*)animation[BLUE_ANIMATION])->setColor (1, 0x00ABFF);
  animation[RED_ANIMATION] = new teamColor();
  ((teamColor*)animation[RED_ANIMATION])->setColor (0, 0xFF0000);
  ((teamColor*)animation[RED_ANIMATION])->setColor (1, 0xD00808);
  animation[CELEBRATE_ANIMATION] = new celebrate();
  animation[SHOOTING_ANIMATION] = new rev();
  animation[DEFAULT_ANIMATION] = new rainbow();
  animation[ONEBALL_ANIMATION] = new numBall();
  ((numBall*)animation[ONEBALL_ANIMATION])->setNumPixels(54);
  animation[TWOBALL_ANIMATION] = new numBall();
  ((numBall*)animation[TWOBALL_ANIMATION])->setNumPixels(41);
  animation[THREEBALL_ANIMATION] = new numBall();
  ((numBall*)animation[THREEBALL_ANIMATION])->setNumPixels(28);
  animation[FOURBALL_ANIMATION] = new numBall();
  ((numBall*)animation[FOURBALL_ANIMATION])->setNumPixels(14);
  animation[FIVEBALL_ANIMATION] = new numBall();
  ((numBall*)animation[FIVEBALL_ANIMATION])->setNumPixels(0);



  //YOU SHALL NOT PASS
  // set up all PixelStrips
  strip[PIXEL_STRIP] = new PixelStrip(68, 3, NEO_GRB);
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->setup();
    strip[s]->setAnimation(animation[FIVEBALL_ANIMATION]);
    strip[s]->setBrightness(BRIGHTNESS);
  }
}

void loop() {
  for (int s = 0; s < MAX_PIXELSTRIPS; s++) {
    strip[s]->draw();
    strip[s]->show();
  }
  delay(10);
  if (wireTimeout > 0 && millis() > wireTimeout)  {
    digitalWrite(LED_BUILTIN, LOW);
    wireTimeout = 0;
  }
}

/**
   Expects to receive two characters.
   The first character specifies the pixel strip number.
   The second character sets the animation number on that strip.
*/
void receiveEvent(int howMany) {
  while (Wire.available() > 0) {
    int s = Wire.read() - '0';
    int a = Wire.read() - '0';
    if (a >= 0 && a < MAX_ANIMATIONS) {
      strip[s]->setAnimation(animation[a]);
    } else {
      strip[s]->setAnimation(0);
    }
    digitalWrite(LED_BUILTIN, HIGH);
    wireTimeout = millis() + 500;
  }
}
