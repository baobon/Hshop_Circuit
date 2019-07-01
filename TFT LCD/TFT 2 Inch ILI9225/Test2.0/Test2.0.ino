// Include application, user and local libraries
#include "SPI.h"
#include "TFT_22_ILI9225.h"
#include <../fonts/FreeSans9pt7b.h>
#include <../fonts/FreeSans12pt7b.h>
#include <../fonts/FreeSans18pt7b.h>
#include <../fonts/FreeSans24pt7b.h>
#define TFT_RST A4
#define TFT_RS A3
#define TFT_CS A5 // SS
#define TFT_SDI A2 // MOSI
#define TFT_CLK A1 // SCK
#define TFT_LED 0 // 0 if wired to +5V directly

#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED,TFT_BRIGHTNESS);
int16_t x=0, y=0, w, h;
// Setup
void setup() {
  tft.begin();
  tft.clear();

  // Draw first string in big font
  String s1 = " Hshop";
  tft.setGFXFont(&FreeSans24pt7b); // Set current font
  tft.getGFXTextExtent(s1, x, y, &w, &h); // Get string extents
  y = h; // Set y position to string height
  tft.drawGFXText(x, y, s1, COLOR_RED); // Print string

  // Draw second string in smaller font
  tft.setGFXFont(&FreeSans18pt7b);  // Change font
  String s2 = "Hshop.vn"; // Create string object
  tft.getGFXTextExtent(s2, x, y, &w, &h); // Get string extents
  y += h + 10; // Set y position to string height plus shift down 10 pixels
  tft.drawGFXText(x, y, s2, COLOR_GREEN); // Print string
  
  // Draw second string in smaller font
  tft.setGFXFont(&FreeSans12pt7b);  // Change font
  String s3 = "Hshop.vn"; // Create string object
  tft.getGFXTextExtent(s3, x, y, &w, &h); // Get string extents
  y += h + 10; // Set y position to string height plus shift down 10 pixels
  tft.drawGFXText(x, y, s3, COLOR_WHITE); // Print string

    // Draw second string in smaller font
  tft.setGFXFont(&FreeSans9pt7b);  // Change font
  String s4 = "Hshop.vn"; // Create string object
  tft.getGFXTextExtent(s4, x, y, &w, &h); // Get string extents
  y += h + 10; // Set y position to string height plus shift down 10 pixels
  tft.drawGFXText(x, y, s4, COLOR_BLUE); // Print string

  delay(5000);
  
   // Draw first string in big font
  String s5 = " Hshop";
  tft.setGFXFont(&FreeSans24pt7b); // Set current font
  tft.getGFXTextExtent(s5, x, y, &w, &h); // Get string extents
  y = h; // Set y position to string height
  tft.drawGFXText(x, y, s5, COLOR_TOMATO); // Print string

  // Draw second string in smaller font
  tft.setGFXFont(&FreeSans18pt7b);  // Change font
  String s6 = "Hshop.vn"; // Create string object
  tft.getGFXTextExtent(s6, x, y, &w, &h); // Get string extents
  y += h + 10; // Set y position to string height plus shift down 10 pixels
  tft.drawGFXText(x, y, s6, COLOR_VIOLET); // Print string
  
  // Draw second string in smaller font
  tft.setGFXFont(&FreeSans12pt7b);  // Change font
  String s7 = "Hshop.vn"; // Create string object
  tft.getGFXTextExtent(s7, x, y, &w, &h); // Get string extents
  y += h + 10; // Set y position to string height plus shift down 10 pixels
  tft.drawGFXText(x, y, s7, COLOR_LIGHTGREY); // Print string

    // Draw second string in smaller font
  tft.setGFXFont(&FreeSans9pt7b);  // Change font
  String s8 = "Hshop.vn"; // Create string object
  tft.getGFXTextExtent(s8, x, y, &w, &h); // Get string extents
  y += h + 10; // Set y position to string height plus shift down 10 pixels
  tft.drawGFXText(x, y, s8, COLOR_ORANGE); // Print stringg
}

// Loop
void loop() {
}
