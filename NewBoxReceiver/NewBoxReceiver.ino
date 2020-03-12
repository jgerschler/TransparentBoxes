

void setup() {
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
  delay(1000);
  digitalWrite(39, HIGH);
  delay(1000);
  digitalWrite(39, LOW);
  delay(1000);
  digitalWrite(40, HIGH);
  delay(1000);
  digitalWrite(40, LOW);
  delay(1000);
  digitalWrite(41, HIGH);
  delay(1000);
  digitalWrite(41, LOW);
  delay(1000);
  digitalWrite(42, HIGH);
  delay(1000);
  digitalWrite(42, LOW);
  delay(1000);
  digitalWrite(43, HIGH);
  delay(1000);
  digitalWrite(43, LOW);
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

