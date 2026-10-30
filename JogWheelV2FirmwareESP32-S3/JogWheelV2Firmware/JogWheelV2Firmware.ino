#include <ESP32Encoder.h>
#include "keydef.h"
#include <elapsedMillis.h>
typedef void (*taskPointer) ();
taskPointer callTask;
elapsedMillis taskTimer;
long eventTime = 0;
bool eventQued = false;
String commandRecieved;

bool normalMode = true;

//void setDelayedFunctionCall(long msDelay,taskPointer task ){
//  callTask = task;
//  eventQued = true;
//  eventTime = msDelay;
//}

#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;
USBCDC USBSerial ;

#include "keyBindings.h"
#include "actions.h"

#include "pins.h"
//#include "BigEncoder.h"
#include "auxEncoders.h"
#include "keyMatrixHandler.h"
#include "eventsAndActions.h"



elapsedMillis SocketTiming;
#define socketUpdateRate 50



void setup() {
  ESP32Encoder::useInternalWeakPullResistors = puType::up;
  // put your setup code here, to run once:
  initEncoders();
  //initWheel();
  EEPROM.begin(10000);
  USBSerial.begin();
  USB.begin();
  Keyboard.begin();
  initKeyMatrix();//from keyMatrixHandler.h
  initKeybindings();
}
  
  


void loop() {
  //processBigWheel();//from "BigEncoder.h"
  readAuxEncoders();//from "auxEncoders.h"
  handleMatrix();
  eventLoop();
  //
  //if (SocketTiming>= socketUpdateRate){
    /*
    if(!normalMode){
      Serial.print("BWP ");
      Serial.print(bigWheelPos);
      Serial.print(" ENP ");
      Serial.print(knobPositions[0]);
      Serial.print(" ");
      Serial.print(knobPositions[1]);
      Serial.print(" ");
      Serial.print(knobPositions[2]);
      Serial.print(" ");
      Serial.print(knobPositions[3]);
      Serial.print(" SW");
      for(int i=0; i<18;i++){
        Serial.print(" ");
        Serial.print(dBSwState[i]);
      }
      
      Serial.println("");
    }
    SocketTiming=0;
  //}*/
}
