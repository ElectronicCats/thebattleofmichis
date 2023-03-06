#include "Game.h"

Game::Game() {
  Vertical = Board::Vertical;
  Horizontal = Board::Horizontal;
}

void Game::start() {
  Game::setup();
  unsigned long time = millis();
  static unsigned long lastTime = time;
  int counter = 0;

  Game::placeShip(2);
  Game::placeShip(3);
  Game::placeShip(3);
  Game::placeShip(4);
  Game::placeShip(5);

  for(;;) {
    // Logic game goes here
  }
}

void Game::setup() {
  player1.hit(5, 8);
  player1.printBoard();
  delay(1000);
  player1.hit(3, 6);
  player1.printBoard();
  delay(1000);
  player1.hit(6, 8);
  player1.printBoard();
  delay(1000);
  player1.hit(7, 8);
  player1.printBoard();
  delay(1000);
  player1.hit(8, 8);
  player1.printBoard();
}

void Game::placeShip(int length) {
  int orientation = Horizontal;
  int center = 4;
  int startX;
  int startY;
  int endX;
  int endY;

  for (;;) {
    player1.loop();
    player1.setCursor('m', center, center, length, orientation);

    // Toggle orientation
    if (player1.joystick.button.isPressed()) {
      orientation = orientation == Vertical ? Horizontal : Vertical;
    }

    // Place ship
    if (player1.button.isPressed()) {
      if (orientation == Horizontal) {
        startX = player1.getCursorX();
        endX = player1.getCursorX() + (length - 1);
        startY = endY = player1.getCursorY();
      } else {
        startX = endX = player1.getCursorX();
        startY = player1.getCursorY();
        endY = player1.getCursorY() + (length - 1);
      }

      // If the ship can be created, place it on the board
      if (player1.createShip(startX, startY, endX, endY)) {
        player1.placeShip(player1.getShip(player1.getShipsList().size() - 1));
        player1.printBoard();
        player1.resetColors();
        // player1.setCursorX(center);
        // player1.setCursorY(center);
        break;
      }
    }
  }
}
