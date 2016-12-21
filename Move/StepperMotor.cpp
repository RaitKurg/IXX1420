#include "StepperMotor.h"

SM_28BYJ48::SM_28BYJ48(short int w_blu, short int w_pik, short int w_yel,  short int w_org)
{
	this->w_blu = PinPairs.find(w_blu)->second;
	this->w_pik = PinPairs.find(w_pik)->second;
	this->w_yel = PinPairs.find(w_yel)->second;
	this->w_org = PinPairs.find(w_org)->second;

	this->gpio_wires_map.insert(std::pair<std::string, int>("w_blu",this->w_blu));
	this->gpio_wires_map.insert(std::pair<std::string, int>("w_pik",this->w_pik));
	this->gpio_wires_map.insert(std::pair<std::string, int>("w_yel",this->w_yel));
	this->gpio_wires_map.insert(std::pair<std::string, int>("w_org",this->w_org));

	for (auto iterator=gpio_wires_map.begin(); iterator!=gpio_wires_map.end(); iterator++)
	{
		/*
			Trows exception if IO handler refuses to assign pin
		*/
		ReservPin(iterator->second) != true ? 
			throw std::runtime_error("Unable to assing one or more GPIO pins") : pinMode(iterator->second, OUTPUT); 
		
	}

	printf("setup completed\n");

}

void SM_28BYJ48::MoveCW(int ticks)
{
	for (size_t i = 0; (i < ticks); i++, this->step_counter++)
	{
		 SetPin(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		 SetPin(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		 SetPin(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		 SetPin(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		 delayMicroseconds(SIGNAL_DELAY);
	}
}

void SM_28BYJ48::MoveCCW(int ticks)
{
	for (size_t i = 0; (i < ticks); i++, this->step_counter++)
	{
		SetPin(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		SetPin(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		SetPin(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		SetPin(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		delayMicroseconds(SIGNAL_DELAY);
	}

}

void SM_28BYJ48::StrideCW(void)
{
	for (size_t i = 0; (i < FULL_SEQ); i++, this->step_counter++)
	{
		 SetPin(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		 SetPin(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		 SetPin(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		 SetPin(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		 delayMicroseconds(SIGNAL_DELAY);
	}

}

void SM_28BYJ48::StrideCCW(void)
{
	for (size_t i = 0; (i < FULL_SEQ); i++, this->step_counter++)
	{
		SetPin(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		SetPin(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		SetPin(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		SetPin(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		delayMicroseconds(SIGNAL_DELAY);
	}
}

void SM_28BYJ48::RotateCW(int rotations)
{
	for (size_t i = 0; (i < FULL_ROTATION_STEPS); i++, this->step_counter++)
	{
		 SetPin(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		 SetPin(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		 SetPin(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		 SetPin(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		 delayMicroseconds(SIGNAL_DELAY);
	}
}

void SM_28BYJ48::RotateCCW(int rotations)
{
	for (size_t i = 0; (i < FULL_ROTATION_STEPS); i++, this->step_counter++)
	{
		SetPin(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		SetPin(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		SetPin(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		SetPin(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		delayMicroseconds(SIGNAL_DELAY);
	}
}

void SM_28BYJ48::SafelyEnd()
{
	printf("Shutting down pins \n");
	SetPin(w_blu, LOW);
	SetPin(w_pik, LOW);
	SetPin(w_yel, LOW);
	SetPin(w_org, LOW);
}

SM_28BYJ48::~SM_28BYJ48()
{
	/*
		Turn pins of incase user hasnt done that
	*/
	SafelyEnd();

	for (auto iterator=gpio_wires_map.begin(); iterator!=gpio_wires_map.end(); iterator++)
	{
		if(FreePin(iterator->second) != true) 
			throw std::runtime_error("Unable to free one or more GPIO pins"); 

	}
}
