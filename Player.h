#include "Arduino.h"
#include "Board.h"

class Player {
  private:
    Board playerBoard;    // 10x10
    Ship destroyer;       // 2x1
    Ship submarine;       // 3x1
    Ship cruiser;         // 3x1
    Ship battleship;      // 4x1
    Ship aircraftCarrier; // 5x1

  public:
    Player();
    int** board();
    void printBoard();
    void placeShip(Ship ship);
    void setDestroyer(int startX, int startY, int endX, int endY);
    Ship getDestroyer();
};