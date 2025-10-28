void setup() {
  //LED Pin
  pinMode(13, OUTPUT);
  //Switch Pin
  pinMode(A2, INPUT);
}

void loop() {
  //Read the state of the switch
  int switchState = digitalRead(A2);

  //Loop to blink if switch is ON
  if (switchState == HIGH) { 
    digitalWrite(13, HIGH); //Turn the LED ON
    delay(250);  // Wait 250 ms
    digitalWrite(13, LOW);   //Turn the LED OFF
    delay(250);  // Wait 250 ms         
  } else {
    digitalWrite(13, LOW); //Keep the LED OFF
  }

}
