#ifndef _FESTIVAL_SCENE_FADEIN_
#define _FESTIVAL_SCENE_FADEIN_

/**
 * @file FadeIn.h
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

class FadeInScene {
public:
  FadeInScene(int duration, int maxBrightness, byte red, byte green, byte blue,
              Timeline *timeline, Controller *ledController);

  void fadeAll(int currentBrightness);
  void cue(int val);

private:
  //	VARIABLES
  Timeline *_timeline;
  Controller *_ledController;
  int _duration;
  int _maxBrightness, _currentBrightness;
  byte _red, _green, _blue;
  //	CONSTANTS
};

#endif
