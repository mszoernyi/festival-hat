#ifndef _FESTIVAL_SCENE_STROBE_
#define _FESTIVAL_SCENE_STROBE_

/**
 * @file Strobe.h
 * @author Mike Szörnyi
 * @version 1.0
 */

#include <Animately.h>
#include <Arduino.h>
#include <Core/Timeline.h>

#include <HatController.h>

// By defining that we're using the Animately namespace, we don't have to prefix
// all Animately classes with "Animately::"
using namespace Animately;

class StrobeScene {
public:
  uint8_t _num_leds;

  StrobeScene(int bpm, Timeline *timeline, HatController *hatController);

  void ledsOn(int pixel) const;
  void ledsOff(int pixel) const;
  void showStrip(int _val) const;
  int bpmInterval(int bpm) const;
  void cue(int val) const;

private:
  //	VARIABLES
  Timeline *_timeline;
  HatController *hatController;
  uint8_t numLED;
  long interval;

  //	CONSTANTS
  const int blinkTime = 100; // in ms - for how long should the LED be on
};

#endif
