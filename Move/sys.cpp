
#include "IOHandler.h"
#include "StepperMotor.h"
#include <exception>
#include <iostream>
#include <stdio.h>
#include <wiringPi.h>
#include "MoveModule.h"
#include "UltrasonicSensor.h"
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{

	/*
		Disable networking and USB hub
	*/
	system("sudo powersaver.sh on");

	ofstream log;

	SM_28BYJ48 * m1 = new SM_28BYJ48(17, 22, 23, 24);
	SM_28BYJ48 * m2 = new SM_28BYJ48(27, 5, 6, 13);
	SM_28BYJ48 * m3 = new SM_28BYJ48(16, 12, 26, 19);
	HC_SR04 * sensor = new HC_SR04(20,21);

	log.open ("log.txt");

	MoveModule mm(m1, m2, 45, 6.5);

	int i = 0;

	while(i < 32)
	{
		m3->StrideCW();
		std::cout << sensor->GetDistance() << '\n'; 
		log << sensor->GetDistance() << endl;
		i++; 
	}
	
	log.close();
	m3->SafelyEnd();


	mm.Push(mm.FORWARD_1);
	mm.Push(mm.FORWARD_1);
	mm.Action();
	
	m1->SafelyEnd();
	m2->SafelyEnd();
	sensor->SafelyEnd();

	system("sudo powersaver.sh off");

	printf("Finished");
	

	getchar();
	return 0;
}

