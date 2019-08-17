
const int ledPin =  9;

int potPin1 = 0;
int potPin2 = 1;

int potVal1 = 0;
int potVal2 = 0;

int mapVal1 = 0;
int mapVal2 = 0;

int intervalON = 0;
int intervalOFF = 0;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(ledPin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  
  potVal1 = analogRead(potPin1);
  potVal2 = analogRead(potPin2);
  
  mapVal1 = map(potVal1, 0, 1023, 500, 2000);
  mapVal2 = map(potVal2, 0, 1023, 500, 2000);
  
  intervalON = mapVal1; 
  intervalOFF = mapVal2;
  
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(intervalON);              // wait for a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(intervalOFF);              // wait for a second
}
