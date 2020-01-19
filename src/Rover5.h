/*  
*************************************************************************************
Rover5.h - Library for driving the Rover5 using Rover5 Motor Driver board.

Created by Dominique CLAUSE
Created: 19/01/2020
*************************************************************************************
*/

#ifndef ROVER5_H
#define ROVER5_H

#include "Arduino.h"
#include "Rover5Motor.h"

class Rover5
{
public:
	Rover5(int left_pwmPin, int right_pwnPin, int left_dirPin, int right_dirPin, int left_currPin = 0, int right_currPin = 0);
	Rover5(int leftFront_pwmPin, int rightFront_pwnPin, int leftRear_pwmPin, int rightRear_pwnPin, int leftFront_dirPin, int rightFront_dirPin, int leftRear_dirPin, int rightRear_dirPin, int leftFront_currPin = 0, int rightFront_currPin = 0, int leftRear_currPin = 0, int rightRear_currPin = 0);
	void moveForward(int speed);
	void moveBackward(int speed);
	void turnLeft(int speed);
	void turnRight(int speed);
	void stop();
	
	int getNbreMotors();
	bool isMoving();
	
	Rover5Motor getMotorLeft();
	Rover5Motor getMotorRight();
	Rover5Motor getMotorLeftFront();
	Rover5Motor getMotorRightFront();
	Rover5Motor getMotorLeftRear();
	Rover5Motor getMotorRightRear();

private:  
	Rover5Motor _motor1;
	Rover5Motor _motor2;
	Rover5Motor _motor3;
	Rover5Motor _motor4;
	int _nMotors;
	bool _isMoving;
};

#endif