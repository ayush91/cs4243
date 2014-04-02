#ifndef LEDLabel_h
#define LEDLabel_h

#include "Arduino.h"
#include "LEDStrip.h"

class LEDLabel
{
  private:
    LEDStrip *strip;
    boolean state;
    int light1;
    int light2;
    int light3;
    
  public:
    LEDLabel(int lite1, int lite2, int lite3, LEDStrip *strip);
    void on();
    void off();
    
};

#endif 
