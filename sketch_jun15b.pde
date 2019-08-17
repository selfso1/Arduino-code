//LED Pin Variables
int ledPins[] = {
  2,3,4,5,6,7,8,9}; //An array to hold the pin each LED is connected to
//i.e. LED #0 is connected to pin 2, LED #1, 3 and so on
//to address an array use ledPins[0] this would equal 2
//and ledPins[7] would equal 9

/*
 * setup() - this function runs once when you turn your Arduino on
 * We the three control pins to outputs
 */
void setup()
{

  //Set each pin connected to an LED to output mode (pulling high (on) or low (off)
  for(int i = 0; i < 8; i++){         //this is a loop and will repeat eight times
    pinMode(ledPins[i],OUTPUT); //we use this to set each LED pin to output
  }                                   //the code this replaces is below

  /* (commented code will not run)
   * these are the lines replaced by the for loop above they do exactly the
   * same thing the one above just uses less typing
   pinMode(ledPins[0],OUTPUT);
   pinMode(ledPins[1],OUTPUT);
   pinMode(ledPins[2],OUTPUT);
   pinMode(ledPins[3],OUTPUT);
   pinMode(ledPins[4],OUTPUT);
   pinMode(ledPins[5],OUTPUT);
   pinMode(ledPins[6],OUTPUT);
   pinMode(ledPins[7],OUTPUT);
   (end of commented code)*/
}


/*
 * loop() - this function will start after setup finishes and then repeat
 * we call a function called oneAfterAnother(). if you would like a different behaviour
 * uncomment (delete the two slashes) one of the other lines
 */
void loop()                     // run over and over again
{
  oneAfterAnotherNoLoop();   //this will turn on each LED one by one then turn each off
  //oneAfterAnotherLoop();   //does the same as oneAfterAnotherNoLoop but with 
  //much less typing
  //oneOnAtATime();          //this will turn one LED on then turn the next one
  //on turning the 
  //former off (one LED will look like it is scrolling 
  //along the line
  //inAndOut();              //lights the two middle LEDs then moves them out then back 
  //in again
}

/*
 * oneAfterAnotherNoLoop() - Will light one LED then delay for delayTime then light
 * the next LED until all LEDs are on it will then turn them off one after another
 *
 * this does it without using a loop which makes for a lot of typing. 
 * oneOnAtATimeLoop() does exactly the same thing with less typing
 */
void oneAfterAnotherNoLoop(){
  int delayTime = 100; //the time (in milliseconds) to pause between LEDs
  //make smaller for quicker switching and larger for slower
  digitalWrite(ledPins[0], HIGH);  //Turns on LED #0 (connected to pin 2 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[1], HIGH);  //Turns on LED #1 (connected to pin 3 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[2], HIGH);  //Turns on LED #2 (connected to pin 4 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[3], HIGH);  //Turns on LED #3 (connected to pin 5 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[4], HIGH);  //Turns on LED #4 (connected to pin 6 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[5], HIGH);  //Turns on LED #5 (connected to pin 7 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[6], HIGH);  //Turns on LED #6 (connected to pin 8 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[7], HIGH);  //Turns on LED #7 (connected to pin 9 )
  delay(delayTime);                //waits delayTime milliseconds  

  //Turns Each LED Off
  digitalWrite(ledPins[7], LOW);  //Turns on LED #0 (connected to pin 2 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[6], LOW);  //Turns on LED #1 (connected to pin 3 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[5], LOW);  //Turns on LED #2 (connected to pin 4 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[4], LOW);  //Turns on LED #3 (connected to pin 5 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[3], LOW);  //Turns on LED #4 (connected to pin 6 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[2], LOW);  //Turns on LED #5 (connected to pin 7 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[1], LOW);  //Turns on LED #6 (connected to pin 8 )
  delay(delayTime);                //waits delayTime milliseconds
  digitalWrite(ledPins[0], LOW);  //Turns on LED #7 (connected to pin 9 )
  delay(delayTime);                //waits delayTime milliseconds  
}


