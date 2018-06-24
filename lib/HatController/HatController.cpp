#include <Arduino.h>
#include "HatController.h"
#include "FastLED.h"

/**
 * @file Controller.cpp
 * @author Mike Szörnyi
 * @version 1.0
 */

Controller::Controller(uint8_t data_pin, uint8_t num_leds, struct CRGB *leds)
{
	_data_pin = data_pin;
	_num_leds = num_leds;
    // Dynamic allocation of the array
    //leds = (struct CRGB *) malloc(num_leds * sizeof(struct CRGB));
	_leds = leds;
}

void Controller::setPixelColor(int Pixel, byte red, byte green, byte blue) const
{
	// FastLED
	_leds[Pixel].r = red;
	_leds[Pixel].g = green;
	_leds[Pixel].b = blue;
}

void Controller::setAllTo(byte red, byte green, byte blue) const
{
	for (int i = 0; i < _num_leds; i++)
	{
		setPixelColor(i, red, green, blue);
	}
}

void Controller::showStrip()
{
	FastLED.show(); // TODO should the be dependent on FastLED directly or should we pass in a class so we can Use neoPixel or FastLED with strips
}

void Controller::handleButtonEvent(AceButton* /* button */, uint8_t eventType,
    uint8_t /* buttonState */) {
  switch (eventType) {
    case AceButton::kEventPressed:
      Serial.println("Button pressed");
      break;
    case AceButton::kEventReleased:
      Serial.println("Button released");
      break;
  }
}
