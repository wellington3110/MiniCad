#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <qvector.h>
#include <qmouseevent>

class Data
{
public:
   Data(QVector<QPoint>& _points, QMouseEvent& _event) : points(_points), event(_event) {}    

   QVector<QPoint>& getPoints() { return points; }
   QMouseEvent& getMouseEvent() { return event; }
private:
   Data(const Data&);
 
   QVector<QPoint> points;
   QMouseEvent event;
};

#endif //INCLUDED_DATA_H