int pinI1=8;//define IN1pin 

         int pinI2=9;//define IN2 pin 

         int speedpin=11;//define EA(PWM) pin 

         int pinI3=6;//define IN3 pin 

         int pinI4=7;//define IN4 pin 

         int speedpin1=10;//define EB(PWM) pin 

         void setup() 

         { 

           pinMode(pinI1,OUTPUT); 

           pinMode(pinI2,OUTPUT); 

           pinMode(speedpin,OUTPUT);
             
           pinMode(pinI3,OUTPUT); 

           pinMode(pinI4,OUTPUT); 

           pinMode(speedpin1,OUTPUT); 

         } 

         void loop() 

         { 

          //go straight 

             analogWrite(speedpin,100);//define speed 

             analogWrite(speedpin1,100); 

             digitalWrite(pinI4,LOW);//right motor move inanticlockwise 

             digitalWrite(pinI3,HIGH); 

             digitalWrite(pinI1,LOW);//left motor move inclockwise 

             digitalWrite(pinI2,HIGH); 

             delay(2000); 

          //go back                                                                         m 
             analogWrite(speedpin,100);//define speed                                o 
             analogWrite(speedpin1,100);                                        
                                                                               
             digitalWrite(pinI4,HIGH);//right motor move inclockwisen 
             digitalWrite(pinI3,LOW);                        

             digitalWrite(pinI1,HIGH);//left motor move inanticlockwise 
             digitalWrite(pinI2,LOW);           
             delay(2000);                    
          //turn left                  s 

             analogWrite(speedpin,60);// 
                             
             analogWrite(speedpin1,60); 
                              
             digitalWrite(pinI4,LOW);// 
                   
             digitalWrite(pinI3,HIGH); 

             digitalWrite(pinI1,HIGH);// 
        
             digitalWrite(pinI2,LOW); 

             delay(2000); 

          //turn right 

             analogWrite(speedpin,60);// 

             analogWrite(speedpin1,60); 

             digitalWrite(pinI4,HIGH);// 

             digitalWrite(pinI3,LOW); 

             digitalWrite(pinI1,LOW);// 

             digitalWrite(pinI2,HIGH); 

             delay(2000); 

          //stop 

             digitalWrite(pinI4,HIGH);// 
             
             digitalWrite(pinI3,HIGH); 

             digitalWrite(pinI1,HIGH);// 

             digitalWrite(pinI2,HIGH); 

             delay(2000); 

        } 
