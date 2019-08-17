//Durango DI team

#include <Servo.h>   // loads servo library
 
Servo myservo;  // create servo object to control a servo 
 
int switchPin = 7;  // analog pin used to connect the potentiometer
int switchVal = 0;
int bounceCheck = 0;
int switchState = 0;
int val = 180;    // this will determine the speed. 180 is top speed
int val2 = 94;    // stop value, may need to go up or down during calibration

int delay1 = 7000; //this value determines the distance. higher= farther

void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

  pinMode(switchPin, INPUT);  // sets digital pin as input
}

void loop() 
{ 
   // read the state of the switchPin value:
  switchVal = digitalRead(switchPin);
  delay(10); 
  //wait 10ms
  bounceCheck = digitalRead(switchPin);      
  if(switchVal == bounceCheck){           //if val is the same then not a bounce
    if(switchVal == HIGH && switchState == 0) { 
      myservo.write(val);                  // sets the servo speed
      delay(delay1);                           // waits for the servo to get there 
      myservo.write(val2);                 //stops servo
      switchState = 1;
      }     
    if(switchVal == LOW) {                 //resets bot
      myservo.write(val2);
      switchState = 0;
      delay(5);
      }  
    }
} 
