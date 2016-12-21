#include "IOHandler.h"

IOHandler::IOHandler(void) 
{
	if(FirstCall)
	{
		wiringPiSetup();
		FirstCall = false;
	}

}

bool IOHandler::ReservPin(short int new_pin)
{
	for (size_t i = 0; i < MAX_GPIO_PORTS; i++)
	{
		if (AvailablePins[i] == new_pin)
		{
			AvailablePins[i] = -1;
			ReservedPins[i] = new_pin;
			return true;
		}
	}

	
/*	int * pIterator = std::find (AvailablePins, AvailablePins+MAX_GPIO_PORTS, new_pin);
	for(size_t i = 0 ; i < MAX_GPIO_PORTS; i++)
	{
		printf(" %d ", AvailablePins[i]);
	}
	printf("\n");
	if(pIterator != AvailablePins+MAX_GPIO_PORTS)
	{
		AvailablePins[(int)*pIterator -1] = -1;
		ReservedPins[(int)*pIterator -1] = new_pin;
		return true;
	}
*/
			  
	return false;
}

bool IOHandler::FreePin(short int previous_pin)
{
	for (size_t i = 0; i < MAX_GPIO_PORTS; i++)
	{
		if (ReservedPins[i] == previous_pin)
		{
			ReservedPins[i] = -1;
			AvailablePins[i] = previous_pin;
			return true;
		}
	}

	return false;
}

void IOHandler::SetPin(short int pin, short int value)
{
	digitalWrite(pin, value);
}

IOHandler::~IOHandler(void){}

/*
		STATIC MEMBERS DEFINITIONS BELOW 
*/


/*
	Summary:
		-1 is default initsialization and stands for "open gpio pin"

*/
int IOHandler::ReservedPins[MAX_GPIO_PORTS] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
/*
	Summary:
		Array holds available GPIO pin numbers
*/
int IOHandler::AvailablePins[MAX_GPIO_PORTS] =  { 7, 0, 2, 3, 21, 22, 23, 24, 25, 1, 4, 5, 6, 26, 27, 28, 29 };

bool IOHandler::FirstCall = true;
