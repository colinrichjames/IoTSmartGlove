/*
   ModelAssistant class abstracts details of the gesture recognition model and various devices supported through handlers in the project.
*/

#ifndef _MODEL_ASSISTANT_H_
#define _MODEL_ASSISTANT_H_

#include "LedHandler.h"
#include "SensorHandler.h"
#include "CommunicationHandler.h"
#include "ThreeDVector.h"

class ModelAssistant
{
   public: // class methods
      ModelAssistant();
      ~ModelAssistant();
      bool initialize();
      void updateAssistant();
      // TODO: this callback should accept a string or int to describe the gesture detected
      void gestureDetectedCallback();

   private:
      bool areReadingsInSync();
      void clearReadings();
      bool isPossibleGesture();
      void sendReadingsToModel();
      void updateReadings();

   private:
      const int updateIntervalInMilliseconds_ = 100;
      int currentUpdateTimeInMilliseconds_ = 0;
      int previousUpdateTimeInMilliseconds_ = 0;
      int maxSizeOfReadings_ = 300;
      CommunicationHandler communicationHandler_;
      LedHandler ledHandler_;
      SensorHandler sensorHandler_;
      ThreeDVector rawData_[30];
      ThreeDVector normData_[30];
};

#endif // _MODEL_ASSISTANT_H_
