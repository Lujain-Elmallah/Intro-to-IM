int led1 = 9;
int led2 = 10;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  if (Serial.available()) {

    // Read a line like: "123,200"
    String input = Serial.readStringUntil('\n');

    // Parse two numbers
    int commaIndex = input.indexOf(',');
    if (commaIndex > 0) {
      int b1 = input.substring(0, commaIndex).toInt();
      int b2 = input.substring(commaIndex + 1).toInt();

      // Write PWM values
      analogWrite(led1, b1);
      analogWrite(led2, b2);
    }
  }
}
