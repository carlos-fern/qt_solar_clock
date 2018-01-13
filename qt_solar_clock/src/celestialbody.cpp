#include "include/celestialbody.h"
#include <QPropertyAnimation>
#include <QDebug>
#include <QtMath>
#include <QFile>
#include <QXmlStreamReader>
#include <QPainter>
#include <QFile>


CelestialBody::CelestialBody( QString bodyName, qreal size, qreal orbitalVelocity, QString trajectoryFilePath, QColor bodyColor){
    vLoadTrajectory(trajectoryFilePath);
    this->bodyName = bodyName;
    this->orbitalVelocity = orbitalVelocity;
    this->bodySize = size;
    this->bodyColor = bodyColor;
}
CelestialBody::~CelestialBody(){
    delete track;


}

ObritalTrack* CelestialBody::getTrjectory(){
    return track;
}


void  CelestialBody::vLoadTrajectory(QString filePath){

    QRegExp trajectoryParser("(\\d{4}\\b)(?:\\s*)(\\d{1,3})(?:\\s*)(-?\\d*\\.?\\d+)(?:\\s*)(-?\\d*\\.?\\d+)(?:\\s*)(-?\\d*\\.?\\d+)"); //Group 1 = Year, Group 2 = DOY, Group 3 = au
    QFile trajectoryFile(filePath);
    trajectoryFile.open(QIODevice::ReadOnly | QIODevice::Text);

    int currentPosition = 0;
    QTextStream trajectoryStream(&trajectoryFile);
        while (!trajectoryStream.atEnd()) {
            QString line = trajectoryStream.readLine();
            while ((currentPosition = trajectoryParser.indexIn(line, currentPosition)) != -1) {
               distanceMeasurements.push_back(trajectoryParser.cap(3).toDouble());
               currentPosition += trajectoryParser.matchedLength();
            }
            currentPosition = 0;
    }

    double max = *std::max_element(distanceMeasurements.begin(), distanceMeasurements.end()) *distanceScale;
    double min = *std::min_element(distanceMeasurements.begin(), distanceMeasurements.end()) *distanceScale;
    obritalTrajectory.addEllipse(QPointF(0,0), max, min);
    track = new ObritalTrack(max, min);
}


void CelestialBody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget){
    QPen pen;
    pen.setColor(bodyColor);
    pen.setWidth(30);
    painter->setPen(pen);
    painter->setBrush(QBrush(pen.color()));
    painter->setRenderHint(QPainter::SmoothPixmapTransform, true);
    painter->setCompositionMode(QPainter::CompositionMode_Plus);
    painter->setRenderHint(QPainter::HighQualityAntialiasing,true);
    painter->drawEllipse(this->scenePos(),bodySize*kmToMKM, bodySize*kmToMKM);

}

void CelestialBody::advance(int step){
    if(!step)
        return;
    else{
       pathPercentComplete = (qreal)((pathPercentComplete + orbitalVelocity / movementScale)<= 1.0 ? (pathPercentComplete + orbitalVelocity / movementScale) : 0.0);
       this->setPos(obritalTrajectory.pointAtPercent(pathPercentComplete));
    }
}


QRectF CelestialBody::boundingRect() const {
    return QRectF(-bodySize*kmToMKM/2, -bodySize*kmToMKM/2,bodySize*kmToMKM, bodySize*kmToMKM);
}


QPainterPath CelestialBody::shape() const{
    QPainterPath path;
    path.addEllipse(0,0, 0, 0);
    return path;
}


void CelestialBody::setMovementScale(int value){
   this->movementScale= abs(value) * simStepScale;
}
