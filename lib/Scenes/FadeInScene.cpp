#include "FadeInScene.h"
#include <Animately.h>
#include <Arduino.h>
#include <Core/Timeline.h>
#include <HatController.h>

/**
 * @file FadeInScene.cpp
 * @author Mike Szörnyi
 * @version 1.0
 */

FadeInScene::FadeInScene(int duration, int maxBrightness, byte red, byte green,
						 byte blue, Timeline *timeline,
						 Controller *ledController)
{
	_timeline = timeline;
	_ledController = ledController;
	_duration = duration;
	_maxBrightness = maxBrightness;
	_red = red;
	_green = green;
	_blue = blue;
}

void FadeInScene::cue(int val)
{
	int delay = (_duration / 2) / _maxBrightness;
	int duration = _duration / 2;

	_timeline->schedule(0, _maxBrightness, 0, duration,
						DELEGATE(this, &FadeInScene::fadeAll),
						DELEGATE(this, &FadeInScene::fadeAll), NULL,
						DELEGATE(this, &FadeInScene::fadeAll));

	_timeline->schedule(_maxBrightness, 0, duration + delay, duration,
						DELEGATE(this, &FadeInScene::fadeAll),
						DELEGATE(this, &FadeInScene::fadeAll), NULL,
						DELEGATE(this, &FadeInScene::fadeAll));

	// Schedule it to play again
	_timeline->schedule(_duration + delay, _duration,
						DELEGATE(this, &FadeInScene::cue), NULL);
}
void FadeInScene::fadeAll(int targetBrightness)
{
	if (targetBrightness == _currentBrightness)
	{
		return;
	}
	float r, g, b;

	// Store current iteration to send less updates
	_currentBrightness = targetBrightness;

	r = (targetBrightness / 256.0) * _red;
	g = (targetBrightness / 256.0) * _green;
	b = (targetBrightness / 256.0) * _blue;
	_ledController->setAllTo(r, g, b);
	_ledController->showStrip();
}
