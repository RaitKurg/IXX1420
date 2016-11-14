#include "IOHandler.h"
#include <iostream> 
#include <map>
#include <wiringPi.h>
#include <string>
#include <stdio.h>
#include <stdexcept>

IOHandler::IOHandler() 
{
	std::copy(std::begin(GpioPins), std::end(GpioPins), std::begin(AvailablePins));
	// wiringPiSetup();
}
SM_28BYJ48 * IOHandler::GetSM_28BYJ48(	short int w_blu,
										short int w_pik,
										short int w_yel,
										short int w_org	)
{

	std::map<std::string, int> input_vars_map;

	input_vars_map["w_blue"] = w_blu;
	input_vars_map["w_pik"] = w_pik;
	input_vars_map["w_yel"] = w_yel;
	input_vars_map["w_org"] = w_org;

	for (auto iterator = input_vars_map.begin(); iterator != input_vars_map.end(); iterator++)
	{
		std::cout << iterator->first << " => " << iterator->second << '\n';
		if (!ReservPin(iterator->second))
		{
			throw std::runtime_error("Unable to assign one or more GPIO pins");
		}
	}

	return  new SM_28BYJ48(PinPairs.find(w_blu)->second, PinPairs.find(w_pik)->second, PinPairs.find(w_yel)->second, PinPairs.find(w_org)->second);
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

IOHandler::~IOHandler()
{

}
