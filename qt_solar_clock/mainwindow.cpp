#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QLatin1String>
#include <QString>
#include <QSlider>
#include <QOpenGLWidget>
#include <QDockWidget>
#include <QGraphicsView>
#include <QTimer>
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
    tiltSlider->setMinimum(-100);
    tiltSlider->setMaximum(-10);
    tiltSlider->setValue(-100);

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
    zoomSlider->setMinimum(-100);
    zoomSlider->setMaximum(-10);
    zoomSlider->setValue(-100);

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
    solarViewer->resize(1024,768);
    solarViewer->scale(2,2);

    this->setCentralWidget(solarViewer);

    QObject::connect(timeWarpSlider, SIGNAL(valueChanged(int)),
                      &solarSytem, SLOT(setMovementScale(int)));

    this->setCentralWidget(solarViewer);
    this->show();


    QObject::connect(&timer, SIGNAL(timeout()), &solarSytem, SLOT(advance()));
    timer.start(1000/66);



}


void MainWindow::setTimeWarpSacle(int scale){


}


void MainWindow::setTiltValue(int scale){

}


void MainWindow::setPanValue(int scale){


}


void MainWindow::setZoomValue(int scale){


}
