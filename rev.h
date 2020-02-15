#ifndef rev_h
#define rev_h
#include <Animation.h>

/**
*/
class rev : public Animation {
  public:
    void reset(Adafruit_NeoPixel*strip);
    void draw(Adafruit_NeoPixel*strip);
    unsigned long waitTime = 30;
    unsigned long pixLength = 7;
    int currentPixel = 0;
  private:
};
#endif
