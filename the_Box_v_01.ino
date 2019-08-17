//calibration code test


int flexPin = A0;

int flexMax = 0;
int flexMin = 1023; 
int counter = 0;

int flexMap = 0;
int flexCon = 0;

int prevVal = 0;

int switchPin = 7;
int switchVal = 0;
boolean calState = false;
int ledPin1 = 12;
int ledPin2 = 13;

const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int flexVal = 0;                // the average

int THRESHOLD = 2;

void setup() {
  
  Serial.begin(31250); 
  
  pinMode(switchPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0; 
}
void loop() {
  
  ///////sensor/switch reads//////

  switchVal = digitalRead(switchPin);
  

 /////test for enter calibration//////// 
  if(switchVal == HIGH) {
    calState = true;
  }  
  if(switchVal == LOW) { 
    calState = false;
  }
 //////begin calibration code/////
  while(calState == true) {  
    
    if(counter == 0){
      flexMax = 0;
      flexMin = 1023;
      counter = 1; 
    }
  flexVal = analogRead(flexPin);  
  
  digitalWrite(ledPin2, HIGH);  // record the maximum sensor value
  digitalWrite(ledPin1, LOW);
    
    if (flexVal > flexMax) {
       flexMax = flexVal;
    }
                                
    if (flexVal < flexMin) {  // record the minimum sensor value
       flexMin = flexVal;
    }
  switchVal = digitalRead(switchPin);
  
    if(switchVal == HIGH) {   // test for stay or exit calibration while loop
      calState = true;
  }  
    if(switchVal == LOW) { 
      calState = false;  
  }
  Serial.print("sensor = " );                       
  Serial.print(flexVal);      
  Serial.print("\t output = ");      
  Serial.println(flexMax);   
  
 } 
//////begin main loop/////////
  counter = 0;
  
  if(switchVal == LOW){            // turn on green led
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, HIGH);
    
  // subtract the last reading:
  total= total - readings[index];         ///smoothing
  // read from the sensor:  
  readings[index] = analogRead(flexPin); 
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  flexVal = total / numReadings;
  
  }  
  flexMap = map(flexVal, flexMin, flexMax, 0, 127);  
  
  flexCon = constrain(flexMap, 0, 127);
  
  if(abs(flexCon - prevVal) >= THRESHOLD){
    
     midiOUT(0xB0, 10, flexCon); 
     prevVal = flexCon;
  }  

}
  
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}      
    
