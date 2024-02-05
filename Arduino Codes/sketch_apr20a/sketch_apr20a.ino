/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>

#include <RF24.h>
#include <RF24_config.h>
RF24 radio(7, 8); // CE, CSN
const byte address[] = {0xB00B1E50D2LL, 0xB00B1E50C3LL, 0xB00B1E50B1LL};
float gotByte;
int state ;
int sense ;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address[0]);
  radio.openReadingPipe(2, address[1]);
  radio.openReadingPipe(3, address[2]);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  byte pipeNum = 0;
  //char gotByte[32] = ""; 
  
  while (radio.available(&pipeNum)) {
    if(pipeNum == 1){
    radio.read( &gotByte, sizeof(gotByte) );
    Serial.print("Recieved message from transmitter: "); 
    Serial.println(pipeNum); 
    Serial.print("message: ");
    Serial.println(gotByte);
    Serial.println();
    }
    else if(pipeNum == 2){
    
    radio.read(&sense, sizeof(sense));
    Serial.print("Recieved message from transmitter: "); 
    Serial.println(pipeNum); 
    Serial.print("message: ");
    Serial.println(sense);
    Serial.println();
    }
    else if(pipeNum == 3){
    
    radio.read(&state, sizeof(state));
    Serial.print("Recieved message from transmitter: "); 
    Serial.println(pipeNum); 
    Serial.print("message: ");
    Serial.println(state);
    Serial.println();
    }
  }
  delay(200);
}
