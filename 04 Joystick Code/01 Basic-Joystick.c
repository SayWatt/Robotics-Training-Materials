#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,                    sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftMotor,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     rightMotor,    tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 *  Moves the robot based on Joystick values.
 */

#include "JoystickDriver.c"

task main() {
  // Keep running this code
  while(true) {
    // Check to see if there are any updates
    getJoystickSettings(joystick);

    // Set the motor values based on joystick position
    motor[leftMotor] = joystick.joy1_y1;
    motor[rightMotor] = joystick.joy1_y2;

    wait1Msec(20);
  }
}
