

int slidePin1 = 0;
int slideVal1 = 0;
int mappVal1 = 0;
int prevVal1 = 0;

int THRESHOLD = 2;
void setup() {
  
  Serial.begin(31250);
}

void loop() {
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
