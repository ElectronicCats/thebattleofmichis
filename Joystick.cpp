#include "Joystick.h"

Joystick::Joystick() : button(SW_PIN) {
  pinMode(SW_PIN, INPUT_PULLUP);
  this->button.setDebounceTime(50);
}