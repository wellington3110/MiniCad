#ifndef INCLUDED_ARCCMD_H
#define INCLUDED_ARCCMD_H

#include "DrawTrackingTemplate.h"

class ArcCmd : public DrawTrackingTemplate
{
protected:
   void draw(Data& data, Ui& ui, bool save);

   bool lastClick(Data& data);
   bool hasEnoughPoints(QVector<QPointF>& points);

};

#endif //INCLUDED_ARC_CMD