// receiver.pde
//


#include <VirtualWire.h>

const int ledPin = 13;

char charVel[5];

int fullVal = 0;

int vel = 0;

int note = 0;

int onVal = 1;
 
int relay1 = 7;
int relay2 = 8;
int relay3 = 4;











;

int del = 0;

void setup()
{
    Serial.begin(31250);	
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
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
       digitalWrite(ledPin, HIGH);        
                   
    }
        
    else  {
       
       digitalWrite(ledPin, LOW);    
    }
    
    //relay1
    if (vel == 127 && note == 60){
    
       digitalWrite(relay1, HIGH);
    }   
       
    else  {
        
       digitalWrite(relay1, LOW);
       
    }
    //relay2
    if (vel == 127 && note == 62){
    
       digitalWrite(relay2, HIGH);
    }   
       
    else  {
        
       digitalWrite(relay2, LOW);
       
    }
    //relay3
    if (vel == 127 && note == 64){
    
       digitalWrite(relay3, HIGH);
    }   
       
    else  {
        
       digitalWrite(relay3, LOW);
       
    }
    //crazy input
   /* if (vel == 127 && note == 69){
        
       
       
       
       onVal = random(HIGH, LOW);
       del = random(50, 3000);
       
       digitalWrite(relay1, onVal);
       
       onVal = random(1, 2);
       digitalWrite(relay2, onVal);
       
       delay(del);
       
       onVal = random(HIGH, LOW);
       del = random(50, 3000);
       
       digitalWrite(relay1, onVal);
       
       del = random(50, 3000);
       delay(del);
       
       onVal = random(HIGH, LOW);
       digitalWrite(relay2, onVal);
       
       delay(del);
  

   }   */
       

    /*Serial.print("fullVal = " );                       
    Serial.print(fullVal);      
    Serial.print("\t note = ");      
    Serial.print(note); 
    Serial.print("\t vel = ");      
    Serial.println(vel);  
    delay(1000);  */
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);  
}  

