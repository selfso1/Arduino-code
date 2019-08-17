

#include <VirtualWire.h>


char charOn1[5];


char charOff1[5];


int buttonPin1 = 3;
int buttonPin2 = 4;
int buttonPin3 = 5;
int buttonPin4 = 6;

int buttonVal1 = 0;
int buttonVal2 = 0;
int buttonVal3 = 0;
int buttonVal4 = 0;

int sendVal = 0;

void setup()
{
  Serial.begin(9600);	  // Debugging only

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);


  // Initialise the IO and ISR
  vw_set_ptt_inverted(true); // Required for DR3100
  vw_setup(2000);	 // Bits per sec
}

void loop()
{

  buttonVal1 = digitalRead(buttonPin1);
  buttonVal2 = digitalRead(buttonPin2);
  buttonVal3 = digitalRead(buttonPin3);
  buttonVal4 = digitalRead(buttonPin4);
  
  if(buttonVal1 == HIGH){
    sendVal = 1;
  }


  if(buttonVal2 == HIGH){
    sendVal = 2;
  }
 
   
  if(buttonVal3 == HIGH){
    sendVal = 3;
  } 
  

  if(buttonVal4 == HIGH){
    sendVal = 4;
  }
  
  if(buttonVal1 == LOW && buttonVal2 == LOW && buttonVal3 == LOW && buttonVal4 == LOW){
    sendVal = 0;
  }      
  
 delay(100);

 Serial.print("sendVal");
 Serial.println(sendVal);

 
 itoa(sendVal, charOn1, 10);

 vw_send((uint8_t *)charOn1, strlen(charOn1));
 vw_wait_tx();                     // Wait until the whole message is gone



}
