#include <FastLED.h>

#define LED_COUNT 1
// Try using LED_BUILTIN if that is defined correctly by your board variant.
#define LED_PIN 35

CRGB leds[LED_COUNT];

void setup() {
  Serial.begin(115200);
  Serial.println("FastLED test starting on LED_PIN defined as:");
  Serial.println(LED_PIN);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  
  
  // Use WS2812B with GRB ordering, which is common for WS2812 LEDs.
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, LED_COUNT);
  FastLED.clear(true);
}

void loop() {
  Serial.println("Turning LED white");
  leds[0] = CRGB::White;
  FastLED.show();
  delay(500);
  
  Serial.println("Turning LED off");
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
}
