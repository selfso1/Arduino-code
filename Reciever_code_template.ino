// receiver.pde
//


#include <VirtualWire.h>



char charVel[5];

int fullVal = 0;


void setup()
{
    Serial.begin(31250);	
   
    
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
         
     
              
                   

