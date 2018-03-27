#include <LiquidCrystal.h>
#include <Wire.h>
#include <stdlib.h>

/*
Voltmeter-1.ino

:updated 08MAR2017 dt..
voltmeter/ammeter for my little psu
range 0 to 50 Volts in 1024 steps
range 0 to 5 amps in 1024 steps

LCD display driven in "4 bits" mode 

Voltage Analog signal is connected to Arduino's analog port 0
Current Analog signal is output from ACS712 Hall Effect Current sensor connected to analog port 1

my code David Thomas, Cottage Computers September 2015,July/August 2016
based a little on code by didier longueville, december 2007
*/
// hardware related constants
#define VanalogPin 0
#define IanalogPin 1

#define ledPin 13
// VAM related constants

int analogValueMax = 0;
int analogValueMin = 1024;
char Edata[] = "12.24";
char Idata[] = "00.15";
char tempdata[5];
float kVD = 10;  // Divider Ratio

LiquidCrystal meterlcd(12, 11, 10, 8, 7, 6, 5);
// rs, rw, enable, d4, d5, d6, d7
// we need 1 line for voltage, 1 line for current
void setup (void) {
  // intialise ADC's


  // initialise LCD
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  meterlcd.begin(8, 2);
  meterlcd.clear(); 
  meterlcd.print("dt's own");
  meterlcd.setCursor(0,1);  // line 2 
  meterlcd.print(" ArduPSU");
  delay(1500);
  meterlcd.clear();
  meterlcd.print("ver:0.05");
  delay(1500); // so that I can see the init and version!
  meterlcd.clear(); // flush screen..
}

void loop() {
  // put your main code here, to run repeatedly:
// A/D conversion factor should be 1024, not 1023 see Ludington, P26, Circuit Cellar 319 Feb 2017
// updated dt 08MAR2017 
// read the input on analog pin 0:
  int VoltageValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1024) to a voltage (0 - 50V):
  double voltage = VoltageValue * ((5.0 / 1024.0) * kVD); // tweaked to match divider chain..
  // print out the value you read:

// read the input on analog pin 1:
  int CurrentValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1024) to a current (0 - 30A):
  // Jaycar XC-4610 sensor gives 66mV/A
  double current = (CurrentValue * (5.0 / 1024.0) - 2.485); // determined by cut and try!!
  // remove ACS712 offset voltage so that 0 voltage = 0 amps current measured;
  // print out the value you read:

  // meterlcd.clear();
  meterlcd.home(); // top left..
  meterlcd.print("E=");  // the blank default values..
  meterlcd.setCursor(0,1);  // line 2  
  meterlcd.print("I=");
  delay(500);
  meterlcd.setCursor(2,0);
  // voltage = dtostrf(voltage,5,2,tempdata);
  meterlcd.print(voltage); // TODO: display works but need decimal place fixed....
  meterlcd.print("V");	  
  meterlcd.setCursor(0,1);  // line 2
  
  meterlcd.print("I=");
  meterlcd.setCursor(2,1);
  meterlcd.print(current);
  meterlcd.print("A");  
  
  delay(2000); // so i can see it!!
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);  
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW); 
  delay(100); 
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);  
  // 3 blinks to make sure arduino is working..  
  meterlcd.setCursor(0,0);
  // meterlcd.print("E=03.30V");
  delay(500);
  
}
