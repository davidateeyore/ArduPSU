# ArduPSU
a small linear psu with arduino based display.

This arduino code is for the little LCD display driven by an Arduino programmed AtMega328 ic, implementing a voltage and current meter for a single ended linear power supply built into a small plastic instrument case salvaged from previous use.

The power supply itself is a standard design using a LM317K TO3 adjustable positive voltage regulator IC on a heatsink; the voltmeter is implemented in an Arduino sketch using a builtin ADC in the atMEGA328P IC; the current meter gets its input from a current Sensor ic module available on eBay and elsewhere connected in series with the positive output rail.

This unit is similar in size to the venerable HP/Agilent/Foresight 61xx little PSUs that adorned every serious scientific lab on the planet! They were a valuable little workhorse, their only failing (in my humble opinion) was having to switch the single meter from voltage to current all the time. My ArduPSU displays both at the same time.

schematics/circuit diagrams and pictures to follow..
