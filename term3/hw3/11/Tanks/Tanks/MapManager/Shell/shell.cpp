#include "shell.h"

Shell::Shell(const QPoint &initCoordinates, int gunAngle, int directionCoef, int radius, int velocity) :
    mInitCoordinates(initCoordinates), mGunAngle(gunAngle), mDirectionCoef(directionCoef), mTimeFromStart(0.0),
    mRadius(radius), mVelocity(velocity)
{
    setPos(mInitCoordinates);
}

void Shell::updateCoordinates()
{
    mTimeFromStart += 0.125;
    setPos(FlightParameters::coordTimeDependence(mInitCoordinates, mVelocity, mGunAngle, mDirectionCoef, mTimeFromStart));
}

void Shell::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::blue);
    painter->setBrush(Qt::blue);
    painter->drawEllipse(QPoint(0, 0), mRadius, mRadius);
}

QRectF Shell::boundingRect() const
{
    return QRectF(QPoint(mRadius, -mRadius), QPoint(-mRadius, mRadius));
}

QPainterPath Shell::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0), mRadius, mRadius);
    return path;
}
