
int i;
int midiNote[] = {74, 72, 64, 61, 65, 62, 67, 71, 68, 60, 69, 50, 51, 52, 53, 54, 55, 57, 58, 59, 48, 49, 50, 40, 41, 43, 35, 45, 38, 44, 39, 36, 28, 29, 33, 30, 31, 23, 24, 25, 22, 26}; // c, d, e, f, g, a // FIRST NOTE IS FIXME 
int buttonVal[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40};
int buttonState[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // number oif notes we are firing
int buttonPin[] = {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 2}; // the Analog input values
int bounceCheck[] = {14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 2}; // the Analog input values match bounch
int intVal = 0;


void setup() {
    Serial.begin(31250);            //MIDI communicates at 31250 baud
    
    for (i=0; i <=40; i++) {
       pinMode(buttonPin[i], INPUT);

    } 
}

void loop() {
 
    for (int i=0; i <=40; i++) {
       fireNote(i);
    } 
  
}

void fireNote (int intVal) {
      
      buttonVal[intVal] = digitalRead(buttonPin[intVal]);    
      delay(5);                              //wait 
      bounceCheck[intVal] = digitalRead(buttonPin[intVal]);   //check again
      if(buttonVal[intVal] == bounceCheck[intVal]){
        if (buttonVal[intVal] == LOW && buttonState[intVal] == 0) {   
          
          midiOUT(0x90, midiNote[intVal], 127); 
          buttonState[intVal] = 1;
        }
        if(buttonVal[intVal] == HIGH && buttonState[intVal] == 1){
       
          midiOUT(0x90, midiNote[intVal], 0); 
          buttonState[intVal] = 0;
        }  
      }
}

void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}  
