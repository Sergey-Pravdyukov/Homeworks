#include "smallShell.h"

SmallShell::SmallShell(const QPoint &initCoordinates, int gunAngle, int directionCoef) :
    Shell(initCoordinates, gunAngle, directionCoef, 3, 50)
{}

void SmallShell::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::blue);
    painter->drawEllipse(QPoint(0, 0), mRadius, mRadius);
}

QRectF SmallShell::boundingRect() const
{
    return QRectF(QPoint(mRadius, -mRadius), QPoint(-mRadius, mRadius));
}

QPainterPath SmallShell::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0), mRadius, mRadius);
    return path;
}
