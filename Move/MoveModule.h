#pragma once

#include "StepperMotor.h"
#include <queue>   


class MoveModule
{
public:
	MoveModule(SM_28BYJ48 * right_wheel, SM_28BYJ48 * left_wheel);
	/*
		Summary:
		Possible moving orders for wheels
		FORWARD_1 ~ 19cm
		FO
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
	void Action();
	~MoveModule();

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
	
};

