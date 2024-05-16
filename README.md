# InTENS project
# Overview
The InTENS is a high-frequency and high-intensity nerve stimulation treatment for pain management. This project builds on prior research from Boston Univesity's EDF and Bridge BUilders program, guided by a physician, and is supplemented by phantom model testing and a new electrode design. 

# Features
- single-channel system for compactness
- delivers sine waves instead of commercial TENS pulse for user comfort
- capable of delivering frequecnies up of atleast 1kHz
- capable of delivering high-intensity waves of up to 140 Vpp

# Changes required to the board before use:

- Solder a wire between pins 1 and 6 of U1 (best done on the bottom side)
This connects DAC reference to 5V
- Solder a wire between J4 pin 3 and J2 pin 5
- Solder a wire between J4 pin 4 and J2 pin 7
This connects the SPI data and clock to the right Arduino pins
- addd a 100kohm resistor to R5 as 2mA is the reccommended ouptut current (for saftey)(ArduinoSheild PCB) 
- addd a 100kohm resistor to C4 and C6 to reduce load on DC DC conversrters so both can function at same time (Battery PCB) 
- heat sink reccommended on the 5V regulator (U1 on BatteryPCB) 

# User Interface 
Installation of Arduino IDE and Packages
- IDE download - https://www.arduino.cc/en/software
- Pathway to DAC MCP Package - https://github.com/akawaiga/InTENS/tree/main/Arduino 

Setup
- Start Arduino IDE and connect the InTens device to the laptop. Ensure the correct board and output port are selected within the IDE. 
- Ensure the DAC MCP library is downloaded from the GitHub repository
- Set output baud rate to 11500
- Upload the code to the Arduino and turn on both switches

Controlling Frequency and Amplitude
- The initial frequency can be set using the freq variable. 
- The initial amplitude can be set using the desiredAmplitude variable. 
- The increment for the frequency can be set by changing the integer value in code line “freq+=10” and “freq-=10”. 
- The increment for the amplitude can be set by changing the integer value in code line “desiredAmplitude+=10” and “desiredAmplitude-=10”.
- The frequency can be increased by entering “+” in the Arduino IDE.
- The frequency can be decreased by entering “-” in the Arduino IDE.
- The amplitude can be increased by entering “A” in the Arduino IDE. 
- The amplitude can be decreased by entering “a” in the Arduino IDE. 
Note: 
You can compound your increments by adding multiple inputs at once. For example: “+++++” or “AAAA”. Avoid combining inputs such as “AaA”. 
The code currently does not support decimal point increments (float), please use integers such as “1” or “25”. 

# Conclusion
Though with 2 PCBs we have acheived the orginal goal of creating a TENS device capcable of creating a sine wave, >1kHz frequecny, and 140Vpp amplitude, we recommend the following updates to the next iteration of the device:
- Shaft Encoder:incorporate a knob to manually control frequency and amplitude rather than through the IDE. This has been done in previous versions of the device (2021-22) 
- LCD Display:incorporate LCD display to show output frequency and amplitude and various parameter changes when changing parameters using the knob. 
- Float type increments: currently the code uses type int for the amplitude and frequency variables, update this to type float to allow decimal increments. 
- Safety: consult with electrical engineers to build in further safety features to ensure the device does not provide unwanted currents to the patient. 
- Finger Clamp: update the finger clamp design to include jaws (example a claw hair clip) so it can accommodate smaller patient anatomies.
- Phantom Testing: continue developing a phantom model for the finger to demonstrate safety and efficacy.  


  


