#include "Arduino.h"
#include <ezButton.h>

#define VRX_PIN         33
#define VRY_PIN         25
#define SW_PIN          32 // Pull-up resistor
#define DEBOUNCE_DELAY  50 // miliseconds
#define THRESHOLD_LOW   1000
#define THRESHOLD_HIGH  3000

class Joystick {
  private:
    int yValue;
    int xValue;
    enum direction_t { LEFT, RIGHT, UP, DOWN, CENTER };
    direction_t direction;

  public:
    Joystick();
    void loop();
    ezButton button;
    direction_t getDirection();
    void printDirection();
};