

// based on input voltage of 9.83 from DC power supply, will have to adjust based on that 
#include "MCP_DAC.h"

uint16_t freq = 30; // Default frequency (lowered)
float desiredAmplitude = 9.0; // Default desired amplitude (in volts)

MCP4921 MCP;
uint16_t count;
uint32_t lastTime = 0;
uint32_t period = 1000000 / freq; // Declare period outside the while loop

#define WAVE_AMPLITUDE_MAX 4095

uint16_t sine[361]; // Lookup table for sine wave

void setup() {
  Serial.begin(115200);

  SPI.begin();
  MCP.begin(6);  // Select pin = 6

  while (1) {
    yield();
    uint32_t now = micros();

    count++;

    if (now - lastTime > 1000000) { // Update frequency every 1 second (increased time)
      lastTime = now;

      // Calculate amplitude for the sine wave based on the desired amplitude
      float waveAmplitude = (desiredAmplitude / 5.0) * WAVE_AMPLITUDE_MAX / 100.0 -10;
      for (int i = 0; i < 361; i++) {
        sine[i] = 2047 + round(waveAmplitude * sin(i * PI / 180));
      }
    }

    // Generate sine wave output based on lookup table
    uint32_t t = now % period;
    int idx = (360 * t) / period;
    MCP.setPercentage((float)sine[idx] / 4095.0 * 100.0); // Update DAC output with percentage

    if (Serial.available()) {
      char c = Serial.read();
      if (c == '+') freq++;
      else if (c == '-') freq--;
      else if (c == 'a') desiredAmplitude -= 1.0; // Decrease desired amplitude by 1 volt
      else if (c == 's') desiredAmplitude += 1.0; // Increase desired amplitude by 1 volt
      Serial.print("Frequency: ");
      Serial.print(freq);
      Serial.print(" Hz, Desired Amplitude: ");
      Serial.print(desiredAmplitude);
      Serial.println("V");

      // Recalculate period based on updated frequency
      period = 1000000 / freq;
    }
  }
}

void loop() {
}

