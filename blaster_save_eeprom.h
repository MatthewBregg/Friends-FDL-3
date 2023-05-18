#include <EEPROM.h>
#pragma once

// Will divide by 500 and save that value. 
// Store two bytes as a form of checksum.
void write_speed_to_eeprom(unsigned long setpoint_rpm) {
byte value = setpoint_rpm / 500;

EEPROM.write(0, value);
EEPROM.write(1, value);

}

unsigned long read_speed_from_eeprom() {
  byte value_1 = EEPROM.read(0);
  byte value_2 = EEPROM.read(1);
  if (value_1 == value_2) {
    return value_1 * 500;
  }

  // Otherwise return the default, safe RPM.
  return 12500;
}