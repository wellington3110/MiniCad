#pragma once
#ifndef INCLUDED_APP_H
#define INCLUDED_APP_H

#include "Data.h"
#include "Receiver.h"
#include "Ui.h"

class Command;
class QApplication;

class App : public Receiver 
{
public:
   App(QApplication& _app);
   ~App();

   void run();
   void receiveRequestToExecuteCmd(Data& data, UiOption::Shape option) { executeCommand(data, option); }

private:
   Ui* ui;
   QApplication* app;

   void executeCommand(Data& data, UiOption::Shape option);
   Command* createCommand(UiOption::Shape option);

};

#endif INCLUDED_APP_H