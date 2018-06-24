#include <Arduino.h>
#include "Strobe.h"
#include <Animately.h>
#include <Core/Timeline.h>
#include <HatController.h>

/**
 * @file Controller.cpp
 * @author Mike Szörnyi
 * @version 1.0
 */

Strobe::Strobe(int bpm, Timeline *timeline, Controller *ledController)
{
	this->interval = bpmInterval(bpm);
	_timeline = timeline;
	this->ledController = ledController;
	this->numLED = (*ledController)._num_leds;
}

void Strobe::cue(int val) const
{
	_timeline->schedule(0, this->numLED, 0, 0,
						DELEGATE(this, &Strobe::ledsOn),
						NULL,
						NULL,
						DELEGATE(this, &Strobe::showStrip));

	_timeline->schedule(0, this->numLED, blinkTime, 0,
						DELEGATE(this, &Strobe::ledsOff),
						NULL,
						NULL,
						DELEGATE(this, &Strobe::showStrip));

	// Schedule it to play again
	_timeline->schedule(this->interval, 0, DELEGATE(this, &Strobe::cue), NULL);
}

void Strobe::ledsOn(int pixel) const
{
	this->ledController->setAllTo(0xff, 0x77, 0x00);
}
void Strobe::ledsOff(int pixel) const
{
	this->ledController->setAllTo(0, 0, 0);
}

void Strobe::showStrip(int _val) const
{
	this->ledController->showStrip();
}

int Strobe::bpmInterval(int bpm) const
{
	long interval = 1000 / (bpm / 60.0);
	if (interval <= this->blinkTime + 50)
	{
		return this->blinkTime + 50;
	}

	return interval;
}
