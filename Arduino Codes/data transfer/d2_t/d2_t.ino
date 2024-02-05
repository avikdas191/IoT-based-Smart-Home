#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

RF24 radio(7, 8); // CE, CSN
const byte address = 0xB00B1E50C3LL;
int ledPin = 9;       // choose the pin for the LED
int buzzer = 2;
int inputPin = 5;     // choose the input pin (for PIR sensor)
int pirState = LOW;   // we start, assuming no motion detected
int val = 0;          // variable for reading the pin status

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);   // declare LED as output
  pinMode(buzzer, OUTPUT);
  pinMode(inputPin, INPUT);  // declare sensor as input
  
  radio.begin();
  radio.openWritingPipe(address);

  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
}

void loop() {
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH); // turn LED ON
    digitalWrite(buzzer, HIGH);
    if (pirState == LOW) {
      // we have just turned on
      
      // We only want to print on the output change, not state
      pirState = HIGH;
      radio.write(&pirState, sizeof(pirState));
    }
    
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    digitalWrite(buzzer, LOW);
    if (pirState == HIGH){
      // we have just turned of
      //Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
    
  }
 
}
