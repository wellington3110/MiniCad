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

   virtual bool hasEnoughPoints(QVector<QPoint>& points) = 0;
   virtual void draw(QVector<QPoint>& shapePoints, Ui& ui, bool save) = 0; 

   bool isDrawing(Data& data);
   bool finalizedDrawing(Data& data);
};

#endif //INCLUDED_DRAWTRACKINGTEMPLATE_H 