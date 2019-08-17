
int switchVal = 0;                    //variable for reading the button status
int switchState = 0;
int bounceCheck = 0;
int switchPin = 5;

int sPin1 = 6;
int sPin2 = 7;
int sPin3 = 8;
int sPin4 = 9;
int sPin5 = 10;
int sPin6 = 11;
int sPin7 = 12;
int sPin8 = 13;

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
int readings2[numReadings];// the readings from the analog input
int readings3[numReadings];// the readings from the analog input
int readings4[numReadings];// the readings from the analog input
int readings5[numReadings];// the readings from the analog input
int readings6[numReadings];// the readings from the analog input
int readings7[numReadings];// the readings from the analog input
int readings8[numReadings];// the readings from the analog input


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

const int THRESHOLD1 = 90;      // threshold for solinod valves
const int THRESHOLD2 = 300;       // threshold for midicc stepping
const int THRESHOLD3 = 60;      // threshold fpr midi not on

const int note1 = 60;
const int note2 = 62;
const int note3 = 64;
const int note4 = 65;
const int note5 = 67;
const int note6 = 69;
const int note7 = 71;
const int note8 = 72;

const int midicc1 = 10;
const int midicc2 = 11;
const int midicc3 = 10;
const int midicc4 = 11;
const int midicc5 = 10;
const int midicc6 = 11;
const int midicc7 = 10;
const int midicc8 = 11;

const int serial = 31250;

