#ifndef numBall_h
#define numBall_h
#include <Animation.h>

/**
*/
class numBall : public Animation {
  public:
  int pixelAmount;
    void reset(Adafruit_NeoPixel *strip);
    void draw(Adafruit_NeoPixel *strip);
    int setNumPixels(int j);
    unsigned long waitTime = 1500;
  private:
};
#endif
