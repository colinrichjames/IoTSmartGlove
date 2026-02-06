/*
   SensorHandeler code file
*/

#include "SensorHandler.h"

// #define DEBUG

bool SensorHandler::initialize()
{
   bool isInitialized = false;
   const int maxNumberOfInitializationAttempts_ = 100;
   for (int numberOfAttempts = 0; numberOfAttempts < maxNumberOfInitializationAttempts_ && !isInitialized; ++numberOfAttempts)
   {
      isInitialized = mpu.begin();
      #ifdef DEBUG
         else
         {
            checkSettings();
         }
      #endif
      delay(500);
   }
   if (!isInitialized)
   {
      Serial.println("Could not find a valid MPU6050 sensor ...");
   }
   
}

ThreeDVector SensorHandler::getRawAccelerometerData()
{
   Vector rawAccel = mpu.readRawAccel();
   return ThreeDVector(rawAccel.XAxis, rawAccel.YAxis, rawAccel.ZAxis);
}

ThreeDVector SensorHandler::getNormalizedAccelerometerData()
{
   Vector normalizedAcceleration = mpu.readNormalizeAccel();
   return ThreeDVector(normalizedAcceleration.XAxis, normalizedAcceleration.YAxis, normalizedAcceleration.ZAxis);
}

void SensorHandler::checkSettings() {
   Serial.println("Beginning MPU6050 check ...");

   Serial.print(" * Sleep Mode:            ");
   Serial.println(mpu.getSleepEnabled() ? "Enabled" : "Disabled");

   Serial.print(" * Clock Source:          ");
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

   Serial.print(" * Accelerometer:         ");

   switch(mpu.getRange())
   {
      case MPU6050_RANGE_16G:            Serial.println("+/- 16 g"); break;
      case MPU6050_RANGE_8G:             Serial.println("+/- 8 g"); break;
      case MPU6050_RANGE_4G:             Serial.println("+/- 4 g"); break;
      case MPU6050_RANGE_2G:             Serial.println("+/- 2 g"); break;
   }

   Serial.print(" * Accelerometer offsets: ");
   Serial.print(mpu.getAccelOffsetX());
   Serial.print(" / ");
   Serial.print(mpu.getAccelOffsetY());
   Serial.print(" / ");
   Serial.println(mpu.getAccelOffsetZ());
   
   Serial.println("MPU6050 check complete!");
}
