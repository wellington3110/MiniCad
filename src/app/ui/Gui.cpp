#include "Gui.h"
#include "qmenubar.h"
#include "qpainter.h"
#include "Data.h"

Gui::Gui(Receiver* _app) : app(_app), data(Data::getInstance()), lineTemp(nullptr)
{
   resize(500, 300);
   QPalette p= palette();
   p.setColor(QPalette::Background, Qt::white);
   setPalette(p);

   configureMenuBar();

   show();
}

void Gui::configureMenuBar()
{
   QMenu* fileMenu= menuBar()->addMenu("Formas");
   QAction *bezierAct= new QAction("Bezier",this);
   bezierAct->setStatusTip("Desenhar curva de bezier");
   connect(bezierAct, SIGNAL (triggered()), this, SLOT(bezier()) );
   fileMenu->addAction(bezierAct);

   QAction *lineAct= new QAction("Linha",this);
   lineAct->setStatusTip("Desenhar uma linha");
   connect(lineAct, SIGNAL (triggered()), this, SLOT( line() ));
   fileMenu->addAction(lineAct);

   QAction *arcAct= new QAction("Arco",this);
   arcAct->setStatusTip("Desenhar um arco");
   connect(arcAct, SIGNAL (triggered()), this, SLOT( arc() ));
   fileMenu->addAction(arcAct);
}


void Gui::refreshActualOption(UiOption::Shape option)
{             
   actualOption= option;
}

void Gui::mouseMoveEvent(QMouseEvent* event)
{
   generateRequest(event);
}

void Gui::mousePressEvent(QMouseEvent* event)
{
   generateRequest(event);
}

void Gui::generateRequest(QMouseEvent* event)
{
   if(event) {
      data.setEvent(event);
      app->receiveRequestToExecuteCmd(data, actualOption);
   }
} 

void Gui::paintEvent(QPaintEvent *)
{
   QPainter p(this);
   QPen pen;
   pen.setColor(Qt::black);
   pen.setWidth(5);
   p.setPen(pen);

   p.drawLines(data.getLines());
   p.drawPoints(data.getPoints());
   p.drawPoints(pointsTemp);
   if(lineTemp)
      p.drawLine(*lineTemp);


   int size= data.getShapes().size();
   for(int i= 0; i < size; i++)
      p.drawPoints(data.getShapes()[i]);

}

void Gui::drawTemp(QLine& _lineTemp)
{
   delete lineTemp;
   lineTemp= new QLine(_lineTemp);
   update();
}

void Gui::drawTemp(QVector<QPointF>& _pointsTemp)
{
   pointsTemp= _pointsTemp;
   update();
}


                                        
                                        
                                        