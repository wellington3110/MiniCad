#pragma once
#ifndef INCLUDED_DRAWTRACKINGTEMPLATE_H
#define INCLUDED_DRAWTRACKINGTEMPLATE_H

#include "Command.h"
#include "qvector.h"
#include "Ui.h"

class DrawTrackingTemplate : public Command
{
public:
   void execute(Data& data, Ui& ui);

protected:
   virtual ~DrawTrackingTemplate() {};
   DrawTrackingTemplate() {}

   UiOption::Shape shape;
   bool isDrawing;

   virtual bool lastClick(Data& data) = 0;
   virtual void draw(Data& data, Ui& ui, bool save) = 0; 
   virtual bool hasEnoughPoints(QVector<QPointF>& points) = 0;

   bool verifyIsDrawing(Data& data);
   bool finalizedDrawing(Data& data);

};

#endif //INCLUDED_DRAWTRACKINGTEMPLATE_H 