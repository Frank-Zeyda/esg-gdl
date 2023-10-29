#include "oled.hpp"
#include "glcdfont.h"

#include "Wire.h"

// Meximum X and Y coordinates per display size.
#define MAXX (OLED_COLS   - 1)
#define MAXY (OLED_ROWS*8 - 1)

namespace oled {
  /* OLED initialisation sequence, enabling the charge pump circuit.
   * Note that per contract, the sequence must not exceed 31 bytes. */
  const byte OLED_INIT_CMDS[] PROGMEM = {
    0xAE,       // Set Display OFF
    0xD5, 0x80, // Set Display Clock Divide Ratio / Oscillator Frequency
    0xA8, MAXY, // Set Multiplex Ratio
    0xD3, 0x00, // Set Display Offset
    0x40,       // Set Display Start Line
    0x8D, 0x14, // Charge Pump Setting (x)
    0x20, 0x00, // Set Memory Addressing Mode
    0xA1,       // Set Segment Re-map
    0xC8,       // Set COM Output Scan Direction
    0xDA, 0x12, // Set COM Pins Hardware Configuration
    0x81, 0xCF, // Set Contrast Control
    0xD9, 0xF1, // Set Pre-charge Period
    0xDB, 0x20, // Set V_COMH Deselect Level (0x20 or 0x40)
    0xA4,       // Entire Display ON
    0xA6,       // Set Normal/Inverse Display
    0x2E,       // Deactivate scroll
    0xAF,       // Set Display ON
  };

  /* Expose the size of the above dynamic array. */
  const size_t OLED_INIT_CMDS_SIZE = sizeof(OLED_INIT_CMDS);

  /* Beware that the OLED_INIT_CMDS[] byte array resides in
   * program (flash) memory, and not in SRAM -> use send_p(). */
  uint8_t init() {
    Wire.begin();
    Wire.setClock(400000);           // use I2C in fast mode
    Wire.setWireTimeout(1000, true); // set time-out to 1 ms
    const uint8_t error =
    send_p(SSD1306_CMD_MODE, OLED_INIT_CMDS, OLED_INIT_CMDS_SIZE);
    if (Wire.getWireTimeoutFlag()) { Wire.clearWireTimeoutFlag(); }
    return error;
  }

  /* REVIEW: Should the below clear the Wire time-out flag too? */
  uint8_t send(byte ctrl_mode, byte data[], size_t length) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(ctrl_mode);
    byte *ptr = data;
    while (length > 0) {
      const size_t n = max(length, 31);
      Wire.write(ptr, n);
      ptr += n; length -= n;
      const uint8_t error =
        Wire.endTransmission(length == 0);
      if (error != 0) { return error; }
    }
    return 0; // no error if reaching here
  }

  /* REVIEW: Should the below clear the Wire time-out flag too? */
  uint8_t send_p(byte ctrl_mode, byte data[], size_t length) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(ctrl_mode);
    byte *ptr = data;
    while (length > 0) {
      // NOTE: 31 bytes are left in the transmission buffer.
      for (size_t avail = 31; length > 0 && avail > 0; length--, avail--) {
        Wire.write(pgm_read_byte(ptr++));
      }
      const uint8_t error =
        Wire.endTransmission(length == 0);
      if (error != 0) { return error; }
    }
    return 0; // no error if reaching here
  }

  uint8_t copy(byte values[], size_t length) {
    return send(SSD1306_DATA_MODE, values, length);
  }

  uint8_t copy_p(byte values[], size_t length) {
    return send_p(SSD1306_DATA_MODE, values, length);
  }

  /* REVIEW: Should the below clear the Wire time-out flag too? */
  uint8_t write(byte value, size_t n = 1) {
    while (n > 0) {
      Wire.beginTransmission(OLED_I2C_ADDRESS);
      Wire.write(SSD1306_DATA_MODE);
      // NOTE: 31 bytes are left in the transmission buffer.
      for (int i = 0; i < 31 && n > 0; i++, n--) {
        Wire.write(value);
      }
      const uint8_t error =
        Wire.endTransmission(n == 0);
      if (error != 0) { return error; }
    }
    return 0; // no error if reaching here
  }

  /* REVIEW: Should the below clear the Wire time-out flag too? */
  uint8_t move(uint row, uint col) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(SSD1306_CMD_MODE);
    Wire.write(0xB0 | (row & 0x07));
    Wire.write(0x00 | ((col >> 0) & 0x0F));
    Wire.write(0x10 | ((col >> 4) & 0x0F));
    return Wire.endTransmission(true);
  }

  uint8_t clear() {
    uint8_t error;
    error = oled::move(0, 0);
    if (error != 0) { return error; }
    error = oled::write(0x00, OLED_ROWS*OLED_COLS);
    if (error != 0) { return error; }
    error = oled::move(0, 0); // strictly not needed
    return error;
  }

  /* REVIEW: Should the below clear the Wire time-out flag too? */
  uint8_t emit(char c) {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    Wire.write(SSD1306_DATA_MODE);
    byte *ptr = glcdfont[(unsigned char) c];
    for (int i = 0; i < GLDC_WIDTH; i++) {
      Wire.write(pgm_read_byte(ptr++));
    }
    Wire.write(0x00); // space between characters
    return Wire.endTransmission(true);
  }

  /* REVIEW: Perhaps require s != nullptr as a precondition. */
  uint8_t print(const char* s) {
    if (s != nullptr) {
      while (*s != '\0') {
        const uint8_t error = emit(*(s++));
        if (error != 0) { return error; }
      }
    }
    return 0; // no error if reaching here
  }

  /* REVIEW: Perhaps require s != nullptr as a precondition. */
  uint8_t print_p(const char* s) {
    if (s != nullptr) {
      char c = pgm_read_byte(s++);
      while (c != '\0') {
        const uint8_t error = emit(c);
        if (error != 0) { return error; }
        c = pgm_read_byte(s++);
      }
    }
    return 0; // no error if reaching here
  }
}
