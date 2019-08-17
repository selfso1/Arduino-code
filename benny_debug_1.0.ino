
int switchVal = 0;                    //variable for reading the button status
int switchState = 0;
                       //variable to hold the buttons current state
int bounceCheck = 0;

int switchPin = 5;

int sPin1 = 6;

int irPin1 = 0;
int irVal1 = 0;
int noteState1 = 0;

int average1 = 0;

int irMap1 = 0;

int prevVal1 = 0;

const int numReadings = 10;

int readings1[numReadings];// the readings from the analog input

int index1 = 0;                  // the index of the current reading
int total1 = 0;

const int irMax1 = 600;
const int irMin1 = 10;
        
const int THRESHOLD1 = 20;      // threshold for solinod valves
const int THRESHOLD2 = 6;       // threshold for midicc stepping
const int THRESHOLD3 = 10;      // threshold fpr midi not on

const int note1 = 60;

const int midicc = 10;

const int serial = 31250;

void setup() {
 
  Serial.begin(serial); 
  pinMode(sPin1, OUTPUT);
  

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
 
  irMap1 = map(average1, irMin1, irMax1, 0, 127);  //map the reading to midi standard
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
    midiOUT(0xB0, midicc, irMap1);
    prevVal1 = irMap1;
  }  
  
  if(irMap1 >= THRESHOLD1 && switchState == 0){
    digitalWrite(sPin1, HIGH);
  }
  else{
    digitalWrite(sPin1, LOW);  
  }
  /*
  Serial.print("irval1 " );                       
  Serial.print(irVal1);      
  Serial.print("\t irMap1 ");      
  Serial.println(irMap1);      
*/

}  
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}      


