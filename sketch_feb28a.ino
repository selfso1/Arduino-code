void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT); //k4
  pinMode(7, OUTPUT); //k2
}

void loop() {
  // put your main code here, to run repeatedly:

  double purgeTime  = 2000;
  double intakeTime = 1000;
  double sampleTime = 4000;
  double pauseTime  = 1000; 
  
  digitalWrite(7 && 8, HIGH);
  delay(100);
  
  digitalWrite(7 && 8, LOW);
  delay(purgeTime);
 
}
