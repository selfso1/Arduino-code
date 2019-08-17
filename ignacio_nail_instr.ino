

int buttonPin1 = 5;
int buttonPin2 = 6;
int buttonPin3 = 7;
int buttonPin4 = 8;
int buttonPin5 = 9;
int buttonPin6 = 10;
int buttonPin7 = 11;
int buttonPin8 = 12;

int buttonVal1 = 0;
int buttonVal2 = 0;
int buttonVal3 = 0;
int buttonVal4 = 0;
int buttonVal5 = 0;
int buttonVal6 = 0;
int buttonVal7 = 0;
int buttonVal8 = 0;

int bounceCheck1 = 0;
int bounceCheck2 = 0;
int bounceCheck3 = 0;
int bounceCheck4 = 0;
int bounceCheck5 = 0;
int bounceCheck6 = 0;
int bounceCheck7 = 0;
int bounceCheck8 = 0;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;

const int midCC1 = 60;
const int midCC2 = 62;
const int midCC3 = 64;
const int midCC4 = 65;
const int midCC5 = 67;
const int midCC6 = 69;
const int midCC7 = 71;
const int midCC8 = 72;

const int midiT = 0x90;
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
  
  buttonVal8 = digitalRead(buttonPin8);     //read input value from button
  delay(dt);                              //wait 10ms
  bounceCheck8 = digitalRead(buttonPin8);   //check again
  if(buttonVal8 == bounceCheck8){           //if val is the same then not a bounce
    if (buttonVal8 == HIGH && buttonState8 == 0) {   //check if the input is HIGH
      
      midiOUT(midiT, midCC8, vl1); //cc chnge, cc83, on
      buttonState8 = 1;
    }
    if(buttonVal8 == LOW && buttonState8 == 1){
      
      midiOUT(midiT, midCC8, vl2); //cc chnge, cc83, off
      buttonState8 = 0;
    }   
  }
}  
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}  
