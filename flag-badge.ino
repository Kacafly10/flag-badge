#include <Arduino_GC9B72.h>
#include <Arduino_GFX.h>


#include <JPEGDEC.h>

#include <FS.h>
#include "LittleFS.h"

#define DOTPIN
#define DASHPIN
#define L 500

File jpgF;
uint16_t currentAlpha2Morse;
currentAlpha2 = null;

/* More data bus class: https://github.com/moononournation/Arduino_GFX/wiki/Data-Bus-Class */
Arduino_DataBus *bus = create_default_Arduino_DataBus();

Arduino_GFX *tft = new Arduino_GC9B72(bus, DF_GFX_RST, 0, false);
JPEGDEC jpg;

void get_alpha2_morse() {
  uint116_t newAlpha2Morse = 10;

  if (DASHPIN == HIGH || DOTPIN == HIGH) {
    start = millis();
    while (millis() - start < L) {
      if (DOTPIN == HIGH) {
        newAlpha2Morse = newAlpha2Morse * 10 + 1;
        start = millis()
      } 
      else if (DASHPIN == HIGH) {
        newAlpha2Morse = newAlpha2Morse * 10;
        start = millis()
      }
    }
    
    newAlpha2Morse *= 100000;
    while (millis() - start < L) {
      if (DOTPIN == HIGH) {
        newAlpha2Morse = newAlpha2Morse * 10 + 1;
        start = millis()
      } 
      else if (DASHPIN == HIGH) {
        newAlpha2Morse = newAlpha2Morse * 10;
        start = millis()
      }
    }

    currentAlpha2Morse = newAlpha2Morse
  }
}

bool tft_out(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t *bitmap) {
}

// TFT_eSPI tft = TFT_eSPI();

// int findLinePixels(int offset) {
//     float t = sqrt(sq(360)-sq(offset));
//     int count = 2 * t + 1;
//     return count;
// }

// int getStartEnd(int offset) {
//     int start =  180 - (findLinePixels(offset) / 2);
//     int end = 360 - start;
//     int result[2] = {start, end};
//     return result;
// }