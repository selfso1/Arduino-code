#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX


byte resetMIDI = 4; //Tied to VS1053 Reset line
byte ledPin = 13; //MIDI traffic inidicator
int  instrument = 41;  //change for different instrument. 1-127

int  buttonPin1 = 8;

int  buttonVal1 = 0;

int  buttonState1 = 0;

int  bounceCheck1 = 0;

int  UDPin = 0;
int  LRPin = 1;

int  LRVal = 0;
int  UDVal = 0;

int  mappUD = 0;
int  mappLR = 0;
int  prevUDVal = 0;
int  prevLRVal = 0;
byte note1 = 60; //The MIDI note value to be played

int  THRESHOLD = 2;

void setup() {
  Serial.begin(57600);

  //Setup soft serial for MIDI control
  mySerial.begin(31250);

  //Reset the VS1053
  pinMode(resetMIDI, OUTPUT);
  pinMode(buttonPin1, INPUT);
  digitalWrite(resetMIDI, LOW);
  delay(100);
  digitalWrite(resetMIDI, HIGH);
  delay(100);
  talkMIDI(0xB0, 0x07, 127); //0xB0 is channel message, set channel volume to near max (127)
  talkMIDI(0xB0, 0, 0x00);
   //Set instrument number. 0xC0 is a 1 data byte command
 
}

void loop() {  
  talkMIDI(0xC0, instrument, 0);
  buttonVal1 = digitalRead(buttonPin1);     //read input value from button
  delay(10);                              //wait 10ms
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
    
 
  UDVal = analogRead(UDPin);  // read the value from the sensor:  
  
  mappUD = map(UDVal, 0, 1023, 0, 127);  //map value to 0-127
  
  if(abs(mappUD - prevUDVal) >= THRESHOLD){
      instrument = mappUD;
      prevUDVal = mappUD;
 
  } 
  LRVal = analogRead(LRPin);  // read the value from the sensor:  
  
  mappLR = map(LRVal, 0, 1023, 0, 127);  //map value to 0-127
  
  if(abs(mappLR - prevLRVal) >= THRESHOLD){

      prevLRVal = mappLR; 
 
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
  digitalWrite(ledPin, HIGH);
  mySerial.write(cmd);
  mySerial.write(data1);

  //Some commands only have one data byte. All cmds less than 0xBn have 2 data bytes 
  //(sort of: http://253.ccarh.org/handout/midiprotocol/)
  if( (cmd & 0xF0) <= 0xB0)
    mySerial.write(data2);

  digitalWrite(ledPin, LOW);
}   
