// receiver.pde
//


#include <VirtualWire.h>




int servoPin = 9;

char charVel[5];

int fullVal = 0;

int vel = 0;

int note = 0;

int onVal = 1;
 
int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
int relay5 = 6;
int relay6 = 7;

int pos = 0;

int del = 0;

void setup()
{
    Serial.begin(31250);	
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    pinMode(relay5, OUTPUT);
    pinMode(relay6, OUTPUT);
    
  
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
         
                          
    }
      
    if(fullVal == 10127 || fullVal == 12127 || fullVal == 14127 || fullVal == 15127 || fullVal == 17127 || fullVal == 19127){
     
       digitalWrite(servoPin, HIGH);
    }
    
    else {
       
       digitalWrite(servoPin, LOW);
      
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
    
   //relay4 
    if (vel == 127 && note == 65){
    
       digitalWrite(relay4, HIGH);
    }   
       
    else  {
        
       digitalWrite(relay4, LOW);
       
    }
    //relay5
    if (vel == 127 && note == 67){
    
       digitalWrite(relay5, HIGH);
    }   
       
    else  {
        
       digitalWrite(relay5, LOW);
       
    }
    //relay6
    if (vel == 127 && note == 69){
    
       digitalWrite(relay6, HIGH);
    }   
       
    else  {
        
       digitalWrite(relay6, LOW);
       
    }
    Serial.print("fullVal = " );                       
    Serial.print(fullVal);      
    Serial.print("\t note = ");      
    Serial.print(note); 
    Serial.print("\t vel = ");      
    Serial.println(vel);  
    delay(10);  
}

