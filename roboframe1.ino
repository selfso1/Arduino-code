
int relay = 10;
int buttonPin = 12;     // the number of the pushbutton pin
int ledPin =  11;      // the number of the LED pin

int red1 = 5;
int red2 = 6;
int blue = 7;
int purple = 8;

int buttonState = 0;

int d1 = 100;
int d2 = 50;
int d3 = 300;
int d4 = 400; 
int d5 = 500;
int d6 = 600; 
int d7 = 700;
/*
int rand = 0;
int rand2 = 0;
int rand3 = 0; 
int rand4 = 0;
int randint = 0;
*/
void setup() {

  pinMode(ledPin, OUTPUT);      
  
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(purple, OUTPUT);
  
  pinMode(relay, OUTPUT);
  pinMode(buttonPin, INPUT);     
  digitalWrite(ledPin, LOW);
}

void loop(){
 
  buttonState = digitalRead(buttonPin);
   

  if (buttonState == HIGH) {     
    /*
    rand = random(50,800);
    rand1 = random(50,900);
    rand2 = random(50,1000);
    rand3 = random(50,800);
    rand4 = random(200,500);
    randint = random(1,3);
    
    if (randint == 1) {
       line = red1;
    }
    if (randint == 2) {
       line = red2;
    }
    if (randint == 3) {
       line = blue;
    }
    */
    digitalWrite(ledPin, HIGH);  
    delay(20);
  
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    delay(d1);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    delay(d1);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    delay(d1);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    delay(d1);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    delay(d1);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    delay(d1);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    delay(d2);
    
    digitalWrite(ledPin, LOW);
    digitalWrite(purple, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    
    
    delay(d1);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
    
    
    digitalWrite(relay, HIGH);
    delay(2000);
    digitalWrite(relay, LOW);
    
    delay(1000);
    
    digitalWrite(ledPin, HIGH);
    digitalWrite(purple, HIGH); 
    digitalWrite(red1, HIGH);
    digitalWrite(red2, HIGH);  
    digitalWrite(blue, HIGH);
  } 
  else {
    
    digitalWrite(ledPin, LOW); 
    digitalWrite(red1, LOW);
    digitalWrite(red2, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(purple, LOW);
    digitalWrite(relay, LOW);
    
  }
}
