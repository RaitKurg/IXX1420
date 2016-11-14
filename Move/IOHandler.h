#pragma once

#include "StepperMotor.h"
#include <map>
#define MAX_GPIO_PORTS 17

/*
	Summary:
		Array holds available GPIO pin numbers
*/
static const int GpioPins[MAX_GPIO_PORTS] = { 4, 17, 27, 22, 5, 6, 13, 19, 26, 18, 23, 24, 25, 12, 16, 20, 21 };

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
	IOHandler();
	
	/*
		Summary:
			Method for declearing 28BYJ48.
		Input:
			Stepper motor wire colours with pin numbers
		Output:
			returns class for stepper motor
		Usage:
			throws pin occupied exception when GPIO pins in use
	
		*/
	
	SM_28BYJ48 * GetSM_28BYJ48(short int w_blu,
		short int w_pik,
		short int w_yel,
		short int w_org);

	~IOHandler();
private:

	/*
		Summary:
		This array holds reserved pin number
		*/
	int ReservedPins[MAX_GPIO_PORTS];
	/*
		Summary:
		This array holds available pin number. Initilized while constructing current class
		*/
	int AvailablePins[MAX_GPIO_PORTS];
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

};

