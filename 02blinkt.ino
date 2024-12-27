int ledGREEN = 7;
int ledRED = 11;
int ledBLUE = 9;

int count = 5;

void setup() {
  pinMode(ledGREEN, OUTPUT);
  pinMode(ledRED, OUTPUT);
  pinMode(ledBLUE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  count = 5;
  digitalWrite(ledGREEN, LOW);
  digitalWrite(ledRED, HIGH);
  delay(500);

  while(count > 0) {
    digitalWrite(ledBLUE, HIGH);
    delay(200);
    digitalWrite(ledBLUE, LOW);
    delay(200);
    count = count - 1;
  }

  count = 5;
  digitalWrite(ledRED, LOW);
  digitalWrite(ledGREEN, HIGH);
  delay(250);

  while(count > 0) {
    digitalWrite(ledBLUE, HIGH);
    delay(200);
    digitalWrite(ledBLUE, LOW);
    delay(200);
    count = count - 1;
  }

}
