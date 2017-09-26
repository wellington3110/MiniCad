#include "LineCmd.h"
#include "Data.h"
#include "qmouseevent"
#include "qline.h"

void LineCmd::draw(QVector<QPoint>& linePoints, Ui& ui, bool save)
{
   QLine line(linePoints[0], linePoints[1]);
   ui.draw(line);
   if(save)
      ui.save(UiOption::LINE, linePoints);
}

bool LineCmd::hasEnoughPoints(QVector<QPoint>& points) 
{
   return points.size() == 2;
}
