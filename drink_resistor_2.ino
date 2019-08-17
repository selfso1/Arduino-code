/*
drink variable resistor
 
 */

int DrinkPin = 0;    // select the input pin for the drink resistor


int DrinkVal = 0;  // variable to store the value coming from the drink resistor


int mappDrink = 0;
int prevVal = 0;


int noteStateC = 0;
int noteStateD = 0;
int noteStateE = 0;
int noteStateF = 0;
int noteStateG = 0;
int noteStateA = 0;
int THRESHOLD = 4;

int high1 = 0;
int low1 = 0;

int high2 = 0;
int low2 = 0;

int high3 = 0;
int low3 = 0;

int high4 = 0;
int low4 = 0;

int high5 = 0;
int low5 = 0;

int high6 = 0;
int low6 = 0;

void setup() {
  
  Serial.begin(31250); // set midi baud rate  
}

void loop() {
 

  DrinkVal = analogRead(DrinkPin);     //read input value from drink resistor
                              
  mappDrink = map(DrinkVal, 0, 1023, 0, 255);  //map value to 0-127
  mappDrink = constrain(mappDrink, 0, 255);
  
  //if(DrinkVal >= 1020){
    //velocMapp = 0;
   
  //}
   
  //if(DrinkVal <= 1019){
    //velocMapp = 127;
  
  //}
if(abs(mappDrink - prevVal) >= THRESHOLD){ 
  
  
  // note c
  if(noteStateC == 0 && (mappDrink >= low1 && mappDrink <= high1)){
    midiOUT(0x90, 60, 127); 
    noteStateC = 1;
  }
  if(noteStateC == 1 && (mappDrink <= low1 || mappDrink >= high1)){
    midiOUT(0x90, 60, 0);
    noteStateC = 0;
  }  
  //note d
  if(noteStateD == 0 && (mappDrink >= low2 && mappDrink <= high2)){
    midiOUT(0x90, 62, 127); 
    noteStateD = 1;
  }
  if(noteStateD == 1 && (mappDrink <= low2 || mappDrink >= high2)){
    midiOUT(0x90, 62, 0);
    noteStateD = 0;
  }
  //note e
  if(noteStateE == 0 && (mappDrink >= low3 && mappDrink <= high3)){
    midiOUT(0x90, 64, 127); 
    noteStateE = 1;
  }
  if(noteStateE == 1 && (mappDrink <= low3 || mappDrink >= high3)){
    midiOUT(0x90, 64, 0);
    noteStateE = 0;
  }  
  //note f
  if(noteStateF == 0 && (mappDrink >= low4 && mappDrink <= high4)){
    midiOUT(0x90, 65, 127); 
    noteStateF = 1;
  }
  if(noteStateF == 1 && (mappDrink <= low4 || mappDrink >= high4)){
    midiOUT(0x90, 65, 0);
    noteStateF = 0;
  }  
  //note g
  if(noteStateG == 0 && (mappDrink >= low5 && mappDrink <= high5)){
    midiOUT(0x90, 67, 127); 
    noteStateG = 1;
  }
  if(noteStateG == 1 && (mappDrink <= low5 || mappDrink >= high5)){
    midiOUT(0x90, 67, 0);
    noteStateG = 0;
  }  
  //note a
  if(noteStateA == 0 && (mappDrink >= low6 && mappDrink <= high6)){
    midiOUT(0x90, 69, 127); 
    noteStateA = 1;
  }
  if(noteStateA == 1 && (mappDrink <= low6 || mappDrink >= high6)){
    midiOUT(0x90, 69, 0);
    noteStateA = 0;
  }  
  prevVal = mappDrink;

}
    
}   
    

  
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
  
}  
