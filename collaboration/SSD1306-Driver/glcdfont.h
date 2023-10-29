#ifndef GLCDFONT_H
#define GLCDFONT_H

#include "Arduino.h"

#define GLDC_WIDTH  5
#define GLDC_HEIGHT 7

/* The font is 5x7 pixels. Data is stored in 8-bit columns. */
extern const byte glcdfont[256][5] PROGMEM;

#endif /* GLCDFONT_H */
