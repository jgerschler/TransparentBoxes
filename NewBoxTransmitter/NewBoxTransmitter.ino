
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte address[6] = "00001";

void setup() {
  //Transmitter Setup
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  // add commands for buttons here
  const char text[] = "ping_1"
  radio.write(&text, sizeof(text));
  // continue...
}
