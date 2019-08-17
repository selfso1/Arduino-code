//benny 3.0



int switchVal = 0;                    //variable for reading the button status
int switchState = 0;                     //variable to hold the buttons current state
int bounceCheck = 0;

int switchPin = 5;

int sPin1 = 6;                // set solenoid pins
int sPin2 = 7;
int sPin3 = 8;
int sPin4 = 9;
int sPin5 = 10;
int sPin6 = 11;
int sPin7 = 12;
int sPin8 = 13;

int irPin1 = 0;                 //set ir pins
int irPin2 = 1;
int irPin3 = 2;                 
int irPin4 = 3;
int irPin5 = 4;                 
int irPin6 = 5;
int irPin7 = 6;                
int irPin8 = 7;

int irVal1 = 0;                  // ir value store
int irVal2 = 0;
int irVal3 = 0;
int irVal4 = 0;
int irVal5 = 0;
int irVal6 = 0;
int irVal7 = 0;
int irVal8 = 0;

int irState1 = 0;
int irState2 = 0;
int irState3 = 0;
int irState4 = 0; 
int irState5 = 0;
int irState6 = 0;
int irState7 = 0;
int irState8 = 0; 

int noteState1 = 0;
int noteState2 = 0;
int noteState3 = 0;
int noteState4 = 0;
int noteState5 = 0;
int noteState6 = 0;
int noteState7 = 0;
int noteState8 = 0; 

int mapVal1 = 0;
int mapVal2 = 0;
int mapVal3 = 0;
int mapVal4 = 0;
int mapVal5 = 0;
int mapVal6 = 0;
int mapVal7 = 0;
int mapVal8 = 0;


const int numReadings1 = 10;
const int numReadings2 = 10;
const int numReadings3 = 10;
const int numReadings4 = 10;
const int numReadings5 = 10;
const int numReadings6 = 10;
const int numReadings7 = 10;
const int numReadings8 = 10;

int readings1[numReadings1];      // the readings from the analog input
int readings2[numReadings2];
int readings3[numReadings3];      // the readings from the analog input
int readings4[numReadings4];
int readings5[numReadings5];      // the readings from the analog input
int readings6[numReadings6];
int readings7[numReadings7];      // the readings from the analog input
int readings8[numReadings8];

int index1 = 0;                   // the index of the current reading
int index2 = 0;
int index3 = 0;                   
int index4 = 0;
int index5 = 0;                   
int index6 = 0;
int index7 = 0;                   
int index8 = 0;

int total1 = 0;                  // the running total
int total2 = 0;
int total3 = 0;                  
int total4 = 0;
int total5 = 0;                  
int total6 = 0;
int total7 = 0;                  
int total8 = 0;

int average1 = 0;                   // the average
int average2 = 0;
int average3 = 0;                  
int average4 = 0;
int average5 = 0;                   
int average6 = 0;
int average7 = 0;                   
int average8 = 0;

int averagemap1 = 0;
int averagemap2 = 0;
int averagemap3 = 0;
int averagemap4 = 0;
int averagemap5 = 0;
int averagemap6 = 0;
int averagemap7 = 0;
int averagemap8 = 0;

int note1 = 54;
int note2 = 49;
int note3 = 66;
int note4 = 61;
int note5 = 78;
int note6 = 73;
int note7 = 90;
int note8 = 85;

int THRESHOLD1 = 65;
int THRESHOLD2 = 65;

void setup() {
  pinMode(sPin1, OUTPUT);
  pinMode(sPin2, OUTPUT);
  pinMode(sPin3, OUTPUT);
  pinMode(sPin4, OUTPUT);
  pinMode(sPin5, OUTPUT);
  pinMode(sPin6, OUTPUT);
  pinMode(sPin7, OUTPUT);
  pinMode(sPin8, OUTPUT);
  
  pinMode(switchPin, INPUT);
  
  Serial.begin(31250);
}

