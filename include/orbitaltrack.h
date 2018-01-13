#ifndef ORBITALTRACK_H
#define ORBITALTRACK_H

#endif // ORBITALTRACK_H
#include <QPainter>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <stdint.h>
#include <QPointF>




class ObritalTrack: public QObject, public QGraphicsItem {
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)

public:
    ObritalTrack(double min, double max);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;
protected:
    void advance(int step) override;

private:
    qreal min;
    qreal max;
};


