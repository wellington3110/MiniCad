#include "DrawTrackingTemplate.h"
#include "Data.h"
#include "qmouseevent"

bool DrawTrackingTemplate::finalizedDrawing(Data& data)
{
   return hasEnoughPoints(data.getPoints()) && data.getMouseEvent().button() == Qt::LeftButton;   
}


void DrawTrackingTemplate::execute(Data& data, Ui& ui)
{
   ui.enableMouseTracking(true);
   isDrawing= verifyIsDrawing(data);
   if(isDrawing) {
      draw(data, ui, false);
      data.getPoints().pop_back();
   } else if( finalizedDrawing(data) ) {
      draw(data, ui, true);
      data.getPoints().clear();
   }
}

bool firstClick(Data& data)
{
   return data.getMouseEvent().button() == Qt::LeftButton && data.getPoints().size() == 0;
}

bool DrawTrackingTemplate::verifyIsDrawing(Data& data)
{
   if( firstClick(data) || lastClick(data)  ) {
      data.getPoints().push_back(data.getMouseEvent().pos());
      return false;
   } if(data.getPoints().size() == 0 && data.getMouseEvent().button() == Qt::NoButton)
      return false;

   data.getPoints().push_back(data.getMouseEvent().pos());
   return true;
}






