#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <iostream>
#include "IOHandler.h"
#include <stdio.h>
#include <string.h>
#include <map>
#include <stdexcept>
#include <time.h>
#include <wiringPi.h>
#include <math.h>

#define TRIGGER_PULSE_DURATION 10 		// 10uS !!!
// #define ECHO_TIMEOUT 60			  		// 60ms , let's see what future brings..
#define SENSOR_SETTLING_TIME 60
#define SPEED_OF_LIGHT 343	  			// m/s !!!
#define CORRECTION_CONSTANT 0.0000001 	// 10^-7
#define LOWEST_DISTANCE 2				// 2 cm
#define HIGHTEST_DISTANCE 400			// 400 cm

class HC_SR04 : IOHandler
{
public:
	/*
		Summary:
			Sensor constructor
	*/
	HC_SR04(unsigned short int w_trigger, unsigned short int w_echo);
	/*
		Summary:
			return distance in cm
	*/
	double GetDistance(void);
	/*
		Summary:
			turns all used pins off
	*/
	void SafelyEnd(void);
	/*
		Summary:
			Destructor, Unlocks used pins for IO
	*/
	~HC_SR04(void);

private:
	/*
		Summary:
			Remembers all pins by name and gpio pin number 
	*/
	std::map<std::string, unsigned short int> gpio_wires_map;
	/*
		Summary:
			Trigger pin number
	*/
	short int w_trigger;
	/*
		Summary:
			Echo pin number
	*/
	short int w_echo;
	/*
		Summary:
			returns current nanoseconds from system clock
	*/
	long int GetNanoseconds(void);
};


#endif
