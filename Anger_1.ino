#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

byte resetMIDI = 4; //Tied to VS1053 Reset line

int  instrument = 40;  //change for different instrument. 1-127

int  buttonPin1 = 5;
int  buttonPin2 = 6;
int  buttonPin3 = 7;
int  buttonPin4 = 8;
int  buttonPin5 = 9;
int  buttonPin6 = 10;
int  buttonPin7 = 11;
int  buttonPin8 = 12;
int  buttonPin9 = 2;

int  buttonVal1 = 0;
int  buttonVal2 = 0;
int  buttonVal3 = 0;
int  buttonVal4 = 0;
int  buttonVal5 = 0;
int  buttonVal6 = 0;
int  buttonVal7 = 0;
int  buttonVal8 = 0;
int  buttonVal9 = 0;


int  buttonState1 = 0;
int  buttonState2 = 0;
int  buttonState3 = 0;
int  buttonState4 = 0;
int  buttonState5 = 0;
int  buttonState6 = 0;
int  buttonState7 = 0;
int  buttonState8 = 0;
int  buttonState9 = 0;

int  bounceCheck1 = 0;
int  bounceCheck2 = 0;
int  bounceCheck3 = 0;
int  bounceCheck4 = 0;
int  bounceCheck5 = 0;
int  bounceCheck6 = 0;
int  bounceCheck7 = 0;
int  bounceCheck8 = 0;
int  bounceCheck9 = 0;



byte note1 = 57; //The MIDI note value to be played
byte note2 = 60;
byte note3 = 62;
byte note4 = 64;
byte note5 = 67;
byte note6 = 69;
byte note7 = 72;
byte note8 = 74;
byte note9 = 76;

int  dy = 10;  //bounce check delay time

void setup() {
  Serial.begin(57600);

  //Setup soft serial for MIDI control
  mySerial.begin(31250);

 //Reset the VS1053
  pinMode(resetMIDI, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(buttonPin6, INPUT);
  pinMode(buttonPin7, INPUT);
  pinMode(buttonPin8, INPUT);
  pinMode(buttonPin9, INPUT);
  digitalWrite(resetMIDI, LOW);
  delay(100);
  digitalWrite(resetMIDI, HIGH);
  delay(100);
  talkMIDI(0xB0, 0x07, 127); //0xB0 is channel message, set channel volume to near max (127)
  talkMIDI(0xB0, 0, 0x00);
  talkMIDI(0xC0, instrument, 0); //Set instrument number. 0xC0 is a 1 data byte command
 
}

void loop() {  
  
  //note1
  buttonVal1 = digitalRead(buttonPin1);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck1 = digitalRead(buttonPin1);   //check again
  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
    if (buttonVal1 == HIGH && buttonState1 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note1, 10);
      buttonState1 = 1;
    }
    if(buttonVal1 == LOW && buttonState1 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note1, 127);
      buttonState1 = 0;
    }
  }   
  
  //note 2
  buttonVal2 = digitalRead(buttonPin2);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck2 = digitalRead(buttonPin2);   //check again
  if(buttonVal2 == bounceCheck2){           //if val is the same then not a bounce
    if (buttonVal2 == HIGH && buttonState2 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note2, 10);
      buttonState2 = 1;
    }
    if(buttonVal2 == LOW && buttonState2 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note2, 127);
      buttonState2 = 0;
    }
  }   
  
  //note 3
  buttonVal3 = digitalRead(buttonPin3);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck3 = digitalRead(buttonPin3);   //check again
  if(buttonVal3 == bounceCheck3){           //if val is the same then not a bounce
    if (buttonVal3 == HIGH && buttonState3 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note3, 10);
      buttonState3 = 1;
    }
    if(buttonVal3 == LOW && buttonState3 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note3, 127);
      buttonState3 = 0;
    }
  }   
  
  //note 4
  buttonVal4 = digitalRead(buttonPin4);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck4 = digitalRead(buttonPin4);   //check again
  if(buttonVal4 == bounceCheck4){           //if val is the same then not a bounce
    if (buttonVal4 == HIGH && buttonState4 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note4, 10);
      buttonState4 = 1;
    }
    if(buttonVal4 == LOW && buttonState4 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note4, 127);
      buttonState4 = 0;
    }
  }   
  
  //note 5
  buttonVal5 = digitalRead(buttonPin5);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck5 = digitalRead(buttonPin5);   //check again
  if(buttonVal5 == bounceCheck5){           //if val is the same then not a bounce
    if (buttonVal5 == HIGH && buttonState5 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note5, 10);
      buttonState5 = 1;
    }
    if(buttonVal5 == LOW && buttonState5 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note5, 127);
      buttonState5 = 0;
    }
  }   
  
  //note 6
  buttonVal6 = digitalRead(buttonPin6);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck6 = digitalRead(buttonPin6);   //check again
  if(buttonVal6 == bounceCheck6){           //if val is the same then not a bounce
    if (buttonVal6 == HIGH && buttonState6 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note6, 10);
      buttonState6 = 1;
    }
    if(buttonVal6 == LOW && buttonState6 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note6, 127);
      buttonState6 = 0;
    }
  }   
  
  //note 7
  buttonVal7 = digitalRead(buttonPin7);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck7 = digitalRead(buttonPin7);   //check again
  if(buttonVal7 == bounceCheck7){           //if val is the same then not a bounce
    if (buttonVal7 == HIGH && buttonState7 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note7, 10);
      buttonState7 = 1;
    }
    if(buttonVal7 == LOW && buttonState7 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note7, 127);
      buttonState7 = 0;
    }
  } 

  
  //note 8
  buttonVal8 = digitalRead(buttonPin8);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck8 = digitalRead(buttonPin8);   //check again
  if(buttonVal8 == bounceCheck8){           //if val is the same then not a bounce
    if (buttonVal8 == HIGH && buttonState8 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note8, 10);
      buttonState8 = 1;
    }
    if(buttonVal8 == LOW && buttonState8 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note8, 127);
      buttonState8 = 0;
    }
  }   


  //note 9
  buttonVal9 = digitalRead(buttonPin9);     //read input value from button
  delay(dy);                              //wait 10ms
  bounceCheck9 = digitalRead(buttonPin9);   //check again
  if(buttonVal9 == bounceCheck9){           //if val is the same then not a bounce
    if (buttonVal9 == HIGH && buttonState9 == 0) {   //check if the input is HIGH
        
     //Note on channel 1 (0x90), some note value (note), middle velocity (0x45):
      noteOff(0, note9, 10);
      buttonState9 = 1;
    }
    if(buttonVal9 == LOW && buttonState9 == 1){
      //Turn off the note with a given off/release velocity
      noteOn(0, note9, 127);
      buttonState9 = 0;
    }
  }     
}    
 //Send a MIDI note-on message.  Like pressing a piano key
//channel ranges from 0-15
void noteOn(byte channel, byte note, byte attack_velocity) {
  talkMIDI( (0x90 | channel), note, attack_velocity);
}

//Send a MIDI note-off message.  Like releasing a piano key
void noteOff(byte channel, byte note, byte release_velocity) {
  talkMIDI( (0x80 | channel), note, release_velocity);
}

//Plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that data values are less than 127
void talkMIDI(byte cmd, byte data1, byte data2) {
  
  mySerial.write(cmd);
  mySerial.write(data1);

  //Some commands only have one data byte. All cmds less than 0xBn have 2 data bytes 
  //(sort of: http://253.ccarh.org/handout/midiprotocol/)
  if( (cmd & 0xF0) <= 0xB0)
    mySerial.write(data2);

  
}   
