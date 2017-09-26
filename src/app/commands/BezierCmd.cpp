#include "BezierCmd.h"
#include "Data.h"
#include "Ui.h"
#include "qmouseevent"

QVector<QPoint> generatePointsBezier(QVector<QPoint> points) {
   int x= 0;
   int y= 0;
   double t= 0.0;
   double d;
   QVector<QPoint> bezier;
   for (int i= 1; t <= i; t+= 0.0001) {
      d= 1.0 - t;
      x= points[0].x() * pow( (d), 3) + points[1].x() * 3 * pow( (d), 2) * t + points[2].x() * 3 * d * pow(t, 2) + points[3].x() * pow(t,3);
      y= points[0].y() * pow( (d), 3) + points[1].y() * 3 * pow( (d), 2) * t + points[2].y() * 3 * d * pow(t, 2) + points[3].y() * pow(t,3);
      bezier.push_back( QPoint(x, y) );
   }
   return bezier;
}

bool isValidDraw(Data& data)
{
   return data.getPoints().size() == 3 && data.getMouseEvent().button() == Qt::MouseButton::LeftButton; 
}

void BezierCmd::execute(Data& data, Ui& ui)
{
   data.getPoints().push_back(data.getMouseEvent().pos());
   ui.draw(data.getMouseEvent().pos());

   if ( isValidDraw(data) ) {
      QVector<QPoint> bezier= generatePointsBezier(data.getPoints());
      ui.save(UiOption::BEZIER, bezier);
      ui.draw(bezier);
      data.getPoints().clear();
   } 
}


