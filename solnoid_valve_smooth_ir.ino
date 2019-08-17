


int sPin = 6;
int irPin = 0;
int irVal = 0;
int mapVal= 0;
int THRESHOLD = 19;
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average
int averagemap = 0;
int inputPin = A0;


void setup() {
               //MIDI communicates at 31250 baud
    pinMode(sPin, OUTPUT);
    Serial.begin(9600);
    for (int thisReading = 0; thisReading < numReadings; thisReading++)
      readings[thisReading] = 0; 
}
void loop() {
  irVal = analogRead(irPin);
   // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor:  
  readings[index] = analogRead(irPin); 
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings;         
  
  averagemap = map(average, 0, 580, 0, 255);
  
  
  
    if(averagemap >= THRESHOLD){
      digitalWrite(sPin, HIGH);
  }
  
    else{
      digitalWrite(sPin, LOW);
    
    }   
    
    
  Serial.print("sensor = " );                       
  Serial.print(irVal);      
  Serial.print("\t output = ");      
  Serial.println(averagemap);   
  




}

