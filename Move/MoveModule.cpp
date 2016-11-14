
#include "MoveModule.h"
#include <iostream> 
#include <stdexcept>


MoveModule::MoveModule(SM_28BYJ48 * right_wheel, SM_28BYJ48 * left_wheel)
{
	this->right_wheel = right_wheel;
	this->left_wheel = left_wheel;
}

void MoveModule::Push(Orders order)
{
	this->CallStack.push(order);
}

void MoveModule::Action()
{
	printf("Executing orders..\n");
	while (!this->CallStack.empty())
	{
		switch (this->CallStack.front())
		{
			case FORWARD_1:
					printf("Executing FORWARD_1\n");
					MoveWheelsForward(1);
				break;
			case FORWARD_3:
					printf("Executing FORWARD_3\n");
					MoveWheelsForward(3);
				break;
			
			case FORWARD_5:
					printf("Executing FORWARD_5\n");
					MoveWheelsForward(5);
				break;
			
			case TURN_LEFT:
				//not implemented yet
				break;

			case TURN_RIGHT:
				//not implemented yet
				break;
			default:
				throw std::runtime_error("Invalid order from Queue!\n");
				break;
		}

		this->CallStack.pop();
	}
}

void MoveModule::MoveWheelsForward(int rotation)
{
	for (size_t i = 0; i < (unsigned)rotation; i++)
	{
		for (size_t i = 0; i < FULL_ROTATION_STEPS; i++)
		{
			this->right_wheel->MoveCW(1);
			this->left_wheel->MoveCW(1);
		}
	}
}

MoveModule::~MoveModule()
{
}
