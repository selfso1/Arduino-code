

int buttonPin1 = 7;
int buttonPin2 = 8;

int buttonVal1 = 0;


int bounceCheck1 = 0;


void setup() {
  
  Serial.begin(9600);
   pinMode(buttonPin1, INPUT);    //declare pushbutton as input
   pinMode(buttonPin2, OUTPUT);
  
}

void loop() {

 //c
  buttonVal1 = digitalRead(buttonPin1);     //read input value from button
  delay(9);                              //wait 10ms
  bounceCheck1 = digitalRead(buttonPin1);   //check again
  if(buttonVal1 == bounceCheck1){           //if val is the same then not a bounce
    if (buttonVal1 == HIGH) {   //check if the input is HIGH
      digitalWrite(buttonPin2, LOW); //cc chnge, cc83, on
     
    }
    if(buttonVal1 == LOW){
      digitalWrite(buttonPin2, HIGH);

    }
  }
}
