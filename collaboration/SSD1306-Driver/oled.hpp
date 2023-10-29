#ifndef OLED_H
#define OLED_H

#include "Arduino.h"

// I2C address of the OLED display (default: 0x3C).
#ifndef OLED_I2C_ADDRESS
#define OLED_I2C_ADDRESS 0x3C
#endif

// Number of rows of the OLED display (default: 8)
#ifndef OLED_ROWS
#define OLED_ROWS 8
#endif

// Number of columns of the OLED display (default: 128)
#ifndef OLED_COLS
#define OLED_COLS 128
#endif

// Control byte for selecting the write mode.
#define SSD1306_CMD_MODE    0x00
#define SSD1306_DATA_MODE   0x40
#define SDD1306_SINGLE_BYTE 0x80 // "or" with one of the above

// Type synonym for "unsigned int" used for brevity.
typedef unsigned int uint;

// All OLED-related global functions live in their own namespace.
namespace oled {
  /* Note that the implementation guarantees that the size of
   * the below array is less than 32 elements. This allows us
   * to send the entire initialisation sequence in a single
   * transmission, since the capacity of the Wire transmission
   * buffer is 32 bytes. The array is held in program (flash)
   * memory because SRAM is scarce and precious. */
  extern const byte OLED_INIT_CMDS[] PROGMEM;

  /* Actual size of the OLED_INIT_CMDS[] array. */
  extern const size_t OLED_INIT_CMDS_SIZE;

  /* Configures the TWI and sends the above initialisation sequence
   * to the OLED. Returns 0 if successful, otherwise returns an error
   * code similar to the return value of Wire.endTransmission(). */
  uint8_t init();

  /* Sends a sequence of bytes in SRAM memory to the OLED.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t send(byte control, byte data[], size_t length);

  /* Sends a sequence of bytes in program memory to the OLED.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t send_p(byte ctrl_mode, byte data[], size_t length);

  /* Write a single value (possibly multiple times) to GDD RAM.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t write(byte value, size_t n = 1);

  /* Copies an array of values from SRAM to the OLED's GDD RAM.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t copy(byte values[], size_t length);

  /* Copies an array of values from program memory to the OLED's GDD RAM.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t copy_p(byte values[], size_t length);

  /* Move the cursor to a given row (0..7) and column (0..127).
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t move(uint row, uint col);

  /* Clear the display and moves the cursor to the top-left position.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t clear();

  /* Emits a given 5x7 ASCII character, using the glcdfont[] array.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t emit(char c);

  /* Prints a null-terminated string by emitting all of its characters.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t print(const char* s);

  /* Prints a null-terminated string by emitting all of its characters.
   * Unlike with print(), the string must reside in program memory.
   * Returns 0 if successful, otherwise returns an error code similar
   * to the return value of Wire.endTransmission(). */
  uint8_t print_p(const char* s);
}

#endif /* OLED_H */
