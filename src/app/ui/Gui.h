#pragma once
#ifndef INCLUDED_GUI_H
#define INCLUDED_GUI_H

#include <qmainwindow.h>
#include "Ui.h"
#include "Receiver.h"

class QPainter;

class Gui : public QMainWindow, public Ui
{
   Q_OBJECT

public:
   Gui(Receiver* app);

   void draw(QLine& line);
   void draw(QPoint& point);
   void draw(QVector<QPoint>& points);
   void save(UiOption::Shape shape, QVector<QPoint> points);

private:
   Receiver* app;
   QWidget* board;
   UiOption::Shape actualOption;

   QVector<QPoint> actualPoints;
   QVector<QLine> lines;
   QVector<QVector<QPoint>> shapes;
   
   void generateRequest(QMouseEvent& event);

   void configureMenuBar();
   void configurePen(QPainter&);
               
protected:
   void mouseMoveEvent(QMouseEvent *);
   void mousePressEvent(QMouseEvent *);

private slots:
   void refreshActualOption(UiOption::Shape option);
};

#endif