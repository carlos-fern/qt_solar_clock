#ifndef CELESTIALBODY_H
#define CELESTIALBODY_H
#include <QPainter>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <stdint.h>



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


public slots:
    void setMovementScale(int scale);

protected:
    void advance(int step) override;

private:
    int distanceScale = 10000;
    qreal movementScale = 10000.0;
    int simStepScale = 100;

    qreal orbitalVelocity;
    std::vector<double> distanceMeasurements;
    QPainterPath obritalTrajectory;
    qreal pathPercentComplete;

    QString bodyName;
    qreal bodySize;
    QPixmap bodyImage;

};








#endif // CELESTIALBODY_H
