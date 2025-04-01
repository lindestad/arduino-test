#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type, number of devices, and SPI pins (adjust if needed)
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1

// Define the pins for DIN, CS, and CLK.
#define DATA_PIN 6
#define CS_PIN   5
#define CLK_PIN  4 

// Create a new instance of the MD_MAX72XX object
MD_MAX72XX matrix = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void setup() {
  matrix.begin();
  matrix.control(MD_MAX72XX::INTENSITY, 8); // Set brightness level (0-15)
  matrix.clear();
}

void loop() {
  // Cycle through each LED sequentially: turn it on, wait, then turn it off.
  for (uint8_t row = 0; row < 8; row++) {
    for (int8_t col = 7; col >= 0; col--) {
      matrix.setPoint(row, col, true);   // Turn on LED at (row, col)
      delay(30);                        // Wait 100ms
      matrix.setPoint(row, col, false);  // Turn that LED off
    }
  }
}
