#include <Adafruit_NeoPixel.h>
#include "rainbow.h"

int rainPixelState = 0;

void rainbow::reset(Adafruit_NeoPixel *strip) {
  strip->begin();
  setTimeout(waitTime);
  currentPixel = 0;
}

int rainbow :: pixelColor(){
  switch (colorCount){
    case 0: return 0xFF0000;//red
    case 1: return 0xEE6600;//orange
    case 2: return 0xFFFF00;//yellow
    case 3: return 0x00FF00;//green
    case 4: return 0x00FFDE;//blue
    case 5: return 0x8900FF;//purple
    case 6: return 0xFF009A;//magenta
    default: return 0;
  }
}
void rainbow::draw(Adafruit_NeoPixel *strip) {
  if (isTimedout()) {
    for (int i = 0; i < strip-> numPixels(); i++) {
      if (i < currentPixel){
        strip->setPixelColor(i, pixelColor());
      }
      
    }

   
    currentPixel = currentPixel + 1;
    if (currentPixel > strip-> numPixels() - 1){
       currentPixel = 0;
       colorCount +=1;
       if (colorCount > 6){
        colorCount = 0;
       }
    }
    
    setTimeout(waitTime);
  }
}
