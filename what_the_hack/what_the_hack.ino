/*
   Project file for What The Hack Team 12 gesture recognition project.

   Team members:
   - jason bunyea
   - pete fuentes
   - colin james
   - jasmine manansala
   - john west

   TODO: Describe the circuit
*/

#include "ModelAssistant.h"
#include "ThreeDVector.h"

#define DEBUG

bool isInitializationSuccessful = false;
CommunicationHandler communicationHandler;
LedHandler ledHandler;
SensorHandler sensorHandler;
ModelAssistant modelAssistant;

void setup()
{
   #ifdef DEBUG
      Serial.begin(9600);
      Serial.println("Initializing program ...");
   #endif
   isInitializationSuccessful = modelAssistant.initialize();
   if (!isInitializationSuccessful)
   {
      Serial.println("Initialization failed! Check wiring.");
   }
}

void loop()
{
   modelAssistant.updateAssistant();
}
