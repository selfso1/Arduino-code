//calibration code test


int flexPin = A0;
int flexVal = 0;

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

int THRESHOLD = 2;

void setup() {
  
  Serial.begin(31250); 
  
  pinMode(switchPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}  
void loop() {
  
  ///////sensor/switch reads//////

  switchVal = digitalRead(switchPin);
  
  flexVal = analogRead(flexPin);

 /////test for enter calibration//////// 
  if(switchVal == HIGH) {
    calState = true;
  }  
  if(switchVal == LOW) { 
    calState = false;
  }
 //////begin calibration code/////
  while(calState == true) {  
    ///////may need a test for moving sensors so they ALL dont reset
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
  
  if(switchVal == LOW){
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin1, HIGH);
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
    
