#include "Arduino.h"
#include "Player.h"

class Game {
  private:
    Player player;

  public:
    Game();
    void start();
    void printBoard(); // For debugging
};