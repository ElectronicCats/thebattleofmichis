#include "Arduino.h"
#include "Ship.h"

class Board {
  private:
    int rows;
    int cols;

  public:
    int **get;
    Board(int rows, int cols);
    void serialPrint();
    void placeShip(Ship ship);
};