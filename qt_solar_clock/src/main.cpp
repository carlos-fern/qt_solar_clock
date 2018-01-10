#include "include/mainwindow.h"
#include <QApplication>
#include <QGraphicsView>
#include <include/solarsystem.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SolarSystem solarSytem;
    QGraphicsView solarViewer(&solarSytem);
    solarViewer.show();

    return a.exec();
}