void setup() {
 
  Serial.begin(serial); 
  pinMode(sPin1, OUTPUT);
  pinMode(sPin2, OUTPUT);
  pinMode(sPin3, OUTPUT);
  pinMode(sPin4, OUTPUT);
  pinMode(sPin5, OUTPUT);
  pinMode(sPin6, OUTPUT);
  pinMode(sPin7, OUTPUT);
  pinMode(sPin8, OUTPUT);
  
  pinMode(switchPin, INPUT);
  

}
void loop() {
  
  switchVal = digitalRead(switchPin);     //read input value from button
  delay(10);                              //wait 10ms
  bounceCheck = digitalRead(switchPin);   //check again
  if(switchVal == bounceCheck){           //if val is the same then not a bounce
    if(switchVal == HIGH) {   //check if the input is HIGH
      switchState = 0;
    }
    if(switchVal == LOW){
      switchState = 1;
    }
  } 
  
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
  
     //ir2
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
  if (index2 >= numReadings)              
    // ...wrap around to the beginning: 
    index2 = 0;                           

  // calculate the average:
  average2 = total2 / numReadings;         
  
  irMap2 = constrain(average2, irMin2, irMax2);
  irMap2 = map(irMap2, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap2 = constrain(irMap2, 0, 127);              //constrain
  
  if(irMap2 >= THRESHOLD3 && noteState2 ==1){ 
    midiOUT(0x90, note2, 127);                 
    noteState2 = 0;
  }
     
  if(irMap2 <= THRESHOLD3 && noteState2 ==0){
     midiOUT(0x90, note2, 0);               
     noteState2 = 1;
  }
    
  if(abs(irMap2 - prevVal2) >= THRESHOLD2){
    midiOUT(0xB0, midicc2, irMap2);
    prevVal2 = irMap2;
  }  
  
  if(irMap2 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin2, HIGH);
  }
  else{
    digitalWrite(sPin2, LOW);  
  }
  
   //ir3
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
  if (index3 >= numReadings)              
    // ...wrap around to the beginning: 
    index3 = 0;                           

  // calculate the average:
  average3 = total3 / numReadings;         
 
  irMap3 = constrain(average3, irMin2, irMax2);
  irMap3 = map(irMap3, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap3 = constrain(irMap3, 0, 127);              //constrain
  
  if(irMap3 >= THRESHOLD3 && noteState3 ==1){ 
    midiOUT(0x90, note3, 127);                 
    noteState3 = 0;
  }
     
  if(irMap3 <= THRESHOLD3 && noteState3 ==0){
     midiOUT(0x90, note3, 0);               
     noteState3 = 1;
  }
    
  if(abs(irMap3 - prevVal3) >= THRESHOLD2){
    midiOUT(0xB0, midicc3, irMap3);
    prevVal3 = irMap3;
  }  
  
  if(irMap3 >= THRESHOLD3 && switchState == 0){
    digitalWrite(sPin3, HIGH);
  }
  else{
    digitalWrite(sPin3, LOW);  
  }
  
     //ir4
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
  if (index4 >= numReadings)              
    // ...wrap around to the beginning: 
    index4 = 0;                           

  // calculate the average:
  average4 = total4 / numReadings;         
  
  irMap4 = constrain(average4, irMin2, irMax2);
  irMap4 = map(irMap4, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap4 = constrain(irMap4, 0, 127);              //constrain
  
  if(irMap4 >= THRESHOLD3 && noteState4 ==1){ 
    midiOUT(0x90, note4, 127);                 
    noteState4 = 0;
  }
     
  if(irMap4 <= THRESHOLD3 && noteState4 ==0){
     midiOUT(0x90, note4, 0);               
     noteState4 = 1;
  }
    
  if(abs(irMap4 - prevVal4) >= THRESHOLD2){
    midiOUT(0xB0, midicc4, irMap4);
    prevVal4 = irMap4;
  }  
  
  if(irMap4 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin4, HIGH);
  }
  else{
    digitalWrite(sPin4, LOW);  
  }
  
  
     //ir5
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
  if (index5 >= numReadings)              
    // ...wrap around to the beginning: 
    index5 = 0;                           

  // calculate the average:
  average5 = total5 / numReadings;         
 
  irMap5 = constrain(average5, irMin2, irMax2);
  irMap5 = map(irMap5, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap5 = constrain(irMap5, 0, 127);              //constrain
  
  if(irMap5 >= THRESHOLD3 && noteState5 ==1){ 
    midiOUT(0x90, note5, 127);                 
    noteState5 = 0;
  }
     
  if(irMap5 <= THRESHOLD3 && noteState5 ==0){
     midiOUT(0x90, note5, 0);               
     noteState5 = 1;
  }
    
  if(abs(irMap5 - prevVal5) >= THRESHOLD2){
    midiOUT(0xB0, midicc5, irMap5);
    prevVal5 = irMap5;
  }  
  
  if(irMap5 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin5, HIGH);
  }
  else{
    digitalWrite(sPin5, LOW);  
  }
  
     //ir6
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
  if (index6 >= numReadings)              
    // ...wrap around to the beginning: 
    index6 = 0;                           

  // calculate the average:
  average6 = total6 / numReadings;         
  
  irMap6 = constrain(average6, irMin2, irMax2);
  irMap6 = map(irMap6, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap6 = constrain(irMap6, 0, 127);              //constrain
  
  if(irMap6 >= THRESHOLD3 && noteState6 ==1){ 
    midiOUT(0x90, note6, 127);                 
    noteState6 = 0;
  }
     
  if(irMap6 <= THRESHOLD3 && noteState6 ==0){
     midiOUT(0x90, note6, 0);               
     noteState6 = 1;
  }
    
  if(abs(irMap6 - prevVal6) >= THRESHOLD2){
    midiOUT(0xB0, midicc6, irMap6);
    prevVal6 = irMap6;
  }  
  
  if(irMap6 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin6, HIGH);
  }
  else{
    digitalWrite(sPin6, LOW);  
  }
  
   //ir7
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
  if (index7 >= numReadings)              
    // ...wrap around to the beginning: 
    index7 = 0;                           

  // calculate the average:
  average7 = total7 / numReadings;         
 
  irMap7 = constrain(average7, irMin2, irMax2);
  irMap7 = map(irMap7, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap7 = constrain(irMap7, 0, 127);              //constrain
  
  if(irMap7 >= THRESHOLD3 && noteState7 ==1){ 
    midiOUT(0x90, note7, 127);                 
    noteState7 = 0;
  }
     
  if(irMap7 <= THRESHOLD3 && noteState7 ==0){
     midiOUT(0x90, note7, 0);               
     noteState7 = 1;
  }
    
  if(abs(irMap7 - prevVal7) >= THRESHOLD2){
    midiOUT(0xB0, midicc7, irMap7);
    prevVal7 = irMap7;
  }  
  
  if(irMap7 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin7, HIGH);
  }
  else{
    digitalWrite(sPin7, LOW);  
  }
  
     //ir8
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
  if (index8 >= numReadings)              
    // ...wrap around to the beginning: 
    index8 = 0;                           

  // calculate the average:
  average8 = total8 / numReadings;         
  
  irMap8 = constrain(average8, irMin2, irMax2);
  irMap8 = map(irMap8, irMin1, irMax1, 0, 127);  //map the reading to midi standard
  irMap8 = constrain(irMap8, 0, 127);              //constrain
  
  if(irMap8 >= THRESHOLD3 && noteState8 ==1){ 
    midiOUT(0x90, note8, 127);                 
    noteState8 = 0;
  }
     
  if(irMap8 <= THRESHOLD3 && noteState8 ==0){
     midiOUT(0x90, note8, 0);               
     noteState8 = 1;
  }
    
  if(abs(irMap8 - prevVal8) >= THRESHOLD2){
    midiOUT(0xB0, midicc8, irMap8);
    prevVal8 = irMap8;
  }  
  
  if(irMap8 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin8, HIGH);
  }
  else{
    digitalWrite(sPin8, LOW);  
  }
  
  /*
  Serial.print("irval1 " );                       
  Serial.print(irVal1);      
  Serial.print("\t irMap1 ");      
  Serial.print(irMap1); 
  Serial.print("irval2 " );                       
  Serial.print(irVal2);      
  Serial.print("\t irMap2 ");      
  Serial.println(irMap2);
    */
} 

void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}      


