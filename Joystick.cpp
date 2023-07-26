#include "Joystick.h"

Joystick::Joystick() : button(SW_PIN) {
  pinMode(SW_PIN, INPUT_PULLUP);
  pinMode(VRX_PIN, INPUT);
  pinMode(VRY_PIN, INPUT);
  this->button.setDebounceTime(DEBOUNCE_DELAY);
}

// Loop is required to listen to the joystick events
// and update the direction variable, it must be called
// in the loop where the joystick is used
void Joystick::loop() {
  this->button.loop();
  this->yValue = analogRead(VRY_PIN);
  this->xValue = analogRead(VRX_PIN);

  if (this->yValue < THRESHOLD_LOW) {
    this->direction = UP;
  } else if (this->yValue > THRESHOLD_HIGH) {
    this->direction = DOWN;
  } else if (this->xValue < THRESHOLD_LOW) {
    this->direction = LEFT;
  } else if (this->xValue > THRESHOLD_HIGH) {
    this->direction = RIGHT;
  } else {
    this->direction = CENTER;
  }
}

// Return the direction of the joystick
// LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3, CENTER = 4
Joystick::direction_t Joystick::getDirection() {
  return this->direction;
}

void Joystick::printDirection() {
  switch (this->direction) {
    case LEFT:
      Serial.println("LEFT");
      break;
    case RIGHT:
      Serial.println("RIGHT");
      break;
    case UP:
      Serial.println("UP");
      break;
    case DOWN:
      Serial.println("DOWN");
      break;
    case CENTER:
      Serial.println("CENTER");
      break;
  }
}
