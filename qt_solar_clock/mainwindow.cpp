#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QLatin1String>
#include <QString>
#include <QSlider>
#include <QOpenGLWidget>
#include <QDockWidget>
#include <QGraphicsView>
#include <QTimer>
#include <QDebug>
#include <include/solarsystem.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // createInteractive();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createInteractive(){

    QSize sliderSize;
    QString dockName;
    sliderSize.setHeight(60);
    sliderSize.setWidth(100);
    timeWarpSlider = new QSlider;
    timeWarpSlider->setInvertedAppearance(false);
    timeWarpSlider->setInvertedControls(false);
    timeWarpSlider->setFixedSize(sliderSize);
    timeWarpSlider->setMinimum(-100);
    timeWarpSlider->setMaximum(-10);
    timeWarpSlider->setValue(-100);

    tiltSlider = new QSlider;
    tiltSlider->setInvertedAppearance(false);
    tiltSlider->setInvertedControls(false);
    tiltSlider->setFixedSize(sliderSize);
    tiltSlider->setMinimum(-3);
    tiltSlider->setMaximum(3);
    tiltSlider->setValue(0);


    panSlider = new QSlider;
    panSlider->setInvertedAppearance(false);
    panSlider->setInvertedControls(false);
    panSlider->setFixedSize(sliderSize);
    panSlider->setMinimum(-100);
    panSlider->setMaximum(-10);
    panSlider->setValue(-100);

    zoomSlider = new QSlider;
    zoomSlider->setInvertedAppearance(false);
    zoomSlider->setInvertedControls(false);
    zoomSlider->setFixedSize(sliderSize);
    zoomSlider->setMinimum(1);
    zoomSlider->setMaximum(100);
    zoomSlider->setValue(5);

    dockName = "Time Warp";
    timeWarpSliderDock =  new QDockWidget(dockName);
    timeWarpSliderDock->setAllowedAreas(Qt::RightDockWidgetArea);
    timeWarpSliderDock->setWidget(timeWarpSlider);

    dockName = "Tilt";
    tiltSliderDock = new QDockWidget(dockName);
    tiltSliderDock->setAllowedAreas(Qt::RightDockWidgetArea);
    tiltSliderDock->setWidget(tiltSlider);

    dockName = "Pan";
    panSliderDock = new QDockWidget(dockName);
    panSliderDock->setAllowedAreas(Qt::RightDockWidgetArea);
    panSliderDock->setWidget(panSlider);

    dockName = "Zoom";
    zoomSliderDock = new QDockWidget(dockName);
    zoomSliderDock->setAllowedAreas(Qt::RightDockWidgetArea);
    zoomSliderDock->setWidget(zoomSlider);

    this->addDockWidget(Qt::RightDockWidgetArea, timeWarpSliderDock);
    this->splitDockWidget(timeWarpSliderDock, tiltSliderDock, Qt::Vertical);
    this->splitDockWidget(tiltSliderDock, panSliderDock, Qt::Vertical);
    this->splitDockWidget(panSliderDock, zoomSliderDock, Qt::Vertical);

    solarViewer = new QGraphicsView(&solarSytem);
    solarViewer->fitInView(solarSytem.sceneRect(), Qt::KeepAspectRatio);
    solarViewer->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "SPACE!"));
    solarViewer->setCacheMode(QGraphicsView::CacheBackground);
    solarViewer->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    solarViewer->setViewport(new QOpenGLWidget);



    solarViewer->setTransform(perspectiveTransform);
    this->setCentralWidget(solarViewer);

    QObject::connect(timeWarpSlider, SIGNAL(valueChanged(int)),
                      &solarSytem, SLOT(setMovementScale(int)));

    QObject::connect(zoomSlider, SIGNAL(valueChanged(int)),
                      this, SLOT(setZoomValue(int)));

    QObject::connect(tiltSlider, SIGNAL(valueChanged(int)),
                      this, SLOT(setTiltValue(int)));

    solarViewer->setResizeAnchor(QGraphicsView::AnchorViewCenter);


    solarViewer->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    solarViewer->scale(solarSytem.height()*.00001, solarSytem.width()*.00001);
    this->setCentralWidget(solarViewer);
    this->showMaximized();

    QObject::connect(&timer, SIGNAL(timeout()), &solarSytem, SLOT(advance()));
    timer.start(1000/66);
}


void MainWindow::setTimeWarpSacle(int scale){

}


void MainWindow::setTiltValue(int scale){
    if (scale == 0)
        scale =1;
  //  perspectiveTransform.setMatrix(1,0,0,0,scale,0,0,0,.01);
   // solarViewer->setTransform(perspectiveTransform);
  //  solarViewer->scale(solarSytem.height()*1*.000001, solarSytem.width()*1*.000001);

}


void MainWindow::setPanValue(int scale){


}


void MainWindow::setZoomValue(int scale){
       solarViewer->resetMatrix();
       solarViewer->scale(solarSytem.height()*scale*.000001, solarSytem.width()*scale*.000001);
}
