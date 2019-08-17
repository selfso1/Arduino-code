

int slidePin1 = 0;
int slideVal1 = 0;
int mappVal1 = 0;
int prevVal1 = 0;

int buttonPin = 7;
int buttonVal = 0; 
int bounceCheck = 0;
int buttonState = 0;
int ledPin = 8;

int THRESHOLD = 2;
void setup() {

  pinMode(ledPin, OUTPUT); 
  pinMode(buttonPin, INPUT);
  Serial.begin(31250);
}

void loop() {
  
  buttonVal = digitalRead(buttonPin);     //read input value from button
  delay(5);                              //wait 10ms
  bounceCheck = digitalRead(buttonPin);   //check again
  if(buttonVal == bounceCheck){           //if val is the same then not a bounce
    if (buttonVal == HIGH && buttonState == 0) {   //check if the input is HIGH
      
      midiOUT(0x90, 60, 127); //note on
      buttonState = 1;
      digitalWrite(ledPin, HIGH);
    }
    if(buttonVal == LOW && buttonState == 1){
      
      midiOUT(0x90, 60, 0); //note off
      buttonState = 0;
      digitalWrite(ledPin, LOW);
    }  
  }  
 slideVal1 = analogRead(slidePin1);

 mappVal1 = map(slideVal1, 0, 19, 0, 127);

 if(abs(slideVal1 - prevVal1) >= THRESHOLD){
    midiOUT(0xB0, 13, mappVal1);
    prevVal1 = slideVal1;
}
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command, BYTE);
  Serial.print(value1, BYTE);
  Serial.print(value2, BYTE);
}  
