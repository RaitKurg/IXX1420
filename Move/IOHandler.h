#ifndef IO_HANDLER_H
#define IO_HANDLER_H

#include "IOHandler.h"
#include <iostream> 
#include <map>
#include <wiringPi.h>
#include <string>
#include <stdio.h>
#include <stdexcept>
#include <algorithm>   

#define MAX_GPIO_PORTS 17
#define SM28BYJ48_GPIO_PORTS 4


/*
	Summary:
		Maps GPIO pin number to wiringPI lib pins
*/
static const std::map<int, int>  PinPairs{
									{ std::make_pair(4, 7) },
									{ std::make_pair(17, 0) },
									{ std::make_pair(27, 2) },
									{ std::make_pair(22, 3) },
									{ std::make_pair(5, 21) },
									{ std::make_pair(6, 22) },
									{ std::make_pair(13, 23) },
									{ std::make_pair(19, 24) },
									{ std::make_pair(26, 25) },
									{ std::make_pair(18, 1) },
									{ std::make_pair(23, 4) },
									{ std::make_pair(24, 5) },
									{ std::make_pair(25, 6) },
									{ std::make_pair(12, 26) },
									{ std::make_pair(16, 27) },
									{ std::make_pair(20, 28) },
									{ std::make_pair(21, 29) },
															};

class IOHandler 
{
public:

	IOHandler(void);
	/*
		Summary:
			delete derived classes also
	*/
	virtual ~IOHandler(void);

protected:

	/*
		Summary:
			Sets specified pin HIGH/LOW
	*/
	void SetPin(short int pin, short int value);
	/*
		Summary:
			Reserves given GPIO pin
		Input:
			short in GpioPin:
				GPIO pin number
	*/
	bool ReservPin(short int GpioPin);
	/*
		Summary:
			Frees given GPIO pin
		Input:
			short int GpioPin:
				GPIO pin number
	*/
	bool FreePin(short int GpioPin);

private:

	/*
		Summary:
			This array holds reserved pin number
		NOTE:
			initsialization is in .cpp file
		*/
	static int ReservedPins[MAX_GPIO_PORTS];
	/*
		Summary:
			This array holds available pin number. Initilized while constructing current class
		NOTE:
			initsialization is in .cpp file
		*/
	static int AvailablePins[MAX_GPIO_PORTS];
	/*
		Summary:
			wether or not call wiringPIsetup
	*/
	static bool FirstCall;	
};

#endif
