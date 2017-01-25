#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include "../Flight/flightParameters.h"

///Class draws a shell and counts its current coordinates
class Shell : public QGraphicsItem
{
public:
    Shell(const QPoint &initCoordinates, int gunAngle, int directionCoef, int radius, int velocity);
    ///Method counts current coordinates of the shell and update them on the scene
    void updateCoordinates();
    ///Method draws a circle, that describes a shell
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
protected:
    QPoint mInitCoordinates;
    int mGunAngle;
    int mDirectionCoef;
    double mTimeFromStart;
    int mRadius;
    int mVelocity;
};
