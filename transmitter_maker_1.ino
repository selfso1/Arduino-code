

#include <VirtualWire.h>

const int buttonPin1 = 6;
const int buttonPin2 = 7;
const int buttonPin3 = 8;
const int buttonPin4 = 9;
const int buttonPin5 = 11;
const int buttonPin6 = 13;



int buttonState1 = 0; 
int buttonState2 = 0;
int buttonState3 = 0; 
int buttonState4 = 0;
int buttonState5 = 0; 
int buttonState6 = 0;

int buttonVal1 = 0;
int buttonVal2 = 0;
int buttonVal3 = 0;
int buttonVal4 = 0;
int buttonVal5 = 0;
int buttonVal6 = 0;

int bounceCheck1 = 0;
int bounceCheck2 = 0;
int bounceCheck3 = 0;
int bounceCheck4 = 0;
int bounceCheck5 = 0;
int bounceCheck6 = 0;
 
const int velSendon1 = 10127; 
const int velSendon2 = 12127;
const int velSendon3 = 14127; 
const int velSendon4 = 15127;
const int velSendon5 = 17127; 
const int velSendon6 = 19127;

const int velSendoff1 = 10000;
const int velSendoff2 = 12000;
const int velSendoff3 = 14000;
const int velSendoff4 = 15000;
const int velSendoff5 = 17000;
const int velSendoff6 = 19000;

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
    
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT); 
    pinMode(buttonPin3, INPUT);
    pinMode(buttonPin4, INPUT); 
    pinMode(buttonPin5, INPUT);
    pinMode(buttonPin6, INPUT);
   
      
    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
}

void loop()
{
  
 //1//
 /* buttonVal1 = digitalRead(buttonPin1);
  delay(9); 
  //wait 10ms
  bounceCheck1 = digitalRead(buttonPin1);      
  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
    if(buttonVal1 == LOW && buttonState1 == 0) {   //check if the input is HIGH
               
      itoa(velSendon1,charOn1,10); 
      
      vw_send((uint8_t *)charOn1, strlen(charOn1));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState1 = 1;
      
     
      delay(50);
    }
    if(buttonVal1 == HIGH && buttonState1 == 1){
      
      itoa(velSendoff1,charOff1,10);
      
      vw_send((uint8_t *)charOff1, strlen(charOff1));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState1 = 0;    
       
     
      delay(50);   
   }
  } 
 */
  //2//
  buttonVal2 = digitalRead(buttonPin2);
  delay(9); 
  //wait 10ms
  bounceCheck2 = digitalRead(buttonPin2);      
  if(buttonVal2 == bounceCheck2){           //if val is the same then not a bounce
    if(buttonVal2 == LOW && buttonState2 == 0) {   //check if the input is HIGH
               
      itoa(velSendon2,charOn2,10); 
      
      vw_send((uint8_t *)charOn2, strlen(charOn2));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState2 = 1;
      
      
      delay(50);
    }
    if(buttonVal2 == HIGH && buttonState2 == 1){
      
      itoa(velSendoff2,charOff2,10);
      
      vw_send((uint8_t *)charOff2, strlen(charOff2));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState2 = 0;    
      
      
      delay(50);   
   }
  } 
  
  //3//
  buttonVal3 = digitalRead(buttonPin3);
  delay(9); 
  //wait 10ms
  bounceCheck3 = digitalRead(buttonPin3);      
  if(buttonVal3 == bounceCheck3){           //if val is the same then not a bounce
    if(buttonVal3 == LOW && buttonState3 == 0) {   //check if the input is HIGH
               
      itoa(velSendon3,charOn3,10); 
      
      vw_send((uint8_t *)charOn3, strlen(charOn3));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState3 = 1;
      
      
      delay(50);
    }
    if(buttonVal3 == HIGH && buttonState3 == 1){
      
      itoa(velSendoff3,charOff3,10);
      
      vw_send((uint8_t *)charOff3, strlen(charOff3));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState3 = 0;    
       
  
      delay(50);   
   }
  } 
 
  //4//
  buttonVal4 = digitalRead(buttonPin4);
  delay(9); 
  //wait 10ms
  bounceCheck4 = digitalRead(buttonPin4);      
  if(buttonVal4 == bounceCheck4){           //if val is the same then not a bounce
    if(buttonVal4 == LOW && buttonState4 == 0) {   //check if the input is HIGH
               
      itoa(velSendon4,charOn4,10); 
      
      vw_send((uint8_t *)charOn4, strlen(charOn4));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState4 = 1;
      
     
      delay(50);
    }
    if(buttonVal4 == HIGH && buttonState4 == 1){
      
      itoa(velSendoff4,charOff4,10);
      
      vw_send((uint8_t *)charOff4, strlen(charOff4));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState4 = 0;    
      
    
      delay(50);   
   }
  } 
  
  //5//
  buttonVal5 = digitalRead(buttonPin5);
  delay(9); 
  //wait 10ms
  bounceCheck5 = digitalRead(buttonPin5);      
  if(buttonVal5 == bounceCheck5){           //if val is the same then not a bounce
    if(buttonVal5 == LOW && buttonState5 == 0) {   //check if the input is HIGH
               
      itoa(velSendon5,charOn5,10); 
      
      vw_send((uint8_t *)charOn5, strlen(charOn5));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState5 = 1;
      
     
      delay(50);
    }
    if(buttonVal5 == HIGH && buttonState5 == 1){
      
      itoa(velSendoff5,charOff5,10);
      
      vw_send((uint8_t *)charOff5, strlen(charOff5));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState5 = 0;    

      delay(50);   
   }
  } 
 
  //6//
  buttonVal6 = digitalRead(buttonPin6);
  delay(9); 
  //wait 10ms
  bounceCheck6 = digitalRead(buttonPin6);      
  if(buttonVal6 == bounceCheck6){           //if val is the same then not a bounce
    if(buttonVal6 == LOW && buttonState6 == 0) {   //check if the input is HIGH
               
      itoa(velSendon6,charOn6,10); 
      
      vw_send((uint8_t *)charOn6, strlen(charOn6));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState6 = 1;
      
     
      delay(50);
    }
    if(buttonVal6 == HIGH && buttonState6 == 1){
      
      itoa(velSendoff6,charOff6,10);
      
      vw_send((uint8_t *)charOff6, strlen(charOff6));
      vw_wait_tx();                     // Wait until the whole message is gone
      buttonState6 = 0;    
      

      delay(50);   
   }
  } 
   
   
   /*
    Serial.print("charOn =" );
    Serial.print(charOn2); 
    Serial.print("\t charOff =" );
    Serial.print(charOff2);
    Serial.print("\t velSendon =" );
    Serial.print(velSendon2);
    Serial.print("\t velSendoff =" );
    Serial.println(velSendoff2);
    delay(1000);  */
}
