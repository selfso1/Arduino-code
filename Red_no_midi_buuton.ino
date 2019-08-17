

int buttonVal1 = 0;
int bounceCheck1 =0;
int buttonPin1 = 7;
int buttonState1 = 0;
int midiT2 = 0x90;
int midCC1 = 67;
int midCC2 = 70;
int midCC3 = 60;
int midCC4 = 62;
int midCC5 = 65;
int d1 = 0;

void setup() {
  
  Serial.begin(31250);
  pinMode(buttonPin1, INPUT); 
}

void loop() {
  buttonVal1 = digitalRead(buttonPin1);     //read input value from button
  delay(5);                              //wait 10ms
  bounceCheck1 = digitalRead(buttonPin1);   //check again
  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
    if(buttonVal1 == HIGH && buttonState1 == 0) {
      midiOUT(midiT2, midCC1, 0);
      delay(d1);
      midiOUT(midiT2, midCC2, 0);
      delay(d1);
      midiOUT(midiT2, midCC3, 0);
      delay(d1);
      midiOUT(midiT2, midCC4, 0);
      delay(d1);
      midiOUT(midiT2, midCC5, 0);
      delay(d1);
      buttonState1 = 1;
     }
    else{
      buttonState1 = 0;
      delay(d1); 
    }
}
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}  
