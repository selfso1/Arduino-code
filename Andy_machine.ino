//led variables

//flex variables

//Ir variables
int irPin1 = 0;
int irPin2 = 1;
int irPin3 = 2;
int irPin4 = 3;
int irPin5 = 4;
int irPin6 = 5;
int irPin7 = 6;
int irPin8 = 7;

int irVal1 = 0;
int irVal2 = 0;
int irVal3 = 0;
int irVal4 = 0;
int irVal5 = 0;
int irVal6 = 0;
int irVal7 = 0;
int irVal8 = 0;

int noteState1 = 0;
int noteState2 = 0;
int noteState3 = 0;
int noteState4 = 0;
int noteState5 = 0;
int noteState6 = 0;
int noteState7 = 0;
int noteState8 = 0;

int irMap1 = 0;
int irMap2 = 0;
int irMap3 = 0;
int irMap4 = 0;
int irMap5 = 0;
int irMap6 = 0;
int irMap7 = 0;
int irMap8 = 0;

int prevVal1 = 0;
int prevVal2 = 0;
int prevVal3 = 0;
int prevVal4 = 0;
int prevVal5 = 0;
int prevVal6 = 0;
int prevVal7 = 0;
int prevVal8 = 0;

const int numReadings = 10;

int readings1[numReadings];// the readings from the analog input



int index1 = 0; 
int index2 = 0; // the index of the current reading
int index3 = 0; 
int index4 = 0; 
int index5 = 0; 
int index6 = 0; 
int index7 = 0; 
int index8 = 0; 

int total1 = 0;
int total2 = 0;
int total3 = 0;
int total4 = 0;
int total5 = 0;
int total6 = 0;
int total7 = 0;
int total8 = 0;

int average1 = 0;
int average2 = 0;
int average3 = 0;
int average4 = 0;
int average5 = 0;
int average6 = 0;
int average7 = 0;
int average8 = 0;

const int irMax1 = 450;
const int irMin1 = 50;

const int irMax2 = 450;
const int irMin2 = 50;

//pot variables

//Button variables
int buttonPin1 = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;
int buttonPin4 = 5;
int buttonPin5 = 6;
int buttonPin6 = 7;
int buttonPin7 = 8;

int buttonVal1 = 0;
int buttonVal2 = 0;
int buttonVal3 = 0;
int buttonVal4 = 0;
int buttonVal5 = 0;
int buttonVal6 = 0;
int buttonVal7 = 0;
int buttonVal8 = 0;
int buttonVal9 = 0;
int buttonVal10 = 0;
int buttonVal11 = 0;

int bounceCheck1 = 0;
int bounceCheck2 = 0;
int bounceCheck3 = 0;
int bounceCheck4 = 0;
int bounceCheck5 = 0;
int bounceCheck6 = 0;
int bounceCheck7 = 0;
int bounceCheck8 = 0;
int bounceCheck9 = 0;
int bounceCheck10 = 0;
int bounceCheck11 = 0;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState9 = 0;
int buttonState10 = 0;
int buttonState11 = 0;

const int midCC1 = 60;
const int midCC2 = 62;
const int midCC3 = 64;
const int midCC4 = 65;
const int midCC5 = 67;
const int midCC6 = 69;
const int midCC7 = 71;


const int midiT = 0xB0;
const int midiT2 = 0xB0;

const int vl1 = 0;
const int vl2 = 127;
const int dt = 8;

void setup() {
  
  Serial.begin(31250);
   pinMode(buttonPin1, INPUT);    //declare pushbutton as input
   pinMode(buttonPin2, INPUT);
   pinMode(buttonPin3, INPUT);
   pinMode(buttonPin4, INPUT);
   pinMode(buttonPin5, INPUT);
   pinMode(buttonPin6, INPUT); 
}

