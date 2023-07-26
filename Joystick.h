#include "Arduino.h"
#include <ezButton.h>

#define VRX_PIN         33
#define VRY_PIN         35
#define SW_PIN          27 // Pull-up resistor in software
#define DEBOUNCE_DELAY  50 // miliseconds
#define THRESHOLD_LOW   1000
#define THRESHOLD_HIGH  3000

class Joystick {
  private:
    int yValue;
    int xValue;
    enum direction_t { LEFT, RIGHT, UP, DOWN, CENTER }; // LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3, CENTER = 4
    direction_t direction;

  public:
    Joystick();
    void loop();
    ezButton button;
    direction_t getDirection();
    void printDirection();
};
