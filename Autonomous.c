#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     IRSensor,       sensorI2CCustom)
#pragma config(Sensor, S3,     touchBoolean1,  sensorTouch)
#pragma config(Sensor, S4,     touchBoolean2,  sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     motorA,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorB,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorC,        tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorF,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* Some comments made by Angie, as the driver during a pair programming session on 11/7/2012*/

#include "JoystickDriver.c"	 //Include file to "handle" the Bluetooth messages.
// #include "/drivers/HTIRS2-driver.h"


void initializeRobot() {
	return;
}
/* A void method is a method that doesn't return anything, just completes actions. (Function that doesn't return 'answer'. Ex. 2+2=4, void will not return 4.)
Stop robot to stop any movement the robot is doing. (Sets power of motor to 0) */
void stopRobot() {
	motor[motorA] = 0;
	motor[motorB] = 0;
	motor[motorC] = 0;
	motor[motorD] = 0;
}
/* Same as StopRobot except power is put into front wheels, by 50%. Power is not the same as speed! Wait: without the wait the robot wouldn't move. */
void moveForward(int duration) {
	motor[motorA] = 50;
	motor[motorD] = 50;
	wait10Msec(duration / 0.01);
	stopRobot();
}
/* Same as first twp only with negative power. (Motor rotates in oposite direction.) */
void moveBackward(int duration) {
	motor[motorA] = -50;
	motor[motorD] = -50;
	wait10Msec(duration / 0.01);
	stopRobot();
}
/* For side wheels, unlike the first few methods that were for the front wheels.Same goes for moveSidewaysReverse */
void moveSideways(int duration) {
	motor[motorB] = 50;
	motor[motorC] = 50;
	wait10Msec(duration / 0.01);
	stopRobot();
}

void moveSidewaysReverse(int duration) {
	motor[motorB] = -50;
	motor[motorC] = -50;
	wait10Msec(duration / 0.01);
	stopRobot();
}
/* Different because two of the motors will go in one direction, two into the other to get the robot to turn. Like pivot turn. */
void turnLeft() {
	motor[motorB] = 50;
	motor[motorD] = 50;
	motor[motorC] = -50;
	motor[motorA] = -50;
	wait10Msec(1/0.01);
}
/*Same as turnLeft*/
void turnRight() {
	motor[motorB] = -50;
	motor[motorD] = -50;
	motor[motorC] = 50;
	motor[motorA] = 50;
	wait10Msec(1/0.01);
}

void raiseArm() {
	motor[motorE] = 10;
	motor[motorF] = 10;
	wait10Msec(1/0.01);
}

void reverseArm() {
	motor[motorE] = -10;
	motor[motorF] = -10;
	wait10Msec(1/0.01);
}

/* Main method is the only method that the computer actually runs. You define the previous methods, but the computer doesn't run them by itself. */
task main() {
	//raiseArm();
	  reverseArm();
	nxtDisplayCenteredTextLine(0, "Running");
	wait10Msec(5/0.01);
}
