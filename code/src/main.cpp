#include <Arduino.h>

#include "init.h"
#include "board_mapping.h"

// ***************  LED  *************** //


Adafruit_NeoPixel pixels(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int pixel = 0;


// ************************************* //

void setup() {
  int initilisation_reussie = 0;
  initilisation_reussie += initialisationsNeoPixel(pixels);
  initilisation_reussie += initialisationSerie();
  initilisation_reussie += initialisationBroches();

}

void loop() {
  int test = 0;

  while(1){

    printf("%i\r\n", test++);
    
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();    
    delay(1000);              // délais 1 sec
    
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.show();      
    delay(1000);              // délais 1 sec
    
  }
}

