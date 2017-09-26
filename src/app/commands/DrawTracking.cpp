#include "DrawTrackingTemplate.h"
#include "Data.h"
#include "qmouseevent"

bool finalizedDrawing(QVector<QPoint>& points, QMouseEvent& event)
{
   return hasEnoughPoints(points) && event.button() == Qt::MouseButton::NoButton;
}

bool isDrawing(QVector<QPoint>& points, QMouseEvent& event) 
{
   return hasEnoughPoints(points) && event.button() == Qt::MouseButton::LeftButton;   
}


void LineCmd::execute(Data& data, Ui& ui, QMouseEvent& event)
{
   
}