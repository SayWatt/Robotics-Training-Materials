#pragma config(Sensor, S1,     lightSensor,         sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

/* This program uses Multi-tasking to follow a line.
 *
 * Essentially, the robot will alternate between being on the left and
 * right side of the line, continually crossing over the line in the middle.
 *
 *
 * Here's a brief description of the two tasks:
 *    - readLightSensor: This task constantly reads the light sensor and
 *                       flips leftSide depending on which side of the line
 *                       it believes the light sensor is on (left vs right).

 *    - main: This task reads the leftSide variable and adjusts the motor
 *            powers depending on which side of the line it believes that it
 *            is on.
 *
 */

bool leftSide = false;

task readLightSensor()
{
  int oldRaw, newRaw;
  int max = 0;
  int min = 100;

  // Initialize the variables.
  oldRaw = SensorValue(lightSensor);
  newRaw = oldRaw;

  // Loops measures the number of loops since we last flipped the boolean
  int loops = 0;

  while(true)
  {
    newRaw = SensorValue[lightSensor];

    /*
     * Check three things:
     *    1) That the sensor value is less than 1/3 of the maximum plus the minimum
     *    2) There was a jump of at least 40, unless it's been a long time since we switched
     *    3) That it's been at least (roughly) 50ms since we last switched, to guarantee we
     *       crossed the line successfully.
     *
     * If all of these are true, we flip the boolean.
     */
    if(newRaw < (max + min)/3 && (abs(oldRaw - newRaw) > 40 || loops > 20) && loops > 10) {
      loops = 0;
      leftSide = !leftSide;
    }

    loops++;

    // Update max and min
    if(newRaw > max) {
      max = newRaw;
    }else if(newRaw < min) {
      min = newRaw;
    }

    oldRaw = newRaw;

    wait1Msec(5);
  }
}

task main()
{
  StartTask(readLightSensor);

  while(true)
  {
    if(leftSide)
    {
      motor[motorB] = 40;
      motor[motorC] = 5;
    }else {
      motor[motorB] = 5;
      motor[motorC] = 40;
    }
  }

}
