/*
 * - Description: This code only write to LX-16A. If you want to Read from Servo, you must buy Servo controller:
 * http://hshop.vn/products/dong-co-serial-bus-rc-servo-lx-16a
 * 

      Wiring:

      Extenal Power------- Arduino Uno  -------------  RC LX-16A
                              3                           S
          GND  -------------- GND ----------------------  -
           5v (>1A) -----------------------------------   +                  
     
*/


#include "LobotServo.h"
SoftwareSerial SerialRC(2,3);
uint8_t _id_ = 1;
uint8_t _mode = 0;    // 0 for Servo mode; 1 for DC mode
uint16_t _speed = 1000;
uint16_t _position = 1000;
uint16_t _time = 1000;

void setup() {
  // put your setup code here, to run once:
  SerialRC.begin(115200);
  
// Please connect one by one servo when setting ID///////////////////////
  uint8_t _oldID = 254; // This is broadcad ID, in case you do not know your ID of the servo.
  uint8_t _newID = 1;
  LobotSerialServoSetID(SerialRC, _oldID, _newID);
/////////////////////////////////////////////////////////////////////////
  
  LobotSerialServoSetMode(SerialRC,_id_, _mode, _speed);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  _position = 500;
  _time= 2000;
  LobotSerialServoMove(SerialRC, _id_, _position, _time);
  delay(2000);

  _position = 1000;
  _time= 1000;
  LobotSerialServoMove(SerialRC, _id_, _position, _time);
  delay(1000);

}
