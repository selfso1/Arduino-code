


int sPin = 6;
int buttonPin = 7;
int buttonVal = 0;
int bounceCheck = 0;
int rnum1 = 0;
int rnum2 = 0;
int rnum3 = 0;
int rnum4 = 0;


void setup() {
               //MIDI communicates at 31250 baud
    pinMode(sPin, OUTPUT);
    pinMode(buttonPin, INPUT);     //declare pushbutton as input
}

void loop() {
 
  rnum1 = random(50, 500); 
  rnum2 = random(50, 500); 
  rnum3 = random(50, 500); 
  rnum4 = random(50, 500); 
  
  buttonVal = digitalRead(buttonPin);     //read input value from button
  //delay(5);                              //wait 10ms
  //bounceCheck = digitalRead(buttonPin);   //check again
  //if(buttonVal == bounceCheck){           //if val is the same then not a bounce
    if(buttonVal == HIGH){
      digitalWrite(sPin, HIGH);
      delay(rnum1);
      digitalWrite(sPin, LOW);
      delay(rnum2);
      digitalWrite(sPin, HIGH);
      delay(rnum3);
      digitalWrite(sPin, LOW);
      delay(rnum4);


}
  
    if(buttonVal == LOW){
      digitalWrite(sPin, LOW);
    
  }
}
