#include "Data.h"

static Data* instance;

Data &Data::getInstance()
{
   if (!instance) 
      instance= new Data();
   return *instance;
}

void Data::save(QVector<QPointF>& points)
{
   shapes.push_back(points);
}

void Data::save(QLine& line)
{
   lines.push_back(line);
}

void Data::setEvent(QMouseEvent* event)
{
   mouseEvent= event;
}
