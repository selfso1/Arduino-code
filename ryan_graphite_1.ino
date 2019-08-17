/*
ryan graphite biatch
 
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin1 = 2; // the number of the pushbutton pin
const int buttonPin2 = 3;
const int buttonPin3 = 4; 
const int buttonPin4 = 5;
const int buttonPin5 = 6; 
const int buttonPin6 = 7; 
const int buttonPin7 = 8;
const int buttonPin8 = 9; 
const int buttonPin9 = 10;
const int buttonPin10 = 11; 
const int buttonPin11 = 12;
const int buttonPin12 = 13; 

const int midiCC1 = 15;
const int midiCC2 = 16;
const int midiCC3 = 17;
const int midiCC4 = 18;
const int midiCC5 = 54;
const int midiCC6 = 56;
const int midiCC7 = 49;
const int midiCC8 = 66;
const int midiCC9 = 68;
const int midiCC10 = 61;
const int midiCC11 = 62;
const int midiCC12 = 24;

// variables will change:
int buttonState1 = 0;  
int buttonState2 = 0;// variable for reading the pushbutton status
int buttonState3 = 0;  
int buttonState4 = 0;
int buttonState5 = 0;  
int buttonState6 = 0;  
int buttonState7 = 0;
int buttonState8 = 0;  
int buttonState9 = 0;
int buttonState10 = 0;  
int buttonState11 = 0;
int buttonState12 = 0; 

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
int buttonVal12 = 0;

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
int bounceCheck12 = 0;

int ledPin1 = 0;

void setup() {
  // initialize the LED pin as an output:
  
  pinMode(ledPin1, OUTPUT);
  
  pinMode(buttonPin1, INPUT);     
  pinMode(buttonPin2, INPUT);  
  pinMode(buttonPin3, INPUT);     
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);     
  pinMode(buttonPin6, INPUT);     
  pinMode(buttonPin7, INPUT);  
  pinMode(buttonPin8, INPUT);     
  pinMode(buttonPin9, INPUT);
  pinMode(buttonPin10, INPUT);  
  pinMode(buttonPin11, INPUT);
  pinMode(buttonPin12, INPUT);
  
  Serial.begin(31250);
}



void loop(){
  // read the state of the pushbutton value:
  buttonVal1 = digitalRead(buttonPin1);
  delay(9); 
  //wait 10ms
  bounceCheck1 = digitalRead(buttonPin1);      
  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
    if (buttonVal1 == HIGH && buttonState1 == 0) {   //check if the input is HIGH
      
      midiOUT(0xB0, midiCC1, 0); //cc chnge, cc83, on
      buttonState1 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal1 == LOW && buttonState1 == 1){
      
      midiOUT(0xB0, midiCC1, 127); //cc chnge, cc83, off
      buttonState1 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  }
  } 
  buttonVal2 = digitalRead(buttonPin2);
  delay(9); 
  //wait 10ms
  bounceCheck2 = digitalRead(buttonPin2);      
  if(buttonVal2 == bounceCheck2){           //if val is the same then not a bounce
    if (buttonVal2 == HIGH && buttonState2 == 0) {   //check if the input is HIGH
      
      midiOUT(0xB0, midiCC2, 0); //cc chnge, cc83, on
      buttonState2 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal2 == LOW && buttonState2 == 1){
      
      midiOUT(0xB0, midiCC2, 127); //cc chnge, cc83, off
      buttonState2 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  buttonVal3 = digitalRead(buttonPin3);
  delay(9); 
  //wait 10ms
  bounceCheck3 = digitalRead(buttonPin3);      
  if(buttonVal3 == bounceCheck3){           //if val is the same then not a bounce
    if (buttonVal3 == HIGH && buttonState3 == 0) {   //check if the input is HIGH
      
      midiOUT(0xB0, midiCC3, 0); //cc chnge, cc83, on
      buttonState3 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal3 == LOW && buttonState3 == 1){
      
      midiOUT(0xB0, midiCC3, 127); //cc chnge, cc83, off
      buttonState3 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  }
  } 
  buttonVal4 = digitalRead(buttonPin4);
  delay(9); 
  //wait 10ms
  bounceCheck4 = digitalRead(buttonPin4);      
  if(buttonVal4 == bounceCheck4){           //if val is the same then not a bounce
    if (buttonVal4 == HIGH && buttonState4 == 0) {   //check if the input is HIGH
      
      midiOUT(0xB0, midiCC4, 0); //cc chnge, cc83, on
      buttonState4 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal4 == LOW && buttonState4 == 1){
      
      midiOUT(0xB0, midiCC4, 127); //cc chnge, cc83, off
      buttonState4 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  buttonVal5 = digitalRead(buttonPin5);
  delay(9); 
  //wait 10ms
  bounceCheck5 = digitalRead(buttonPin5);      
  if(buttonVal5 == bounceCheck5){           //if val is the same then not a bounce
    if (buttonVal5 == HIGH && buttonState5 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC5, 0); //cc chnge, cc83, on
      buttonState5 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal5 == LOW && buttonState5 == 1){
      
      midiOUT(0x90, midiCC5, 127); //cc chnge, cc83, off
      buttonState5 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  
  buttonVal6 = digitalRead(buttonPin6);
  delay(9); 
  //wait 10ms
  bounceCheck6 = digitalRead(buttonPin6);      
  if(buttonVal6 == bounceCheck6){           //if val is the same then not a bounce
    if (buttonVal6 == HIGH && buttonState6 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC6, 0); //cc chnge, cc83, on
      buttonState6 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal6 == LOW && buttonState6 == 1){
      
      midiOUT(0x90, midiCC6, 127); //cc chnge, cc83, off
      buttonState6 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  buttonVal7 = digitalRead(buttonPin7);
  delay(9); 
  //wait 10ms
  bounceCheck7 = digitalRead(buttonPin7);      
  if(buttonVal7 == bounceCheck7){           //if val is the same then not a bounce
    if (buttonVal7 == HIGH && buttonState7 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC7, 0); //cc chnge, cc83, on
      buttonState7 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal7 == LOW && buttonState7 == 1){
      
      midiOUT(0x90, midiCC7, 127); //cc chnge, cc83, off
      buttonState7 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  
  buttonVal8 = digitalRead(buttonPin8);
  delay(9); 
  //wait 10ms
  bounceCheck8 = digitalRead(buttonPin8);      
  if(buttonVal8 == bounceCheck8){           //if val is the same then not a bounce
    if (buttonVal8 == HIGH && buttonState8 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC8, 0); //cc chnge, cc83, on
      buttonState8 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal8 == LOW && buttonState8 == 1){
      
      midiOUT(0x90, midiCC8, 127); //cc chnge, cc83, off
      buttonState8 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  
  buttonVal9 = digitalRead(buttonPin9);
  delay(9); 
  //wait 10ms
  bounceCheck9 = digitalRead(buttonPin9);      
  if(buttonVal9 == bounceCheck9){           //if val is the same then not a bounce
    if (buttonVal9 == HIGH && buttonState9 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC9, 0); //cc chnge, cc83, on
      buttonState9 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal9 == LOW && buttonState9 == 1){
      
      midiOUT(0x90, midiCC9, 127); //cc chnge, cc83, off
      buttonState9 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  
  buttonVal10 = digitalRead(buttonPin10);
  delay(9); 
  //wait 10ms
  bounceCheck10 = digitalRead(buttonPin10);      
  if(buttonVal10 == bounceCheck10){           //if val is the same then not a bounce
    if (buttonVal10 == HIGH && buttonState10 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC10, 0); //cc chnge, cc83, on
      buttonState10 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal10 == LOW && buttonState10 == 1){
      
      midiOUT(0x90, midiCC10, 127); //cc chnge, cc83, off
      buttonState10 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  buttonVal11 = digitalRead(buttonPin11);
  delay(9); 
  //wait 10ms
  bounceCheck11 = digitalRead(buttonPin11);      
  if(buttonVal11 == bounceCheck11){           //if val is the same then not a bounce
    if (buttonVal11 == HIGH && buttonState11 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC11, 0); //cc chnge, cc83, on
      buttonState11 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal11 == LOW && buttonState11 == 1){
      
      midiOUT(0x90, midiCC11, 127); //cc chnge, cc83, off
      buttonState11 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
  
  buttonVal12 = digitalRead(buttonPin12);
  delay(9); 
  //wait 10ms
  bounceCheck12 = digitalRead(buttonPin12);      
  if(buttonVal12 == bounceCheck12){           //if val is the same then not a bounce
    if (buttonVal12 == HIGH && buttonState12 == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, midiCC12, 0); //cc chnge, cc83, on
      buttonState12 = 1;
      digitalWrite(ledPin1, LOW);
  }
    if(buttonVal12 == LOW && buttonState12 == 1){
      
      midiOUT(0x90, midiCC12, 127); //cc chnge, cc83, off
      buttonState12 = 0;// turn LED on:    
      digitalWrite(ledPin1, HIGH);  
  } 
  }
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}  
