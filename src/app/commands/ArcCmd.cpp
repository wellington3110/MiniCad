#include "ArcCmd.h"
#include "Data.h"
#include "Ui.h"
#include "qmouseevent"

void ArcCmd::draw(Data& data, Ui& ui, bool save)
{
   QVector<QPointF> arc;
   if(save) {
      data.save(arc);
      ui.draw();
   } else
      ui.drawTemp(arc);
}

bool ArcCmd::hasEnoughPoints(QVector<QPointF>& points) 
{
   return points.size() == 3;
}

bool ArcCmd::lastClick(Data& data)
{
   return data.getMouseEvent().button() == Qt::LeftButton && data.getPoints().size() == 2;
}

