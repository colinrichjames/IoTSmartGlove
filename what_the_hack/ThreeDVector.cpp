/*
   ThreeDVector code file
*/

#include "ThreeDVector.h"

ThreeDVector::ThreeDVector()
{
}

ThreeDVector::ThreeDVector(float xAcceleration, float yAcceleration, float zAcceleration)
{
   setXAcceleration(xAcceleration);
   setYAcceleration(yAcceleration);
   setZAcceleration(zAcceleration);
}

float ThreeDVector::getXAcceleration()
{
   return xAcceleration_;
}

float ThreeDVector::getYAcceleration()
{
   return yAcceleration_;
}

float ThreeDVector::getZAcceleration()
{
   return zAcceleration_;
}

String ThreeDVector::printCommaDelimited()
{
   return String(getXAcceleration()) + "," + String(getYAcceleration()) + "," + String(getZAcceleration());
}

void ThreeDVector::setXAcceleration(float xAcceleration)
{
   xAcceleration_ = xAcceleration;
}

void ThreeDVector::setYAcceleration(float yAcceleration)
{
   yAcceleration_ = yAcceleration;
}

void ThreeDVector::setZAcceleration(float zAcceleration)
{
   zAcceleration_ = zAcceleration;
}
