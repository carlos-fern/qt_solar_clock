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
    createInteractive();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createInteractive(){

    QSize sliderSize;
    QString dockName;
    sliderSize.setHeight(100);
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
    tiltSlider->setMinimum(30);
    tiltSlider->setMaximum(70);
    tiltSlider->setValue(30);

    zoomSlider = new QSlider;
    zoomSlider->setInvertedAppearance(false);
    zoomSlider->setInvertedControls(false);
    zoomSlider->setFixedSize(sliderSize);
    zoomSlider->setMinimum(3);
    zoomSlider->setMaximum(120);
    zoomSlider->setValue(5);

    dockName = "Time Warp";
    timeWarpSliderDock =  new QDockWidget(dockName);
    timeWarpSliderDock->setAllowedAreas(Qt::RightDockWidgetArea);
    timeWarpSliderDock->setWidget(timeWarpSlider);

    dockName = "Tilt";
    tiltSliderDock = new QDockWidget(dockName);
    tiltSliderDock->setAllowedAreas(Qt::RightDockWidgetArea);
    tiltSliderDock->setWidget(tiltSlider);

    dockName = "Zoom";
    zoomSliderDock = new QDockWidget(dockName);
    zoomSliderDock->setAllowedAreas(Qt::RightDockWidgetArea);
    zoomSliderDock->setWidget(zoomSlider);

    this->addDockWidget(Qt::RightDockWidgetArea, timeWarpSliderDock);
    this->splitDockWidget(timeWarpSliderDock, tiltSliderDock, Qt::Vertical);
    this->splitDockWidget(tiltSliderDock, zoomSliderDock, Qt::Vertical);


    QObject::connect(timeWarpSlider, SIGNAL(valueChanged(int)),
                      &solarSytem, SLOT(setMovementScale(int)));

    QObject::connect(zoomSlider, SIGNAL(valueChanged(int)),
                      this, SLOT(setZoomValue(int)));

    QObject::connect(tiltSlider, SIGNAL(valueChanged(int)),
                      this, SLOT(setTiltValue(int)));


    solarViewer = new QGraphicsView(&solarSytem);
    solarViewer->fitInView(solarSytem.sceneRect(), Qt::KeepAspectRatio);
    solarViewer->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "SPACE!"));
    solarViewer->setCacheMode(QGraphicsView::CacheBackground);
    solarViewer->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    solarViewer->setViewport(new QOpenGLWidget);
    solarViewer->setDragMode(QGraphicsView::ScrollHandDrag);
    this->setCentralWidget(solarViewer);

    solarViewer->setResizeAnchor(QGraphicsView::AnchorViewCenter);
    solarViewer->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    solarViewer->resetMatrix();

    this->setCentralWidget(solarViewer);
    this->showMaximized();
    this->setZoomValue(zoom);
    QObject::connect(&timer, SIGNAL(timeout()), &solarSytem, SLOT(advance()));
    timer.start(1000/66);
}

void MainWindow::setTiltValue(int scale){
    if(scale ==  30) //<--- HACK: 2-29 result in the trajectoreis disapearing
        scale =1;

    QTransform trans;
    tilt = scale;
    trans.rotate(tilt, Qt::XAxis);
    solarViewer->setTransform(trans);
    solarViewer->scale(solarSytem.height()*zoom*visualScale, solarSytem.width()*zoom*visualScale);
}


void MainWindow::setPanValue(int scale){

    solarViewer->rotate(scale);
}


void MainWindow::setZoomValue(int scale){
       solarViewer->resetMatrix();
       zoom = scale;
       QTransform trans;
       trans.rotate(tilt, Qt::XAxis);
       solarViewer->setTransform(trans);
       solarViewer->scale(solarSytem.height()*zoom*visualScale, solarSytem.width()*zoom*visualScale);
}
