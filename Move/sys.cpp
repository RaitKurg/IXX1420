
#include "IOHandler.h"
#include "StepperMotor.h"
#include <exception>
#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include "MoveModule.h"

#pragma warning ( disable : 4996 )
using namespace std;

int main()
{
	IOHandler test;
	
	SM_28BYJ48  * motor1 = test.GetSM_28BYJ48(17, 22, 23, 24);
	SM_28BYJ48  * motor2 = test.GetSM_28BYJ48(27, 5, 6, 13);
	MoveModule mm(motor1, motor2);
	mm.Push(mm.FORWARD_5);
	mm.Push(mm.FORWARD_3);
	mm.Action();
	
	getchar();
	return 0;
}

