
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//RF24 radio(7, 8);

//const byte address[6] = "00001";

// tracking which buttons are lit
bool buttonStates[5] = {false, false, false, false, false}

void setup() {
  //Receiver Setup
  /*
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  */
  //Illuminated Buttons
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  //Buzzer
  pinMode(44, OUTPUT);
  //LED Strip
  pinMode(45, OUTPUT);
  //Button Switches
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(36, INPUT);
  pinMode(37, INPUT);
  pinMode(38, INPUT);
}

void loop() {
  for (int i = 34; i <= 38; i++) {
    if (digitalRead(i) == HIGH) {
      buttonStates[i - 34] = true;
    }
  }
  // need to decide on behavior before continuing here!
  /*
  if (radio.available()) {
    char text{16} = "";
    radio.read(&text, sizeof(text));
    //parse text to pull out instructions
  }
  */
}

void alert() {
  for (int i = 0; i <= 5; i++) {
    delay(200);
    digitalWrite(44, HIGH);
    digitalWrite(45, HIGH);
    delay(200);
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
  }
}

