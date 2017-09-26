#include "Gui.h"
#include "qmenubar.h"
#include "qpainter.h"
#include "Data.h"

Gui::Gui(Receiver* _app) : app(_app)
{
   board= new QWidget(this);
   board->setMouseTracking(true);
   setCentralWidget(board);
   resize(500, 300);
   QPalette p= palette();
   p.setColor(QPalette::Background, Qt::white);
   setPalette(p);
   
   configureMenuBar();

}

void Gui::configureMenuBar()
{
   QMenu* fileMenu= menuBar()->addMenu("Shapeas");
   QAction *bezierAct= new QAction("Bezier",this);
   bezierAct->setStatusTip("Desenhar curva de bezier");
   connect(bezierAct, SIGNAL (bezierAct->triggered()), this, SLOT( refreshActualOption(UiOption::BEZIER) ) );
   fileMenu->addAction(bezierAct);

   QAction *lineAct= new QAction("Linha",this);
   lineAct->setStatusTip("Desenhar uma linha");
   connect(lineAct, SIGNAL (lineAct->triggered()), this, SLOT( refreshActualOption(UiOption::LINE) ) );
   fileMenu->addAction(lineAct);

   QAction *arcAct= new QAction("Arco",this);
   arcAct->setStatusTip("Desenhar um arco");
   connect(arcAct, SIGNAL (arcAct->triggered()), this, SLOT( refreshActualOption(UiOption::ARC) ) );
   fileMenu->addAction(arcAct);
 
}

void Gui::configurePen(QPainter& p)
{
   QPen pen;
   pen.setColor(Qt::black);
   pen.setWidth(10);
   p.setPen(pen);
}


void Gui::refreshActualOption(UiOption::Shape option)
{
   actualOption= option;
   actualPoints.clear();
}

void Gui::mouseMoveEvent(QMouseEvent* event)
{
   generateRequest(*event);
}

void Gui::mousePressEvent(QMouseEvent* event)
{
   generateRequest(*event);
}

void Gui::generateRequest(QMouseEvent& event)
{
   Data data(actualPoints, event);
   app->receiveRequestToExecuteCmd(data, actualOption);
}

void Gui::save(UiOption::Shape shape, QVector<QPoint> points)
{
   if (shape == UiOption::LINE) 
      lines.push_back( QLine(points[0], points[1]) );
   else
      shapes.push_back(points);
}

void Gui::draw(QLine& line)             //
{                                       //
   QPainter p;                          //
   configurePen(p);                     //
   p.drawLine(line);                    //
}                                       //
                                        //
void Gui::draw(QPoint& point)           //
{                                       //
   QPainter p;                          //
   configurePen(p);                     //TIRAR OS CÓDIGOS REPETIDOS
   p.drawPoint(point);                  //E INCLUIR QUE SE DEVE
}                                       //DESENHAR TODAS AS FORMAS
                                        //ANTES DE DESENHAR O PARAMETRO ENVIADO
void Gui::draw(QVector<QPoint>& points) //
{                                       //
                                        //
   QPainter p;                          //
   configurePen(p);                     //
   p.drawPoints(points);                //
}                                       //
                                        //
                                        //
                                        //