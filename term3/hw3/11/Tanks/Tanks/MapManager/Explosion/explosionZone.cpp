#include "explosionZone.h"

ExplosionZone::ExplosionZone(const QPointF &center) : center(center)
{
    setPos(center);
}

void ExplosionZone::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(Qt::red);
    painter->drawEllipse(QPoint(0, 0), explosionRadius, explosionRadius);
}

QRectF ExplosionZone::boundingRect() const
{
    return (QRectF(QPoint(explosionRadius, -explosionRadius), QPoint(-explosionRadius, explosionRadius)));
}

QPainterPath ExplosionZone::shape() const
{
    QPainterPath path;
    path.addEllipse(QPoint(0, 0), explosionRadius, explosionRadius);
    return path;
}
