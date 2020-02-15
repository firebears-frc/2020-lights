#ifndef rainbow_h
#define rainbow_h
#include <Animation.h>

/**
*/
class rainbow : public Animation {
  public:
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    int pixelColor();
    unsigned long waitTime = 30;
    int currentPixel = 0;
    int colorCount = 0;
  private:
};
#endif
