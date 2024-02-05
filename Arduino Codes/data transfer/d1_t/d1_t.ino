#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <dht.h>
#define dataPin 5

RF24 radio(7, 8); // CE, CSN
const byte address = 0xB00B1E50D2LL;
dht DHT;

void setup() {
 
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
  //Serial.begin(9600);
}

void loop() {
  int readData = DHT.read22(dataPin);
  float t = DHT.temperature;
  radio.write(&t, sizeof(t));
  //Serial.println(t);
  delay(1000);
}
