/*-----------------------------------------------------------------------------*/
// Library: EEPROM24LCXX                                                       //
// File: EEPROM24LCXX.h                                                        //
// Description: Class Definition for the EEPROM24LCXX lib                      //
// Author: Edward Blaha                                                        //
// Last Update: April 2026                                                     //
//                                                                             //
// Dedicated to the public domain via The Unlicense.                           //
// See https://unlicense.org/ for details.                                     //
//                                                                             //
// For more information about this project, please visit                       //
// https://github.com/Edward-Blaha                                             //
/*-----------------------------------------------------------------------------*/
#ifndef EEPROM24LCXX_H
#define EEPROM24LCXX_H
#include <Wire.h>
#include <Arduino.h>
class EEPROM24LCXX{
public:
  void begin();
  byte ReadByte(unsigned int memAddress);
  void WriteByte(unsigned int memAddress, byte data);
  void writeStringToEEPROM(unsigned int startAddress, const char* data);
  void eraseMemory(byte value = 0xFF);
};
#endif
