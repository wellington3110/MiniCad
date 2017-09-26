#include "DrawTrackingTemplate.h"
#include "Data.h"
#include "qmouseevent"

bool DrawTrackingTemplate::isDrawing(Data& data)
{
   return hasEnoughPoints(data.getPoints()) && data.getMouseEvent().button() == Qt::MouseButton::NoButton;   
}

bool DrawTrackingTemplate::finalizedDrawing(Data& data)
{
   return hasEnoughPoints(data.getPoints()) && data.getMouseEvent().button() == Qt::MouseButton::LeftButton;   
}

void DrawTrackingTemplate::execute(Data& data, Ui& ui)
{
   data.getPoints().push_back(data.getMouseEvent().pos());
   if ( isDrawing(data) ) {
      draw(data.getPoints(), ui, false);
      data.getPoints().pop_back();

   } else if ( finalizedDrawing(data) ) {
      draw(data.getPoints(), ui, true);
      data.getPoints().clear();
   }
}



