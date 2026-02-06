/*
   LedHandeler code file
*/

#include "CommunicationHandler.h"

#define DEBUG

CommunicationHandler::CommunicationHandler()
{
}

CommunicationHandler::~CommunicationHandler()
{
   delete HM10_;
}

void CommunicationHandler::initialize()
{
   const int bluetoothReceivePin_ = 2;
   const int bluetoothTransmitPin_ = 3;
   HM10_ = new SoftwareSerial(2, 3);
   HM10_->begin(9600); // set HM10 serial at 9600 baud rate
   pinMode(bluetoothReceivePin_, INPUT);
   pinMode(bluetoothTransmitPin_, OUTPUT);
   #ifdef DEBUG
      Serial.println("HM10: HM10_serial started at 9600\n");
      HM10_->println("HM10: HM10_serial started at 9600\n");
   #endif
}

void CommunicationHandler::sendData(int id, String data)
{
   if (isBluetoothConnected())
   {
      String message = "{\"ID\" : \"" + String(id) + "\", \"DATA\" : \"" + data + "\"}";
      #ifdef DEBUG
         Serial.println(message);
      #endif
      HM10_->println(message);
   }
   else
   {
      #ifdef DEBUG
         Serial.println("No connections with which to send data!");
      #endif
   }
}

bool CommunicationHandler::isBluetoothConnected()
{
   // TODO: detect bluetooth connection
   return true;
}
