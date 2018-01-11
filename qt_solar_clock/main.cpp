#include "include/mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QTimer>
#include <QOpenGLWidget>
#include <include/solarsystem.h>
#include <QSlider>
#include <QDockWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

 /*   SolarSystem solarSytem;

    QGraphicsView solarViewer(&solarSytem);
    solarViewer.fitInView(solarSytem.sceneRect(), Qt::KeepAspectRatio);
    solarViewer.setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "SPACE!"));
    solarViewer.setCacheMode(QGraphicsView::CacheBackground);
    solarViewer.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    solarViewer.setViewport(new QOpenGLWidget);
    solarViewer.resize(1024,768);
    solarViewer.scale(2,2);

    QSize t;
    t.setHeight(60);
    t.setWidth(100);
    QSlider *scale = new QSlider;
    scale->setInvertedAppearance(false);
    scale->setInvertedControls(false);
    scale->setFixedSize(t);
    scale->setMinimum(-100);
    scale->setMaximum(-10);
    scale->setValue(-100);

    QSlider *scale2 = new QSlider;
    scale2->setInvertedAppearance(false);
    scale2->setInvertedControls(false);
    scale2->setFixedSize(t);
    scale2->setMinimum(-100);
    scale2->setMaximum(-10);
    scale2->setValue(-100);

    QSlider *scale3 = new QSlider;
    scale3->setInvertedAppearance(false);
    scale3->setInvertedControls(false);
    scale3->setFixedSize(t);
    scale3->setMinimum(-100);
    scale3->setMaximum(-10);
    scale3->setValue(-100);
    */

 //   solarViewer.addScrollBarWidget(scale,Qt::TopLeftCorner);
  /*  QTransform trans;
    trans.setMatrix(1,0,0,0,5,0,0,0,2);
    solarViewer.setTransform(trans);
    QString test3 = "Time Warp";
    QDockWidget * dock = new QDockWidget(test3);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(scale);
    dock->move(QPoint(30,5));

    QString test4= "Step";
    QDockWidget * dock2 = new QDockWidget(test4);
    dock2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock2->setWidget(scale2);

    QString test5="Pan";
    QDockWidget * dock3 = new QDockWidget(test5);
    dock2->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock2->setWidget(scale3);

*/
    //dock->setMaximumHeight(20);
    //dock->setMinimumWidth(20);
   // dock->setMinimumHeight(20);
   // dock->setMaximumWidth(20);
//    QObject::connect(scale, SIGNAL(valueChanged(int)),
  //                    &solarSytem, SLOT(setMovementScale(int)));

  //  w.addDockWidget(Qt::RightDockWidgetArea, dock);
   // w.addDockWidget(Qt::RightDockWidgetArea, dock2);
   // w.splitDockWidget(dock,dock2,Qt::Vertical);
  //  w.splitDockWidget(dock2, dock3, Qt::Vertical);
 //   w.setCentralWidget(&solarViewer);
  //  w.show();



    return a.exec();
}
