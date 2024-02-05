//Start of program
// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h> //https://bitbucket.org/teckel12/arduino-new-ping/downloads/

#define TRIGGER_PIN  12 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 10 // Height of the Water Tank  (in centimeters). 


int motor = 10;
int val=0;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup() 
{

   pinMode(motor,OUTPUT); //Setup Relay pin as output pin
   digitalWrite(motor,LOW);
   Serial.begin(9600);
}

void loop() 
{
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  val=sonar.ping_cm();

 if(val<2) //Water level reaches the Top of the Tank
  {

  delay(50);

  digitalWrite(motor,LOW); //Pump off
  
  Serial.println("PUMP OFF");
  }

  
  else if(val>4) // Water is empty on the Tank
  {
  

  digitalWrite(motor,HIGH); // Pump ON
 
  Serial.println("PUMP ON");

  }
 
}

//End of program
