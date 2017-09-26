#pragma once
#ifndef INCLUDED_LINECMD_H
#define INCLUDED_LINECMD_H

#include "DrawTrackingTemplate.h"

class LineCmd : public DrawTrackingTemplate
{
protected:
   bool hasEnoughPoints(QVector<QPoint>& points);
   void draw(QVector<QPoint>& shapePoints, Ui& ui, bool save);
};

#endif //INCLUDED_LINECMD_H 