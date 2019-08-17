/*
 * 0.2beta Benny the Booze Organ
 * ryan finnigan
 * 
 * 
 * 
 * 
 * 
 */

int ledPin = 11;                //choose the pin for the LED - needs to be (3,5,6,9,10, or 11)
int buttonPin = 2;               //choose the input pin for a pushbutton
int irPin = 0;                  //choose the input pin for a potentometer
int buttonVal = 0;                    //variable for reading the button status
int buttonState = 0;            //variable to hold the buttons current state
int irState =0;
int noteState =0;
int bounceCheck = 0;            //variable for debouncing
int irVal = 0;                 //variable for reading potentiometer value
int irVal1 = 0;       
int irVal2 = 0;    
int irVal3 = 0;       
int irVal4 = 0;    
int irVal5 = 0;       
int irVal6 = 0;    
int irVal7 = 0;       
int irVal8 = 0;
int irVal9 = 0;       
int irVal10 = 0;
int mappedirVal = 0;          //variable for holding remapped pot value
int previrVal = 0;               //variable for storing our prev pot value
int THRESHOLD1 = 5;            //threshold amount
int THRESHOLD2 = 30;

void setup() {
  pinMode(ledPin, OUTPUT);      //declare LED as output
  pinMode(buttonPin, INPUT);     //declare pushbutton as input
  Serial.begin(31250);            //MIDI communicates at 31250 baud
}

void loop(){

  buttonVal = digitalRead(buttonPin);     //read input value from button
  delay(10);                              //wait 10ms
  bounceCheck = digitalRead(buttonPin);   //check again
  if(buttonVal == bounceCheck){           //if val is the same then not a bounce
    if (buttonVal == HIGH && buttonState == 1) {   //check if the input is HIGH
      digitalWrite(ledPin, LOW);         //turn LED OFF
      midiOUT(0x90, 60, 0); //Note ON (CH 1), middle C, zero velocity turns note off
      buttonState = 0;
    }
    if(buttonVal == LOW && buttonState == 0){
      digitalWrite(ledPin, HIGH);       //turn LED ON
      midiOUT(0x90, 60, 127); //Note ON (CH 1), middle C, velocity 127
      buttonState = 1;
    }

  }

   irVal1 = analogRead(irPin);         //read input from potentiometer
   delay(2);
   irVal2 = analogRead(irPin);         
   delay(2);
   irVal3 = analogRead(irPin);         
   delay(2);
   irVal4 = analogRead(irPin);         
   delay(2);
   irVal5 = analogRead(irPin);         //read input from potentiometer
   delay(2);
   irVal6 = analogRead(irPin);         
   delay(2);
   irVal7 = analogRead(irPin);         
   delay(2);
   irVal8 = analogRead(irPin); 
   delay(2);
   irVal9 = analogRead(irPin);         
   delay(2);
   irVal10 = analogRead(irPin);
   
   
   irVal = abs((irVal1 + irVal2 + irVal3 + irVal4 + irVal5 + irVal6 + irVal7 + irVal8 + irVal9 + irVal10)/ 10);
   mappedirVal = map(irVal, 5, 550, 0, 127);  //map value to 0-127
 
   if(abs(mappedirVal - previrVal) >= THRESHOLD1){ //determine
     if (abs(irVal) == 0 ){
       mappedirVal = 0;    
     }     
     midiOUT(0xB0, 7, mappedirVal); //Control Change (Ch 1), Controller 7 - default control for volume.
     digitalWrite(ledPin, HIGH);
     previrVal = mappedirVal;
     }
   if(irVal >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
     irState = 1;
   }
   if(irVal <= THRESHOLD2){  
     irState = 0;
   }
    
   if(irState == 0 && noteState == 1){ 
     midiOUT(0x90, 60, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     noteState = 0;
     }
     
   if(irState == 1 && noteState == 0){
     midiOUT(0x90, 60, 127); //Note ON (CH 1), middle C, velocity 127
     noteState = 1;
     }
   
          
    
}      
   
void midiOUT(char command, char value1, char value2) {
  Serial.print(command, BYTE);
  Serial.print(value1, BYTE);
  Serial.print(value2, BYTE);

}

