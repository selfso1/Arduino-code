// receiver.pde
//
// Simple example of how to use VirtualWire to receive messages
// Implements a simplex (one-way) receiver with an Rx-B1 module
//
// See VirtualWire.h for detailed API docs
// Author: Mike McCauley (mikem@airspyce.com)FGFGHdfghfghgggggggggg
// Copyright (C) 2008 Mike McCauley
// $Id: receiver.pde,v 1.3 2009/03/30 00:07:24 mikem Exp $

#include <VirtualWire.h>


const int sPin = 12;
const int sPin2 = 7;
char charVel[5];

int fullVal = 0;

int vel = 0;

int note = 0;


void setup()
{
    Serial.begin(31250);	
    
    pinMode(sPin, OUTPUT);
    pinMode(sPin2, OUTPUT);
    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    vw_set_rx_pin(23);
    vw_rx_start();       // Start the receiver PLL running
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) {// Non-blocking
        
       int i;
     
       for (i = 0; i < buflen; i++){
        
         charVel[i] = char(buf[i]);
         
         charVel[buflen] = '\0';
       }  
      
       fullVal = atoi(charVel);
         
       note = (fullVal/1000+50);
                  
       vel = (fullVal-(note-50)*1000); 
         
       midiOUT(0x90, note, vel);
       //digitalWrite(ledPin, HIGH);        
                   
    }
        
    else  {
       
       //digitalWrite(ledPin, LOW);    
    }
    
    if (vel == 127 && note == 67){
    
       digitalWrite(sPin, HIGH);
    }   
       
    else  {
        
       digitalWrite(sPin, LOW);
       
    }
    if (vel == 127 && note == 62){
    
       digitalWrite(sPin2, HIGH);
    }   
       
    else  {
        
       digitalWrite(sPin2, LOW);
    }   
   /* Serial.print("fullVal = " );                       
    Serial.print(fullVal);      
    Serial.print("\t note = ");      
    Serial.print(note); 
    Serial.print("\t vel = ");      
    Serial.println(vel);  
    delay(1000);  */
}
void midiOUT(char command, char value1, char value2) {
  Serial.print(command);
  Serial.print(value1);
  Serial.print(value2);
}

