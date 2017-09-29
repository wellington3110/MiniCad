#include <Gui.h>
#include <qapplication.h>
#include <App.h>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   App app(a);
   app.run();
   return 0;
}