/*
   LedHandeler code file
*/

#include "LedHandler.h"
#include <SoftwareSerial.h>

// #define DEBUG

void LedHandler::blinkLed()
{
   if (ledActivity_ == LedActivity::OFF)
   {
      #ifdef DEBUG
         Serial.println("Starting blink command");
      #endif
      startMilliseconds_ = millis();
      ledActivity_ = LedActivity::BLINKING;
      changeState();
   }
}

void LedHandler::initializeLed()
{
   #ifdef DEBUG
      Serial.println("Initializing LED ...");
   #endif
   const int defaultLedPin_ = LED_BUILTIN;
   initializeLed(defaultLedPin_);
}

void LedHandler::initializeLed(int ledPinNumber)
{
   #ifdef DEBUG
      Serial.println(ledPinNumber);
   #endif
   pinMode(ledPinNumber, OUTPUT);
}

void LedHandler::lightLed()
{
   if (ledActivity_ == LedActivity::OFF)
   {
      #ifdef DEBUG
         Serial.println("Starting light command");
      #endif
      startMilliseconds_ = millis();
      ledActivity_ = LedActivity::LIT;
      changeState();
   }
}

void LedHandler::updateLed()
{
   #ifdef DEBUG
      Serial.println("Updating LED ...");
   #endif
   if (ledActivity_ != LedActivity::OFF)
   {
      #ifdef DEBUG
         Serial.println("LED active");
      #endif
      int currentMilliseconds = millis();
      if (currentMilliseconds - startMilliseconds_ >= 3000)
      {
         #ifdef DEBUG
            Serial.println("Light command complete");
         #endif
         completeLightingCommand();
      }      

      if (ledActivity_ == LedActivity::BLINKING)
      {
         if (currentMilliseconds - lastStateChangeInMilliseconds_ >= 500)
         {
            changeState();
         }
      }
   }
}

void LedHandler::changeState()
{
   lastStateChangeInMilliseconds_ = millis();
   // if the LED is off turn it on and vice-versa:
   if (ledState_ == LOW)
   {
      ledState_ = HIGH;
   }
   else
   {
      ledState_ = LOW;
   }
   digitalWrite(ledPinNumber_, ledState_);
}

void LedHandler::completeLightingCommand()
{
   ledActivity_ = LedActivity::OFF;
   ledState_ = LOW;
   digitalWrite(ledPinNumber_, ledState_);
   durationInMilliseconds_ = 0;
   lastStateChangeInMilliseconds_ = 0;
   startMilliseconds_ = 0;
}
