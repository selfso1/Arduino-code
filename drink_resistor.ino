/*
drink variable resistor
 
 */

int DrinkPin = 0;    // select the input pin for the drink resistor
//int UDPin = 2;    // select the input pin for the u/d potentiometer

int DrinkVal = 0;  // variable to store the value coming from the drink resistor
//int LRVal = 0;  // variable to store the value coming from the L/R pot

int mappDrink = 0;
//int mappLR = 0;

int prevDrinkVal = 0;
//nt prevLRVal = 0;

int mappNote = 0;
int velocMapp = 0;
int noteState = 0;



void setup() {
  
  Serial.begin(31250); // set midi baud rate  
}

void loop() {
 

  DrinkVal = analogRead(DrinkPin);     //read input value from drink resistor
                              
  mappDrink = map(DrinkVal, 0, 1023, 0, 127);  //map value to 0-127
  mappDrink = constrain(mappDrink, 0, 127);
  
  if(mappDrink >= 116){
    velocMapp = 0;
    noteState = 0;
  }
   
  if(mappDrink <= 116){
    velocMapp = 127;
  
  }
  
  
  if(mappDrink >= 113 && mappDrink <= 115)
    mappNote = 60;
  if(mappDrink >= 109 && mappDrink <= 112)
    mappNote = 62;  
  if(mappDrink >= 105 && mappDrink <= 108)
    mappNote = 64;
  if(mappDrink >= 99 && mappDrink <= 104)
    mappNote = 65;  
  if(mappDrink >= 90 && mappDrink <= 98)
    mappNote = 67;    
  if(mappDrink >= 57 && mappDrink <= 88)
    mappNote = 69;   
        
    if(noteState == 0)
      midiOUT(0x90, mappNote, velocMapp); //cc chnge, cc83, on
      noteState = 1;
    
  
}
    
    
    
 /* LRVal = analogRead(LRPin);  // read the value from the sensor:  
  
  mappLR = map(LRVal, 60, 1023, 0, 127);  //map value to 0-127
  
  if(abs(mappLR - prevLRVal) >= THRESHOLD){
      midiOUT(0xB0, 14, mappLR);
      prevLRVal = mappLR; 
 */
 
  
void midiOUT(char command, char value1, char value2) {
  Serial.print(command, BYTE);
  Serial.print(value1, BYTE);
  Serial.print(value2, BYTE);
  
}  
