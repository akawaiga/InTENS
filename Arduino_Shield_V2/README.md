# Design review 2/22/24

**Schematic / Overall**

* Why the change to the TSSOP package for the LTC6090?.  The SO-8
  package is much easier to solder and in stock.
* Missing HV power supplies on the LTC6090.  You need to be able to
  supply external power to this for testing at voltages above 5V.
  Suggest to add a 3 pin connector with +HV, GND, -HV which are
  connected to the V+, GND, V- on the LTC6090
* The chips are missing bypass capacitors.  Please read over the
  datahsheets for recommendations.  These are capacitors to GND on
  each power supply to a chip (so total of 3 minimum, Vdd the MCP4921
  and two on V+ and V- of the LTC6090)  
* Mounting holes should be on schematic
* Name symbols consistently:  you have U1 and IC1 where you should
  have U1 and U2.
* Don't interconnect the two SDA and SCL pins on the Arduino.

**PCB Layout**

The layout looks nice and neat, but there are quite a few issues which
should be addressed to ensure good performance:

* There must be an overall GND plane.  This is most easily done by
  converting the design to 4 layers and using an inner layer for this.
* The bypass capacitors mentioned above need to be placed near the
  chips.
* The datasheet for the LTC6090 (did you read it?) specifically
  reccomends surface-mount components.  I highly recommend switching
  all the passives (R, C) to surface mount.  An 0805 or 1206 size is
  quite large and easy to use.  I can help you with soldering them.

The wiring seems a bit random... did you use the autoroute feature?
Never do that.


  
