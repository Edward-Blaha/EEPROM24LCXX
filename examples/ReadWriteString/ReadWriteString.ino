/*-----------------------------------------------------------------------------*/
// Project: 24LCXX EEPROM controller lib                                       //
// Description: Example code for writing a string to and reading bytes         //
// from an external 24LCxx family EEPROM using a custom library.               //
// (Code tested with 24LC16)                                                   //
// Author: Edward Blaha                                                        //
// Date: April 2026                                                            //
//                                                                             //
// Dedicated to the public domain via The Unlicense.                           //
// See https://unlicense.org/ for details.                                     //
//                                                                             //
// For more information about this project, please visit                       //
// https://github.com/Edward-Blaha                                             //
/*-----------------------------------------------------------------------------*/

#include <EEPROM24LCXX.h> // custom lib
#include <Arduino.h>
#include <Wire.h>

EEPROM24LCXX eeprom;
char* dataMain = "(LIBRARY TO WRITE TO AN EEPROM UTILISING I2C (designed to work with the 24LCxx family)";
int sizeOfData;
char data[512]; // 512 byte buffer, Change for max amount of data you plan on running within your system
void setup() {
  eeprom.begin();
  delay(50);
  Serial.begin(9600); 
  // Write data using lib
  eeprom.writeStringToEEPROM(0,dataMain); // 0 = starter EEPROM address, dataMain = message
}

void loop() {
  sizeOfData = strlen(dataMain);
  for(int i = 0; i<sizeOfData; i++){ // read Bytes from eeprom, and assign to array
    data[i] = eeprom.ReadByte(i);
  }
  Serial.print("Data Recieved: ");
  Serial.println();
  for(int i = 0; i<sizeOfData; i++){
    Serial.print(data[i]);
  }
  Serial.println("\n");
}
