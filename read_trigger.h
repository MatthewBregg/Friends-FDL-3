#pragma once
const int trigSwitchA = 6;
const int trigSwitchB = 7;

// Returns true IFF the trigger switch is depressed.
// Correct plug orientation: Stripe on heat shrink towards edge of board. Should curve away from arduino.
bool readTrigger() {
  return !digitalRead(trigSwitchA) && digitalRead(trigSwitchB);
}

bool readAndDebounceTriggerSync(unsigned long m) {
  // Is button initially down?
  if (readTrigger()) {
    delay(m);
    // Return if button is still down after a debounce delay
    return readTrigger();
  }
  // Button was never down, return false.
  return false;
}