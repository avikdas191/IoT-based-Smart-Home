/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Reciever Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 10
RF24 radio(7, 8); // CE, CSN
const byte addresses[6] = {"00001"};
boolean buttonState = 0;
void setup() {
  pinMode(10, OUTPUT);
  radio.begin();
  
  radio.openReadingPipe(1, addresses);
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {

  delay(5);
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
  if (buttonState == HIGH) {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
}
