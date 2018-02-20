//illini lights single letter sketch (c) 2018 David Hickox
//released under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
int pixelrand;
int colorrand;
// Which pin on the Arduino is connected to the NeoPixels?

#define PIN            0 

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_BRG + NEO_KHZ800);

int delayval = 5000; // delay for half a second
int delayval2 = 20;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
  delayval = random(3000,8000);
  delayval2 = random(20,100);
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(255,28,5));
    pixels.show();
    delay(delayval2);
  }
  delay(delayval);
  delayval = random(3000,8000);
  delayval2 = random(20,70);
  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(20,20,150));
    pixels.show();
    delay(delayval2);
  }
  delay(delayval); // Delay for a period of time (in milliseconds).
  
}
