int led = 5;
int sensor = A7;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, analogRead(sensor) / 4);
}
