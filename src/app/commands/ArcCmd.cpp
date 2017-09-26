#include "ArcCmd.h"
#include "Data.h"
#include "Ui.h"
#include "qmouseevent"

void ArcCmd::draw(QVector<QPoint>& arcPoints, Ui& ui, bool save)
{
   QVector<QPoint> arc;

   //logica

  ui.draw(arc);
  if(save)
     ui.save(UiOption::ARC, arc);
}

bool ArcCmd::hasEnoughPoints(QVector<QPoint>& points) 
{
   return points.size() == 3;
}
