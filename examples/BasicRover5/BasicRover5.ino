/*
*************************************************************************************
In this example, we will demonstrate how to driver a Rover5 (4 wheel drive version)
using the "Dagu Rover5 Motor Driver board".

Created by Dominique CLAUSE
Created: 19/01/2020
*/

#include <Rover5.h>

// ########################
// Pins usage.

//Motor wheel 1 (Left Front)
const int pwm_1 = 2;
const int dir_1 = 3;

//Motor wheel 2 (Rear Front)
const int pwm_2 = 5;
const int dir_2 = 6;

// Motor wheel 3 (Right Rear)
const int pwm_3 = 8;
const int dir_3 = 9;

// Motor wheel 4 (Left Rear)
const int pwm_4 = 11;
const int dir_4 = 12;

// ########################
// Rover instantiation.
Rover5 rover(pwm_1, pwm_2, pwm_3, pwm_4, dir_1, dir_2, dir_3, dir_4);

void setup(){
	Serial.begin(9600);
	Serial.println("Rover 5 Example");
}

void loop(){
	// Move forward for 2 second.
	rover.moveForward(255);
	delay(2000);
	
	// Turn left for 1 second.
	rover.turnLeft(255);
	delay(1000);
	
	// Stop for 2 seconds.
	rover.stop();
	delay(2000);
}