#ifndef LEDMenu_h
#define LEDMenu_h

#include "Arduino.h"
#include "LEDStrip.h"
#include "LEDLabel.h"

class LEDMenu
{
  private:
    LEDStrip *strip1;

    
    //Categories
    LEDLabel *appetizers;
    LEDLabel *desserts;
    LEDLabel *drinks;
    LEDLabel *entrees;
    LEDLabel *menu;
    LEDLabel *salads;
    LEDLabel *sides;
    LEDLabel *soups;

    //Items
    LEDLabel *food1;
    LEDLabel *food2;
    LEDLabel *food3;
    LEDLabel *food4;
    LEDLabel *food5;
    LEDLabel *food6;
    LEDLabel *food7;
    LEDLabel *food8;

  public:
    //Methods
    LEDMenu(int SDI, int CKI, int size);
    void entreesSelect();
    void drinksSelect();
    void soupsSelect();
    void menuSelect();
    void food1Select();
    void food3Select();
};

#endif 
