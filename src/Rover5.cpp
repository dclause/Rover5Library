/*  
*************************************************************************************
Rover5.h - Library for driving the Rover5 using Rover5 Motor Driver board.

Created by Dominique CLAUSE
Created: 19/01/2020
*************************************************************************************
*/

#include "Arduino.h"
#include "Rover5.h"

Rover5::Rover5(int left_pwmPin, int right_pwnPin, int left_dirPin, int right_dirPin, int left_currPin, int right_currPin):
	_motor1(left_pwmPin, left_dirPin, left_currPin),
	_motor2(right_pwnPin, right_dirPin, right_currPin),
	_motor3(0, 0, 0),
	_motor4(0, 0, 0),
	_nMotors(2),
	_isMoving(false)
{
	_motor1.begin();
	_motor2.begin();
}

Rover5::Rover5(int leftFront_pwmPin, int rightFront_pwnPin, int leftRear_pwmPin, int rightRear_pwnPin, int leftFront_dirPin, int rightFront_dirPin, int leftRear_dirPin, int rightRear_dirPin, int leftFront_currPin, int rightFront_currPin, int leftRear_currPin, int rightRear_currPin):
	_motor1(leftFront_pwmPin, leftFront_dirPin, leftFront_currPin),
	_motor2(rightFront_pwnPin, rightFront_dirPin, rightFront_currPin),
	_motor3(rightRear_pwnPin, rightRear_dirPin, rightRear_currPin),
	_motor4(leftRear_pwmPin, leftRear_dirPin, leftRear_currPin),
	_nMotors(4),
	_isMoving(false)
{
	_motor1.begin();
	_motor2.begin();
	_motor3.begin();
	_motor4.begin();
}

void Rover5::moveForward(int speed)
{
	_motor1.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
	_motor2.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
	_motor1.setSpeed(speed);
	_motor2.setSpeed(speed);
	
	if (_nMotors == 4)
	{
		_motor3.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
		_motor4.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
		_motor3.setSpeed(speed);
		_motor4.setSpeed(speed);
	}
	
	_isMoving = true;
}

void Rover5::moveBackward(int speed)
{
	_motor1.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
	_motor2.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
	_motor1.setSpeed(speed);
	_motor2.setSpeed(speed);
	
	if (_nMotors == 4)
	{
		_motor3.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
		_motor4.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
		_motor3.setSpeed(speed);
		_motor4.setSpeed(speed);
	}
	
	_isMoving = true;
}

void Rover5::stop()
{
	_motor1.stop();
	_motor2.stop();
	_motor3.stop();
	_motor4.stop();
	_isMoving = false;
}

void Rover5::turnLeft(int speed)
{
	_motor1.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
	_motor2.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
	_motor1.setSpeed(speed);
	_motor2.setSpeed(speed);
	
	if (_nMotors == 4)
	{
		_motor3.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
		_motor4.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
		_motor3.setSpeed(speed);
		_motor4.setSpeed(speed);
	}
	
	_isMoving = true;
}

void Rover5::turnRight(int speed)
{
	_motor1.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
	_motor2.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
	_motor1.setSpeed(speed);
	_motor2.setSpeed(speed);
	
	if (_nMotors == 4)
	{
		_motor3.setDirection(ROVER5_MOTOR_DIRECTION_FORWARD);
		_motor4.setDirection(ROVER5_MOTOR_DIRECTION_BACKWARD);
		_motor3.setSpeed(speed);
		_motor4.setSpeed(speed);
	}
	
	_isMoving = true;
}

int Rover5::getNbreMotors()
{
	return _nMotors;
}

bool Rover5::isMoving()
{
	return _isMoving;
}

Rover5Motor& Rover5::getMotorLeft()
{
	return _motor1;
}

Rover5Motor& Rover5::getMotorRight()
{
	return _motor2;
}


Rover5Motor& Rover5::getMotorLeftFront()
{
	return _motor1;
}

Rover5Motor& Rover5::getMotorRightFront()
{
	return _motor2;
}


Rover5Motor& Rover5::getMotorLeftRear()
{
	return _motor3;
}

Rover5Motor& Rover5::getMotorRightRear()
{
	return _motor4;
}