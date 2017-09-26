#pragma once
#ifndef INCLUDED_UI_H
#define INCLUDED_UI_H

class QLine;
class QAction;
#include "qvector.h"

namespace UiOption {
   enum Shape {ARC, BEZIER, LINE};
}

class Ui
{
public:
   virtual ~Ui() {}   

   virtual void draw(QLine& line) = 0;
   virtual void draw(QPoint& point) = 0;
   virtual void draw(QVector<QPoint>& points) = 0;
   virtual void save(UiOption::Shape shape, QVector<QPoint> points) = 0;

};

#endif //INCLUDED_UI_H