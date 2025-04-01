#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type and number of devices
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1

// Define your custom SPI pins (from your working configuration)
#define DATA_PIN 37    // DIN
#define CLK_PIN  35    // CLK
#define CS_PIN   36    // CS

// Create an instance of MD_Parola using software SPI (custom pin configuration)
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  myDisplay.begin();
  myDisplay.setIntensity(8);       // Set brightness (0-15)
  myDisplay.displayClear();
  // Configure scrolling text: "Hello, World! " scrolling from right to left at 50ms per frame.
  myDisplay.displayText("Hello, World! ", PA_LEFT, 100, 30, PA_SCROLL_LEFT, PA_SCROLL_LEFT);

}

void loop() {
  // Update the display animation.
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}
