#pragma once

#include "shell.h"

///Class draws small shell
class SmallShell : public Shell
{
public:
    SmallShell(const QPoint &initCoordinates, int gunAngle, int directionCoef);
    ///Method draws shell as a black circle
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
};
