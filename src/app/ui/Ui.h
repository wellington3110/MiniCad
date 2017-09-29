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

   virtual void draw() = 0;
   virtual void enableMouseTracking(bool) = 0;
   virtual void drawTemp(QLine& lineTemp) = 0;
   virtual void drawTemp(QVector<QPointF>& pointsTemp) = 0;

};

#endif //INCLUDED_UI_H