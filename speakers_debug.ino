//Declare Spectrum Shield pin connections
#define STROBE 4
#define RESET 6
#define DC_One A0
#define DC_Two A1 


//Define LED connections on the shield
int led1 = 5;
int led2 = 9;

//Define spectrum variables
int freq_amp;
int Frequencies_One[7];
int Frequencies_Two[7]; 
int i;

/********************Setup Loop*************************/
void setup() {
  
   Serial.begin(9600);


  {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  }
  
  //Set Spectrum Shield pin configurations
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

void loop() {
  
  Read_Frequencies();
  Graph_Frequencies();
  delay(50);
 
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

void Graph_Frequencies(){
  /*
  for( i= 0; i<7; i++)
   {
     if(Frequencies_Two[i] > Frequencies_One[i]){
        analogWrite(LED[i], Frequencies_Two[i]/4);
     }
     else{
        analogWrite(LED[i], Frequencies_One[i]/4);
     }
   }
   */
   Serial.print("Frequencies_One = " );
   Serial.print(Frequencies_One[i]);
   Serial.print("\t Frequencies_Two = ");
   Serial.print(Frequencies_Two[i]);
   Serial.print("\t freq_amp = ");
   Serial.println(freq_amp[i]);
   delay(50);
 
}  
