/*
 * 0.2beta Benny the Booze Organ
 * ryan finnigan
 * 
 * 
 * 
 * 
 * 
 */

//int ledPin = 11;                
int buttonPin = 2;               //choose the input pin for a pushbutton
int ir1Pin = 0;                  //choose the input pin for a ir
int ir2Pin = 1;
int ir3Pin = 2;
int ir4Pin = 3;

int buttonVal = 0;                    //variable for reading the button status
int buttonState = 0;            //variable to hold the buttons current state
int irState = 0;
int ir1State = 0;
int noteState = 0;
int note1State = 0; 
int ir3State = 0;
int ir4State = 0;
int note3State = 0;
int note4State = 0; 
int bounceCheck = 0;            //variable for debouncing
//1r 1
int irVal = 0;                 //variable for reading ir1 value
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
int mappedirVal = 0;          
int previrVal = 0;               
//ir 2
int ir1Val = 0;                 
int ir1Val1 = 0;       
int ir1Val2 = 0;    
int ir1Val3 = 0;       
int ir1Val4 = 0;    
int ir1Val5 = 0;       
int ir1Val6 = 0;    
int ir1Val7 = 0;       
int ir1Val8 = 0;
int ir1Val9 = 0;       
int ir1Val10 = 0;
int mappedir1Val = 0;          //variable for holding remapped ir value
int previr1Val = 0;

int ir3Val = 0;                 
int ir3Val1 = 0;       
int ir3Val2 = 0;    
int ir3Val3 = 0;       
int ir3Val4 = 0;    
int ir3Val5 = 0;       
int ir3Val6 = 0;    
int ir3Val7 = 0;       
int ir3Val8 = 0;
int ir3Val9 = 0;       
int ir3Val10 = 0;
int mappedir3Val = 0;          //variable for holding remapped ir value
int previr3Val = 0;

int ir4Val = 0;                 
int ir4Val1 = 0;       
int ir4Val2 = 0;    
int ir4Val3 = 0;       
int ir4Val4 = 0;    
int ir4Val5 = 0;       
int ir4Val6 = 0;    
int ir4Val7 = 0;       
int ir4Val8 = 0;
int ir4Val9 = 0;       
int ir4Val10 = 0;
int mappedir4Val = 0;          //variable for holding remapped ir value
int previr4Val = 0;

int THRESHOLD1 = 20;            //threshold amount
int THRESHOLD2 = 120;

void setup() {
  //pinMode(ledPin, OUTPUT);      //declare LED as output
  pinMode(buttonPin, INPUT);     //declare pushbutton as input
  Serial.begin(31250);            //MIDI communicates at 31250 baud
}

