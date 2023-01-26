#include "Arduino.h"
#include "Board.h"

class Player {
  private:
    Board playerBoard;

  public:
    Player();
    int** board();
    void printBoard();
    void setShip();
};