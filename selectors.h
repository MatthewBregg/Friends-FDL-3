#include "read_trigger.h"
#pragma once

int forward_selector = A2;
int backward_selector = A3;

bool forward_selector_active() {
  return digitalRead(forward_selector) == LOW;
}

bool forward_selector_debounce_sync_active() {
  // Is button initially down?
  if (forward_selector_active()) {
    delay(50);
    // Return if button is still down after a debounce delay
    return forward_selector_active();
  }
  // Button was never down, return false.
  return false;
}

bool backward_selector_active() {
  return digitalRead(backward_selector) == LOW;
}

bool backward_selector_debounce_sync_active() {
  // Is button initially down?
  if (backward_selector_active()) {
    delay(50);
    // Return if button is still down after a debounce delay
    return backward_selector_active();
  }
  // Button was never down, return false.
  return false;
}

void blink_led_three_times() {
  for (int i = 0; i != 3; ++i) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

void blip_flywheel_drives(unsigned long duration_ms) {
  OCR1A = 500;                                   //Start motors
  OCR1B = 500;
  delay(duration_ms);
  OCR1A = 230;                                   //Shutdown motors
  OCR1B = 230;
}

void check_selector_input() {

  while (forward_selector_active()) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
  while (backward_selector_active()) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}