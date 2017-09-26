#pragma once
#ifndef INCLUDED_BEZIERCMD_H
#define INCLUDED_BEZIERCMD_H

#include "Command.h"

class BezierCmd : public Command
{
public:
   void execute(Data& data, Ui& ui);

};
#endif //INCLUDED_BEZIERCMD_H