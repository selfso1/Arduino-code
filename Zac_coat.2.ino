// Adafruit IO Feed Reading
// Tutorial Link: https://learn.adafruit.com/adafruit-io-basics-feeds/sharing-a-feed
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Brent Rubell for Adafruit Industries
// Copyright (c) 2018 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

//////zach coat

#include "config.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24// Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

// the Adafruit IO username of whomever owns the feed
#define FEED_OWNER "ryan_f"

String stringTwo =  String("This is a string");

// set up the `sharedFeed`
AdafruitIO_Feed *sharedFeed = io.feed("weather", FEED_OWNER);




void setup() {
  
  // start the serial connection
  Serial.begin(11520);

  // wait for serial monitor to open
  while(! Serial);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // set up a message handler for the 'sharedFeed' feed.
  // the handleMessage function (defined below)
  // will be called whenever a message is
  // received from adafruit io.
  sharedFeed->onMessage(handleMessage);

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());
  sharedFeed->get();
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  
  

}

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

}

// this function is called whenever an 'sharedFeed' feed message
// is received from Adafruit IO. it was attached to
// the 'digital' feed in the setup() function above.
void handleMessage(AdafruitIO_Data *data) {

  String stringTwo = data->toString();
  //*char_val = data;
  Serial.print("toString: ");
  Serial.println(data->toString());
  
  if (stringTwo == "Sunny"){
    Serial.println("Holy Crap!");
    for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0, 255, 0));
      pixels.show();
    }
  }
  if (stringTwo == "Rainy"){
    Serial.println("weather snacks");
    for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0, 0, 255));
      pixels.show();
    }
  }
  if (stringTwo == "Trump"){
    Serial.println("booooo!");
    for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(255, 165, 0));
      pixels.show();
    }
  }
   if (stringTwo == "Snowing"){
    Serial.println("mooooo!");
    for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(255, 255, 255));
      pixels.show();
    }
  }
  delay(DELAYVAL); 
  
}
