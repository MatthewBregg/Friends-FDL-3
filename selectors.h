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
bool full_auto = true;
unsigned long forward_depressed = 0;
unsigned long backward_depressed = 0;
unsigned long depress_time;
void check_selector_input() {

  if (forward_selector_active()) {
    // If forward depressed is 0, record current time.
     if (forward_depressed == 0) {
         forward_depressed = millis();
     } else {
       // If forward depressed is not 0, then check how long the forward selector has been active for. If over depress_time, then enable full auto.
      if  ((millis() - forward_depressed) > depress_time) {
        full_auto = true;
      }
     }
  } else {
    // Reset countdown
    forward_depressed = 0;
  }

  if (backward_selector_active()) {
    // If backward depressed is 0, record current time.
     if (backward_depressed == 0) {
         backward_depressed = millis();
     } else {
       // If backward depressed is not 0, then check how long the backward selector has been active for. If over depress_time, then disable full auto.
      if  ((millis() - backward_depressed) > depress_time) {
        full_auto = false;
      }
     }
  } else {
    // Reset countdown
    backward_depressed = 0;
  }

}