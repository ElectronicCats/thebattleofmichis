#include "Arduino.h"
#include "Player.h"
#include <esp_now.h>
#include <WiFi.h>

typedef struct struct_message {
    uint8_t x;
    uint8_t y;
    uint8_t z;
} struct_message;
    
class Game {
  private:
    Player player1;
    Player player2;

    // REPLACE WITH THE MAC Address of your receiver 30:AE:A4:F5:0E:A4
    uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};

    // Create a struct_message called outgoing
    struct_message outgoing;
    
    // Create a struct_message to hold incoming
    struct_message incoming;

    esp_now_peer_info_t peerInfo;

  public:
    Game();
    void start();
    void setup();
};
