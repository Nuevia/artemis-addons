/***************************************************
  This sketch is to run the "Artemis Captain's Handheld"
  unit, which allows the captain to switch between the
  8 views that can be shown on the forward screen of
  the bridge.  Normally, the captain doesn't have a
  computer, so has to ask bridge members to switch
  views.

  This sketch requires:
  
  - Adafruit 2.8" TFT Shield or breakout (v2)
  - Arduino Leonardo/Mega (w/appropriate mods to shield)
  - Artemis 2.x running on machine that Arduino's USB cable
      is plugged into
  - Adafruit GFX and ILI9341 libraries, which as of July 2014
      require Arduino 1.0.5+
      
 ****************************************************/


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

void setup() {
//  Serial.begin(9600);
//  Serial.println("ILI9341 Test!"); 
 
  tft.begin();

/**  
* If you wish to view TFT diagnostic info, uncomment this section 
**/

//  // read diagnostics (optional but can help debug problems)
//  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
//  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDMADCTL);
//  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDPIXFMT);
//  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDIMGFMT);
//  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
//  x = tft.readcommand8(ILI9341_RDSELFDIAG);
//  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 
//  
//  Serial.println(F("Benchmark                Time (microseconds)"));



}


void loop(void) {
  
  testTextDimensions();
  delay(10000);
}


/**
* For demonstrating text size and draw speeds,
* fill the screen with characters of each size
* for 8 seconds.
*
* Note: The default Adafruit font is 5x8, which
* results in 40x40 at size 1, 20x20 at size 2.
**/

unsigned long testTextDimensions() {
  tft.setTextWrap(false);
  tft.fillScreen(ILI9341_BLACK);
  
  tft.setCursor(0, 0);
  tft.setTextColor(ILI9341_WHITE);  
  
  // fill screen with text size 1
  tft.setTextSize(1);
  tft.println("12345678901234567890123456789012345678901234567890");
  int x2;
  for(x2=2; x2<=40; x2+=1) {
    String s = String(x2);
    tft.println(String(s + " 123456789012345678901234567890"));
  }
  delay(8000);
  
  // fill screen with text size 2
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0, 0);
  tft.setTextSize(2);
  tft.println("12345678901234567890123456789012345678901234567890");
//  int x2;
  for(x2=2; x2<=35; x2+=1) {
    String s = String(x2);
    tft.println(String(s + " 123456789012345678901234567890"));
  }
  delay(8000);
}


