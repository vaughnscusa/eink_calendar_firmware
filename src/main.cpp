// TEST SKETCH — confirms wiring + panel work, no WiFi/server needed.
//
// How to use:
//   1. Temporarily rename your real src/main.cpp to src/main.cpp.bak
//   2. Rename this file from main_test_pattern.cpp to main.cpp
//   3. Build + upload
//   4. Once you see text/shapes on the panel, swap the files back
//      (restore the real main.cpp) before moving on to the fetch firmware.

#include <Arduino.h>
#include <SPI.h>
#include <GxEPD2_BW.h>

#define PIN_BUSY 25
#define PIN_RST  26
#define PIN_DC   27
#define PIN_CS   15
#define PIN_SCK  13
#define PIN_MOSI 14

// If the screen stays blank after upload, try GxEPD2_750 instead of
// GxEPD2_750_T7 here (V1 vs V2 panel controller).
GxEPD2_BW<GxEPD2_750_T7, GxEPD2_750_T7::HEIGHT> display(
    GxEPD2_750_T7(PIN_CS, PIN_DC, PIN_RST, PIN_BUSY));

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Test pattern starting...");

  SPI.begin(13, 12, 14, 15); // SCK, MISO, MOSI, CS 

  display.init(115200);

  display.setFullWindow();
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);

    // A few shapes so you can confirm orientation + that drawing works
    display.drawRect(10, 10, 200, 100, GxEPD_BLACK);
    display.fillRect(230, 10, 200, 100, GxEPD_BLACK);
    display.drawLine(0, 150, 799, 150, GxEPD_BLACK);
    display.drawCircle(400, 300, 80, GxEPD_BLACK);

    // Text
    display.setCursor(10, 400);
    display.setTextColor(GxEPD_BLACK);
    display.setTextSize(3);
    display.print("E-ink is alive!");
  } while (display.nextPage());

  Serial.println("Test pattern drawn. Check the panel.");
}

void loop() {
  // nothing to do
}
