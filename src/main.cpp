#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <QTimer>
#include <QOpenGLWidget>
#include "solarsystem.h"
#include <QSlider>
#include <QDockWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
