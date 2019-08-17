///////////////////
///////////////////DRUM KAT 1.0


unsigned char PadNote[6] = {52,16,66,63,40,65};         // MIDI notes from 0 to 127 (Mid C = 60)

int PadCutOff[6] = {600,600,600,600,600,600};           // Minimum Analog value to cause a drum hit

int MaxPlayTime[6] = {90,45,45,90,90,90};               // Cycles before a 2nd hit is allowed

#define  midichannel	0;                              // MIDI channel from 0 to 15 (+1 in "real world")

boolean VelocityFlag  = true;                           // Velocity ON (true) or OFF (false)

int midiType = 0x90;

int switchPin = 3;
int switchVal = 0;
int bounceCheck = 0;

//*******************************************************************************************************************
// Internal Use Variables			
//*******************************************************************************************************************

boolean activePad[6] = {0,0,0,0,0,0};                   // Array of flags of pad currently playing
int PinPlayTime[6] = {0,0,0,0,0,0};                     // Counter since pad started to play

unsigned char status;

int pin = 0;     
int hitavg = 0;

//*******************************************************************************************************************
// Setup			
//*******************************************************************************************************************

void setup() 
{
  Serial.begin(9600);   // connect to the serial port 115200
  pinMode(switchPin, INPUT);
  
  switchVal = digitalRead(switchPin);     //read input value from button
  delay(10);                              //wait 10ms
  bounceCheck = digitalRead(switchPin);   //check again
  if(switchVal == bounceCheck){           //if val is the same then not a bounce
  if(switchVal == HIGH) {   //check if the input is HIGH
    PadNote[1] = 60;
    PadNote[2] = 62;
    PadNote[3] = 64;
    PadNote[4] = 65;
    PadNote[5] = 67;
    PadNote[6] = 69;
    }
  if(switchVal == LOW){
    PadNote[1] = 71;
    PadNote[2] = 72;
    PadNote[3] = 74;
    PadNote[4] = 76;
    PadNote[5] = 77;
    PadNote[6] = 79;
    } 
  }
}

//*******************************************************************************************************************
// Main Program			
//*******************************************************************************************************************

void loop() 
{
  
   
  for(int pin=0; pin < 6; pin++)
  {
    hitavg = analogRead(pin);                              // read the input pin

    if((hitavg > PadCutOff[pin]))
    {
      if((activePad[pin] == false))
      {
        if(VelocityFlag == true)
        {
          hitavg = 127 / ((1023 - PadCutOff[pin]) / (hitavg - PadCutOff[pin]));    // With full range (Too sensitive ?)
        //  hitavg = (hitavg / 8) -1 ;                                                 // Upper range
        }
        else
        {
          hitavg = 127;
        }

      //  midiOUT(midiType,PadNote[pin],hitavg); 
        PinPlayTime[pin] = 0;
        activePad[pin] = true;
      }
      else
      {
        PinPlayTime[pin] = PinPlayTime[pin] + 1;
      }
    }
    else if((activePad[pin] == true))
    {
      PinPlayTime[pin] = PinPlayTime[pin] + 1;
      
      if(PinPlayTime[pin] > MaxPlayTime[pin])
      {
        activePad[pin] = false;
     //   midiOUT(midiType,PadNote[pin],0); 
      }
    }
  } 
  
  Serial.print("hitavg= ");
  Serial.println(hitavg);
  
}


//*******************************************************************************************************************
// Transmit MIDI Message			
//*******************************************************************************************************************
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}


