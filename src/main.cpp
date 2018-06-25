#include <Arduino.h>
// Configuration for Animately must happen BEFORE including Animately.h.
// This #define increases the number of animations that we can schedule at one
// time.
#define TIMELINE_MAX_SCHEDULED_ENTRIES 20

#include "FastLED.h"
#include <AceButton.h>
#include <Animately.h>
#include <Core/Timeline.h>
#include <HatController.h>
using namespace ace_button;

// By defining that we're using the Animately namespace, we don't have to prefix
// all Animately classes with "Animately::"
using namespace Animately;

#define BUTTON_PIN 12
#define LED_PIN 9
#define NUM_LEDS 35
#define MAX_BRIGHTNESS 255
CRGB leds[NUM_LEDS];

// Scenes
#include <FadeInScene.h>
#include <StrobeScene.h>

// Setup all our global parts
Timeline timeline;
AceButton button(BUTTON_PIN);

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);

  // TODO : Move this to controller
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS)
      .setCorrection(TypicalLEDStrip);

  // Setup all our parts
  HatController hatController(LED_PIN, NUM_LEDS, leds);
  button.setEventHandler(hatController.handleButtonEvent);

  // Create the scenes
  StrobeScene strobe(200, &timeline, &hatController);
  FadeInScene fadeInScene(5000, 20, 200, 200, 200, &timeline, &hatController);
  // Choose a scene to start:
  // chaseScene.cue(0);
  // bounceScene.cue(0);
  // Strobe.cue(-1);
  fadeInScene.cue(255);
}

void loop() {
  button.check();
  // timeline.tick() should be called at least once per ms. Calling it more
  // often is fine.
  timeline.tick();
}
