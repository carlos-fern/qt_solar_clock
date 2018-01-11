#include <QPainter>
#include <QtSvg/QSvgRenderer>
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
    this->setSceneRect(-1024, -768, 2048 , 1536);
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
   QSvgRenderer *render = new QSvgRenderer(QLatin1String("./assets/sun.svg"));
   //render->setViewBox(QRect(78.5, 78.5, 78.5,78.5));
   //QScale
   Sun = new QGraphicsSvgItem();
   Sun->setPos(-39.25, -39.25);
   Sun->setSharedRenderer(render);
   Sun->setScale(.01 * 109);

   Mercury = new CelestialBody("Mercury", .38, 47.4,"./heliocentric_trajectories/Mercury.lst", "./images/mercury.jpg");
   Venus = new CelestialBody("Venus", .95 ,35.0,"./heliocentric_trajectories/Venus.lst", "./images/venus.jpg");
   Earth = new CelestialBody("Earth",1, 29.8, "./heliocentric_trajectories/Earth.lst", "./images/earth.jpg");
   Mars = new CelestialBody("Mars",.53, 24.1, "./heliocentric_trajectories/Mars.lst", "./images/mars.jpg");
   Jupiter = new CelestialBody("Jupiter", 11.19, 13.1, "./heliocentric_trajectories/Jupiter.lst", "/images/jupiter.jpg");
   Saturn = new CelestialBody("Saturn", 9.40, 9.7, "./heliocentric_trajectories/Saturn.lst", "/images/saturn.jpg");
   Uranus = new CelestialBody("Uranus", 4.04, 6.8, "./heliocentric_trajectories/Uranus.lst", "/images/uranus.jpg");
   Neptune = new CelestialBody("Neptune",3.88, 5.4, "./heliocentric_trajectories/Neptune.lst", "./images/neptune.jpg");
   QPen pen;
   pen.setColor(Qt::red);
   pen.setWidth(109*10);
   this->addEllipse(0.0,0.0, 10 * 109, 10 *109, pen);
  // this->addItem(Sun);
   this->addItem(Mercury);
   this->addItem(Venus);
   this->addItem(Earth);
   this->addItem(Mars);
   this->addItem(Jupiter);
   this->addItem(Saturn);
   this->addItem(Uranus);
   this->addItem(Neptune);
   this->setItemIndexMethod(QGraphicsScene::BspTreeIndex);

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
