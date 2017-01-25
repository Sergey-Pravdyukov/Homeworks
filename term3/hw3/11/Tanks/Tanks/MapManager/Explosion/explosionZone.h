#pragma once

#include <QGraphicsItem>
#include <QPainter>

///Class draws an explosion on the scene
class ExplosionZone : public QGraphicsItem
{
public:
    ExplosionZone(const QPointF &center);
    ///Draw an explosion zone as a red circle
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    QRectF boundingRect() const;
    QPainterPath shape() const;

private:
    QPointF center;
    static const int explosionRadius = 10;
};
