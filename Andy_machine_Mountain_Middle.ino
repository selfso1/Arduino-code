//led variables

//flex variables
int flexVal1 = 0;

int flexPin1 = 0; 

int mapflex1 = 0;

int prevflexVal1 = 0;

//Ir variables
int irPin1 = 0;

int irVal1 = 0;

int irMap1 = 0;

int prevVal1 = 0;

const int numReadings = 10;

int readings1[numReadings];// the readings from the analog input

int index1 = 0; 

int total1 = 0;

int average1 = 0;

int noteState1 = 0;

const int not1 = 60;

const int irMax1 = 450;
const int irMin1 = 50;

const int irMax2 = 450;
const int irMin2 = 50;

//pot variables
int potVal1 = 0;
int potVal2 = 0;
int potVal3 = 0;
int potVal4 = 0;

int potPin1 = 3;
int potPin2 = 4;
int potPin3 = 5;
int potPin4 = 2;

int mapPot1 = 0;
int mapPot2 = 0;
int mapPot3 = 0;
int mapPot4 = 0;

int prevpotVal1 = 0;
int prevpotVal2 = 0;
int prevpotVal3 = 0;
int prevpotVal4 = 0;


//Button variables
int buttonPin1 = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;
int buttonPin4 = 5;
int buttonPin5 = 6;
int buttonPin6 = 10;
int buttonPin7 = 11;

int buttonVal1 = 0;
int buttonVal2 = 0;
int buttonVal3 = 0;
int buttonVal4 = 0;
int buttonVal5 = 0;
int buttonVal6 = 0;
int buttonVal7 = 0;

int bounceCheck1 = 0;
int bounceCheck2 = 0;
int bounceCheck3 = 0;
int bounceCheck4 = 0;
int bounceCheck5 = 0;
int bounceCheck6 = 0;
int bounceCheck7 = 0;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;

const int midCC1 = 60;
const int midCC2 = 62;
const int midCC3 = 64;
const int midCC4 = 65;
const int midCC5 = 67;
const int midCC6 = 69;
const int midCC7 = 71;

const int irCC = 25; 


const int midiT = 0x90;
const int midiT2 = 0xB0;

const int vl1 = 0;
const int vl2 = 127;
const int dt = 8;

int THRESHOLD = 2;
int THRESHOLD1 = 90;
int THRESHOLD2 = 300; 
int THRESHOLD3 = 60;

void setup() {
  //Change serial.begin from 9600 (testing) to 31250
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
      
      midiOUT(midiT, midCC1, vl1); //cc chnge, cc83, on
      buttonState1 = 1;
    }
    if(buttonVal1 == LOW && buttonState1 == 1){
      
      midiOUT(midiT, midCC1, vl2); //cc chnge, cc83, off
      buttonState1 = 0;
    }
  }
  //d
  buttonVal2 = digitalRead(buttonPin2);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck2 = digitalRead(buttonPin2);   //check again
  if(buttonVal2 == bounceCheck2){           //if val is the same then not a bounce
    if (buttonVal2 == HIGH && buttonState2 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT, midCC2, vl1); //cc chnge, cc83, on
      buttonState2 = 2;
    }
    if(buttonVal2 == LOW && buttonState2 == 2){
      
      midiOUT(midiT, midCC2, vl2); //cc chnge, cc83, off
      buttonState2 = 0;
    }
  } 
 
  buttonVal3 = digitalRead(buttonPin3);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck3 = digitalRead(buttonPin3);   //check again
  if(buttonVal3 == bounceCheck3){           //if val is the same then not a bounce
    if (buttonVal3 == HIGH && buttonState3 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT, midCC3, vl1); //cc chnge, cc83, on
      buttonState3 = 1;
    }
    if(buttonVal3 == LOW && buttonState3 == 1){
      
      midiOUT(midiT, midCC3, vl2); //cc chnge, cc83, off
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
  /*
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
  */
//pot1
  
potVal1 = analogRead(potPin1);  // read the value from the sensor:  
  
  mapPot1 = map(potVal1, 0, 1023, 0, 127);  //map value to 0-127
  mapPot1 = constrain(mapPot1, 0, 127);
  
  if(abs(mapPot1 - prevpotVal1) >= 4){
      midiOUT(0xB0, 15, mapPot1);
      prevpotVal1 = mapPot1;
         
  }

//pot2
  
potVal2 = analogRead(potPin2);  // read the value from the sensor:  
  
  mapPot2 = map(potVal2, 0, 1023, 0, 127);  //map value to 0-127
  mapPot2 = constrain(mapPot2, 0, 127);
  
  if(abs(mapPot2 - prevpotVal2) >= THRESHOLD){
      midiOUT(0xB0, 16, mapPot2);
      prevpotVal2 = mapPot2;
         
  }


//pot3
  
potVal3 = analogRead(potPin3);  // read the value from the sensor:  
  
  mapPot3 = map(potVal3, 0, 1023, 0, 127);  //map value to 0-127
  mapPot3 = constrain(mapPot3, 0, 127);
  
  if(abs(mapPot3 - prevpotVal3) >= THRESHOLD){
      midiOUT(0xB0, 17, mapPot3);
      prevpotVal3 = mapPot3;
         
  }
/*
  //pot4
  
potVal4 = analogRead(potPin4);  // read the value from the sensor:  
  
  mapPot4 = map(potVal4, 0, 1023, 0, 127);  //map value to 0-127
  mapPot4 = constrain(mapPot4, 0, 127);
  
  if(abs(mapPot4 - prevpotVal4) >= THRESHOLD){
      midiOUT(0xB0, 18, mapPot4);
      prevpotVal4 = mapPot4;
         
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
  
  /*if(irMap1 >= THRESHOLD3 && noteState1 ==1){ 
    midiOUT(0x90, note1, 127);                 
    noteState1 = 0;
  }
     
  if(irMap1 <= THRESHOLD3 && noteState1 ==0){
     midiOUT(0x90, note1, 0);               
     noteState1 = 1;
  } 
    
  if(abs(irMap1 - prevVal1) >= THRESHOLD2){
    midiOUT(0xB0, irCC, irMap1);
    prevVal1 = irMap1;
  }  

  */
//Flex sensor
//flex1 
  
flexVal1 = analogRead(flexPin1);  // read the value from the sensor:  
  
  mapflex1 = map(flexVal1, 689, 900, 0, 127);  //map value to 0-127
  mapflex1 = constrain(mapflex1, 0, 127);
  
  if(abs(mapflex1 - prevflexVal1) >= THRESHOLD){
      midiOUT(0xB0, 14, mapflex1);
      prevflexVal1 = mapflex1;

  }
//led control
// testing. add /* at beginning and */ to end to grey out
/*
Serial.print("irVal1");
Serial.print(irVal1);
Serial.print("/t irMap1");
Serial.print(irMap1);


Serial.print("flexVal1");
Serial.print(flexVal1);
Serial.print("/t mapflex1");
Serial.println(mapflex1);
*/
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}  
