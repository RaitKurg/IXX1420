#include <iostream>
#include "MoveModule.h"

MoveModule::MoveModule() : BaseModule()
{

}

MoveModule::~MoveModule()
{

}

void MoveModule::Action()
{
    std::cout << "Move Action\n";
}