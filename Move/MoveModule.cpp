
#include "MoveModule.h"


MoveModule::MoveModule(SM_28BYJ48 * right_wheel, SM_28BYJ48 * left_wheel, double distance_between_wheels, double wheel_diameter)
{
	this->right_wheel = right_wheel;
	this->left_wheel = left_wheel;

	this->ticks_required_for_turning = (unsigned int)((FULL_ROTATION_STEPS * (distance_between_wheels / 2)) / (4 * (wheel_diameter / 2)));
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
					printf("Turning Left \n");
					TurnLeft();
				break;

			case TURN_RIGHT:
					printf("Turning Right \n");
					TurnRight();
				break;
			default:
				throw std::runtime_error("Invalid order from Queue!\n");
				break;
		}

		this->CallStack.pop();
	}
}

void MoveModule::TurnLeft(void)
{

	for(size_t i = 0; i < ticks_required_for_turning; i++)
	{
		this->right_wheel->MoveCW(1);
		this->left_wheel->MoveCCW(1);
	}

}

void MoveModule::TurnRight(void)
{

	//TODO!


}

void MoveModule::MoveWheelsForward(int rotation)
{
	for (size_t i = 0; i < (unsigned)rotation; i++)
	{
		for (size_t i = 0; i < FULL_ROTATION_STEPS; i++)
		{
			this->right_wheel->MoveCW(1);
			this->left_wheel->MoveCCW(1);
		}
	}
}

MoveModule::~MoveModule(void)
{
}
