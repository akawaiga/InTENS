# Sinewave TENS project
3/29 Eric Notes (1st)
The board looks like a good start, just a few things:
-  The DC/DC is the wrong part number.  It should be R05-100B.

-  The DC/DC converters should be mounted in sockets.  I suggest to use a DIP-24_W15.24mm footprint.
   There will be extra pins; just ignore them.

-  The 7805 regulator you chose won't work with 6V input.  It has a "drop out" voltage (minimum input to output of 2V).  You need, as I mentioned, an "LDO" (low drop-out) regulator.  For example LF50CV, DigiKey# 497-8357-5-ND.  It has the same footprint so you just have to order a different part, though you should update the schematic.

-  The wiring is wrong around U3.  Connect:
    +VOUT to GND
    - VOUT to -VSW (as it is)
    Cap C6 from -VOUT to GND

-  The 5V needs to go to +VIN on both DC/DC converters.  -VIN goes to GND.

-  For the switches, I suggest to use a switch like this which you can access from outside the box.  DigiKey# 2449-ANT11TFHQE-ND.


Or if that's too big, one of these.  DigiKey CKN9629-ND


If you can fix these things today I'll take another look.

3/29 Eric Notes (2nd)
Sorry to say, but there are even more wiring problems now.
I strongly suggest you make the symbols for the DC/DC look like the one
in the datasheet; this will make the schematic much easier.


If you use this type of symbol then your schematic becomes much
easier to read and understand, something like this, more or less what
I sketched on paper.

I think you need to redraw it; the current schematic is just too hard
to check carefully, and the current schematic has too many errors.
I'm attaching the version I sketched as a zip.

If you want to use it, feel free, but you will need to re-associate the footprints, etc.



