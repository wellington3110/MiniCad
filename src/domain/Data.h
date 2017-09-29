#pragma once
#ifndef INCLUDED_DATA_H
#define INCLUDED_DATA_H

#include <qvector.h>
#include <qmouseevent>
#include <qline.h>

class Data
{
public:
   
   static Data& getInstance();
   
   void save(QLine& line);
   void save(QVector<QPointF>& points);
   void setEvent(QMouseEvent* event);

   QMouseEvent& getMouseEvent() { return *mouseEvent; }
   QVector<QPointF>& getPoints() { return points; }
   QVector<QLine>& getLines() {return lines;}
   QVector<QVector<QPointF>> getShapes() { return shapes;}

private:
   Data(const Data&);
   Data() : mouseEvent(nullptr){} 

   QVector<QLine> lines;
   QVector<QPointF> points;
   QVector<QVector<QPointF>> shapes;

   QMouseEvent* mouseEvent;
};

#endif //INCLUDED_DATA_H