#include "UltrasonicSensor.h"

HC_SR04::HC_SR04(unsigned short int w_trigger, unsigned short int w_echo)
{
	this->w_trigger = PinPairs.find(w_trigger)->second;
	this->w_echo = PinPairs.find(w_echo)->second;

	this->gpio_wires_map.insert(std::pair<std::string, unsigned short int>("w_trigger",this->w_trigger));
	this->gpio_wires_map.insert(std::pair<std::string, unsigned short int>("w_echo",this->w_echo));

	for (auto iterator=gpio_wires_map.begin(); iterator!=gpio_wires_map.end(); iterator++)
	{
		/*
			Trows runtime exception if IO handler refuses to assign pin
		*/
		if(ReservPin(iterator->second) != true)
			throw std::runtime_error("Unable to assing one or more GPIO pins"); 
		(strcmp((iterator->first).c_str(),"w_echo") == 0) 	 
			? 	pinMode(iterator->second, INPUT)
			:	pinMode(iterator->second, OUTPUT); 
		
	}

	SetPin(w_trigger, LOW);

	printf("UltrasonicSensor setup completed! \n");

}

double HC_SR04::GetDistance(void)
{
	/*
		Settle sensor with 60ms delay to use this function in while loop
	*/
	delay(SENSOR_SETTLING_TIME);
	/*
			pulse_start = t0
			pulse_end = t1
			(pulse)lenght	-> (t1 -t0)
	*/
	long int pulse_start = 0;	// ns !!!
	long int pulse_end = 0;		// ns !!!

	double distance = 0;

	/*
		Send pulse to trigger input
	*/
	
	SetPin(w_trigger, HIGH);
	delayMicroseconds(TRIGGER_PULSE_DURATION);
	SetPin(w_trigger, LOW);

	/*
		Measure t0.
	*/

	do
	{
		pulse_start = GetNanoseconds();

	}while(digitalRead(w_echo) == LOW);

	/*
		Measure t1
	*/

	do
	{
		pulse_end = GetNanoseconds();

	}while(digitalRead(w_echo) == HIGH);
	/*
		Correction constant is used to convert speed of light m/s -> cm/ns
	*/
	distance = (((pulse_end - pulse_start) * SPEED_OF_LIGHT) * CORRECTION_CONSTANT) / 2;

	/*
		Verify result
	*/
	if((distance < LOWEST_DISTANCE) || (distance > HIGHTEST_DISTANCE))
		return -1;

	/*
		Round decimal places
	*/

	return (round(distance * 100) / 100);
}

void HC_SR04::SafelyEnd(void)
{
	printf("Shutting UltrasonicSensor pins down \n");
	SetPin(w_trigger, LOW);
	SetPin(w_echo, LOW);
}

long int HC_SR04::GetNanoseconds(void)
 {
 	struct timespec ts_obj;
 	timespec_get(&ts_obj, TIME_UTC);

 	return ts_obj.tv_nsec;
 }

HC_SR04::~HC_SR04(void)
{
	/*
		Turn pins of incase user hasnt done that
	*/
	SafelyEnd();
	
	for (auto iterator=gpio_wires_map.begin(); iterator!=gpio_wires_map.end(); iterator++)
	{
		FreePin(iterator->second) != true ? 
			throw std::runtime_error("Unable to free one or more GPIO pins") : printf("pin free \n");/* pinMode(iterator->second); */

	}
	
}
