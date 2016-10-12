#include <iostream>
#include "MoveModule.h"

MoveModule::MoveModule() : BaseModule()
{

}

MoveModule::~MoveModule()
{

}

void MoveModule::action()
{
    std::cout << "Move action\n";
}

MoveHistory& MoveModule::getMoveHistory()
{
    return m_MoveHistory;
}

void setPath()
{

}