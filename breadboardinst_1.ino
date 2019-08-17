
int buttonPin1 = 7;
int buttonPin2 = 8;
int buttonPin3 = 9;
int buttonPin4 = 10;
int buttonPin5 = 11;
int buttonPin6 = 12;
int buttonPin7 = 13;

int photo2Pin = 1; 

int buttonVal1, buttonVal2, buttonVal3, buttonVal4, buttonVal5, buttonVal6, buttonVal7 = 0;                    //variable for reading the button status
int buttonState1, buttonState2, buttonState3, buttonState4, buttonState5, buttonState6, buttonState7 = 0;            //variable to hold the buttons current state
int bounceCheck1, bounceCheck2, bounceCheck3, bounceCheck4, bounceCheck5, bounceCheck6, bounceCheck7 = 0; 

int pvalue2 = 0;
int mappedIn2 = 0;
int previnVal2 = 0;
int THRESHOLD = 3;

int i;
int midiNote[] = {60, 62, 64, 65, 67, 69, 72}; // c, d, e, f, g, a, c
int buttonVal[] = {0, 1, 2, 3, 4, 5, 6};
int buttonState[] = {0, 0 ,0 ,0 ,0 ,0, 0}; // number oif notes we are firing
int buttonPin[] = {7, 8, 9, 10, 11, 12, 13}; // the Analog input values
int bounceCheck[] = {7, 8, 9, 10, 11, 12, 13}; // the Analog input values match bounch
int intVal = 0;


void setup() {
    Serial.begin(31250);            //MIDI communicates at 31250 baud
    
    for (i=0; i <7; i++) {
       pinMode(buttonPin[i], INPUT);
//       Serial.println(buttonVal[i]);
    } 
//    pinMode(buttonPin1, INPUT);    //declare pushbutton as input
//    pinMode(buttonPin2, INPUT);
//    pinMode(buttonPin3, INPUT);
//    pinMode(buttonPin4, INPUT);
//    pinMode(buttonPin5, INPUT);
//    pinMode(buttonPin6, INPUT);
//    pinMode(buttonPin7, INPUT);
}

void loop() {
 
    for (int i=1; i <=7; i++) {
       fireNote(i);
    } 
  //c
//  buttonVal1 = digitalRead(buttonPin1);     //read input value from button
//  delay(5);                              //wait 10ms
//  bounceCheck1 = digitalRead(buttonPin1);   //check again
//  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
//    if (buttonVal1 == HIGH && buttonState1 == 0) {   //check if the input is HIGH
//      
//      midiOUT(0x90, 60, 127); //cc chnge, cc83, on
//      buttonState1 = 1;
//    }
//    if(buttonVal1 == LOW && buttonState1 == 1){
//      
//      midiOUT(0x90, 60, 0); //cc chnge, cc83, off
//      buttonState1 = 0;
//    }
  
//  //d
//  buttonVal1 = digitalRead(buttonPin1);     //read input value from button
//  delay(5);                              //wait 10ms
//  bounceCheck1 = digitalRead(buttonPin1);   //check again
//  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
//    if (buttonVal1 == HIGH && buttonState1 == 0) {   //check if the input is HIGH
//      
//      midiOUT(0x90, 62, 127); //cc chnge, cc83, on
//      buttonState1 = 1;
//    }
//    if(buttonVal1 == LOW && buttonState1 == 1){
//      
//      midiOUT(0x90, 62, 0); //cc chnge, cc83, off
//      buttonState1 = 0;
//    }
//  buttonVal2 = digitalRead(buttonPin2);     //read input value from button
//  delay(5);                              //wait 10ms
//  bounceCheck2 = digitalRead(buttonPin2);   //check again
//  if(buttonVal2 == bounceCheck2){           //if val is the same then not a bounce
//    if (buttonVal2 == HIGH && buttonState2 == 0) {   //check if the input is HIGH
//      
//      midiOUT(0x90, 64, 127); //cc chnge, cc83, on
//      buttonState2 = 1;
//    }
//    if(buttonVal2 == LOW && buttonState2 == 1){
//      
//      midiOUT(0x90, 64, 0); //cc chnge, cc83, off
//      buttonState2 = 0;
//    }  
//
//
//  buttonVal3 = digitalRead(buttonPin3);     //read input value from button
//  delay(5);                              //wait 10ms
//  bounceCheck3 = digitalRead(buttonPin3);   //check again
//  if(buttonVal3 == bounceCheck3){           //if val is the same then not a bounce
//    if (buttonVal3 == HIGH && buttonState3 == 0) {   //check if the input is HIGH
//      
//      midiOUT(0x90, 65, 127); //cc chnge, cc83, on
//      buttonState3 = 1;
//    }
//    if(buttonVal3 == LOW && buttonState3 == 1){
//      
//      midiOUT(0x90, 65, 0); //cc chnge, cc83, off
//      buttonState3 = 0;
//    }  

  //pvalue2 = analogRead(photo2Pin);
 
  //mappedIn2 = map(pvalue2, 0, 1023, 0, 127);
  
  
  //if(abs(mappedIn2 - previnVal2) >= THRESHOLD){ //set 0 as default
     //if (abs(pvalue2) == 0 )
       //mappedIn2 = 0;    
          
     //midiOUT(0xB0, 103, mappedIn2); //Control Change (Ch 1), Controller 7 - default control for volume.
     //previnVal2 = mappedIn2;




//  }

//  }

//} 
//  }
}

void fireNote (int intVal) {
      
      buttonVal[intVal] = digitalRead(buttonPin[intVal]);     //read input value from button
      Serial.println(buttonState[intVal]);
      delay(5);                              //wait 10ms
      bounceCheck[intVal] = digitalRead(buttonPin[intVal]);   //check again
      if(buttonVal[intVal] == bounceCheck[intVal]){
        if (buttonVal[intVal] == HIGH && buttonState[intVal] == 0) {   //check if the input is HIGH
          //Serial.println(midiNote[intVal]);
          midiOUT(0x90, midiNote[intVal], 127); //cc chnge, cc83, on
          buttonState[intVal] = 1;
        }
        if(buttonVal[intVal] == LOW && buttonState[intVal] == 1){
          //Serial.println(buttonState[intVal]);
          midiOUT(0x90, midiNote[intVal], 0); //cc chnge, cc83, off
          buttonState[intVal] = 0;
        }  
      }
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command, BYTE);
  Serial.print(value1, BYTE);
  Serial.print(value2, BYTE);

}