void loop() {
  switchVal = digitalRead(switchPin);     //read input value from button
  delay(10);                              //wait 10ms
  bounceCheck = digitalRead(switchPin);   //check again
  if(switchVal == bounceCheck){           //if val is the same then not a bounce
    if(switchVal == HIGH) {   //check if the input is HIGH
      switchState = 1;
    }
    if(switchVal == LOW){
      switchState = 0;
    }
  }

  
  irVal1 = analogRead(irPin1);
   // subtract the last reading:
  total1= total1 - readings1[index1];         
  // read from the sensor:  
  readings1[index1] = analogRead(irPin1); 
  // add the reading to the total:
  total1= total1 + readings1[index1];       
  // advance to the next position in the array:  
  index1 = index1 + 1;                    

  // if we're at the end of the array...
  if (index1 >= numReadings1)              
    // ...wrap around to the beginning: 
    index1 = 0;                           

  // calculate the average:
  average1 = total1 / numReadings1;         
 
  averagemap1 = map(average1, 0, 580, 0, 255);
    
    if(averagemap1 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin1, HIGH);
  }
  
    else{
      digitalWrite(sPin1, LOW);
    
    }   
    
     
    if(averagemap1 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState1 = 1;                   // digital value set to ON 
     }
    if(averagemap1 <= THRESHOLD2){  
      irState1 = 0;                  //digital value is set to OFF
     }
    
    if(irState1 == 0 && noteState1 ==1){ 
      midiOUT(0x90, note1, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState1 = 0;
     }
     
    if(irState1 == 1 && noteState1 == 0){
      midiOUT(0x90, note1, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState1 = 1;
     }
    
    //22222 
  irVal2 = analogRead(irPin2);
   // subtract the last reading:
  total2= total2 - readings2[index2];         
  // read from the sensor:  
  readings2[index2] = analogRead(irPin2); 
  // add the reading to the total:
  total2= total2 + readings2[index2];       
  // advance to the next position in the array:  
  index2 = index2 + 1;                    

  // if we're at the end of the array...
  if (index2 >= numReadings2)              
    // ...wrap around to the beginning: 
    index2 = 0;                           

  // calculate the average:
  average2 = total2 / numReadings2;         
 
  averagemap2 = map(average2, 0, 580, 0, 255);
    
    if(averagemap2 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin2, HIGH);
  }
  
    else{
      digitalWrite(sPin2, LOW);
    
    }   
    
     
    if(averagemap2 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState1 = 1;                   // digital value set to ON 
     }
    if(averagemap2 <= THRESHOLD2){  
      irState1 = 0;                  //digital value is set to OFF
     }
    
    if(irState2 == 0 && noteState2 ==1){ 
      midiOUT(0x90, note2, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState2 = 0;
     }
     
    if(irState2 == 1 && noteState2 == 0){
      midiOUT(0x90, note2, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState2 = 1;
     }
         
  /////33333
  irVal3 = analogRead(irPin3);
   // subtract the last reading:
  total3= total3 - readings3[index3];         
  // read from the sensor:  
  readings3[index3] = analogRead(irPin3); 
  // add the reading to the total:
  total3= total3 + readings3[index3];       
  // advance to the next position in the array:  
  index3 = index3 + 1;                    

  // if we're at the end of the array...
  if (index3 >= numReadings3)              
    // ...wrap around to the beginning: 
    index3 = 0;                           

  // calculate the average:
  average3 = total3 / numReadings3;         
 
  averagemap3 = map(average3, 0, 580, 0, 255);
    
    if(averagemap3 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin3, HIGH);
  }
  
    else{
      digitalWrite(sPin3, LOW);
    
    }   
    
     
    if(averagemap3 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState3 = 1;                   // digital value set to ON 
     }
    if(averagemap3 <= THRESHOLD2){  
      irState3 = 0;                  //digital value is set to OFF
     }
    
    if(irState3 == 0 && noteState3 ==1){ 
      midiOUT(0x90, note3, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState3 = 0;
     }
     
    if(irState3 == 1 && noteState3 == 0){
      midiOUT(0x90, note3, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState3 = 1;
     }
    
    //444444 
  irVal4 = analogRead(irPin4);
   // subtract the last reading:
  total4= total4 - readings4[index4];         
  // read from the sensor:  
  readings4[index4] = analogRead(irPin4); 
  // add the reading to the total:
  total4= total4 + readings4[index4];       
  // advance to the next position in the array:  
  index4 = index4 + 1;                    

  // if we're at the end of the array...
  if (index4 >= numReadings4)              
    // ...wrap around to the beginning: 
    index4 = 0;                           

  // calculate the average:
  average4 = total4 / numReadings4;         
 
  averagemap4 = map(average4, 0, 580, 0, 255);
    
    if(averagemap4 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin4, HIGH);
  }
  
    else{
      digitalWrite(sPin4, LOW);
    
    }   
    
     
    if(averagemap4 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState4 = 1;                   // digital value set to ON 
     }
    if(averagemap4 <= THRESHOLD2){  
      irState4 = 0;                  //digital value is set to OFF
     }
    
    if(irState4 == 0 && noteState4 ==1){ 
      midiOUT(0x90, note4, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState4 = 0;
     }
     
    if(irState4 == 1 && noteState4 == 0){
      midiOUT(0x90, note4, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState4 = 1;
     }
     
   //555555  
  irVal5 = analogRead(irPin5);
   // subtract the last reading:
  total5= total5 - readings5[index5];         
  // read from the sensor:  
  readings5[index5] = analogRead(irPin5); 
  // add the reading to the total:
  total5= total5 + readings5[index5];       
  // advance to the next position in the array:  
  index5 = index5 + 1;                    

  // if we're at the end of the array...
  if (index5 >= numReadings5)              
    // ...wrap around to the beginning: 
    index5 = 0;                           

  // calculate the average:
  average5 = total5 / numReadings5;         
 
  averagemap5 = map(average5, 0, 580, 0, 255);
    
    if(averagemap5 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin5, HIGH);
  }
  
    else{
      digitalWrite(sPin5, LOW);
    
    }   
    
     
    if(averagemap5 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState5 = 1;                   // digital value set to ON 
     }
    if(averagemap5 <= THRESHOLD2){  
      irState5 = 0;                  //digital value is set to OFF
     }
    
    if(irState5 == 0 && noteState5 ==1){ 
      midiOUT(0x90, note5, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState5 = 0;
     }
     
    if(irState5 == 1 && noteState5 == 0){
      midiOUT(0x90, note5, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState5 = 1;
     }
    
   //666666  
  irVal6 = analogRead(irPin6);
   // subtract the last reading:
  total6= total6 - readings6[index6];         
  // read from the sensor:  
  readings6[index6] = analogRead(irPin6); 
  // add the reading to the total:
  total6= total6 + readings6[index6];       
  // advance to the next position in the array:  
  index6 = index6 + 1;                    

  // if we're at the end of the array...
  if (index6 >= numReadings6)              
    // ...wrap around to the beginning: 
    index6 = 0;                           

  // calculate the average:
  average6 = total6 / numReadings6;         
 
  averagemap6 = map(average6, 0, 580, 0, 255);
    
    if(averagemap6 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin6, HIGH);
  }
  
    else{
      digitalWrite(sPin6, LOW);
    
    }   
    
     
    if(averagemap6 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState6 = 1;                   // digital value set to ON 
     }
    if(averagemap6 <= THRESHOLD2){  
      irState6 = 0;                  //digital value is set to OFF
     }
    
    if(irState6 == 0 && noteState6 ==1){ 
      midiOUT(0x90, note6, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState6 = 0;
     }
     
    if(irState6 == 1 && noteState6 == 0){
      midiOUT(0x90, note6, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState6 = 1;
     }
  
  //7777
  irVal7 = analogRead(irPin7);
   // subtract the last reading:
  total7= total7 - readings7[index7];         
  // read from the sensor:  
  readings7[index7] = analogRead(irPin7); 
  // add the reading to the total:
  total7= total7 + readings7[index7];       
  // advance to the next position in the array:  
  index7 = index7 + 1;                    

  // if we're at the end of the array...
  if (index7 >= numReadings7)              
    // ...wrap around to the beginning: 
    index7 = 0;                           

  // calculate the average:
  average7 = total7 / numReadings7;         
 
  averagemap7 = map(average7, 0, 580, 0, 255);
    
    if(averagemap7 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin7, HIGH);
  }
  
    else{
      digitalWrite(sPin7, LOW);
    
    }   
    
     
    if(averagemap7 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState7 = 1;                   // digital value set to ON 
     }
    if(averagemap7 <= THRESHOLD2){  
      irState7 = 0;                  //digital value is set to OFF
     }
    
    if(irState7 == 0 && noteState7 ==1){ 
      midiOUT(0x90, note7, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState7 = 0;
     }
     
    if(irState7 == 1 && noteState7 == 0){
      midiOUT(0x90, note7, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState7 = 1;
     }
    
   //88888  
  irVal8 = analogRead(irPin8);
   // subtract the last reading:
  total8= total8 - readings8[index8];         
  // read from the sensor:  
  readings8[index8] = analogRead(irPin8); 
  // add the reading to the total:
  total8= total8 + readings8[index8];       
  // advance to the next position in the array:  
  index8 = index8 + 1;                    

  // if we're at the end of the array...
  if (index8 >= numReadings8)              
    // ...wrap around to the beginning: 
    index8 = 0;                           

  // calculate the average:
  average8 = total8 / numReadings8;         
 
  averagemap8 = map(average8, 0, 580, 0, 255);
    
    if(averagemap8 >= THRESHOLD1){
      if(switchState == 1)
      digitalWrite(sPin8, HIGH);
  }
  
    else{
      digitalWrite(sPin8, LOW);
    
    }   
    
     
    if(averagemap8 >= THRESHOLD2){         // start midi note send// determine ir state, set digital value
      irState8 = 1;                   // digital value set to ON 
     }
    if(averagemap8 <= THRESHOLD2){  
      irState8 = 0;                  //digital value is set to OFF
     }
    
    if(irState8 == 0 && noteState8 ==1){ 
      midiOUT(0x90, note8, 0);                 //Note ON (CH 1), middle C, zero velocity turns note off
      noteState8 = 0;
     }
     
    if(irState8 == 1 && noteState8 == 0){
      midiOUT(0x90, note8, 127);               //Note ON (CH 1), middle C, velocity 127
      noteState8 = 1;
     }   
  
    
       



}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}  
