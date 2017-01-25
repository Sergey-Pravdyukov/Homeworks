#pragma once

#include <QPoint>
#include <QtMath>

///Class counts coordinates of shells' flights
class FlightParameters
{
public:
    ///Method counts coordinates of the object using initial coordinates, using the angle of the throw,
    /// velocity of the throw, time from start throwing
    static QPoint coordTimeDependence(const QPoint &initialCoord, int velocity, int angle, int directionCoef,
                                      double timeFromStart);
private:
    static const int accelerationG = 10;
};
