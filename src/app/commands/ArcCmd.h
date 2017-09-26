#ifndef INCLUDED_ARCCMD_H
#define INCLUDED_ARCCMD_H

#include "DrawTrackingTemplate.h"

class ArcCmd : public DrawTrackingTemplate
{
protected:
   void defineShape() { shape= UiOption::ARC; }
   bool hasEnoughPoints(QVector<QPoint>& points);
   void draw(QVector<QPoint>& shapePoints, Ui& ui, bool save);

};

#endif //INCLUDED_ARC_CMD