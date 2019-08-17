//force sensor/ dual joystick midi controller sketch
// by ryanfinnigan




int THRESHOLD = 2;

int previnVal = 0;
int previnVal2 = 0;
//joystick 1
int LRPin = 1;    // select the input pin for the l/r potentiometer
int UDPin = 0;    // select the input pin for the u/d potentiometer

int UDVal = 0;  // variable to store the value coming from the U/D pot
int LRVal = 0;  // variable to store the value coming from the L/R pot

int mappUD = 0;
int mappLR = 0;

int prevUDVal = 0;
int prevLRVal = 0;
//joystick2
int LR2Pin = 3;    // select the input pin for the l/r potentiometer
int UD2Pin = 2;    // select the input pin for the u/d potentiometer

int UDVal2 = 0;  // variable to store the value coming from the U/D pot
int LRVal2 = 0;  // variable to store the value coming from the L/R pot

int mappUD2 = 0;
int mappLR2 = 0;

int prevUDVal2 = 0;
int prevLRVal2 = 0;





void setup() {
    Serial.begin(31250);            //MIDI communicates at 31250 baud
 
}

void loop() {

   //joystick 1

  UDVal = analogRead(UDPin);  // read the value from the sensor:  
  
  mappUD = map(UDVal, 40, 988, 0, 127);  //map value to 0-127
  
  if(abs(mappUD - prevUDVal) >= THRESHOLD){
      midiOUT(0xB0, 13, mappUD);
      prevUDVal = mappUD;
 
  } 
  LRVal = analogRead(LRPin);  // read the value from the sensor:  
  
  mappLR = map(LRVal, 60, 1023, 0, 127);  //map value to 0-127
  
  if(abs(mappLR - prevLRVal) >= THRESHOLD){
      midiOUT(0xB0, 14, mappLR);
      prevLRVal = mappLR;
    
  }
  //joystick 2
  
  UDVal2 = analogRead(UD2Pin);  // read the value from the sensor:  
  
  mappUD2 = map(UDVal2, 40, 988, 0, 127);  //map value to 0-127
  
  if(abs(mappUD2 - prevUDVal2) >= THRESHOLD){
      midiOUT(0xB0, 15, mappUD2);
      prevUDVal2 = mappUD2;
 
  } 
  LRVal2 = analogRead(LR2Pin);  // read the value from the sensor:  
  
  mappLR2= map(LRVal2, 60, 1023, 0, 127);  //map value to 0-127
  
  if(abs(mappLR2 - prevLRVal2) >= THRESHOLD){
      midiOUT(0xB0, 16, mappLR2);
      prevLRVal2 = mappLR2;
    
  }



}



void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);

}
