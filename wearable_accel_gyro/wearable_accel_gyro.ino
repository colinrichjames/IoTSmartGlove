/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// include external resources
#include "MPU6050.h"
#include <Wire.h>
#include <SoftwareSerial.h>

#define DEBUG

//
const uint8_t ledPin = 13;

// variables will change:
MPU6050 mpu;

SoftwareSerial HM10(2, 3); // RX = 2, TX = 3
char appData;
String inData = "";

void setup() {
  // initialize the MPU accelerometer and gyroscope:
  Serial.begin(9600);
  HM10.begin(9600); // set HM10 serial at 9600 baud rate
  
  #ifdef DEBUG
    Serial.println("Serial: serial started at 9600");
    HM10.println("HM10: HM10_serial started at 9600\n");
  
    Serial.println("Initialize MPU6050");
  #endif

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)){
    #ifdef DEBUG
      Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    #endif
    delay(500);
  }

  // If you want, you can set accelerometer offsets
  // mpu.setAccelOffsetX();
  // mpu.setAccelOffsetY();
  // mpu.setAccelOffsetZ();

  #ifdef DEBUG
    checkSettings();
  #endif

  HM10.println("Xraw,Yraw,Zraw,Xnorm,Ynorm,Znorm");
}

void loop() {
  Vector rawAccel = mpu.readRawAccel();
 	Vector normAccel = mpu.readNormalizeAccel();

  #ifdef DEBUG
 	  Serial.print(" Xraw = ");
 	  Serial.print(rawAccel.XAxis);
 	  Serial.print(" Yraw = ");
 	  Serial.print(rawAccel.YAxis);
 	  Serial.print(" Zraw = ");

 	  Serial.println(rawAccel.ZAxis);
 	  Serial.print(" Xnorm = ");
 	  Serial.print(normAccel.XAxis);
 	  Serial.print(" Ynorm = ");
 	  Serial.print(normAccel.YAxis);
 	  Serial.print(" Znorm = ");
 	  Serial.println(normAccel.ZAxis);
  #endif

  String accel_data = String(rawAccel.XAxis) + "," + String(rawAccel.YAxis) + "," + String(rawAccel.ZAxis) + "," + 
    String(normAccel.XAxis) + "," + String(normAccel.YAxis) + "," + String(normAccel.ZAxis);

  HM10.println(accel_data);
 	
 	delay(10);
}

void checkSettings() {
  #ifdef DEBUG
    Serial.println();

    Serial.print(" * Sleep Mode:            ");
    Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");

    Serial.print(" * Clock Source:          ");
  #endif

  switch(mpu.getClockSource())
  {
    case MPU6050_CLOCK_KEEP_RESET:     Serial.println("Stops the clock and keeps the timing generator in reset"); break;
    case MPU6050_CLOCK_EXTERNAL_19MHZ: Serial.println("PLL with external 19.2MHz reference"); break;
    case MPU6050_CLOCK_EXTERNAL_32KHZ: Serial.println("PLL with external 32.768kHz reference"); break;
    case MPU6050_CLOCK_PLL_ZGYRO:      Serial.println("PLL with Z axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_YGYRO:      Serial.println("PLL with Y axis gyroscope reference"); break;
    case MPU6050_CLOCK_PLL_XGYRO:      Serial.println("PLL with X axis gyroscope reference"); break;
    case MPU6050_CLOCK_INTERNAL_8MHZ:  Serial.println("Internal 8MHz oscillator"); break;
  }

  #ifdef DEBUG
    Serial.print(" * Accelerometer:         ");
  #endif
  
  switch(mpu.getRange())
  {
    case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
    case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
    case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
    case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
  }

  #ifdef DEBUG
    Serial.print(" * Accelerometer offsets: ");
    Serial.print(mpu.getAccelOffsetX());
    Serial.print(" / ");
    Serial.print(mpu.getAccelOffsetY());
    Serial.print(" / ");
    Serial.println(mpu.getAccelOffsetZ());

    Serial.println();
  #endif
}
