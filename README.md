# Sinewave TENS project
3/30 Eric Notes
Looks much better!

Just a few more things....

The GND copper zone is cut in several pieces.  Easiest way to fix this is to add another GND zone on the back.

Just FYI the small potentiometers were fine and it would be better to go back to them.  The ones you have now are single-turn and will be hard to adjust accurately.  You should use 10 turn or 15 turn ones.  For your power estimate, the relevant voltage is not 70V but 5V (the voltage on VREF). 

Changes required to the board:

Solder a wire between pins 1 and 6 of U1 (best done on the bottom side)
This connects DAC reference to 5V
Solder a wire between J4 pin 3 and J2 pin 5
Solder a wire between J4 pin 4 and J2 pin 7
This connects the SPI data and clock to the right Arduino pins


