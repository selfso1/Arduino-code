

#include <Servo.h>

Servo Acoxa; 
Servo Afem;
Servo Atib;
Servo Bcoxa; 
Servo Bfem;
Servo Btib;
Servo Ccoxa; 
Servo Cfem;
Servo Ctib;
Servo Ecoxa; 
Servo Efem;
Servo Etib;

int AcoxaF = 90;
int AcoxaB = 0;
int BcoxaF = 90;
int BcoxaB = 0;
int CcoxaF = 90;
int CcoxaB = 0;
int EcoxaF = 180;
int EcoxaB = 90;

int AfemUp = 110;
int AfemDn = 25;
int CfemUp = 110;
int CfemDn = 25;
int EfemUp = 110;
int EfemDn = 25;

int AtibUp = 90;
int AtibDn = 120;
int CtibUp = 90;
int CtibDn = 120;
int EtibUp = 90;
int EtibDn = 120;


int delay1 = 5;
int delay2 = 500;
void setup() {
  Acoxa.attach(51);
  Afem.attach(52);
  Atib.attach(53);
  Ccoxa.attach(43);
  Cfem.attach(44);
  Ctib.attach(45);
  Ecoxa.attach(37);
  Efem.attach(38);
  Etib.attach(39);

  
  pinMode(51, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(53, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
 
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
  Cfem.write(CfemUp);
  Efem.write(EfemUp);
  
  Atib.write(AtibUp);
  Ctib.write(CtibUp);
  Etib.write(EtibUp);
  delay(delay2);
   
  Acoxa.write(AcoxaF);
  Ccoxa.write(CcoxaF);
  Ecoxa.write(EcoxaF);
  delay(delay2);
  
  Afem.write(AfemDn);
  Cfem.write(CfemDn);
  Efem.write(EfemDn);
  
  Atib.write(AtibDn);
  Ctib.write(CtibDn);
  Etib.write(EtibDn);
  delay(delay2);
  
  Acoxa.write(AcoxaB);
  Ccoxa.write(CcoxaB);
  Ecoxa.write(EcoxaB);
  delay(delay1);
  };


