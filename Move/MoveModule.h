#ifndef MOVE_MODULE_H
#define MOVE_MODULE_H

#include "StepperMotor.h"
#include <queue>   
#include <iostream> 
#include <stdexcept>


class MoveModule
{
public:
	MoveModule(SM_28BYJ48 * right_wheel, SM_28BYJ48 * left_wheel, double distance_between_wheels, double wheel_diameter);
	/*
		Summary:
			Possible moving orders for wheels
	*/
	enum Orders { FORWARD_1, FORWARD_3, FORWARD_5, TURN_LEFT, TURN_RIGHT };
	/*
		Summary:
			Add one order to CallStack
	*/
	void Push(Orders);
	/*
		Summary:
			Orders from CallStack will be excecuted
	*/
	void Action(void);


	~MoveModule(void);

private:
	/*
		Summary:
		Orders from somewhere are pushed here
	*/
	std::queue<Orders> CallStack;

	/*
		Summary:
		Right wheel pointer
	*/
	SM_28BYJ48 * right_wheel;
	/*
		Summary:
		Left wheel pointer
	*/
	SM_28BYJ48  * left_wheel;
	/*
		Summary:
			Moves both wheels for x rotations
	*/
	void MoveWheelsForward(int rotions);
	/*
		Summary:
			Turns robot left by moving both wheel dif direction
	*/
	void TurnLeft(void);
	/*
		Summary:
			Turns robot left by moving both wheel dif direction
	*/
	void TurnRight(void);

	/*
		Summary:
			Tick count to motors to turn robot left/right
	*/
	unsigned int ticks_required_for_turning;
};

#endif