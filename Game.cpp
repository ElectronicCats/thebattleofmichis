#include "Game.h"

Game::Game() {
  Vertical = Board::Vertical;
  Horizontal = Board::Horizontal;
}

void Game::start() {
  static unsigned long lastTime = millis();
  Game::setup();

  for(;;) {
    // Logic game goes here
    player1.loop();
    player1.setCursor('e', 4, 4, 1, Horizontal);

    if (player1.button.isPressed()) {
      Serial.println("x: " + String(player1.getCursorX()) + " y: " + String(player1.getCursorY()));
      Serial.println("Is hit: " + String(player1.hit(player1.getCursorX(), player1.getCursorY())));
      player1.resetColors();
    }
  }
}

void Game::setup() {
  Game::placeShip(2);
  Game::placeShip(3);
  Game::placeShip(3);
  Game::placeShip(4);
  Game::placeShip(5);
}

void Game::placeShip(int length) {
  int orientation = Horizontal;
  int center = 4;
  int startX, startY, endX, endY;

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
        break;
      }
    }
  }
}
