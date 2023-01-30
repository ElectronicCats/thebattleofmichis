#include "Arduino.h"
#include "Board.h"
#include <vector>

class Player {
  private:
    Board playerBoard;    // 10x10
    Ship destroyer;       // 2x1
    Ship submarine;       // 3x1
    Ship cruiser;         // 3x1
    Ship battleship;      // 4x1
    Ship aircraftCarrier; // 5x1
    int sunkenShips;      // 5 when all ships are sunken
    std::vector<Ship> ships;

  public:
    Player();
    int** board();
    void printBoard();

    void placeShip(Ship ship); // Place a ship on the board
    void addShip(Ship ship); // Add a ship to the stack of ships
    void hit(int x, int y);
    bool isShipSunken(Ship ship);
    int getSunkenShips();

    void setDestroyer(String name, int startX, int startY, int endX, int endY);
    Ship getDestroyer();

    void setSubmarine(String name, int startX, int startY, int endX, int endY);
    Ship getSubmarine();

    void setCruiser(String name, int startX, int startY, int endX, int endY);
    Ship getCruiser();
    
    void setBattleship(String name, int startX, int startY, int endX, int endY);
    Ship getBattleship();

    void setAircraftCarrier(String name, int startX, int startY, int endX, int endY);
    Ship getAircraftCarrier();
};