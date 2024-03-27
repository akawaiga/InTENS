//
// simple example from the MCP DAC library online
// https://github.com/michd/Arduino-MCP492X
//

#include "MCP_DAC.h" // Include the library

#define PIN_SPI_CHIP_SELECT_DAC 6 // Or any pin you'd like to use
#define PIN_LDAC 7 // nLDAC needs to be set low

#define WAVE_AMP 100

MCP4921 myDac;

void setup() {
  // put your setup code here, to run once:
  pinMode( PIN_LDAC, OUTPUT);
  digitalWrite( PIN_LDAC, LOW);   // MCP4921 datasheet says this may be tied low
  SPI.begin();
  myDac.begin( PIN_SPI_CHIP_SELECT_DAC);
}

void loop() {
  // put your main code here, to run repeatedly:

  // generate a small square wave about the mid-range
  myDac.fastWriteA(2048 + WAVE_AMP);
  delay(10);  // 10ms delay so 1/20ms (50Hz)
  myDac.fastWriteA(2048 - WAVE_AMP);
  delay(10);
}