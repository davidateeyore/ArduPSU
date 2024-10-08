# ArduPSU
a small linear psu with arduino based display.

This arduino code is for the little LCD display driven by an Arduino programmed AtMega328 ic, implementing a voltage and current meter for a single ended linear power supply built into a small plastic instrument case salvaged from previous use.

The power supply itself is a standard design using a LM317K TO3 adjustable positive voltage regulator IC on a heatsink, with an added LM431 1.24V ref from -17 volts to allow the output voltage to be adjusted to 0v; the voltmeter is implemented in an Arduino sketch using a builtin ADC in the atMEGA328P IC, its 5V supply along with that of the current sensor and the LCD is provided by a small LDO 5V regulator driven from the main PSU pre-regulator supply; the current meter gets its input from a ACS712 Hall Effect current Sensor ic module available on eBay and elsewhere connected in series with the positive output rail.

This unit is similar in size to the venerable HP/Agilent/Foresight 61xx series little PSUs that adorned every serious scientific lab on the planet! They were a valuable little workhorse, their only failing (in my humble opinion) was having to switch the single meter from voltage to current all the time. My ArduPSU displays both at the same time.

Since this project was started, there are now nice little coloured Volt/Amp meters available on eBay etc. They would be worth looking at for other power projects..

My display module PCB's arrived, but required a new version to suit the little LCDs; This board has an embedded Arduino atMega328 mcu with LCD interface and interfaces to the voltage sensing divider and current sensor. Now up to the V1.1 version to be tested soon! I did consider using a Pictiva OLED (nice bright yellow) but they are proving somewhat intractable.. did also consider the tiny 2 colour I2C OLEDs for Arduino, but it meant rejigging the PSU front panel..  
On that note, it occurs to me that new front panels would be a breeze with OPENScad and my Ender 5 printer! 

the code still requires some further tweaking to improve the voltage and current display updating.. I will use a different library for the A to D interpreting; the current code is not reliable enough.  

schematics/circuit diagrams (I have to redraw them to make them readable!) and pictures to follow..

Update:
The pictiva displays are now working after a second go at the interface pcb, but would take up too much room in the target PSU case, next project possibly.

Update 2:
considering changes to the analog side to provide the 5V to Arduino/Display board from a small IC based buck converter PCB (could add extra RFI to the DC output, however..)

Update 3:
Have now made a version of the PCB to accomodate 8x2 OLEDs (Parallel I/face from VISHAY via Farnell/Element14) much brighter green display on black background. Now working on new front panel in OpenSCAD for a newer box with similar circuitry.

Update 4:
Have decided to put the OLED display PCB in a newer box; more room to clear terminals..Now redoing original unit with LCD and fixing up -ve supply to pull LM317K down to zero volts output..

Update 5: [Happy New Year]
Have located and ordered some cheaper 8x2 OLEDs from AliExpress; will rework the PCB to fit lower profile cases.. The schematic/circuit diagrams are more of a mess than I remembered, they will need redrawing!

Update 6:
The provision of -10V to the 1.24V reference (to bias the LM317K to go down to 0V at output is proving more fiddly than I thought with a single secondary winding transformer...

Update 7:
Have overcome the supply of -10V issue; 2 elcaps and a bridge rectifier and output elcap..must devote more time to this (stop playing with Raspberry Pi PiCO board!)

Update 8:
The -10V supply is working properly, 10V zener to regulate the the input to LMV431 1.24 v ref device. An LM7805 is on a separate board to provide +5V to the ArduPSU module and the ACS712 current sensor. The whole contraption has been shoehorned into its original little case for a couple of weeks of testing; already some nonlinearity of the current sensor has been noticed..

Update 9:
the unit is still working quite well, have enough bits for another one but a PCB for the PSU internals apart from the display Arduino is on the cards!

Update 10:
The voltmeter works OK, but the current detector is not quite right, needs calibrating for a linear current reading..

