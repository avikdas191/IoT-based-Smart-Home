/*
* Arduino Wireless Communication Tutorial
*     Example 2 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define button 3
RF24 radio(7, 8); // CE, CSN
const byte addresses[6] = {"00001"};

boolean buttonState = 0;
void setup() {
  pinMode(button, INPUT);
  
  radio.begin();
  radio.openWritingPipe(addresses);
  
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {

    delay(5);
    radio.stopListening();
    buttonState = digitalRead(button);
    radio.write(&buttonState, sizeof(buttonState));
  
}
