


int sPin = 6;
int irPin = 0;
int irVal = 0;
int mapVal= 0;
int THRESHOLD = 50;



void setup() {
               //MIDI communicates at 31250 baud
    pinMode(sPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
 
  
  irVal = analogRead(irPin);     //read input value from button
  mapVal = map(irVal, 0, 560, 0, 255);
  
  
  
    if(mapVal >= THRESHOLD){
      digitalWrite(sPin, HIGH);
  }
  
    else{
      digitalWrite(sPin, LOW);
    
    }   
    
    
  Serial.print("sensor = " );                       
  Serial.print(irVal);      
  Serial.print("\t output = ");      
  Serial.println(mapVal);   
  




}

