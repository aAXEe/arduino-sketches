/*
  Demo program for RGB Sketch
  
  Author: Axel Utech <axel@brashack.de>
  License: MIT (see bottom of sketch)
*/

// constant pin numbers for led outputs
const int pinRed = 3;
const int pinGreen = 5;
const int pinBlue = 6;

// runtime variables for each color brightness
int valueRed = 0;
int valueGreen = 100;
int valueBlue = 200;

void setup(){
  Serial.begin(9600);
  Serial.println("RGB Demo Sketch");
  
  // set output mode for pins
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
}

void loop(){   
  // increase each value by 1
  // if value is greater than 255 ( = maximal birgthness) then set value to 0
  valueRed++;
  if(valueRed >= 255) {
    valueRed = 1;
  }
  analogWrite(pinRed, valueRed); // PWM output
  
  valueGreen++;
  if(valueGreen >= 255) {
    valueGreen = 1;
  }
  analogWrite(pinGreen, valueGreen);
  
  valueBlue++;
  if(valueBlue >= 255) {
    valueBlue = 1;
  }
  analogWrite(pinBlue, valueBlue); 
  
  // display current values via serial console
  Serial.print("Ausgabewert: red: ");
  Serial.print(valueRed);
  Serial.print(" green:");
  Serial.print(valueGreen);
  Serial.print(" blue:");
  Serial.print(valueBlue);
  Serial.println(); 
  
  // wait for 100 ms between loops
  delay(100);
}

/*
The MIT License (MIT)

Copyright (c) 2016 Axel Utech

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
