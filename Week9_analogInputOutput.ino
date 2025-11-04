const int potPin = A0;
const int button1Pin = A1;
const int button2Pin = A2;
const int led1Pin = 10;
const int led2Pin = 11;

bool led1Flashing = false;
bool led2Flashing = false;

bool lastButton1State = HIGH;
bool lastButton2State = HIGH;

unsigned long prevMillis1 = 0;
unsigned long prevMillis2 = 0;
const int flashDelay = 300;

void setup() {
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Map potentiometer to brightness
  int potValue = analogRead(potPin);
  int brightness = map(potValue, 0, 1023, 0, 255);

  //Button 1
  bool button1State = digitalRead(button1Pin);
  if (button1State == LOW && lastButton1State == HIGH) {
    led1Flashing = !led1Flashing; 
    if (!led1Flashing) {
      analogWrite(led1Pin, brightness); 
    }
    delay(200);
  }
  lastButton1State = button1State;

  //Button 2
  bool button2State = digitalRead(button2Pin);
  if (button2State == LOW && lastButton2State == HIGH) {
    led2Flashing = !led2Flashing;
    if (!led2Flashing) {
      analogWrite(led2Pin, brightness);
    }
    delay(200);
  }
  lastButton2State = button2State;

  unsigned long currentMillis = millis();

  //LED 1 Flashing
  if (led1Flashing && currentMillis - prevMillis1 >= flashDelay) {
    prevMillis1 = currentMillis;
    static bool led1On = false;
    led1On = !led1On;
    analogWrite(led1Pin, led1On ? brightness : 0);
  }

  //LED 2 Flashing
  if (led2Flashing && currentMillis - prevMillis2 >= flashDelay) {
    prevMillis2 = currentMillis;
    static bool led2On = false;
    led2On = !led2On;
    analogWrite(led2Pin, led2On ? brightness : 0);
  }
}

