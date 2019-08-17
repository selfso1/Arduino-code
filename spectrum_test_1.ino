/****************************************************************************** 
SparkFun Spectrum Shield Demo
Toni Klopfenstein @ SparkFun Electronics
December 2015
https://github.com/sparkfun/Spectrum_Shield
This sketch shows the basic functionality of the Spectrum Shield, working with a basic RGB LED Matrix.
The Spectrum Shield code is based off of the original demo sketch by Ben Moyes @Bliptronics.  
This sketch is available in the Spectrum Shield repository. 
Development environment specifics:
Developed in Arduino 1.6.
This code is beerware; if you see me (or any other SparkFun employee) at the local, and you've found our code helpful, please buy us a round!
Distributed as-is; no warranty is given.
*********************************************************************************/

//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 5
#define DC_One A0
#define DC_Two A1 


//Define LED connections on the Arduino/Shield
int LED = 7;

//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7]; 
int i;
int Average = 0;
int THRESHOLD = 400;
/********************Setup Loop*************************/
void setup() {
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  
  
  //Set spectrum Shield pin configurations
  pinMode(STROBE, OUTPUT);
  pinMode(RESET, OUTPUT);
  pinMode(DC_One, INPUT);
  pinMode(DC_Two, INPUT);  
  digitalWrite(STROBE, HIGH);
  digitalWrite(RESET, HIGH);
  
  //Initialize Spectrum Analyzers
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, HIGH);
  delay(1);
  digitalWrite(STROBE, HIGH);
  delay(1);
  digitalWrite(STROBE, LOW);
  delay(1);
  digitalWrite(RESET, LOW);
}


/**************************Main Function Loop*****************************/
void loop() {
  
  Read_Frequencies();
  Graph_Frequencies();
  delay(5);
 
}


/*******************Pull frquencies from Spectrum Shield********************/
void Read_Frequencies(){
  //Read frequencies for each band
  for (freq_amp = 0; freq_amp<7; freq_amp++)
  {
    Frequencies_One[freq_amp] = analogRead(DC_One);
    Frequencies_Two[freq_amp] = analogRead(DC_Two); 
    digitalWrite(STROBE, HIGH);
    digitalWrite(STROBE, LOW);
  }
}

/*******************Light LEDs based on frequencies*****************************/
void Graph_Frequencies(){
  /*(for( i= 0; i<7; i++)
   {
     if(Frequencies_Two[i] > Frequencies_One[i]){
        analogWrite(LED[i], Frequencies_Two[i]/4);
     }
     else{
        analogWrite(LED[i], Frequencies_One[i]/4);
     }*/

  Average = abs((Frequencies_One[0]+Frequencies_One[1]+Frequencies_One[2]+Frequencies_One[3]+Frequencies_One[4]+Frequencies_One[5]+Frequencies_One[6])/7);  

  if(Average > THRESHOLD){
    digitalWrite(LED, HIGH);
    delay(20);
  }
    else{ 
    digitalWrite(LED, LOW);
  } 
  
  Serial.print("Average = ");
  Serial.print(Average); 
  Serial.print("  1 = ");
  Serial.print(Frequencies_One[0]);
  Serial.print("  2 = ");
  Serial.print(Frequencies_One[1]);
  Serial.print("  3 = ");
  Serial.print(Frequencies_One[2]);
  Serial.print("  4 = ");
  Serial.print(Frequencies_One[3]);
  Serial.print("  5 = ");
  Serial.print(Frequencies_One[4]);
  Serial.print("  6 = ");
  Serial.print(Frequencies_One[5]);
  Serial.print("  7 = ");
  Serial.print(Frequencies_One[6]);
  Serial.print("  Two1 = ");
  Serial.print(Frequencies_Two[0]);
  Serial.print("  Two2 = ");
  Serial.print(Frequencies_Two[1]);
  Serial.print("  Two3 = ");
  Serial.print(Frequencies_Two[2]);
  Serial.print("  Two4 = ");
  Serial.print(Frequencies_Two[3]);
  Serial.print("  Two5 = ");
  Serial.print(Frequencies_Two[4]);
  Serial.print("  Two6 = ");
  Serial.print(Frequencies_Two[5]);
  Serial.print("  Two7 = ");
  Serial.println(Frequencies_Two[6]);
  //delay(50);

  
   }

