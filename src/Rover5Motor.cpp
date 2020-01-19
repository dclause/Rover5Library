/*  
*************************************************************************************
Rover5Motor.cpp - Library for driving the Rover5 using Rover5 Motor Driver board.

Created by Dominique CLAUSE
Created: 19/01/2020
*************************************************************************************
Notes
pwmPin: Digital pin to set motor speed
dirPin: Digital pin to set motor direction
currPin: Analog pin to monitor current usage
*************************************************************************************
*/

#include "Arduino.h"
#include "Rover5Motor.h"

Rover5Motor::Rover5Motor(int pwmPin, int dirPin, int currPin) :
  _pwm(pwmPin),
  _dir(dirPin),
  _curr(currPin),
  _currRate(0),
  _speed(0)
{ }

void Rover5Motor::begin()
{
	pinMode(_pwm, OUTPUT);
	pinMode(_dir, OUTPUT);
	pinMode(_curr, INPUT);
}

void Rover5Motor::stop()
{
	digitalWrite(_pwm, LOW);
	setSpeed(0);
}

void Rover5Motor::setSpeed(int speedMotor)
{
	speedMotor = constrain(speedMotor, 0, 255);
	analogWrite(_pwm, speedMotor);
	_speed=speedMotor;
}

void Rover5Motor::setDirection(bool direction)
{
	if (direction == ROVER5_MOTOR_DIRECTION_BACKWARD)
	{
		digitalWrite(_dir, LOW);
	}
	else
	{
		digitalWrite(_dir, HIGH);
	}
}

int Rover5Motor::getCurrent()
{
	_currRate = analogRead(_curr);
	return _currRate;
}

int Rover5Motor::getSpeed()
{
     return _speed;
}






	
