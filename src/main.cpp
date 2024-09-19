#include <Arduino.h>
#include <M5Atom.h>

#include "udp_server.h"

// define
#define PIN_22 22 // output to move trank motor

#define IDLE_LOOP     0x01
#define MOVE_TRANK    0x02
#define CLOSE_TRANK   0x03

void setup() {
  M5.begin();

  pinMode(PIN_22, OUTPUT);
  digitalWrite(PIN_22, LOW);
  
  udp_server_open();
  delay(500);
 
}

void loop() {
  st_udp_server *p_udp_server = &g_udp_server;
  
  udp_server_receive_data();
  
  switch (p_udp_server->receiveData){
    case IDLE_LOOP:
      digitalWrite(PIN_22, LOW);
      break;
    case MOVE_TRANK:
      digitalWrite(PIN_22, HIGH);
      break;
  }

}