void loop(){

  /*buttonVal = digitalRead(buttonPin);     //read input value from button
  delay(10);                              //wait 10ms
  bounceCheck = digitalRead(buttonPin);   //check again
  if(buttonVal == bounceCheck){           //if val is the same then not a bounce
    if (buttonVal == HIGH && buttonState == 1) {   //check if the input is HIGH
      //digitalWrite(ledPin, HIGH);         //turn LED on
      midiOUT(0xB0, 83, 0); //cc chnge, cc83, on
      buttonState = 0;
    }
    if(buttonVal == LOW && buttonState == 0){
      //digitalWrite(ledPin, LOW);       //turn LED off
      midiOUT(0xB0, 83, 127); //cc chnge, cc83, off
      buttonState = 1;
    }*/
  
    //ir 1
   irVal1 = analogRead(ir1Pin);         //read input from ir 1
   delay(2);
   irVal2 = analogRead(ir1Pin);         
   delay(2);
   irVal3 = analogRead(ir1Pin);         
   delay(2);
   irVal4 = analogRead(ir1Pin);         
   delay(2);
   irVal5 = analogRead(ir1Pin);         
   delay(2);
   irVal6 = analogRead(ir1Pin);         
   delay(2);
   irVal7 = analogRead(ir1Pin);         
   delay(2);
   irVal8 = analogRead(ir1Pin); 
   delay(2);
   irVal9 = analogRead(ir1Pin);         
   delay(2);
   irVal10 = analogRead(ir1Pin);
   
   
   irVal = abs((irVal1 + irVal2 + irVal3 + irVal4 + irVal5 + irVal6 + irVal7 + irVal8 + irVal9 + irVal10)/ 10);
   mappedirVal = map(irVal, 0, 600, 127, 0);  //map value to 0-127
 
   if(abs(mappedirVal - previrVal) >= THRESHOLD1){ //set 0 as default
     if (abs(irVal) == 0 ){
       mappedirVal = 0;    
     }     
     midiOUT(0xB0, 9, mappedirVal); //Control Change (Ch 1), Controller 7 - default control for volume.
     previrVal = mappedirVal;
    
     }
    
   if(irVal >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
     irState = 1;
   }
   if(irVal <= THRESHOLD2){  
     irState = 0;
   }
    
   if(irState == 0 && noteState ==1){ 
     midiOUT(0x90, 60, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     noteState = 0;
     }
     
   if(irState == 1 && noteState == 0){
     midiOUT(0x90, 60, 127); //Note ON (CH 1), middle C, velocity 127
     noteState = 1;
     }
  
     
     //ir 2
   ir1Val1 = analogRead(ir2Pin);         //read input from ir 2
   delay(2);
   ir1Val2 = analogRead(ir2Pin);         
   delay(2);
   ir1Val3 = analogRead(ir2Pin);         
   delay(2);
   ir1Val4 = analogRead(ir2Pin);         
   delay(2);
   ir1Val5 = analogRead(ir2Pin);         
   delay(2);
   ir1Val6 = analogRead(ir2Pin);         
   delay(2);
   ir1Val7 = analogRead(ir2Pin);         
   delay(2);
   ir1Val8 = analogRead(ir2Pin); 
   delay(2);
   ir1Val9 = analogRead(ir2Pin);         
   delay(2);
   ir1Val10 = analogRead(ir2Pin);
   
   
   ir1Val = abs((ir1Val1 + ir1Val2 + ir1Val3 + ir1Val4 + ir1Val5 + ir1Val6 + ir1Val7 + ir1Val8 + ir1Val9 + ir1Val10)/ 10);
   mappedir1Val = map(ir1Val, 0, 600, 127, 0);  //map value to 0-127   //it seems that min midi cc effects gitter in two bad servos
 
   if(abs(mappedir1Val - previr1Val) >= THRESHOLD1){ //set 0 as default
     if (abs(ir1Val) == 0 ){
       mappedir1Val = 0;    
     }     
     midiOUT(0xB0, 10, mappedir1Val); //Control Change (Ch 1), Controller 2 - 
     previr1Val = mappedir1Val;
     }
   
   if(ir1Val >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
     ir1State = 1;
   }
   if(ir1Val <= THRESHOLD2){  
     ir1State = 0;
   }
    
   if(ir1State == 0 && note1State ==1){ 
     midiOUT(0x90, 62, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     note1State = 0;
     }
     
   if(ir1State == 1 && note1State == 0){
     midiOUT(0x90, 62, 127); //Note ON (CH 1), middle C, velocity 127
     note1State = 1;
     }
   //note 3
     //ir 3
   ir3Val1 = analogRead(ir2Pin);         //read input from ir 1
   delay(2);
   ir3Val2 = analogRead(ir3Pin);         
   delay(2);
   ir3Val3 = analogRead(ir3Pin);         
   delay(2);
   ir3Val4 = analogRead(ir3Pin);         
   delay(2);
   ir3Val5 = analogRead(ir3Pin);         
   delay(2);
   ir3Val6 = analogRead(ir3Pin);         
   delay(2);
   ir3Val7 = analogRead(ir3Pin);         
   delay(2);
   ir3Val8 = analogRead(ir3Pin); 
   delay(2);
   ir3Val9 = analogRead(ir3Pin);         
   delay(2);
   ir3Val10 = analogRead(ir3Pin);
   
   
   ir3Val = abs((ir3Val1 + ir3Val2 + ir3Val3 + ir3Val4 + ir3Val5 + ir3Val6 + ir3Val7 + ir3Val8 + ir3Val9 + ir3Val10)/ 10);
   mappedir3Val = map(ir3Val, 0, 600, 127, 0);  //map value to 0-127
 
   if(abs(mappedir3Val - previr3Val) >= THRESHOLD1){ //set 0 as default
     if (abs(ir3Val) == 0 ){
       mappedir3Val = 0;    
     }     
     midiOUT(0xB0, 11, mappedir3Val); //Control Change (Ch 1), Controller 7 - default control for volume.
     previr3Val = mappedir3Val;
    
     }
    
   if(ir3Val >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
     ir3State = 1;
   }
   if(ir3Val <= THRESHOLD2){  
     ir3State = 0;
   }
    
   if(ir3State == 0 && note3State ==1){ 
     midiOUT(0x90, 64, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     note3State = 0;
     }
     
   if(ir3State == 1 && note3State == 0){
     midiOUT(0x90, 64, 127); //Note ON (CH 1), middle C, velocity 127
     note3State = 1;
     }         
    //note 4
     //ir 4
   ir4Val1 = analogRead(ir4Pin);         //read input from ir 1
   delay(2);
   ir4Val2 = analogRead(ir4Pin);         
   delay(2);
   ir4Val3 = analogRead(ir4Pin);         
   delay(2);
   ir4Val4 = analogRead(ir4Pin);         
   delay(2);
   ir4Val5 = analogRead(ir4Pin);         
   delay(2);
   ir4Val6 = analogRead(ir4Pin);         
   delay(2);
   ir4Val7 = analogRead(ir4Pin);         
   delay(2);
   ir4Val8 = analogRead(ir4Pin); 
   delay(2);
   ir4Val9 = analogRead(ir4Pin);         
   delay(2);
   ir4Val10 = analogRead(ir4Pin);
   
   
   ir4Val = abs((ir4Val1 + ir4Val2 + ir4Val3 + ir4Val4 + ir4Val5 + ir4Val6 + ir4Val7 + ir4Val8 + ir4Val9 + ir4Val10)/ 10);
   mappedir4Val = map(ir4Val, 0, 600, 127, 0);  //map value to 0-127
 
   if(abs(mappedir4Val - previr4Val) >= THRESHOLD1){ //set 0 as default
     if (abs(ir4Val) == 0 ){
       mappedir4Val = 0;    
     }     
     midiOUT(0xB0, 12, mappedir4Val); //Control Change (Ch 1), Controller 7 - default control for volume.
     previr4Val = mappedir4Val;
    
     }
    
   if(ir4Val >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
     ir4State = 1;
   }
   if(ir4Val <= THRESHOLD2){  
     ir4State = 0;
   }
    
   if(ir4State == 0 && note4State ==1){ 
     midiOUT(0x90, 65, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     note4State = 0;
     }
     
   if(ir4State == 1 && note4State == 0){
     midiOUT(0x90, 65, 127); //Note ON (CH 1), middle C, velocity 127
     note4State = 1;
     }   
}      
   
void midiOUT(char command, char value1, char value2) {
  Serial.print(command, BYTE);
  Serial.print(value1, BYTE);
  Serial.print(value2, BYTE);

}

