  int red = 4;
  int yellow = 7;
  int blue = 8;
  int green = 11;
  int button = 3;

  int w = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(button, INPUT);

  startUp();
}

void loop() {
  // put your main code here, to run repeatedly:
      digitalWrite(red, 1);
      digitalWrite(yellow, 1);
      digitalWrite(green, 1);
      digitalWrite(blue, 1);

  if(digitalRead(button)) {
    for(int i=0; i<5; i++) {

      delay(100);

      digitalWrite(red, 0);
      digitalWrite(yellow, 0);
      digitalWrite(green, 0);
      digitalWrite(blue, 0);
    }

    for(int k=0; k<13; k++) {
      roll();
      delay(125);
    }
    roll();
    delay(200);
    roll();
    delay(300);
    roll();
    delay(400);
    roll();
    delay(600);
    roll();
    delay(800);
    roll();
    while(digitalRead(button) == LOW){
      //wait
    }
    delay(200);
  }
}




//own voids

//roll()
void roll() {
  digitalWrite(red, 0);
  digitalWrite(yellow, 0);
  digitalWrite(green, 0);
  digitalWrite(blue, 0);
  delay(100);

  w = random(1,7);

  if(w==1) {
    digitalWrite(blue, 1);
  }
  
  if(w==2) {
    digitalWrite(red, 1);
  }
  
  if(w==3) {
    digitalWrite(blue, 1);
    digitalWrite(green, 1);
  }
  
  if(w==4) {
    digitalWrite(red, 1);
    digitalWrite(green, 1);
  }
  
  if(w==5) {
    digitalWrite(blue, 1);
    digitalWrite(red, 1);
    digitalWrite(green, 1);
  }
  
  if(w==6) {
    digitalWrite(red, 1);
    digitalWrite(yellow, 1);
    digitalWrite(green, 1);
  }
}

//changeLED()
void changeLED() {
    digitalWrite(red, 1);

    delay(400);

    digitalWrite(red, 0);
    digitalWrite(yellow, 1);

    delay(400);

    digitalWrite(yellow, 0);
    digitalWrite(green, 1);

    delay(400);

    digitalWrite(green, 0);
}

//StartUp()
void startUp() {

  changeLED();

  for(int j=0; j<2; j++) {
    digitalWrite(blue, 1);
    delay(200);
    digitalWrite(blue, 0);
    delay(200);
  }

  delay(250);
}
