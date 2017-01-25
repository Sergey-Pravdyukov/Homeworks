#include "flightParameters.h"

QPoint FlightParameters::coordTimeDependence(const QPoint &initialCoord, int velocity, int angle, int directionCoef,
                                             double timeFromStart)
{
    const double angleInRadians = qDegreesToRadians(static_cast<double>(angle));
    const double cosAngle = qCos(angleInRadians);
    const double sinAngle = qSin(angleInRadians);
    const double velocityX = directionCoef * velocity * cosAngle;
    const double velocityY = velocity * sinAngle;
    const double coordX = initialCoord.x() + timeFromStart * velocityX;
    const double coordY =  - initialCoord.y() + velocityY * timeFromStart - accelerationG * timeFromStart * timeFromStart / 2;
    return QPoint(coordX, - coordY);
}
