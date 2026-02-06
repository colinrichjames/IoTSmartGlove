/*
   ModelAssistant code file
*/

#include "ModelAssistant.h"

#define DEBUG

ModelAssistant::ModelAssistant() :
      currentUpdateTimeInMilliseconds_(0),
      previousUpdateTimeInMilliseconds_(0),
      maxSizeOfReadings_(300),
      communicationHandler_(),
      ledHandler_(),
      sensorHandler_()
{
}

ModelAssistant::~ModelAssistant()
{
}

bool ModelAssistant::initialize()
{
   bool success = sensorHandler_.initialize();
   ledHandler_.initializeLed();
   communicationHandler_.initialize();
   #ifdef DEBUG
      communicationHandler_.sendData(2, "Xraw,Yraw,Zraw,Xnorm,Ynorm,Znorm");
   #endif
   return success;
}

void ModelAssistant::updateAssistant()
{
   ledHandler_.updateLed();
   currentUpdateTimeInMilliseconds_ = millis();
   if (currentUpdateTimeInMilliseconds_ - previousUpdateTimeInMilliseconds_ >= updateIntervalInMilliseconds_)
   {
      #ifdef DEBUG
         Serial.println("Model assistant updating");
      #endif
      updateReadings();
      if (isPossibleGesture())
      {
         sendReadingsToModel();
      }
      previousUpdateTimeInMilliseconds_ = currentUpdateTimeInMilliseconds_;
   }
}

// TODO: this callback should accept a string or int to describe the gesture detected
void ModelAssistant::gestureDetectedCallback()
{
   bool isValidGesture = true;
   // TODO: update building message data with the type of gesture detected in either enumeration or defined String format
   String messageData;
   if (isValidGesture)
   {
      ledHandler_.lightLed();
      messageData = "Type of gesture detected";
   }
   else
   {
      ledHandler_.blinkLed();
      messageData = "No gesture detected";
   }
   communicationHandler_.sendData(1, messageData);
}

bool ModelAssistant::isPossibleGesture()
{
   // TODO: implement segmentation and detection
   return false;
}

void ModelAssistant::sendReadingsToModel()
{
   // TODO: implement call to send readings to model
}

void ModelAssistant::updateReadings()
{
   ThreeDVector rawData = sensorHandler_.getRawAccelerometerData();
   ThreeDVector normData = sensorHandler_.getNormalizedAccelerometerData();
   String currentReading = rawData.printCommaDelimited() + "," + normData.printCommaDelimited();
   Serial.println(currentReading);
   // normalizedSensorReadings_.Append(sensorHandler_.getNormalizedAccelerometerData());
   // rawSensorReadings_.Append(sensorHandler_.getRawAccelerometerData());
   #ifdef DEBUG
      // String currentReading = normalizedSensorReadings_.Last().printCommaDelimited() + "," + rawSensorReadings_.Last().printCommaDelimited();
      // communicationHandler_.sendData(2, currentReading);
   #endif
}
