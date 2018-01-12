#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QDockWidget>
#include <QGraphicsView>
#include <QTimer>
#include <include/solarsystem.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void createInteractive();
    ~MainWindow();

public slots:
    void setTimeWarpSacle(int scale);
    void setTiltValue(int scale);
    void setPanValue(int scale);
    void setZoomValue(int scale);

private:
    Ui::MainWindow *ui;

    QSlider *timeWarpSlider;
    QSlider *tiltSlider;
    QSlider *panSlider;
    QSlider *zoomSlider;
    QTransform perspectiveTransform;
    QMatrix perspectiveTrasformMatrix;
    SolarSystem solarSytem;
    QGraphicsView *solarViewer;


    QDockWidget *timeWarpSliderDock;
    QDockWidget *tiltSliderDock;
    QDockWidget *panSliderDock;
    QDockWidget *zoomSliderDock;
    QTimer timer;
    int zoom= 4;
    int tilt =0;

};

#endif // MAINWINDOW_H
