//calibration code test

int i;
int dPin[] ={22,23,24,25,26,27,28,29,30,31};
int pinCount = 14;


int sPin[] ={0,1,2,3,4,5,6,7,8};
int sVal[] ={0,0,0,0,0,0,0,0,0};

int sMax[]= {0,0,0,0,0,0,0,0,0};
int sMin[] = {1023,1023,1023,1023,1023,1023,1023,1023,1023};

int counter[] = {0,0,0,0,0,0,0,0,0};

int preCal[]   = {0,0,0,0,0,0,0,0,0};      //
int calDiff[]  = {0,0,0,0,0,0,0,0,0};      //  variables used to determine sensor movement for min/max reset
int calMax[]   = {0,0,0,0,0,0,0,0,0};      //

int saVal = 0;                  // analog sensor array value

const int numReadings = 10;

int readings[numReadings];// the readings from the analog input

int index = 0;                  // the index of the current reading
int total[] = {0,0,0,0,0,0,0,0,0};

int sMap[] = {0,0,0,0,0,0,0,0,0};          //sensor value mapped to midi values (0 to 127)
int sCon[] = {0,0,0,0,0,0,0,0,0};          //sensor contrain number, this is the final value sent to midi
int prevVal[]  = {0,0,0,0,0,0,0,0,0};      //

int switchPin = 2;   //calibration switch pin
int switchVal = 0;
boolean calState = false;  //boolean state for calibration enter/exit test

int ledPin1 = 3;   //green led
int ledPin2 = 4;   //red led

int THRESHOLD = 2;
int THRESHOLD2 = 90;  //cycle count for calibration sensor movement
int calThreshold = 25;

int sMidiType = 0xB0;
int sMidiVal[] = {10,11,12,13,14,15,16,17,18};


void setup() {
  
  Serial.begin(31250); 
 
  pinMode(switchPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
 
  for (int thisPin = 0; thisPin < pinCount; thisPin++)  {
      pinMode(dPin[thisPin], INPUT);
  }
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {  ///smoothing array setup
    readings[thisReading] = 0; 
  } 
}  
void loop() {
  
  switchVal = digitalRead(switchPin);    ///////calibration switch read//////
  
  if(switchVal == LOW){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, HIGH);
    calState = false; 
  }
 
  if(switchVal == HIGH) {     /////test for enter calibration////////
    calState = true;
  }  
  
  counter[] = 0;                // reset calibration counter, this is for the cycle time to determine which sensors are moving
  
  for (int i=0; i <=9; i++) {
      sensorMidisend(i);
  }     

//////begin calibration code/////

  while(calState == true) {  
    
    digitalWrite(ledPin2, HIGH);  //indicate calibration mode by turning on red led
    digitalWrite(ledPin1, LOW);
    
  for (int saVal=0; saVal <=9; saVal++) {
      
    sVal[saVal] = analogRead(sPin[saVal]);   
    
    if(counter <= THRESHOLD2){       ///count through 90 cycles to test for movement
      counter++; 
      calDiff[saVal] = abs(sVal[saVal] - preCal[saVal]);
      preCal[saVal] = sVal[saVal]; 
      }
      if(calDiff[saVal] >= calMax[saVal]){    /////// a test for moving sensors so they ALL dont reset   
        calMax[saVal] = calDiff[saVal];       
      }  
      if(calMax[saVal] >= calThreshold){    ///reset the one(s) moving
        sMax[saVal] = 0;
        sMin[saVal] = 1023;
        calDiff[saVal] = 0;
        calMax[saVal] = 0;
    }   
    
    if (sVal[saVal] > sMax[saVal]) {  // record the maximum sensor value
       sMax[saVal] = sVal[saVal];
    }
                                
    if (sVal[saVal] < sMin[saVal]) {  // record the minimum sensor value
       sMin[saVal] = sVal[saVal];
    }
  switchVal = digitalRead(switchPin);
  
    if(switchVal == HIGH) {   // test for stay or exit calibration while loop
      calState = true;
  }  
    if(switchVal == LOW) { 
      calState = false;  
  }
  Serial.print("sensor = " );                       
  Serial.print(sVal[saVal]);      
  Serial.print("\t output = ");      
  Serial.println(sMax[saVal]);   
  }
 } 
}
////begin sensor read/midi send//////

void sensorMidisend(int saVal) {
   
  total[saVal]= total[saVal] - readings[index];         
  // read from the sensor:  
  readings[index] = analogRead(sPin[saVal]); 
  // add the reading to the total:
  total[saVal]= total[saVal] + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  sVal[saVal] = total[saVal] / numReadings;         
  
  sMap[saVal] = map(sVal[saVal], sMin[saVal], sMax[saVal], 0, 127);  
  
  sCon[saVal] = constrain(sMap[saVal], 0, 127);
  
  if(abs(sCon[saVal] - prevVal[saVal]) >= THRESHOLD){    // this is used to dtermine movement of the sensor value, if no change, then no value send
    
     midiOUT(sMidiType, sMidiVal[saVal], sCon[saVal]); 
     prevVal[saVal] = sCon[saVal];
  }  

}
  
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}      
    
