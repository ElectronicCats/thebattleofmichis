#include "Arduino.h"
#include "Board.h"
#include <vector>
#include "Joystick.h"

#define ROWS 8
#define COLS 8
const int PIN_MATRIX_1 = 16;
const int PIN_MATRIX_2 = 17;

class Player {
  private:
    Board<16> mainBoard;
    Board<16> enemyBoard;
    int sunkenShips;      // 5 when all ships are sunken
    std::vector<Ship> ships;

  public:
    Player();
    int** board();
    void printBoard();

    void placeShip(Ship ship); // Place a ship on the board
    void addShip(Ship ship); // Add a ship to the list of ships
    void hit(int x, int y);
    bool isShipSunken(Ship ship); // Increase the number of sunken ships
    int getSunkenShips();
    bool createShip(int startX, int startY, int endX, int endY);
    bool isValidShipCoordinates(int startX, int startY, int endX, int endY);
    Ship getShip(int arrayPosition);
    std::vector<Ship> getShipsList();

    void setCursor(int x, int y);
    Joystick joystick;
};