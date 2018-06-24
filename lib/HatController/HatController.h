#ifndef _FESTIVAL_CONTROLLER_LIB_
#define _FESTIVAL_CONTROLLER_LIB_

/**
 * @file Controller.h
 * @author Mike Szörnyi
 * @version 1.0
 */

#include <Arduino.h>
#include "FastLED.h"
#include <AceButton.h>
using namespace ace_button;

class Controller {

	public:
    	uint8_t _num_leds;

		Controller(uint8_t data_pin, uint8_t num_leds, struct CRGB *leds);

		void setPixelColor(int Pixel, byte red, byte green, byte blue) const;
		void setAllTo(byte red, byte green, byte blue) const;
		void showStrip();

		static void handleButtonEvent(AceButton* /* button */, uint8_t eventType,
    uint8_t /* buttonState */);

	private:

		//	VARIABLES
    	uint8_t _data_pin;
		struct CRGB *_leds;

		//	CONSTANTS
};

#endif
