int sensor = A7;
int n = 7;
int leds[] = {11, 10, 8, 7, 5, 4, 2};


void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < n; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int s = analogRead(sensor);
  int p = map(s, 0, 1023.5, 0, n);
  
  for (int i = 0; i < n; i++) {
    if(i < p) {
      digitalWrite(leds[i], HIGH);
    }
    else {
      digitalWrite(leds[i], LOW);
    }
  }
}
