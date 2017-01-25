#pragma once

#include "shell.h"

///Class draws a big bomb
class BigShell : public Shell
{
public:
    BigShell(const QPoint &initCoordinates, int gunAngle, int directionCoef);
    ///Method draws big shell as a big circle
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
};
