








int irPin1 = 0;
int mappedIrVal = 0;
int irVal = 0;

int note;

// A C E G A
int mappedVals [] = {39, 60, 40 ,43, 51 };

void setup() {
  // Set Midi Baud
  Serial.begin(31250);

}

void loop() {
    irVal = analogRead(irPin1);
    
    mappedIrVal = map(irVal, 5, 550, 0, 127);
    
    midiOUT(0xB0, 60, mappedIrVal);
    
}

void midiOUT(char cmd, char value1, char value2) {
  Serial.print(cmd, BYTE);
  Serial.print(value1, BYTE);
  Serial.print(value2, BYTE);
}


void mapArrayVal(int val){
   
  switch (val) {
   case 1:
     note = 0;
     break;
   case 2:
     note = 3;
     break;
   case 3 :
     note = 5;
     break;
   case 4:
     note = 7;
     break; 
  }
  
  for (int i=0; i < 5; i++) {
     mappedVals[i] = mappedVals[i] + i;
  } 
  
  return;
}
