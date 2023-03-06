#include "Arduino.h"
#include "Player.h"

class Game {
  private:
    Player player1;
    Player player2;
    int Vertical;
    int Horizontal;

  public:
    Game();
    void start();
    void setup();
    void placeShip(int length);
};