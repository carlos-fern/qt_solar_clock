#include <QPainter>
#include <QtSvg/QSvgRenderer>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>
#include <QPointF>
#include "include/solarsystem.h"


SolarSystem::SolarSystem(){
    //Configure Window
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->setPalette(pal);
    this->createScene();
    this->setSceneRect(-1024*100, -768*100, 2048*100, 1536*100); //large values to keep the GraphicsViwer happy with the internl scene.
}


SolarSystem::~SolarSystem(){
    delete Mercury;
    delete Venus;
    delete Earth; // <-- :(
    delete Mars;
    delete Jupiter;
    delete Saturn;
    delete Uranus;
    delete Neptune;
}

void SolarSystem::createScene(){

    Mercury = new CelestialBody("Mercury", 4878, 47.4,"./heliocentric_trajectories/Mercury.lst", "./assets/mercury.svg");
    Venus = new CelestialBody("Venus", 12104 ,35.0,"./heliocentric_trajectories/Venus.lst", "./assets/venus.svg");
    Earth = new CelestialBody("Earth", 6794, 29.8, "./heliocentric_trajectories/Earth.lst", "./assets/earth.svg");
    Mars = new CelestialBody("Mars", 6794, 24.1, "./heliocentric_trajectories/Mars.lst", "./assets/mars.svg");
    Jupiter = new CelestialBody("Jupiter", 142984, 13.1, "./heliocentric_trajectories/Jupiter.lst", "./assets/jupiter.svg");
    Saturn = new CelestialBody("Saturn", 120536, 9.7, "./heliocentric_trajectories/Saturn.lst", "./assets/saturn.svg");
    Uranus = new CelestialBody("Uranus", 51118, 6.8, "./heliocentric_trajectories/Uranus.lst", "./assets/uranus.svg");
    Neptune = new CelestialBody("Neptune",49532, 5.4, "./heliocentric_trajectories/Neptune.lst", "./assets/neptune.svg");

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(200);
    sun = new QGraphicsEllipseItem(0.0,0.0, 1391400*.0001, 1391400*.0001);
    sun->setPos(QPointF(0,0));
    sun->setPen(pen);

    //add tracks (lowest draw)
    this->addItem(Mercury->getTrjectory());
    this->addItem(Venus->getTrjectory());
    this->addItem(Earth->getTrjectory());
    this->addItem(Mars->getTrjectory());
    this->addItem(Jupiter->getTrjectory());
    this->addItem(Saturn->getTrjectory());
    this->addItem(Uranus->getTrjectory());
    this->addItem(Neptune->getTrjectory());

    //add bodies
    this->addItem(sun);
    this->addItem(Mercury);
    this->addItem(Venus);
    this->addItem(Earth);
    this->addItem(Mars);
    this->addItem(Jupiter);
    this->addItem(Saturn);
    this->addItem(Uranus);
    this->addItem(Neptune);
    this->setItemIndexMethod(QGraphicsScene::NoIndex);

    QObject::connect(this, SIGNAL(valueChanged(int)), Mercury, SLOT(setMovementScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Venus, SLOT(setMovementScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Earth, SLOT(setMovementScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Mars, SLOT(setMovementScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Jupiter, SLOT(setMovementScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Saturn, SLOT(setMovementScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Uranus, SLOT(setMovementScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Neptune, SLOT(setMovementScale(int)));
}


void SolarSystem::setMovementScale(int scale){
    emit valueChanged(scale);
}
