 

int i;
int midiNote[] = {60, 62, 64, 65, 67, 69, 71, 72}; // c, d, e, f, g, a // FIRST NOTE IS FIXME 
int buttonVal[] = {0, 1, 2, 3, 4, 5, 6, 7};
int buttonState[] = {0, 0, 0 ,0 ,0 ,0 ,0, 0}; // number oif notes we are firing
int buttonPin[] = {6, 7, 8, 9, 10, 11, 12, 13}; // the Analog input values
int bounceCheck[] = {6, 7, 8, 9, 10, 11, 12, 13}; // the Analog input values match bounch
int intVal = 0;


void setup() {
    Serial.begin(31250);            //MIDI communicates at 31250 baud
    
    for (i=0; i <=7; i++) {
       pinMode(buttonPin[i], INPUT);
//       Serial.println(buttonVal[i]);
    } 
}

void loop() {
 
    for (int i=0; i <=7; i++) {
       fireNote(i);
    } 
  
}

void fireNote (int intVal) {
      
      buttonVal[intVal] = digitalRead(buttonPin[intVal]);     //read input value from button
//      Serial.println(buttonState[intVal]);
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
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);

}
