/*
   LedHandler class abstracts details of the led indicator in the project.
*/

#ifndef _LED_HANDLER_H_
#define _LED_HANDLER_H_

#include <Arduino.h>

class LedHandler
{
   public: // class methods
      void blinkLed();
      void initializeLed();
      void initializeLed(int ledPinNumber);
      void lightLed();
      void updateLed();

   private: // helper methods
      void changeState();
      void completeLightingCommand();
      bool isLedActive();
      bool isActivityTimeComplete();

   private: // data members
      int durationInMilliseconds_ = 0;
      int lastStateChangeInMilliseconds_ = 0;
      int ledPinNumber_ = 0;
      int ledState_ = LOW;
      int ledActivity_ = LedActivity::OFF;
      int startMilliseconds_ = 0;

   private:
      enum LedActivity
      {
         OFF = 0,
         LIT = 1,
         BLINKING = 2,
      };
};

#endif // _LED_HANDLER_H_
