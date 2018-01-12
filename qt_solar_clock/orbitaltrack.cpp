#include <include/orbitaltrack.h>

ObritalTrack::ObritalTrack(double min, double max){

    this->min = min*2; //2x due to odd behavior of QPainterPath PointAtPercent vs drawing
    this->max = max*2;
}

void ObritalTrack::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                         QWidget *widget){

    QColor color;
    QBrush brush;
    brush.setColor(Qt::blue);
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(180);
    pen.setCapStyle(Qt::FlatCap);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::HighQualityAntialiasing);
    painter->drawEllipse(this->pos(), min ,max);
}

QRectF ObritalTrack::boundingRect() const {
    return QRectF(0, 0,0, 0);
}


QPainterPath ObritalTrack::shape() const{
    QPainterPath path;
    path.addEllipse(0,0,0,0);
    return path;
}
