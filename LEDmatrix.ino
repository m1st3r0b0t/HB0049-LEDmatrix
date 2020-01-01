#include <FastLED.h>

//#define DEBUG 1
#define NUM_LEDS 64
#define DATA_PIN A14

CRGB leds[NUM_LEDS];

void setup()
{ 
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  #ifdef DEBUG
    Serial.begin(9600);
    Serial.println();
    Serial.println();
    Serial.print("LED");
    Serial.print("\t");
    Serial.print("RED");
    Serial.print("\t");
    Serial.print("GREEN");
    Serial.print("\t");
    Serial.println("BLUE");
  #endif
}

void loop() 
{
  int i = random(64); 
  int red = random(256);
  int green = random(256);
  int blue = random(256);
  int rgb = (green << 16) + (red << 8) + (blue);
  leds[i] = rgb;
  #ifdef DEBUG
    Serial.print(i);
    Serial.print("\t");
    Serial.print(red);
    Serial.print("\t");
    Serial.print(green);
    Serial.print("\t");
    Serial.println(blue);
  #endif
  FastLED.show();
  delay(4000);
  leds[i] = 0;
  FastLED.show();
}
