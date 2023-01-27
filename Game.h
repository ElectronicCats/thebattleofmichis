#include "Arduino.h"
#include "Player.h"

class Game {
  private:
    Player player1;
    Player player2;

  public:
    Game();
    void start();
    void setup();
};