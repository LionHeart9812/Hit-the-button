int rot = 11;
int gelb = 9;
int gruen = 7;
int f_rot = 4;
int f_gruen = 2;
int taste = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(rot,  OUTPUT);
  pinMode(gelb, OUTPUT);
  pinMode(gruen, OUTPUT);
  pinMode(f_rot, OUTPUT);
  pinMode(f_gruen, OUTPUT);
  pinMode(taste, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(gruen, HIGH);
  digitalWrite(f_rot, HIGH);

  if(digitalRead(taste) == HIGH) {
    digitalWrite(gruen, LOW);
    digitalWrite(gelb, HIGH);

    delay(1800);

    digitalWrite(gelb, LOW);
    digitalWrite(rot, HIGH);

    delay(1500);

    digitalWrite(f_rot, LOW);
    digitalWrite(f_gruen, HIGH);

    delay(6000);
    
    digitalWrite(f_gruen, LOW);
    digitalWrite(f_rot, HIGH);

    delay(600);

    digitalWrite(gelb, HIGH);

    delay(1500);

    digitalWrite(gelb, LOW);
    digitalWrite(rot, LOW);
    digitalWrite(gruen, HIGH);

    delay(2500);
  }
}
