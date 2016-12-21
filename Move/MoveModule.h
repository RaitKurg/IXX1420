/*
    Description:
        Handles robot movement
    Author:
        Marek Grencštein <marekgrencstein@gmail.com>
*/
#ifndef _Move_MoveModule_h_
#define _Move_MoveModule_h_

#include "../Base/BaseModule.h"

class MoveModule : public BaseModule
{

    public:
        MoveModule();
        virtual ~MoveModule();

    protected:
        void action();

    private:
    
};

#endif