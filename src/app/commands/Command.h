#pragma once
#ifndef INCLUDED_COMMAND_H
#define INCLUDED_COMMAND_H

class Data;
class Ui;
class QMouseEvent;

class Command
{
public:
   virtual ~Command() {}
   virtual void execute(Data& data, Ui& ui) = 0;

};
#endif //INCLUDED_COMMAND_H