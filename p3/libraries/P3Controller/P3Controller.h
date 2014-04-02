#ifndef P3Controller_h
#define P3Controller_h

#include "Arduino.h"
#include "LEDMenu.h"
#include "LEDLabel.h"
#include "LEDStrip.h"

class P3Controller
{
	private:
		LEDMenu *ledMenu;

	public:
		P3Controller(int , int , int);
		void rfSelect(String);
		void mobileSelect(String);
};

#endif