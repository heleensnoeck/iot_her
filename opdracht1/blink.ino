#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN D2

int buttonPin = D1;
int ledPin = D2;
//int val = 0;  

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); //switch pin
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip.setBrightness(40);
}
//short mode=0;
void loop() {
    int val = digitalRead(buttonPin);
    Serial.println(val);  
    
  //TODO use the button to switch on the LEDs and to change their colours.
  //complete the function ColorLed() to switch on the LEDs
  if (val == 0) { 
    colorLed(255, 0, 0); // Red
    delay(500);
    
    colorLed(0, 0, 255); // Blue
    delay(500);
    
    colorLed(0, 0, 0);//leds off
    delay(500);
   
    colorLed(0, 255, 0); // green
    delay(500);
    
    } else {
    colorLed(0, 0, 0); 
    delay(500);  
  }
}

// Fill the dots one after the other with a color
void colorLed(short r, short g, short b) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    //TODO complete the loop to switch on the leds with the colour you want.
    //the setPixelColor() method could help you.
    strip.setPixelColor(i, r, g, b); 
    strip.show();
    delay(50);
  }
}


