#ifndef _FESTIVAL_HAT_CONTROLLER_LIB_
#define _FESTIVAL_HAT_CONTROLLER_LIB_

/**
 * @file HatController.h
 * @author Mike Szörnyi
 * @version 1.0
 */

#include "FastLED.h"
#include <AceButton.h>
#include <Arduino.h>
using namespace ace_button;

class HatController {

public:
  uint8_t _num_leds;

  HatController(uint8_t data_pin, uint8_t num_leds, struct CRGB *leds);

  void setPixelColor(int Pixel, byte red, byte green, byte blue) const;
  void setAllTo(byte red, byte green, byte blue) const;
  void showStrip();

  static void handleButtonEvent(AceButton * /* button */, uint8_t eventType,
                                uint8_t /* buttonState */);

private:
  //	VARIABLES
  uint8_t _data_pin;
  struct CRGB *_leds;

  //	CONSTANTS
};

#endif
