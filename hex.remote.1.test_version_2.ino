

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

int valStore = 0;

int block1 = 0;
int block2 = 0;
int block3 = 0;
int block4 = 0;
int block5 = 0;


int counter = 0;

int command1 = 0;

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
    if(sendVal != valStore)
      counter++;
  }


  if(buttonVal2 == HIGH){
    sendVal = 2;
    if(sendVal != valStore)
      counter++;
  }
 
   
  if(buttonVal3 == HIGH){
    sendVal = 3;
    if(sendVal != valStore)
      counter++;
  } 
  

  if(buttonVal4 == HIGH){
    sendVal = 4;
    if(sendVal != valStore)
      counter++;
  }
  
  valStore = sendVal;
  
  if(buttonVal1 == LOW && buttonVal2 == LOW && buttonVal3 == LOW && buttonVal4 == LOW){
    sendVal = 0;
  }      

  delay(30);

  if(counter == 1 && sendVal != 0){
    block1 = valStore;
  }
  
  if(counter == 2 && sendVal != 0){
    block2 = valStore;
  }

  if(counter == 3 && sendVal != 0){
    block3 = valStore;
  }

  if(counter == 4 && sendVal != 0){
    block4 = valStore;
  }

  if(counter == 5 && sendVal != 0){
    block5 = valStore;
    counter = 0;
  }
  
  if(counter != 0 && sendVal == 1 && block1 != 1){
    counter = 0; 
  }
  
  delay(30);

  if(block1 == 1 && block2 == 2 && block3 == 3 && block4 == 4 && block5 == 4){
    command1 = 1234; 
  }
  else{
    command1 = 0;
    
  }
 Serial.print("sendVal  ");
 Serial.print( sendVal);
 Serial.print("\t counter  ");
 Serial.print( counter);
 Serial.print("\t block1  ");
 Serial.print( block1);
 Serial.print("\t block2  ");
 Serial.print( block2);
 Serial.print("\t block3  ");
 Serial.print( block3);
 Serial.print("\t block4  ");
 Serial.print( block4);
 Serial.print("\t block5  ");
 Serial.print( block5);
 Serial.print("\t command1  ");
 Serial.println( command1);
 
 
 itoa(sendVal, charOn1, 10);

 vw_send((uint8_t *)charOn1, strlen(charOn1));
 vw_wait_tx();                     // Wait until the whole message is gone



}
