#ifndef STEPPER_MOTOR_H
#define STEPPER_MOTOR_H


#include <wiringPi.h>
#include "IOHandler.h"
#include <map>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <string.h>

#define FULL_ROTATION_STEPS 4096 
#define FULL_SEQ 8
#define SM_WIRE_COUNT 4
#define SIGNAL_DELAY 1250 /*1 000 000(1s) / 100 (steps ->100Hz) / 8 (signal sequence count per step) */
/*
	Summary: SM_28BYJ48  CW signal sequence
*/
													
static const int SM_SIGNAL_SEQ[FULL_SEQ][SM_WIRE_COUNT] = {
				{ HIGH, LOW, LOW, HIGH } ,
				{ HIGH, LOW, LOW, LOW },
				{ HIGH, HIGH, LOW, LOW },
				{ LOW, HIGH, LOW, LOW },
				{ LOW, HIGH, HIGH, LOW },
				{ LOW, LOW, HIGH, LOW },
				{ LOW, LOW, HIGH, HIGH },
				{ LOW, LOW, LOW, HIGH }
};
/*
	Summary:
		Based on wheel radius -> 2 x pi x radius
*/
static const double rotation_in_cm = 19.47;

class SM_28BYJ48 : IOHandler
{
public:
	/**
		Summary:
			Creates one motor class
		Input:
			short int:
				GPIO pins as wire colors
		Exceptions:
			GPIO pings already used - throwed by GPIO handler
	*/
	SM_28BYJ48(short int w_blu, short int w_pik, short int w_yel, short int w_org);

	void MoveCW(int ticks);
	/**
		Summary:
			Move wheel counter clockvise
		Input:
			int ticks:
				count of *tick
		Usage:
			0 < ticks < max_ticks
	*/
	void MoveCCW (int ticks);
	/**
		Summary:
			Stride wheel once clockvise
	*/
	void StrideCW(void);
	/**
		Summary:
			Stride wheel once counter clockvise
	*/
	void StrideCCW(void);
	/**
		Summary:
			Rotates wheel counter clockwise for x *rotations
		Input:
			int rotations:
				*rotation count
		Usage:
			0 < rotations < max_rotations
	*/
	void RotateCW(int rotations);
	/**
		Summary:
			Rotates wheel clockwise for x *rotations
		Input:
			int rotations:
				*rotation count
		Usage:
			0 < rotations < max_rotations
	*/
	void RotateCCW(int rotations);
	/**
		Summary:
			Safely zeros all pins
	*/
	void SafelyEnd(void);
	/**
		Summary:
			frees all pins
	*/
	~SM_28BYJ48(void);

private:
	/*
		Summary:
			Remembers all pins by name and gpio pin number 
	*/
	std::map<std::string, int> gpio_wires_map;
	/*
		Summary:
			Motor wires
	*/
	short int w_blu;
	/*
		Summary:
			Motor wires
	*/
	short int w_pik;
	/*
		Summary:
			Motor wires
	*/
	short int w_yel;
	/*
		Summary:
			Motor wires
	*/
	short int w_org;
	/*
		Summary:
			holds stepper position
	*/
	unsigned long long int step_counter = 0;
};

/*
					EXTRAS AND DEFINITIONS
	--------------------------------------------------
	ticks - one tick = 1/8 one step angle, 28BYJ48 step angle is 5.625(deg)
	stride - shift 5.625 deg
	rotation - one rotation = 360 (deg) full circle
*/

#endif