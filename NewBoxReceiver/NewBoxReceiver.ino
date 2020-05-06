
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//illuminated buttons
const int r_b_led = 39;
const int y_b_led = 40;
const int g_b_led = 41;
const int b_b_led = 42;
const int w_b_led = 43;

//button switches
const int r_b_sw = 34;
const int y_b_sw = 35;
const int g_b_sw = 36;
const int b_b_sw = 37;
const int w_b_sw = 38;

//buzzer
const int buzzer = 44;

//led strip
const int led_strip = 45;

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

  pinMode(r_b_led, OUTPUT);
  pinMode(y_b_led, OUTPUT);
  pinMode(g_b_led, OUTPUT);
  pinMode(b_b_led, OUTPUT);
  pinMode(w_b_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_strip, OUTPUT);
  //Button Switches
  pinMode(r_b_sw, INPUT);
  pinMode(y_b_sw, INPUT);
  pinMode(g_b_sw, INPUT);
  pinMode(r_b_sw, INPUT);
  pinMode(r_b_sw, INPUT);
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
