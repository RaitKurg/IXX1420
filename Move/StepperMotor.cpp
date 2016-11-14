#include "StepperMotor.h"
#include <wiringPi.h>
#include <iostream>
#include <stdio.h>


SM_28BYJ48::SM_28BYJ48(	short int w_blu,
						short int w_pik,
						short int w_yel,
						short int w_org )
{
	this->w_blu = w_blu;
	this->w_pik = w_pik;
	this->w_yel = w_yel;
	this->w_org = w_org;

	printf("setup completed\n");
	// pinMode(w_blu, OUTPUT);
	// pinMode(w_pik, OUTPUT);
	// pinMode(w_yel, OUTPUT);
	// pinMode(w_org, OUTPUT);

}

void SM_28BYJ48::MoveCW( int ticks)
{
	//printf("CW started\n");
	for (size_t i = 0; (i < ticks); i++, this->step_counter++)
	{
		// digitalWrite(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		// digitalWrite(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		// digitalWrite(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		// digitalWrite(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		// delay(1);
	}

//	safelyEnd();
}

void SM_28BYJ48::MoveCCW( int ticks)
{
	//printf("CCW started\n");
	for (size_t i = 0; (i < ticks); i++, this->step_counter++)
	{
		// digitalWrite(w_org, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][0]));
		// digitalWrite(w_yel, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][1]));
		// digitalWrite(w_pik, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][2]));
		// digitalWrite(w_blu, (SM_SIGNAL_SEQ[this->step_counter % FULL_SEQ][3]));
		// delay(1);
	}

}

void SM_28BYJ48::SafelyEnd()
{
	// printf("Shutting down pins \n");
	// digitalWrite(w_blu, LOW);
	// digitalWrite(w_pik, LOW);
	// digitalWrite(w_yel, LOW);
	// digitalWrite(w_org, LOW);
}


SM_28BYJ48::~SM_28BYJ48()
{
}
