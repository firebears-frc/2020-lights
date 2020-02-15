#include <Adafruit_NeoPixel.h>
#include "rev.h"

int revPixelState = 0;

void rev::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
  currentPixel = 0;
}

void rev::draw(Adafruit_NeoPixel *strip) {
    for (int i = 0; i < strip->numPixels(); i++) {
      if (i >= currentPixel && i < currentPixel + (pixLength - 1)){
        strip->setPixelColor(i, 0xFFFFFF);
      } else {
        strip->setPixelColor(i, 0x149A00);
      }
    }
    currentPixel++;
    if (currentPixel  > strip->numPixels())
        currentPixel  = 0;
    delay(waitTime);
}
