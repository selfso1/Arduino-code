const int ledPin =  3;      // the number of the LED pin
//const int ledPin2 = 8;      // the number of the LED pin

int potPin1 = 0;
int potPin2 = 5;

int potVal1 = 0;
int potVal2 = 0;

int mapVal1 = 0;
int mapVal2 = 0;

int ledState = LOW;             // ledState used to set the LED


unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned long previousMilisOff = 0;
int intervalON = 0;
int intervalOFF = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  potVal1 = analogRead(potPin1);
  potVal2 = analogRead(potPin2);
  
  mapVal1 = map(potVal1, 0, 1023, 800, 2000);
  mapVal2 = map(potVal2, 0, 1023, 800, 2000);
  
  unsigned long currentMillis = millis();
  intervalON = potVal1; 
  intervalOFF = potVal2;
  if(currentMillis - previousMillis >= intervalON) {
    previousMillis = currentMillis;
    if (ledState == LOW)
      ledState = HIGH;
      
    digitalWrite(ledPin, ledState);
  } else if(currentMillis - previousMillis >= intervalOFF) {
    if (ledState == HIGH)
      ledState = LOW;
    digitalWrite(ledPin, ledState);
  }
}

