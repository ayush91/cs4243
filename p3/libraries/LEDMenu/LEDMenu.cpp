
#include "Arduino.h"
#include "LEDStrip.h"
#include "LEDLabel.h"
#include "LEDMenu.h"


LEDMenu::LEDMenu(int SDI, int CKI, int size)
{
  strip1 = new LEDStrip(SDI, CKI, size);
  if(size == 40)
  {
    entrees = new LEDLabel(12, 11, 10, strip1);
    drinks = new LEDLabel(9, 8, 7, strip1);
    soups = new LEDLabel(6, 5, 4, strip1);
    menu = new LEDLabel(3, 2, 1, strip1);

    food1 = new LEDLabel(27, 28, 29, strip1);
    food3 = new LEDLabel(33, 34, 35, strip1);
  }
  else if(size == 72)
  {
    entrees = new LEDLabel(12, 11, 10, strip1);
    drinks = new LEDLabel(9, 8, 7, strip1);
    soups = new LEDLabel(6, 5, 4, strip1);
    menu = new LEDLabel(3, 2, 1, strip1);

    food1 = new LEDLabel(59, 60, 61, strip1);
    food3 = new LEDLabel(65, 66, 67, strip1);
  }

  entrees->off();
  drinks->off();
  soups->off();
  menu->on();
  food1->off();
  food3->off();
  strip1->post_frame();
}

void LEDMenu::entreesSelect()
{
  entrees->on();
  drinks->off();
  soups->off();
  menu->off();

  food1->off();
  food3->off();

  strip1->post_frame();
}

void LEDMenu::drinksSelect()
{
  entrees->off();
  drinks->on();
  soups->off();
  menu->off();

  food1->off();
  food3->off();

  strip1->post_frame();
}

void LEDMenu::soupsSelect()
{
  entrees->off();
  drinks->off();
  soups->on();
  menu->off();

  food1->off();
  food3->off();

  strip1->post_frame();
}

void LEDMenu::menuSelect()
{
  entrees->off();
  drinks->off();
  soups->off();
  menu->on();

  food1->off();
  food3->off();

  strip1->post_frame();
}

void LEDMenu::food1Select()
{
  food1->on();
  food3->off();

  strip1->post_frame();
}

void LEDMenu::food3Select()
{
  food1->off();
  food3->on();

  strip1->post_frame();
}
