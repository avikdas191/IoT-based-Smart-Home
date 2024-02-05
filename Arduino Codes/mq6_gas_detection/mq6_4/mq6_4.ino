#include <Servo.h>
Servo servo_1;

int redLed = 5;
int greenLed = 6;
int buzzer = 9;
int gas = 2;
int sensorThres = 1;
int motor = 10;

void setup() {
  pinMode(gas, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(servo_1.attach(3), OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int digitalSensor = digitalRead(gas);

  if (digitalSensor != sensorThres)
  {
    Serial.println("Gas leaked");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(motor, HIGH);
    servo_1.write(85);
    tone(buzzer, 1000, 200);
  }
  else if (digitalSensor == sensorThres)
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(motor, LOW);
    servo_1.write(5);
    noTone(buzzer);
  }
  delay(100);
}
