const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

int switchPin1 = 11;
int switchPin2 = 12;

int elPin1 = 2;
int elPin2 = 3;
int elPin3 = 4;
int elPin4 = 5;
int elPin5 = 6; 

int sensVal = 0;
int mapVal1 = 0;
int switchVal1 = 0;
int switchVal2 = 0;

int state = 1;
void setup() {                
 
  pinMode(elPin1, OUTPUT);  
  pinMode(elPin2, OUTPUT);  
  pinMode(elPin3, OUTPUT);
  pinMode(elPin4, OUTPUT);  
  pinMode(elPin5, OUTPUT);
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  
  // initialize serial communication with computer:
                    
  // initialize all the readings to 0: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;          

  Serial.begin(9600); 
}


void loop() {

  // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor:  
  readings[index] = analogRead(inputPin); 
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings;         
  // send it to the computer as ASCII digits
                


 
  mapVal1= map(average, 0, 970, 0, 250);
  
  sensVal = constrain(mapVal1, 0, 250);
  
  switchVal1 = digitalRead(switchPin1);
  switchVal2 = digitalRead(switchPin2);
  
  if (switchVal1 == HIGH && switchVal2 == LOW)
     state = 1;
  if (switchVal1 == LOW && switchVal2 == HIGH)
     state = 2;  
 
  
  switch (state) {
  
  case 1:
    if (sensVal >= 0 && sensVal <= 225){
       digitalWrite(elPin1, HIGH);  
  }
    else {
       digitalWrite(elPin1, LOW); 
  } 
  
    if (sensVal >= 0 && sensVal <= 200){
       digitalWrite(elPin2, HIGH);  
  }
    else {
       digitalWrite(elPin2, LOW); 
  } 
    if (sensVal >= 0 && sensVal <= 150){
       digitalWrite(elPin3, HIGH);  
  }
    else {
       digitalWrite(elPin3, LOW); 
  } 
    if (sensVal >= 0 && sensVal <= 100){
       digitalWrite(elPin4, HIGH);  
  }
    else {
       digitalWrite(elPin4, LOW); 
  } 
  
    if (sensVal >= 0 && sensVal <= 50){
       digitalWrite(elPin5, HIGH);  
  }
    else {
       digitalWrite(elPin5, LOW); 
  } 
    break;
    
    
  case 2:
    if (sensVal >= 0 && sensVal <= 50){
       digitalWrite(elPin1, HIGH);  
  }
    else {
       digitalWrite(elPin1, LOW); 
  } 
  
    if (sensVal >= 50 && sensVal <= 100){
       digitalWrite(elPin2, HIGH);  
  }
    else {
       digitalWrite(elPin2, LOW); 
  } 
    if (sensVal >= 100 && sensVal <= 150){
       digitalWrite(elPin3, HIGH);  
  }
    else {
       digitalWrite(elPin3, LOW); 
  } 
    if (sensVal >= 150 && sensVal <= 200){
       digitalWrite(elPin4, HIGH);  
  }
    else {
       digitalWrite(elPin4, LOW); 
  } 
  
    if (sensVal >= 200 && sensVal <= 250){
       digitalWrite(elPin5, HIGH);  
  }
    else {
       digitalWrite(elPin5, LOW); 
   
    break;
  
    }  
  Serial.println(average); 
   
}
}

