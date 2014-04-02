#include "Arduino.h"
#include "LEDStrip.h"
#include "LEDLabel.h"
#include "LEDMenu.h"
#include "P3Controller.h"


P3Controller::P3Controller(int SDI, int CKI, int size)
{
  ledMenu = new LEDMenu(SDI, CKI, size);
}

void P3Controller::rfSelect(String selection)
{
  if(selection == "entrees")
  {
    ledMenu->entreesSelect();
  }
  else if(selection == "drinks")
  {
    ledMenu->drinksSelect();
  }
  else if(selection == "soups")
  {
    ledMenu->soupsSelect();
  }
  else if(selection == "food1")
  {
    ledMenu->food1Select();
  }
  else if(selection == "food3")
  {
    ledMenu->food3Select();
  }
  else
  {
    ledMenu->menuSelect();
  }
}

void P3Controller::mobileSelect(String selection)
{
  if(selection == "entrees")
  {
    ledMenu->entreesSelect();
  }
  else if(selection == "drinks")
  {
    ledMenu->drinksSelect();
  }
  else if(selection == "soups")
  {
    ledMenu->soupsSelect();
  }
  else if(selection == "food1")
  {
    ledMenu->food1Select();
  }
  else if(selection == "food3")
  {
    ledMenu->food3Select();
  }
  else
  {
    ledMenu->menuSelect();
  }

}
