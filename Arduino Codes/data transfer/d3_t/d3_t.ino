#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <Servo.h>

Servo servo_1;
int redLed = 5;
int greenLed = 6;
int buzzer = 9;
//int smokeA0 = A0;
int smokeD0 = 2;
int sensorThres = 1;
int motor = 10;
RF24 radio(7, 8); // CE, CSN
const byte address = 0xB00B1E50B1LL;

void setup() {
  pinMode(smokeD0, INPUT);
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(motor, OUTPUT);
  pinMode(servo_1.attach(3), OUTPUT);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
  
}

void loop() {
  int digitalSensor = digitalRead(smokeD0);
  if (digitalSensor != sensorThres)
  {
    Serial.println("Gas leaked");
    
    radio.write(&digitalSensor, sizeof(digitalSensor));
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
