//illini lights multi letter sketch (c) 2018 David Hickox
//released under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License

#include <TimedAction.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            2
#define PINA           3
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_BRG + NEO_KHZ800);
Adafruit_NeoPixel pixel2 = Adafruit_NeoPixel(NUMPIXELS, PINA, NEO_BRG + NEO_KHZ800);
int delayvala; // delay for half a second
int delayvala2;
int delayvalb; // delay for half a second
int delayvalb2;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  pixel2.begin();
}
int letterastate = 0;
int letterbstate = 0;

int pixelacurrent;
int pixelbcurrent;

void letteratransorange();
void letteratransblue();
void letterbtransorange();
void letterbtransblue();
void letterawait();
void letterbwait();

TimedAction ATransOrangeThread = TimedAction(100000,letteratransorange);
TimedAction ATransBlueThread = TimedAction(100000,letteratransblue);
TimedAction BTransOrangeThread = TimedAction(100000,letterbtransorange);
TimedAction BTransBlueThread = TimedAction(100000,letterbtransblue);
TimedAction AWaitThread = TimedAction(100,letterawait);
TimedAction BWaitThread = TimedAction(200,letterbwait);

void letteratransorange(){
   pixels.setPixelColor(pixelacurrent, pixels.Color(255,28,5));
   pixels.show();
   if(pixelacurrent == 49){
    pixelacurrent = 0;
    ATransOrangeThread.setInterval(100000);
   }else{
    pixelacurrent++;
   }
}

void letteratransblue(){
  pixels.setPixelColor(pixelacurrent, pixels.Color(20,20,150));
  pixels.show();
  if(pixelacurrent == 49){
    pixelacurrent = 0;
    ATransBlueThread.setInterval(100000);
   }else{
    pixelacurrent++;
   }
}

void letterbtransorange(){
   pixel2.setPixelColor(pixelbcurrent, pixel2.Color(255,28,5));
   pixel2.show();
   if(pixelbcurrent == 49){
    pixelbcurrent = 0;
    BTransOrangeThread.setInterval(100000);
   }else{
    pixelbcurrent++;
   }
}

void letterbtransblue(){
  pixel2.setPixelColor(pixelbcurrent, pixel2.Color(20,20,150));
  pixel2.show();
  if(pixelbcurrent == 49){
    pixelbcurrent = 0;
    BTransBlueThread.setInterval(100000);
   }else{
    pixelbcurrent++;
   }
}

void letterawait(){
  delayvala2 = random(32,161);
  if (letterastate == 0){
    ATransOrangeThread.setInterval(delayvala2);
    letterastate = 1;
    AWaitThread.setInterval(delayvala);
  }else{
    ATransBlueThread.setInterval(delayvala2);
    letterastate = 0;
    AWaitThread.setInterval(delayvala);
  }
}
void letterbwait(){
  delayvalb2 = random(32, 161);
  if (letterbstate == 0){
    BTransOrangeThread.setInterval(delayvalb2);
    letterbstate = 1;
    BWaitThread.setInterval(delayvalb);
  }else{
    BTransBlueThread.setInterval(delayvalb2);
    letterbstate = 0;
    BWaitThread.setInterval(delayvalb);
  }
}

void loop() {
  delayvala = random(6000,11000);
  delayvalb = random(6000,11000);
  ATransOrangeThread.check();
  ATransBlueThread.check();
  BTransOrangeThread.check();
  BTransBlueThread.check();
  AWaitThread.check();
  BWaitThread.check();
  
  
}
