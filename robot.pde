//force sensor/ dual joystick midi controller sketch
// by ryanfinnigan



int sensePin = 3;
int sense2Pin = 4;
int ledPin = 9;
int buttonPin = 13;

int svalue = 0;
int svalue2 = 0;

int senState = 0;
int senState2 = 0;

int noteState = 0;
int noteState2 = 0;

int mappedIn = 0;
int mappedIn2 = 0;

int buttonVal = 0;                    //variable for reading the button status
int buttonState = 0;            //variable to hold the buttons current state
int bounceCheck = 0;            //variable for debouncing

int THRESHOLD = 2;

int previnVal = 0;
int previnVal2 = 0;
//joystick 1
int LRPin = 1;    // select the input pin for the l/r potentiometer
int UDPin = 2;    // select the input pin for the u/d potentiometer

int UDVal = 0;  // variable to store the value coming from the U/D pot
int LRVal = 0;  // variable to store the value coming from the L/R pot

int mappUD = 0;
int mappLR = 0;

int prevUDVal = 0;
int prevLRVal = 0;
//joystick2
int LR2Pin = 0;    // select the input pin for the l/r potentiometer
int UD2Pin = 5;    // select the input pin for the u/d potentiometer

int UDVal2 = 0;  // variable to store the value coming from the U/D pot
int LRVal2 = 0;  // variable to store the value coming from the L/R pot

int mappUD2 = 0;
int mappLR2 = 0;

int prevUDVal2 = 0;
int prevLRVal2 = 0;





void setup() {
    Serial.begin(31250);            //MIDI communicates at 31250 baud
    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);     //declare pushbutton as input
}

void loop() {
 
  
  buttonVal = digitalRead(buttonPin);     //read input value from button
  delay(5);                              //wait 10ms
  bounceCheck = digitalRead(buttonPin);   //check again
  if(buttonVal == bounceCheck){           //if val is the same then not a bounce
    if (buttonVal == HIGH && buttonState == 1) {   //check if the input is HIGH
      
      midiOUT(0xB0, 83, 0); //cc chnge, cc83, on
      buttonState = 0;
    }
    if(buttonVal == LOW && buttonState == 0){
      
      midiOUT(0xB0, 83, 127); //cc chnge, cc83, off
      buttonState = 1;
    }
  }
  //fsensor start
  svalue = analogRead(sensePin);
 
  mappedIn = map(svalue, 0, 1023, 0, 90);
  
  
  if(abs(mappedIn - previnVal) >= THRESHOLD){ //set 0 as default
     if (abs(svalue) == 0 )
       mappedIn = 0;    
          
     midiOUT(0xB0, 5, mappedIn); //Control Change (Ch 1), Controller 7 - default control for volume.
     previnVal = mappedIn;
   
  } 
  if(mappedIn <= 124){         // start midi note send// determine ir state, set digital value
     senState = 1;
  }
  if(mappedIn >= 125){  
     senState = 0;
  }
    
  if(senState == 0 && noteState ==1){ 
     midiOUT(0x90, 60, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     noteState = 0;
     }
     
  if(senState == 1 && noteState == 0){
     midiOUT(0x90, 60, 127); //Note ON (CH 1), middle C, velocity 127
     noteState = 1;
     }
  
  
  
  svalue2 = analogRead(sense2Pin);
 
  mappedIn2 = map(svalue2, 50, 1023, 0, 127);
  
  
  if(abs(mappedIn2 - previnVal2) >= THRESHOLD){ //set 0 as default
     if (abs(svalue2) == 0 )
       mappedIn2 = 0;    
          
     midiOUT(0xB0, 103, mappedIn2); //Control Change (Ch 1), Controller 7 - default control for volume.
     previnVal2 = mappedIn2;
   
  } 
  if(mappedIn2 <= 124){         // start midi note send// determine ir state, set digital value
     senState2 = 1;
  }
  if(mappedIn2 >= 125){  
     senState2 = 0;
  }
    
  if(senState2 == 0 && noteState2 ==1){ 
     midiOUT(0x90, 67, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     noteState2 = 0;
     }
     
  if(senState2 == 1 && noteState2 == 0){
     midiOUT(0x90, 67, 127); //Note ON (CH 1), middle C, velocity 127
     noteState2 = 1;
     }
  

   //joystick 1

  UDVal = analogRead(UDPin);  // read the value from the sensor:  
  
  mappUD = map(UDVal, 40, 988, 0, 100);  //map value to 0-127
  
  if(abs(mappUD - prevUDVal) >= THRESHOLD){
      midiOUT(0xB0, 7, mappUD);
      prevUDVal = mappUD;
 
  } 
  LRVal = analogRead(LRPin);  // read the value from the sensor:  
  
  mappLR = map(LRVal, 60, 1023, 50, 120);  //map value to 0-127
  
  if(abs(mappLR - prevLRVal) >= THRESHOLD){
      midiOUT(0xB0, 6, mappLR);
      prevLRVal = mappLR;
    
  }
  //joystick 2
  
  UDVal2 = analogRead(UD2Pin);  // read the value from the sensor:  
  
  mappUD2 = map(UDVal2, 40, 988, 0, 127);  //map value to 0-127
  
  if(abs(mappUD2 - prevUDVal2) >= THRESHOLD){
      midiOUT(0xB0, 8, mappUD2);
      prevUDVal2 = mappUD2;
 
  } 
  LRVal2 = analogRead(LR2Pin);  // read the value from the sensor:  
  
  mappLR2= map(LRVal2, 60, 1023, 40, 75);  //map value to 0-127
  
  if(abs(mappLR2 - prevLRVal2) >= THRESHOLD){
      midiOUT(0xB0, 9, mappLR2);
      prevLRVal2 = mappLR2;
    
  }



}



void midiOUT(char command, char value1, char value2) {
  Serial.print(command, BYTE);
  Serial.print(value1, BYTE);
  Serial.print(value2, BYTE);

}
