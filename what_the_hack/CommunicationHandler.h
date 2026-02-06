/*
   CommunicationHandler class abstracts details of the communication devices in the project.
   Currently supporting: HM10 Bluetooth model
*/

#ifndef _COMMUNICATION_HANDLER_H_
#define _COMMUNICATION_HANDLER_H_

#include <Arduino.h>
#include <SoftwareSerial.h>

class SoftwareSerial;

class CommunicationHandler
{
   public: // class methods
      CommunicationHandler();
      ~CommunicationHandler();
      void initialize();
      void sendData(int id, String data);

   private: // helper methods
      bool isBluetoothConnected();

   private: // data members
      SoftwareSerial *HM10_;
};

#endif // _COMMUNICATION_HANDLER_H_
