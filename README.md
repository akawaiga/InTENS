# InTENS project
# Overview
The InTENS is a high-frequency and high-intensity nerve stimulation treatment for pain management. This project builds on prior research from Boston Univesity's EDF and Bridge BUilders program, guided by a physician, and is supplemented by phantom model testing and a new electrode design. 

# Features
- single-channel system for compactness
- delivers sine waves instead of commercial TENS pulse for user comfort
- capable of delivering frequecnies up of atleast 1kHz
- capable of delivering high-intensity waves of up to 140 Vpp

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
The increment for the frequency can be set by changing the integer value in code line “freq+=10” and “freq-=10”. 
The increment for the amplitude can be set by changing the integer value in code line “desiredAmplitude+=10” and “desiredAmplitude-=10”.
The frequency can be increased by entering “+” in the Arduino IDE.
The frequency can be decreased by entering “-” in the Arduino IDE.
The amplitude can be increased by entering “A” in the Arduino IDE. 
The amplitude can be decreased by entering “a” in the Arduino IDE. 
Note: 
You can compound your increments by adding multiple inputs at once. For example: “+++++” or “AAAA”. Avoid combining inputs such as “AaA”. 
The code currently does not support decimal point increments (float), please use integers such as “1” or “25”. 


Changes required to the board:

Solder a wire between pins 1 and 6 of U1 (best done on the bottom side)
This connects DAC reference to 5V
Solder a wire between J4 pin 3 and J2 pin 5
Solder a wire between J4 pin 4 and J2 pin 7
This connects the SPI data and clock to the right Arduino pins


