
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
bool buttons_active = true;

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
  pinMode(b_b_sw, INPUT);
  pinMode(w_b_sw, INPUT);
}

void loop() {

  // need to decide on behavior before continuing here!
  /*
  if (radio.available()) {
    char text{16} = "";
    radio.read(&text, sizeof(text));
    //parse text to pull out instructions
  }
  */
  if (/*serial activate sign recvd*/) {
    buttons_active = true;
    activate_buttons();
  }
  if (/*serial deactivate sign recvd*/) {
    buttons_active = false;
  }
  if (/*serial reset sign recvd*/) {
    reset_buttons();
  }
}

void activate_buttons() {
  while (buttons_active == true) {
    if (digitalRead(r_b_sw) == HIGH) {
      digitalWrite(r_b_led, HIGH);
      buttons_active = false;
    }
    if (digitalRead(y_b_sw) == HIGH) {
      digitalWrite(y_b_led, HIGH);
      buttons_active = false;
    }
    if (digitalRead(g_b_sw) == HIGH) {
      digitalWrite(g_b_led, HIGH);
      buttons_active = false;
    }
    if (digitalRead(b_b_sw) == HIGH) {
      digitalWrite(b_b_led, HIGH);
      buttons_active = false;
    }
    if (digitalRead(w_b_sw) == HIGH) {
      digitalWrite(w_b_led, HIGH);
      buttons_active = false;
    }
  }
  loop();
}

void reset_buttons() {
    digitalWrite(r_b_led, LOW);
    digitalWrite(y_b_led, LOW);
    digitalWrite(g_b_led, LOW);
    digitalWrite(b_b_led, LOW);
    digitalWrite(w_b_led, LOW);
    loop();
}

void alert() {
  for (int i = 0; i <= 5; i++) {
    delay(200);
    digitalWrite(buzzer, HIGH);
    digitalWrite(led_strip, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    digitalWrite(led_strip, LOW);
  }
}
