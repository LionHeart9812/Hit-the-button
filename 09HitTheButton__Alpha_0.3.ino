int game_over_red = 11;
int okay_green = 10;

int green = 6;
int blue = 7;
int yellow = 8;
int red = 9;

int button_down = 2;
int button_left = 3;
int button_right = 4;
int button_up = 5;


int start_led_state = LOW;
unsigned long previousMillis = 0;
const long interval = 500;
unsigned int stop = 1;

int right_button_pressed = 0;

// 1: red/up
// 2: yellow/right
// 3: blue/left
// 4: green/down
int right_color = 0;

void setup() {
  pinMode(game_over_red, OUTPUT);
  pinMode(okay_green, OUTPUT);

  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  pinMode(button_down, INPUT_PULLUP);
  pinMode(button_left, INPUT_PULLUP);
  pinMode(button_right, INPUT_PULLUP);
  pinMode(button_up, INPUT_PULLUP);

  digitalWrite(game_over_red, 1);
  digitalWrite(okay_green, 1);
}

void loop() {

  //start
  if(digitalRead(button_down) == LOW) {
    digitalWrite(green, 0);
    digitalWrite(game_over_red, 0);
    digitalWrite(okay_green, 0);

    stop = 0;

    //continue programm
  }

  if(stop == 1) {

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if(start_led_state == LOW) {
      start_led_state = HIGH;
    } else {
      start_led_state = LOW;
    }

    digitalWrite(green, start_led_state);
  }

  }
}
