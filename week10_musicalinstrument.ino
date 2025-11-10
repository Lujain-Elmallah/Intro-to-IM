// Musical foil instrument

const int stripPins[3] = {3, 4, 5}; // four foil strips
const int buzzerPin = 8;               // buzzer (passive piezo)
const int potPin = A0;                 // potentiometer for pitch control
const int pullDown = 10000;            // used for wiring, not in code

// Base frequencies for the 4 strips (Hz) - change to taste
int baseFreqs[3] = {165, 494, 659};

// debounce
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 30; // ms

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(stripPins[i], INPUT);
    // pins have external pull-down resistors in hardware wiring
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int activeIndex = -1;
  // check strips
  for (int i = 0; i < 3; i++) {
    int val = digitalRead(stripPins[i]);
    if (val == HIGH) {
      activeIndex = i;
    }
  }

  // read potentiometer (0..1023) and map to multiplier (0.6 .. 1.8)
  int potVal = analogRead(potPin);
  float multiplier = map(potVal, 0, 1023, 60, 180) / 100.0;

  if (activeIndex >= 0) {
    int freq = int(baseFreqs[activeIndex] * multiplier);
    freq = constrain(freq, 100, 5000);

    tone(buzzerPin, freq);
    Serial.print("Strip "); Serial.print(activeIndex+1);
    Serial.print(" freq=");
    Serial.println(freq);

    delay(50);
  } else {
    noTone(buzzerPin);
  }

  delay(10); // small loop delay
}
