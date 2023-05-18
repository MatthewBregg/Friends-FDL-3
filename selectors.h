#include "read_trigger.h"
#pragma once

int forward_selector = A2;
int backward_selector = A3;

bool forward_selector_active() {
  return digitalRead(forward_selector) == LOW;
}
bool backward_selector_active() {
  return digitalRead(backward_selector) == LOW;
}
void blink_led_three_times() {
  for (int i = 0; i != 3; ++i) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}
void boot_into_speed_set_mode() {
  if ((forward_selector_active() || backward_selector_active()) && readTrigger()) {
    blink_led_three_times();
    // Enter speed set mode
    // Speed set mode done, catch here until blaster power off.
    while (true) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
  }
  }
  return;
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