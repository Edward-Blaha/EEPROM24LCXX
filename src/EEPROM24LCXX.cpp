/*-----------------------------------------------------------------------------*/
// Library: EEPROM24LCXX                                                       //
// File: EEPROM24LCXX.cpp                                                      //
// Description: Implementation of I2C communication logic for 24LCxx EEPROMs.  //
// Handles device addressing and Wire protocol sequences.                      //
// Author: Edward Blaha                                                        //
// Last Update: April 2026                                                     //
//                                                                             //
// Dedicated to the public domain via The Unlicense.                           //
// See https://unlicense.org/ for details.                                     //
//                                                                             //
// For more information about this project, please visit                       //
// https://github.com/Edward-Blaha                                             //
/*-----------------------------------------------------------------------------*/
#include "EEPROM24LCXX.h"
void EEPROM24LCXX::begin(){
  Wire.begin();
}
// WRITE SINGLE BYTE TO MEMORY
void EEPROM24LCXX::WriteByte(unsigned int memAddress, byte data) {
  byte deviceAddress = 0x50 | ((memAddress >> 8) & 0x07);
  byte addressByte = memAddress & 0xFF;

  Wire.beginTransmission(deviceAddress);
  Wire.write(addressByte);
  Wire.write(data);
  Wire.endTransmission();

  delay(1);
}

//READ SINGLE BYTE MEMORY &ADDRESS
byte EEPROM24LCXX::ReadByte(unsigned int memAddress) {
  byte deviceAddress = 0x50 | ((memAddress >> 8) & 0x07);
  byte addressByte = memAddress & 0xFF;

  Wire.beginTransmission(deviceAddress);
  Wire.write(addressByte);
  Wire.endTransmission();

  Wire.requestFrom(deviceAddress, (byte)1);
  delay(1);
  return Wire.available() ? Wire.read() : 0xFF;
}

void EEPROM24LCXX::writeStringToEEPROM(unsigned int startAddress, const char* data) {
  int sizeData = strlen(data);
  for (int i = 0; i < sizeData; i++) {
    WriteByte(i + startAddress, data[i]);
    delay(1);
  }
}

//ERASE MEMORY FUNCTION
void EEPROM24LCXX::eraseMemory(byte value = 0xFF) {
  for (unsigned int addr = 0; addr < 2048; addr++) {
    WriteByte(addr, value);
  }
}
