/*
   SensorHandler class abstracts details of the sensors in the project.
   Currently supporting: MPU6050 sensor
*/

#ifndef _SENSOR_HANDLER_H_
#define _SENSOR_HANDLER_H_

#include "MPU6050.h"
#include "ThreeDVector.h"

class SensorHandler
{
   public: // class methods
      bool initialize();
      ThreeDVector getRawAccelerometerData();
      ThreeDVector getNormalizedAccelerometerData();

   private: // helper methods
      void checkSettings();

   private: // data members
      MPU6050 mpu;
};

#endif // _SENSOR_HANDLER_H_
