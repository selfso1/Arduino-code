#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

const int ledPin = 9;
const int ledPin2 = 10;

int ulState = 0;

void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();

   if (a <= 10){
    ulState = 1;
   }
   else {
    ulState = 0;
   }
   
   if (ulState == 1) {
   
     digitalWrite(ledPin, HIGH);
     digitalWrite(ledPin2, LOW);
     
  }  
  
   else {
    
     digitalWrite(ledPin, LOW);
     digitalWrite(ledPin2, HIGH);
  }

   
   Serial.print(a);
   Serial.println("cm");
   delay(200);
}
