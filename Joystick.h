#include "Arduino.h"
#include <ezButton.h>

#define VRX_PIN 33
#define VRY_PIN 25
#define SW_PIN 27 // Pull-up resistor

class Joystick {
  private:
    const int THRESHOLD_LOW = 1000;
    const int THRESHOLD_HIGH = 3000;
    enum direction_t { LEFT, RIGHT, UP, DOWN, CENTER };

  public:
    Joystick();
    direction_t direction = CENTER;
    ezButton button;
};