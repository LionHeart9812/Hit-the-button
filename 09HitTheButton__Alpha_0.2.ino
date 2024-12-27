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

int right_button_pressed = false;

// 1: red/up
// 2: yellow/right
// 3: blue/left
// 4: green/down
int right_color = 0;

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

  digitalWrite(game_over_red, 0);
  digitalWrite(alarm_yellow, 0);
  digitalWrite(okay_green, 0);

  digitalWrite(green, 0);
  digitalWrite(blue, 0);
  digitalWrite(yellow, 0);
  digitalWrite(red, 0);
}

void loop() {
  startingLoop();
  digitalWrite(blue, 1);
}


//startingLoop()
void startingLoop() {
  while(digitalRead(button_down) == HIGH && digitalRead(button_left) == HIGH && digitalRead(button_right) == HIGH && digitalRead(button_up) == HIGH) {
    digitalWrite(okay_green, 0);
    digitalWrite(game_over_red, 1);

    delay(1000);

    digitalWrite(game_over_red, 0);
    digitalWrite(alarm_yellow, 1);

    delay(1000);

    digitalWrite(alarm_yellow, 0);
    digitalWrite(okay_green, 1);

    delay(1000);
  }
}

//timer()
void timer() {
  digitalWrite(okay_green, 0);
  digitalWrite(game_over_red, 0);
  digitalWrite(alarm_yellow, 0);

  delay(25);

  digitalWrite(game_over_red, 1);
}