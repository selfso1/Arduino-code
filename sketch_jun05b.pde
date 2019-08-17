int motorPin = 9;  // define the pin the motor is connected to
const int buttonPin = 2;
int buttonState = 0;// (if you use pin 9,10,11 or 3you can also control speed)

/*
 * setup() - this function runs once when you turn your Arduino on
 * We set the motors pin to be an output (turning the pin high (+5v) or low (ground) (-))
 * rather than an input (checking whether a pin is high or low)
 */
void setup()
{
 pinMode(motorPin, OUTPUT); 
 pinMode(buttonPin, INPUT);

}



/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called motorOnThenOff()
 */

void loop() {
 //motorOnThenOff();
 //motorOnThenOffWithSpeed();
 //
 motorAcceleration();
//button();
}


void button()
// run over and over again
{ buttonState = digitalRead(buttonPin); // read the state of the pushbutton value:
  int onTime = 100;  //the number of milliseconds for the motor to turn on for
  int offTime = 1000; //the number of milliseconds for the motor to turn off for
  
  
  


  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {        
    digitalWrite(motorPin, LOW); // turns the motor On
                  // waits for onTime milliseconds
     
  


} 
  else {
    // turn LED off:
    digitalWrite(motorPin, HIGH); 
  }
}


/*
 * motorOnThenOff() - turns motor on then off 
 * (notice this code is identical to the code we used for
 * the blinking LED)
 */
void motorOnThenOff(){
  int onTime = 100;  //the number of milliseconds for the motor to turn on for
  int offTime = 1000; //the number of milliseconds for the motor to turn off for
  
  digitalWrite(motorPin, HIGH); // turns the motor On
  delay(onTime);                // waits for onTime milliseconds
  digitalWrite(motorPin, LOW);  // turns the motor Off
  delay(offTime);               // waits for offTime milliseconds
}

/*
 * motorOnThenOffWithSpeed() - turns motor on then off but uses speed values as well 
 * (notice this code is identical to the code we used for
 * the blinking LED)
 */
void motorOnThenOffWithSpeed(){
  
  int onSpeed = 100;  // a number between 0 (stopped) and 255 (full speed) 
  int onTime = 1000;  //the number of milliseconds for the motor to turn on for
  
  int offSpeed = 40;  // a number between 0 (stopped) and 255 (full speed) 
  int offTime = 2000; //the number of milliseconds for the motor to turn off for
  
  analogWrite(motorPin, onSpeed);   // turns the motor On
  delay(onTime);                    // waits for onTime milliseconds
  analogWrite(motorPin, offSpeed);  // turns the motor Off
  delay(offTime);                   // waits for offTime milliseconds
}

/*
 * motorAcceleration() - accelerates the motor to full speed then
 * back down to zero
*/
void motorAcceleration(){
  int delayTime = 50; //milliseconds between each speed step
  
  //Accelerates the motor
  for(int i = 0; i < 256; i++){ //goes through each speed from 0 to 255
    analogWrite(motorPin, i);   //sets the new speed
    delay(delayTime);           // waits for delayTime milliseconds
  }
  
  //Decelerates the motor
  for(int i = 255; i >= 0; i--){ //goes through each speed from 255 to 0
    analogWrite(motorPin, i);   //sets the new speed
    delay(delayTime);           // waits for delayTime milliseconds
  }
}


