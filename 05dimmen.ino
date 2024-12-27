int led = 5;
int hell = 0;
int schritt = 15;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, hell);
  hell += schritt;
  if (hell == 0 || hell == 255) {
    schritt = -schritt;
  }
  delay(25);
}
