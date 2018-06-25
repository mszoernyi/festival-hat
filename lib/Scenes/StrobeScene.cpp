#include <Animately.h>
#include <Arduino.h>
#include <Core/Timeline.h>

#include <HatController.h>
#include "StrobeScene.h"

/**
 * @file Strobe.cpp
 * @author Mike Szörnyi
 * @version 1.0
 */

StrobeScene::StrobeScene(int bpm, Timeline *timeline,
                         HatController *hatController)
{
  this->interval = bpmInterval(bpm);
  _timeline = timeline;
  this->hatController = hatController;
  this->numLED = (*hatController)._num_leds;
}

void StrobeScene::cue(int val) const
{
  _timeline->schedule(0, this->numLED, 0, 0,
                      DELEGATE(this, &StrobeScene::ledsOn), NULL, NULL,
                      DELEGATE(this, &StrobeScene::showStrip));

  _timeline->schedule(0, this->numLED, blinkTime, 0,
                      DELEGATE(this, &StrobeScene::ledsOff), NULL, NULL,
                      DELEGATE(this, &StrobeScene::showStrip));

  // Schedule it to play again
  _timeline->schedule(this->interval, 0, DELEGATE(this, &StrobeScene::cue),
                      NULL);
}

void StrobeScene::ledsOn(int pixel) const
{
  this->hatController->setAllTo(0xff, 0x77, 0x00);
}
void StrobeScene::ledsOff(int pixel) const
{
  this->hatController->setAllTo(0, 0, 0);
}

void StrobeScene::showStrip(int _val) const
{
  this->hatController->showStrip();
}

int StrobeScene::bpmInterval(int bpm) const
{
  long interval = 1000 / (bpm / 60.0);
  if (interval <= this->blinkTime + 50)
  {
    return this->blinkTime + 50;
  }

  return interval;
}
