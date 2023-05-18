int forward_selector = A2;
int backward_selector = A3;

bool forward_selector_active() {
  return digitalRead(forward_selector) == LOW;
}
bool backward_selector_active() {
  return digitalRead(backward_selector) == LOW;
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