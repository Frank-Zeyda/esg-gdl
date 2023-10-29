#include "oled.hpp"

/* Using the below with oled::print_p(...) saves precious SRAM. */
static const char PROGMEM s1[] = "Hello ESGs!";
static const char PROGMEM s2[] = "How are you today?";

/* The setup() function is called only once by the AVR run-time. */
void setup() {
  oled::init();
  oled::clear();
}

/* The loop() function is called repetitively by the AVR run-time. */
void loop() {
  oled::move(0, 0);
  oled::print_p(s1);
  oled::move(2, 10);
  oled::print_p(s2);
  while (true) { /* wait forever */ }
}
