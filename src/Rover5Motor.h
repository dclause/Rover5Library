/*  
*************************************************************************************
Rover5Motor.h - Library for driving the Rover5 using Rover5 Motor Driver board.

Created by Dominique CLAUSE
Created: 19/01/2020
*************************************************************************************
Notes
pwmPin: Digital pin to set motor speed
dirPin: Digital pin to set motor direction
currPin: Analog pin to monitor current usage
*************************************************************************************
*/

#ifndef ROVER5MOTOR_H
#define ROVER5MOTOR_H

#define ROVER5_MOTOR_DIRECTION_FORWARD true
#define ROVER5_MOTOR_DIRECTION_BACKWARD false

#include "Arduino.h"

class Rover5Motor
{
public:
	Rover5Motor(int pwmPin, int dirPin, int currPin = 0);
	void begin();
	void stop();
	void setSpeed(int speedMotor);
	void setDirection(bool isMotor);
	int getCurrent();
	int getSpeed();

private:  
    int _pwm;
    int _dir;
    int _curr;
    int _currRate;
    int _speed;
};

#endif