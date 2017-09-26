#pragma once
#ifndef INCLUDED_RECEIVER_H
#define INCLUDED_RECEIVER_H

#include <string>
#include "Ui.h"
class Data;
class QMouseEvent;

class Receiver
{
public:
   virtual ~Receiver(){}
   virtual void receiveRequestToExecuteCmd(Data& data, UiOption::Shape) = 0;
   
};

#endif