#include <QPainter>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>
#include "include/solarsystem.h"


SolarSystem::SolarSystem(){
    //Configure Window
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->setPalette(pal);
    this->createScene();
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

    star.setDevicePixelRatio(10000);
    star.load("./images/sun.jpg");
    star = star.scaledToHeight(300);
    star = star.scaledToWidth(400);

    Mercury = new CelestialBody("Mercury", 1, 47.4,"./heliocentric_trajectories/Mercury.lst", "./images/mercury.jpg");
    Venus = new CelestialBody("Venus", 2 ,35.0,"./heliocentric_trajectories/Venus/lst", "./images/venus.jpg");
    Earth = new CelestialBody("Earth",3, 29.8, "./heliocentric_trajectories/Earth/lst", "./images/earth.jpg");
    Mars = new CelestialBody("Mars",4, 24.1, "./heliocentric_trajectories/Mars/lst", "./images/mars.jpg");
    Jupiter = new CelestialBody("Jupiter", 5, 13.1, "./heliocentric_trajectories/Jupiter/lst", "/images/jupiter.jpg");
    Saturn = new CelestialBody("Saturn",6, 9.7, "./heliocentric_trajectories/Saturn/lst", "/images/saturn.jpg");
    Uranus = new CelestialBody("Uranus",7, 6.8, "./heliocentric_trajectories/Uranus/lst", "/images/uranus.jpg");
    Neptune = new CelestialBody("Neptune",8, 5.4, "./heliocentric_trajectories/Venus/lst", "./images/neptune.jpg");

    QGraphicsPixmapItem *pm = this->addPixmap(star);
    pm->setPos(0,0);
    this->addItem(Mercury);
    this->addItem(Venus);
    this->addItem(Earth);
    this->addItem(Mars);
    this->addItem(Jupiter);
    this->addItem(Saturn);
    this->addItem(Uranus);
    this->addItem(Neptune);
    this->setItemIndexMethod(QGraphicsScene::BspTreeIndex);

    QObject::connect(this, SIGNAL(valueChanged(int)), Mercury, SLOT(vSetScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Venus, SLOT(vSetScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Earth, SLOT(vSetScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Mars, SLOT(vSetScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Jupiter, SLOT(vSetScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Saturn, SLOT(vSetScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Uranus, SLOT(vSetScale(int)));
    QObject::connect(this, SIGNAL(valueChanged(int)), Neptune, SLOT(vSetScale(int)));
}


void SolarSystem::setMovementScale(int scale){
    emit valueChanged(scale);
}
