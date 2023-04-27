#include "Arduino.h"
#include "Board.h"
#include "Joystick.h"
#include "Coordinate.h"

#define ROWS            8
#define COLS            8
#define MOVE_DELAY      200 // miliseconds

#define BUTTON_PIN      32 // Pull-up resistor in software
#define DEBOUNCE_DELAY  50 // miliseconds

class Player {
  private:
    Board board;
    int sunkenShips;      // 5 when all ships are sunken
    std::vector<Ship> ships;
    std::vector<Coordinate> hitsList;

  public:
    Player();
    void loop();
    void printBoard();

    void placeShip(Ship ship); // Place a ship on the board
    void addShip(Ship ship); // Add a ship to the list of ships
    bool hit(int x, int y);
    bool isShipSunken(Ship ship); // Increase the number of sunken ships
    int getSunkenShips();
    void setSunkenShips(int sunkenShips);
    bool createShip(int startX, int startY, int endX, int endY);
    bool isValidShipCoordinates(int startX, int startY, int endX, int endY);
    Ship getShip(int arrayPosition);
    std::vector<Ship> getShipsList();
    std::vector<Coordinate> getHitsList();
    void setHitToList(Coordinate hit);
    void clearHitsList();
    bool isValidHit(int x, int y);

    void setCursor(char id, int x, int y, int length, int orientation, int color);
    int getCursorX();
    int getCursorY();
    int getColor(char id, int x, int y);
    void setColor(char id, int x, int y, int color);
    void clearBoard(char id);
    void resetEnemyColors();
    void resetMainColors();
    Joystick joystick;
    ezButton button;

    void printScroller(int id);
};
