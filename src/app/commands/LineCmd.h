#pragma once
#ifndef INCLUDED_LINECMD_H
#define INCLUDED_LINECMD_H

#include "DrawTrackingTemplate.h"

class LineCmd : public DrawTrackingTemplate
{
protected:
   void draw(Data& data, Ui& ui, bool save);

   bool lastClick(Data& data);
   bool hasEnoughPoints(QVector<QPointF>& points);

};

#endif //INCLUDED_LINECMD_H 