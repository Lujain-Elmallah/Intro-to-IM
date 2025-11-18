#define TRIG 10
#define ECHO A1

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Make sure trigger is LOW
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Send 10us HIGH pulse to trigger ultrasonic
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
