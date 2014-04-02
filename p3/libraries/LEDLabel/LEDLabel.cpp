
#include "Arduino.h"
#include "LEDStrip.h"
#include "LEDLabel.h"

#define WHITE 0xffffff
#define BLACK 0x000000

LEDLabel::LEDLabel(int lite1, int lite2, int lite3, LEDStrip *stripPtr)
{
  strip = stripPtr;
  state = false;
  light1 = lite1;
  light2 = lite2;
  light3 = lite3;
}

void LEDLabel::on()
{
  state = true;
  strip->setLED(light1, WHITE);
  strip->setLED(light2, WHITE);
  strip->setLED(light3, WHITE);
}

void LEDLabel::off()
{
  state = false;
  strip->setLED(light1, BLACK);
  strip->setLED(light2, BLACK);
  strip->setLED(light3, BLACK);
}
