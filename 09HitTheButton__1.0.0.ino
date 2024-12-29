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

bool game_running = true;
int right_button_pressed = 0;
int right_condition = 0;

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

    delay(300);

    //main game start
    while(game_running) {
        right_color = random(1,5);
        setColor(right_color);
        setRightCondition();
        right_button_pressed = 0;

        while(right_button_pressed == 0) {
          buttonCheck(right_color);

          //Stop game
          if (digitalRead(button_up) == LOW && digitalRead(button_down) == LOW) {
            game_running = false;
            break;
        }
      }
        delay(100);
        clearLEDS();
  }
    //main game end
    //game end
    clearLEDS();
    digitalWrite(game_over_red, HIGH);
    delay(1000);
    digitalWrite(game_over_red, LOW);
    stop = 1;
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

//setColor
void setColor(int numberCheck) {
// 1: red/up
// 2: yellow/right
// 3: blue/left
// 4: green/down

  if(numberCheck == 1){
    digitalWrite(red, 1);
  }
  
  if(numberCheck == 2){
    digitalWrite(yellow, 1);
  }

  if(numberCheck == 3){
    digitalWrite(blue, 1);
  }

  if(numberCheck == 4){
    digitalWrite(green, 1);
  }
}

//setRightCondition()
void setRightCondition() {
  if(right_color == 1) {
    right_condition = 1;
  }
  else if(right_color == 2) {
    right_condition = 2;
  }
  else if(right_color == 3) {
    right_condition = 3;
  }
  else if(right_color == 4) {
    right_condition = 4;
  }
}


//buttonCheck()
void buttonCheck(int colorCheck) {
  if(colorCheck == 1 && digitalRead(button_up) == LOW) {
    digitalWrite(okay_green, 1);
    delay(300);
    digitalWrite(okay_green, 0);

    right_button_pressed = 1;
  }

  else if(digitalRead(button_up) == LOW) {
    right_condition = 1;
  }

  else if(colorCheck == 2 && digitalRead(button_right) == LOW) {
    digitalWrite(okay_green, 1);
    delay(300);
    digitalWrite(okay_green, 0);

    right_button_pressed = 1;
  }

  else if(digitalRead(button_right) == LOW) {
    right_condition = 2;
  }

  else if(colorCheck == 3 && digitalRead(button_left) == LOW) {
    digitalWrite(okay_green, 1);
    delay(300);
    digitalWrite(okay_green, 0);

    right_button_pressed = 1;
  }

  else if(digitalRead(button_left) == LOW) {
    right_condition = 3;
  }

  else if(colorCheck == 4 && digitalRead(button_down) == LOW) {
    digitalWrite(okay_green, 1);
    delay(300);
    digitalWrite(okay_green, 0);

    right_button_pressed = 1;
  }

  else if(digitalRead(button_down) == LOW) {
    right_condition = 4;
  }
  
  else if(colorCheck != right_condition) {
      digitalWrite(game_over_red, HIGH);
      delay(200);
      digitalWrite(game_over_red, LOW);
    right_button_pressed = 0; 
    right_condition = colorCheck;
  }
}

//clearLEDS()
void clearLEDS() {
  digitalWrite(red, 0);
  digitalWrite(green, 0);
  digitalWrite(blue, 0);
  digitalWrite(yellow, 0);

  digitalWrite(game_over_red, 0);
  digitalWrite(okay_green, 0);
}