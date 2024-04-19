#include "MCP_DAC.h"

uint16_t     freq = 10;
uint32_t   period = 0;
uint32_t   halvePeriod = 0;

//  q = square
//  s = sinus
//  w = sawtooth
//  t = triangle
//  r = random
char mode = 's';

MCP4921 MCP;
uint16_t count;
uint32_t lastTime = 0;
uint16_t desiredAmplitude = 10;

// LOOKUP TABLE SINE
uint16_t sine[361];

#define WAVE_AMPLITUDE_MAX 4095

void setup()
{
  Serial.begin(115200);
  //  fill table with sinus values for fast lookup
  for (int i = 0; i < 361; i++)
  {
    uint16_t waveAmplitude = (desiredAmplitude / 5) * WAVE_AMPLITUDE_MAX / 100;
    sine[i] = 2047 + round(waveAmplitude * sin(i * PI / 180));
  }
  SPI.begin();
  MCP.begin(6);  // select pin = 10
  MCP.fastWriteA(0);

  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  period = 1e6 / freq;
  halvePeriod = period / 2;

  while (1)
  {
    //  Serial.println(analogRead(A0));   //  read output back via A0.
    yield();
    uint32_t now = micros();

    count++;

    if (now - lastTime > 100000)
    {
      lastTime = now;
      //  Serial.println(count);  //  show # updates per 0.1 second
      count = 0;
      if (Serial.available())
      {
        int c = Serial.read();
        switch (c)
        {
          case '+':
            freq+=10;
            break;
          case '-':
            freq-=10;
            break;
          case 'a':
            desiredAmplitude-=10;
            break;
          case 'A':
            desiredAmplitude+=10;
            break;
          default:
            break;
        }
        period = 1e6 / freq;
        halvePeriod = period / 2;
        // Recalculate sine array here
        for (int i = 0; i < 361; i++)
        {
          uint16_t waveAmplitude = (desiredAmplitude / 5) * WAVE_AMPLITUDE_MAX / 100;
          sine[i] = 2047 + round(waveAmplitude * sin(i * PI / 180));
        }
        // Print for debugging
        Serial.println(desiredAmplitude);
      }
    }

    uint32_t t = now % period;

    switch (mode)
    {
      default:
      case 's':
        //  reference
        //  float f = ((PI * 2) * t)/period;
        //  MCP.setValue(2047 + 2047 * sin(f));
        //
        int idx = (360 * t) / period;
        MCP.fastWriteA(sine[idx]);  //  lookup table
        break;
    }
  }
}

void loop()
{
}

//  -- END OF FILE --