void loop() {
 //c
  buttonVal1 = digitalRead(buttonPin1);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck1 = digitalRead(buttonPin1);   //check again
  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
     if (buttonVal1 == HIGH && buttonState1 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT2, midCC1, vl1); //cc chnge, cc83, on
      buttonState1 = 1;
    }
    if(buttonVal1 == LOW && buttonState1 == 1){
      
      midiOUT(midiT2, midCC1, vl2); //cc chnge, cc83, off
      buttonState1 = 0;
    }
  }
  //d
  buttonVal2 = digitalRead(buttonPin2);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck2 = digitalRead(buttonPin2);   //check again
  if(buttonVal2 == bounceCheck2){           //if val is the same then not a bounce
    if (buttonVal2 == HIGH && buttonState2 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT2, midCC2, vl1); //cc chnge, cc83, on
      buttonState2 = 2;
    }
    if(buttonVal2 == LOW && buttonState2 == 2){
      
      midiOUT(midiT2, midCC2, vl2); //cc chnge, cc83, off
      buttonState2 = 0;
    }
  } 
 
  buttonVal3 = digitalRead(buttonPin3);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck3 = digitalRead(buttonPin3);   //check again
  if(buttonVal3 == bounceCheck3){           //if val is the same then not a bounce
    if (buttonVal3 == HIGH && buttonState3 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT2, midCC3, vl1); //cc chnge, cc83, on
      buttonState3 = 1;
    }
    if(buttonVal3 == LOW && buttonState3 == 1){
      
      midiOUT(midiT2, midCC3, vl2); //cc chnge, cc83, off
      buttonState3 = 0;
    }  
  }
  
  buttonVal4 = digitalRead(buttonPin4);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck4 = digitalRead(buttonPin4);   //check again
  if(buttonVal4 == bounceCheck4){           //if val is the same then not a bounce
    if (buttonVal4 == HIGH && buttonState4 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT, midCC4, vl1); //cc chnge, cc83, on
      buttonState4 = 1;
    }
    if(buttonVal4 == LOW && buttonState4 == 1){
      
      midiOUT(midiT, midCC4, vl2); //cc chnge, cc83, off
      buttonState4 = 0;
    }   
  
  }
  
  buttonVal5 = digitalRead(buttonPin5);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck5 = digitalRead(buttonPin5);   //check again
  if(buttonVal5 == bounceCheck5){           //if val is the same then not a bounce
    if (buttonVal5 == HIGH && buttonState5 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT, midCC5, vl1); //cc chnge, cc83, on
      buttonState5 = 1;
    }
    if(buttonVal5 == LOW && buttonState5 == 1){
      
      midiOUT(midiT, midCC5, vl2); //cc chnge, cc83, off
      buttonState5 = 0;
    }   
  
  }
  
   buttonVal6 = digitalRead(buttonPin6);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck6 = digitalRead(buttonPin6);   //check again
  if(buttonVal6 == bounceCheck6){           //if val is the same then not a bounce
    if (buttonVal6 == HIGH && buttonState6 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT, midCC6, vl1); //cc chnge, cc83, on
      buttonState6 = 1;
    }
    if(buttonVal6 == LOW && buttonState6 == 1){
      
      midiOUT(midiT, midCC6, vl2); //cc chnge, cc83, off
      buttonState6 = 0;
    }   
  }
  
  buttonVal7 = digitalRead(buttonPin7);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck7 = digitalRead(buttonPin7);   //check again
  if(buttonVal7 == bounceCheck7){           //if val is the same then not a bounce
    if (buttonVal7 == HIGH && buttonState7 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT, midCC7, vl1); //cc chnge, cc83, on
      buttonState7 = 1;
    }
    if(buttonVal7 == LOW && buttonState7 == 1){
      
      midiOUT(midiT, midCC7, vl2); //cc chnge, cc83, off
      buttonState7 = 0;
    }   
  
  }
  
//pot1
  
potVal1 = analogRead(potPin1);  // read the value from the sensor:  
  
  mapppot1 = map(potVal1, 0, 1023, 0, 127);  //map value to 0-127
  mapPot1 = constrain(mapPot1, 0, 127);
  
  if(abs(mapPot1 - prevpotVal1) >= THRESHOLD){
      midiOUT(0xB0, 14, mapPot1);
      prevpotVal1 = mapPot1;
         
  }

//pot2

potVal1 = analogRead(potPin1);  // read the value from the sensor:  
  
  mapppot1 = map(potVal1, 0, 1023, 0, 127);  //map value to 0-127
  mapPot1 = constrain(mapPot1, 0, 127);
  
  if(abs(mapPot1 - prevpotVal1) >= THRESHOLD){
      midiOUT(0xB0, 15, mapPot1);
      prevpotVal1 = mapPot1;
         
  }

//IR sensor
   //ir1
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
  if (index1 >= numReadings)              
    // ...wrap around to the beginning: 
    index1 = 0;                           

  // calculate the average:
  average1 = total1 / numReadings;         
 
  irMap1 = constrain(average1, irMin2, irMax2);
  irMap1 = map(irMap1, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap1 = constrain(irMap1, 0, 127);              //constrain
  
  if(irMap1 >= THRESHOLD3 && noteState1 ==1){ 
    midiOUT(0x90, note1, 127);                 
    noteState1 = 0;
  }
     
  if(irMap1 <= THRESHOLD3 && noteState1 ==0){
     midiOUT(0x90, note1, 0);               
     noteState1 = 1;
  }
    
  if(abs(irMap1 - prevVal1) >= THRESHOLD2){
    midiOUT(0xB0, midicc1, irMap1);
    prevVal1 = irMap1;
  }  
  
  if(irMap1 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin1, HIGH);
  }
  else{
    digitalWrite(sPin1, LOW);  
  }
  
//Flex sensor

//led control

}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}  
