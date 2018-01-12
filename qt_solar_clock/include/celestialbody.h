#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <QPainter>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <stdint.h>
#include <QtSvg/QSvgRenderer>
#include <QtSvg/QGraphicsSvgItem>
#include "orbitaltrack.h"



class CelestialBody: public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    CelestialBody(QString bodyName, qreal size, qreal orbitalVelocity, QString trajectoryFilePath, QString imageFilePath);
    ~CelestialBody();
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
    void vLoadTrajectory(QString filePath);
    ObritalTrack* getTrjectory();

public slots:
    void setMovementScale(int scale);

protected:
    void advance(int step) override;

private:
    int distanceScale = 1500; //150millionkm = 1au
    qreal kmToMKM = .001;
    qreal movementScale = 10000.0;
    int simStepScale = 10;

    qreal orbitalVelocity;
    std::vector<double> distanceMeasurements;
    QPainterPath obritalTrajectory;
    ObritalTrack *track;
    QPainterPath testtraj;
    qreal pathPercentComplete;
    QPolygonF pathPoly;
    QString bodyName;
    qreal bodySize;
    QSvgRenderer *render;
    QGraphicsSvgItem svg;
};








#endif // CELESTIALBODY_H
