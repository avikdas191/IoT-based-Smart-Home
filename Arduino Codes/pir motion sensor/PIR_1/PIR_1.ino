int pirSensor = 9;
int led = 5;
void setup() {
  pinMode(pirSensor, INPUT);
  pinMode(led, OUTPUT);  
}
void loop() {
  int sensorValue = digitalRead(pirSensor);
  if (sensorValue == 1) {
    digitalWrite(led, LOW); // The Relay Input works Inversly
  }
}

