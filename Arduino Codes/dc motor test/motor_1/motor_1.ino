int pwm = 8; // assigns pin 12 to variable pwm
int pot = A0; // assigns analog input A0 to variable pot
int t1 = 0;   // declares variable t1
int t2 = 0;   // declares variable t2
void setup()  // setup loop
{
  pinMode(pwm, OUTPUT); // declares pin 12 as output
  pinMode(pot, INPUT);  // declares pin A0 as input
  Serial.begin(9600);
}
void loop()
{
  t2= analogRead(pot);// reads the voltage at A0 and saves in t2
  Serial.println(t2);
  t1= 1000-t2;         // subtracts t2 from 1000 ans saves the result in t1
  digitalWrite(pwm, HIGH); // sets pin 12 HIGH
  delayMicroseconds(t1);   // waits for t1 uS (high time)
  digitalWrite(pwm, LOW);  // sets pin 12 LOW
  delayMicroseconds(t2);   // waits for t2 uS (low time)
} 
