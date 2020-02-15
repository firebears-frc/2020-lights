#include <Adafruit_NeoPixel.h>
#include "numBall.h"

int pixelState = 0;

int numBall::setNumPixels(int j) {
  pixelAmount = j;
   
}

void numBall::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(1);
}

void numBall::draw(Adafruit_NeoPixel *strip) {
      for (int i = 0; i < strip->numPixels()- pixelAmount; i++) {
        strip->setPixelColor(i, 0x149A00);
      }
  }
