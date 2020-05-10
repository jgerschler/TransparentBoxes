
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

//led strip (not currently installed for transmitter)
const int led_strip = 45;

RF24 radio(7, 8);

const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();

  pinMode(r_b_led, OUTPUT);
  pinMode(y_b_led, OUTPUT);
  pinMode(g_b_led, OUTPUT);
  pinMode(b_b_led, OUTPUT);
  pinMode(w_b_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_strip, OUTPUT);
  pinMode(r_b_sw, INPUT);
  pinMode(y_b_sw, INPUT);
  pinMode(g_b_sw, INPUT);
  pinMode(b_b_sw, INPUT);
  pinMode(w_b_sw, INPUT);

  const char text[] = "alert";
  radio.write(&text, sizeof(text));
}

void loop() {
  const char text[] = "alert";
  radio.write(&text, sizeof(text));
  delay(5000);
  // eventually will be broken down by receiver unit
  // need to add activate and reset func
  if (digitalRead(r_b_sw) == HIGH) {
    const char text[] = "alert";
    radio.write(&text, sizeof(text));
  }
  if (digitalRead(y_b_sw) == HIGH) {
    const char text[] = "alert";
    radio.write(&text, sizeof(text));
  }
  if (digitalRead(g_b_sw) == HIGH) {
    const char text[] = "alert";
    radio.write(&text, sizeof(text));
  }
  if (digitalRead(b_b_sw) == HIGH) {
    const char text[] = "alert";
    radio.write(&text, sizeof(text));
  }
  if (digitalRead(w_b_sw) == HIGH) {
    const char text[] = "alert";
    radio.write(&text, sizeof(text));
  }
}
