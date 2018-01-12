#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QXmlStreamReader>

#include <QtSvg/QGraphicsSvgItem>
#include <QPainterPathStroker>

#include <QFile>

#include "celestialbody.h"

class SolarSystem: public QGraphicsScene{
    Q_OBJECT
public:
    SolarSystem();
    ~SolarSystem();
public slots:
    void setMovementScale(int scale);

signals:
    void valueChanged(int scale);

private:
    void createScene();
    QGraphicsSvgItem *Sun;
    QGraphicsEllipseItem *sun;
    QPainterPathStroker strokedPath;
    QGraphicsItemGroup group;
    CelestialBody *Mercury;
    CelestialBody *Venus;
    CelestialBody *Earth;
    CelestialBody *Mars;
    CelestialBody *Jupiter;
    CelestialBody *Saturn;
    CelestialBody *Uranus;
    CelestialBody *Neptune;
};



#endif // SOLARSYSTEM_H
