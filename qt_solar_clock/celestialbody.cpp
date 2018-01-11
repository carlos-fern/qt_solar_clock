#include "include/celestialbody.h"
#include <QPropertyAnimation>
#include <QDebug>
#include <QtMath>
#include <QFile>
#include <QXmlStreamReader>
#include <QFile>


CelestialBody::CelestialBody( QString bodyName, qreal size, qreal orbitalVelocity, QString trajectoryFilePath, QString imageFilePath){
     vLoadTrajectory(trajectoryFilePath);
   // bodyImage.load(imageFilePath);
    this->bodyName = bodyName;
    this->orbitalVelocity = orbitalVelocity;
    this->bodySize = size;
}


CelestialBody::~CelestialBody(){


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

    double max = *std::max_element(distanceMeasurements.begin(), distanceMeasurements.end());
    double min = *std::min_element(distanceMeasurements.begin(), distanceMeasurements.end());
    obritalTrajectory.addEllipse(QPointF(0,0), max*distanceScale, min*distanceScale);
}


void CelestialBody::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget){

    QColor color;
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(4);
    painter->setPen(pen);

    painter->drawEllipse(QPoint(0,0),50*bodySize,50*bodySize);
    /*
    QPixmap stp1;
    stp1.setDevicePixelRatio(30000);
    stp1 = bodyImage.scaledToHeight(10);

    QPixmap stp2;
    stp2.setDevicePixelRatio(30000);
    stp2 = stp1.scaledToWidth(10);

    QPainterPath path;
    path.addEllipse(0, 0, 8, 8);
    painter->setClifpPath(path);
    painter->drawPixmap(0, 0, 10, 10, stp2);
    */

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
    return QRectF(-640, -480, 1280, 960);
}


QPainterPath CelestialBody::shape() const{
    QPainterPath path;
    path.addRect(-10, -20, 40, 80);
    return path;
}


void CelestialBody::setMovementScale(int value){
   this->movementScale= abs(value) * simStepScale;
}
