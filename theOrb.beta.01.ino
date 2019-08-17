//force sensor sketch




int sensePin = 0;
int sense2Pin = 4;
int ledPin = 9;

int svalue = 0;
int svalue2 = 0;

int senState = 0;
int senState2 = 0;

int noteState = 0;
int noteState2 = 0;

int mappedIn = 0;
int mappedVal2 = 0;
int conVal1 = 0;

int THRESHOLD = 2;

int previnVal = 0;
int previnVal2 = 0;

int minN = 75;
int maxN = 76;

void setup() {
    Serial.begin(9600);            //MIDI communicates at 31250 baud
    pinMode(ledPin, OUTPUT);
}

void loop() {
  
  svalue = analogRead(sensePin);
 
  mappedIn = map(svalue, 0, 920, 0, 127);
  /*
  
  analogWrite(ledPin, svalue);
  if(abs(mappedIn - previnVal) >= THRESHOLD){ //set 0 as default
     if (abs(svalue) == 0 )
       mappedIn = 0;    
          
     midiOUT(0xB0, 103, mappedIn); //Control Change (Ch 1), Controller 7 - default control for volume.
     previnVal = mappedIn;
   
  } */
  if(mappedIn <= minN){         // start midi note send// determine ir state, set digital value
     senState = 1;
  }
  if(mappedIn >= maxN){  
     senState = 0;
  }
    
  if(senState == 0 && noteState ==1){ 
     midiOUT(0x90, 60, 127); //Note ON (CH 1), middle C, zero velocity turns note off
     noteState = 0;
     }
     
  if(senState == 1 && noteState == 0){
     midiOUT(0x90, 60, 0); //Note ON (CH 1), middle C, velocity 127
     noteState = 1;
     }
  
  /*
  
  svalue2 = analogRead(sense2Pin);
 
  mappedVal2 = map(svalue2, 0, 920, 0, 127);
  conVal1 = constrain(, 0, 127);
  
  if(abs(conVal1 - previnVal2) >= THRESHOLD){ //set 0 as default
     if (abs(svalue2) == 0 )
       conVal1 = 0;    
          
     midiOUT(0xB0, 103, conVal1); //Control Change (Ch 1), Controller 7 - default control for volume.
     previnVal2 = conVal1;
   
  } 
  if(conVal1 <= 124){         // start midi note send// determine ir state, set digital value
     senState2 = 1;
  }
  if(conVal1 >= 125){  
     senState2 = 0;
  }
    
  if(senState2 == 0 && noteState2 ==1){ 
     midiOUT(0x90, 67, 0); //Note ON (CH 1), middle C, zero velocity turns note off
     noteState2 = 0;
     }
     
  if(senState2 == 1 && noteState2 == 0){
     midiOUT(0x90, 67, 127); //Note ON (CH 1), middle C, velocity 127
     noteState2 = 1;
     }
  
  
  
*/ 
  Serial.print("svalue = ");
  Serial.print(svalue); 
  Serial.print("\t mappedIn = ");
  Serial.print(mappedIn);
  Serial.print("\t senState = ");
  Serial.println(senState);

}



void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);

}
