/*
   3dVector class provides a convenience wrapper for sensor data.
*/

#ifndef _THREE_D_VECTOR_H_
#define _THREE_D_VECTOR_H_

#include <Arduino.h>

class ThreeDVector
{
   public:
      ThreeDVector();
      ThreeDVector(float xAcceleration, float yAcceleration, float zAcceleration);
      float getXAcceleration();
      float getYAcceleration();
      float getZAcceleration();
      String printCommaDelimited();
      void setXAcceleration(float xAcceleration);
      void setYAcceleration(float yAcceleration);
      void setZAcceleration(float zAcceleration);

   private:
      float xAcceleration_ = 0;
      float yAcceleration_ = 0;
      float zAcceleration_ = 0;
};

#endif // _THREE_D_VECTOR_H_
