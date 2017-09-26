#include "App.h"
#include "Gui.h"
#include "ArcCmd.h"
#include "BezierCmd.h"
#include "LineCmd.h"
#include "qapplication.h"

App::~App()
{
   delete ui;
}

App::App(QApplication& _app) : app(&_app)
{
   ui= new Gui(this);
}

void App::run()
{
   app->exec();
}

void App::executeCommand(Data& data, UiOption::Shape option)
{
   auto cActual= createCommand(option);
   if (cActual)
      cActual->execute(data, *ui);
   delete cActual;

}

Command* App::createCommand(UiOption::Shape option)
{
   switch(option) {
      case UiOption::BEZIER: return new BezierCmd();
      case UiOption::ARC:    return new ArcCmd();
      case UiOption::LINE:   return new LineCmd();
      default:; //criar o idle q eu esqueci;
   };
}