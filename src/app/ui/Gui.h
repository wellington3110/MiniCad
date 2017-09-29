#pragma once
#ifndef INCLUDED_GUI_H
#define INCLUDED_GUI_H

#include <qmainwindow.h>
#include "Ui.h"
#include "Receiver.h"

class Data;
class Line;

class QPainter;

class Gui : public QMainWindow, public Ui
{
   Q_OBJECT

public:
   Gui(Receiver* app);

   void enableMouseTracking(bool enable) {setMouseTracking(enable);}

   void draw() {update();}
   void drawTemp(QLine& lineTemp);
   void drawTemp(QVector<QPointF>& pointsTemp);

private:
   Data& data;
   QLine* lineTemp;
   QVector<QPointF> pointsTemp;
   Receiver* app;
   UiOption::Shape actualOption;


   void configureMenuBar();
   void generateRequest(QMouseEvent* event);
   void refreshActualOption(UiOption::Shape option);

protected:
   void mouseMoveEvent(QMouseEvent *);
   void mousePressEvent(QMouseEvent *);
   void paintEvent(QPaintEvent *);

private slots:
   void arc() {refreshActualOption(UiOption::ARC);}
   void line() {refreshActualOption(UiOption::LINE);}
   void bezier() {refreshActualOption(UiOption::BEZIER);}
};

#endif