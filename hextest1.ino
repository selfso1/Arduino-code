

#include <Servo.h>

Servo Acoxa; 
Servo Afem;
Servo Atib;


int AcoxaF = 90;
int AcoxaB = 0;


int AfemUp = 110;
int AfemDn = 25;

int AtibUp = 90;
int AtibDn = 120;

int coxa = 51;
int fem = 52;
int tib = 53;


int delay1 = 5;
int delay2 = 500;

void setup() {
  Acoxa.attach(coxa);
  Afem.attach(fem);
  Atib.attach(tib);
 


  pinMode(coxa, OUTPUT);
  pinMode(fem, OUTPUT);
  pinMode(tib, OUTPUT);
 
}

void loop() {
   for (int i=40; i<=180; i++){  
     walkFwd();
     delay(2);
}
}
void walkFwd(){
  
  frRightfwd();
  delay(delay2);
  
}
void frRightfwd(){   
  
  Afem.write(AfemUp);
  
  Atib.write(AtibUp);
 
  delay(delay2);
   
  Acoxa.write(AcoxaF);
 
  delay(delay2);
  
  Afem.write(AfemDn);
 
  Atib.write(AtibDn);
 
  delay(delay2);
  Acoxa.write(AcoxaB);
  
  delay(delay1);
  }


