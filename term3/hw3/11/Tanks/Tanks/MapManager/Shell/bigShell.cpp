#include "bigShell.h"

BigShell::BigShell(const QPoint &initCoordinates, int gunAngle, int directionCoef) :
    Shell(initCoordinates, gunAngle, directionCoef, 5, 30) {}

void BigShell::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red);
    painter->drawEllipse(QPoint(0, 0), mRadius, mRadius);
}

QRectF BigShell::boundingRect() const
{
    return QRectF(QPoint(mRadius, mRadius), QPoint(mRadius, mRadius));
}

QPainterPath BigShell::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0), mRadius, mRadius);
    return path;
}
