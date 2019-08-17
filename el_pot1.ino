
int elPin1 = 2;
int elPin2 = 3;
int elPin3 = 4;
int elPin4 = 5;
int elPin5 = 6; 

int potPin1 = 0;
int potVal1 = 0;
int mapVal1 = 0;

void setup() {                
 
  pinMode(elPin1, OUTPUT);  
  pinMode(elPin2, OUTPUT);  
  pinMode(elPin3, OUTPUT);
  pinMode(elPin4, OUTPUT);  
  pinMode(elPin5, OUTPUT);
}

void loop() {
  
  potVal1 = analogRead(potPin1);
  mapVal1= map(potVal1, 0, 1023, 0, 250);
  
  if (mapVal1 >= 0 && mapVal1 <= 50){
     digitalWrite(elPin1, HIGH);  
  }
  else {
     digitalWrite(elPin1, LOW); 
  } 
  
  if (mapVal1 >= 50 && mapVal1 <= 100){
     digitalWrite(elPin2, HIGH);  
  }
  else {
     digitalWrite(elPin2, LOW); 
  } 
  if (mapVal1 >= 100 && mapVal1 <= 150){
     digitalWrite(elPin3, HIGH);  
  }
  else {
     digitalWrite(elPin3, LOW); 
  } 
  if (mapVal1 >= 150 && mapVal1 <= 200){
     digitalWrite(elPin4, HIGH);  
  }
  else {
     digitalWrite(elPin4, LOW); 
  } 
  
  if (mapVal1 >= 200 && mapVal1 <= 250){
     digitalWrite(elPin5, HIGH);  
  }
  else {
     digitalWrite(elPin5, LOW); 
  } 

   
}
