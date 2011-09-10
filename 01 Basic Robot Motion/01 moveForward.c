#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,                    sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightMotor,    tmotorNormal, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
 *  Moves the robot forward at full speed for two seconds.
 */

task main() {
  // Start the motors
  motor[leftMotor] = 100;
  motor[rightMotor] = 100;

  wait1Msec(2000); // Pause two seconds

  // Stop the motors
  motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}
