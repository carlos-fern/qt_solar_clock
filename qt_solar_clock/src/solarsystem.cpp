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
    this->setSceneRect(-1024*100, -768*100, 2048*100, 1536*100);
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

//150 Millonkm == 1 au
void SolarSystem::createScene(){
    QSvgRenderer *render = new QSvgRenderer(QLatin1String("./assets/sun.svg"));
    //render->setViewBox(QRect(78.5, 78.5, 78.5,78.5));
    //QScale
    Sun = new QGraphicsSvgItem();
    Sun->setPos(-39.25, -39.25);
    Sun->setSharedRenderer(render);
    Sun->setScale(.001 * 109);

    Mercury = new CelestialBody("Mercury", 4878, 47.4,"./heliocentric_trajectories/Mercury.lst", "./images/mercury.jpg");
    Venus = new CelestialBody("Venus", 12104 ,35.0,"./heliocentric_trajectories/Venus.lst", "./images/venus.jpg");
    Earth = new CelestialBody("Earth", 6794, 29.8, "./heliocentric_trajectories/Earth.lst", "./images/earth.jpg");
    Mars = new CelestialBody("Mars", 6794, 24.1, "./heliocentric_trajectories/Mars.lst", "./images/mars.jpg");
    Jupiter = new CelestialBody("Jupiter", 142984, 13.1, "./heliocentric_trajectories/Jupiter.lst", "/images/jupiter.jpg");
    Saturn = new CelestialBody("Saturn", 120536, 9.7, "./heliocentric_trajectories/Saturn.lst", "/images/saturn.jpg");
    Uranus = new CelestialBody("Uranus", 51118, 6.8, "./heliocentric_trajectories/Uranus.lst", "/images/uranus.jpg");
    Neptune = new CelestialBody("Neptune",49532, 5.4, "./heliocentric_trajectories/Neptune.lst", "./images/neptune.jpg");
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
