// receiver.pde
//


#include <VirtualWire.h>


char charVel[5];

int fullVal = 0;


int onState = 0;
 
int elPin1 = 2;
int elPin2 = 3;
int elPin3 = 4;
int elPin4 = 5;

int del = 0;

void setup()
{
    Serial.begin(9600);	
    pinMode(elPin1, OUTPUT);
    pinMode(elPin2, OUTPUT);
    pinMode(elPin3, OUTPUT);
    pinMode(elPin4, OUTPUT);
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
    }  
    if (fullVal == 10127){
       
       digitalWrite(elPin1, HIGH);
       digitalWrite(elPin2, HIGH);
       digitalWrite(elPin3, HIGH);
       digitalWrite(elPin4, HIGH);
       
       del = random(300,800 );
       delay(del);
        
       digitalWrite(elPin2, LOW);
       digitalWrite(elPin3, LOW);
       
       del = random(30, 500);
       delay(del);
       
       digitalWrite(elPin2, HIGH);
       digitalWrite(elPin4, LOW);
       
       del = random(60, 600);
       delay(del);
       
       digitalWrite(elPin3, HIGH);
       
       del = random(70, 800);
       delay(del);
             
       digitalWrite(elPin2, LOW);
       
       del = random(50, 600);
       delay(del);
      
       digitalWrite(elPin1, LOW);
       digitalWrite(elPin2, LOW);
       digitalWrite(elPin3, LOW);
       digitalWrite(elPin4, HIGH);
       
       del = random(60, 400);
       delay(del);
       
       digitalWrite(elPin1, HIGH);
       digitalWrite(elPin2, HIGH);
       digitalWrite(elPin3, LOW);
       digitalWrite(elPin4, LOW);
       
       del = random(20, 500);
       delay(del);
       
       digitalWrite(elPin2, LOW);
       digitalWrite(elPin3, HIGH);
       digitalWrite(elPin4, LOW);
       
       del = random(40, 570);
       delay(del);
       
       digitalWrite(elPin2, LOW);
       digitalWrite(elPin3, LOW);
       digitalWrite(elPin4, LOW);
       
       del = random(120, 900);
       delay(del);
       
       digitalWrite(elPin2, HIGH);
       digitalWrite(elPin3, LOW);
       digitalWrite(elPin4, HIGH);
       
       //onState = 0;
           
                   
    }
        
    if (fullVal == 10000){
       
       digitalWrite(elPin1, LOW);
       digitalWrite(elPin2, LOW);
       digitalWrite(elPin3, LOW);
       digitalWrite(elPin4, LOW);
       //onState = 1;   
    }
       
         

    /*Serial.print("fullVal = " );                       
    Serial.print(fullVal);      
    Serial.print("\t onState = ");      
    Serial.println(onState);   */
       
    delay(50);  
}

