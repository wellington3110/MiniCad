#include "LineCmd.h"
#include "Data.h"
#include "qmouseevent"
#include "qline.h"

void LineCmd::draw(Data& data, Ui& ui, bool save)
{
   QLine line(data.getPoints()[0].toPoint(), data.getPoints()[1].toPoint());
   if(save) {
      data.save(line);
      ui.draw();
   } else
      ui.drawTemp(line);
}

bool LineCmd::hasEnoughPoints(QVector<QPointF>& points) 
{
   return points.size() == 2;
}

bool LineCmd::lastClick(Data& data)
{
  return data.getMouseEvent().button() == Qt::LeftButton && data.getPoints().size() == 1;


}

