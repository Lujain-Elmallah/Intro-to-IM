int led = 12;
int TRIG = 10;
int ECHO = A1;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}



void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    int state = input.toInt();
    digitalWrite(led, state);
    return; 
}

  ////////////////// PART 2 ///////////////////////

  // Make sure trigger is LOW
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // send a 10s trigger
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read echo time
  duration = pulseIn(ECHO, HIGH);

  // Convert to distance in cm
  distance = duration * 0.034 / 2;

  // Send only the distance value to Serial
  Serial.println(distance);

  delay(30);  // small delay for stability
}
