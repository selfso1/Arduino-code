

#include <VirtualWire.h>


char charOn1[5];
char charOn2[5];
char charOn3[5];
char charOn4[5];
char charOn5[5];
char charOn6[5];

char charOff1[5];
char charOff2[5];
char charOff3[5];
char charOff4[5];
char charOff5[5];
char charOff6[5];


void setup()
{
    Serial.begin(9600);	  // Debugging only
    
   
      
    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
}

void loop()
{
              
      itoa(---VARIBLE HERE---,charOn1,10); 
      
      vw_send((uint8_t *)charOn1, strlen(charOn1));
      vw_wait_tx();                     // Wait until the whole message is gone
 
 


