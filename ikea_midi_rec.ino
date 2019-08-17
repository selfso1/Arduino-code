// receiver.pde
//


#include <VirtualWire.h>



char charVel[5];

int fullVal = 0;

int vel = 0;

int note = 0;

int onVal = 1;
 
int ledPin = 7;

int del = 0;

void setup()
{
    Serial.begin(9600);	
   
    pinMode(ledPin, OUTPUT);
    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) {// Non-blocking
        
       int i;
     
       for (i = 0; i < buflen; i++){
        
         charVel[i] = char(buf[i]);
         
         charVel[buflen] = '\0';
       }  
      
       fullVal = atoi(charVel);
         
       note = (fullVal/1000+50);
                  
       vel = (fullVal-(note-50)*1000); 
         
       midiOUT(0x90, note, vel);
              
       delay(5);            
    }
        
     
    if (fullVal == 10127 || fullVal == 12127 || fullVal == 14127 || fullVal == 15127 || fullVal == 17127 || fullVal == 19127){
       
       digitalWrite(ledPin, HIGH);
       delay(200);
       digitalWrite(ledPin, LOW);
       delay(200);
  
    }
    
    else {
      
       digitalWrite(ledPin, LOW);
       
    }    
    Serial.print("fullVal = " );                       
    Serial.print(fullVal);      
    Serial.print("\t note = ");      
    Serial.print(note); 
    Serial.print("\t vel = ");      
    Serial.println(vel);  
    delay(1000);  
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}

