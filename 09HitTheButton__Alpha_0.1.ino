int game_over_red = 12;
int alarm_yellow = 11;
int okay_green = 10;

int green = 6;
int blue = 7;
int yellow = 8;
int red = 9;

int button_down = 2;
int button_left = 3;
int button_right = 4;
int button_up = 5;

void setup() {
  pinMode(game_over_red, OUTPUT);
  pinMode(alarm_yellow, OUTPUT);
  pinMode(okay_green, OUTPUT);

  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_left, INPUT_PULLUP);
  pinMode(button_right, INPUT_PULLUP);
  pinMode(button_up, INPUT_PULLUP);
}

void loop() {
  digitalWrite(game_over_red, 1);
  digitalWrite(alarm_yellow, 1);
  digitalWrite(okay_green, 1);

  digitalWrite(green, 0);
  digitalWrite(blue, 0);
  digitalWrite(yellow, 0);
  digitalWrite(red, 0);


  if(digitalRead(button_down) == LOW) {
    digitalWrite(green, 1);
  }

  if(digitalRead(button_right) == LOW) {
    digitalWrite(yellow, 1);
  }

  if(digitalRead(button_left) == LOW) {
    digitalWrite(blue, 1);
  }

  if(digitalRead(button_up) == LOW) {
    digitalWrite(red, 1);
  }
}