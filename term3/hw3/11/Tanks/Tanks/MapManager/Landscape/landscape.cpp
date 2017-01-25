#include "landscape.h"

Landscape::Landscape(const QPolygon &points) : mPoints(points)
{
    const int pointsCount = points.size();
    for (int i = 1; i < pointsCount; i++)
    {
        const double length = countDistance(mPoints[i - 1], mPoints[i]);
        for (int j = 0; j < length - 1; j = j + 5)
        {
            const QPoint nextPoint = countRelativeCoord(mPoints[i - 1], mPoints[i], j, static_cast<int>(length));
            mRelativeCoord.append(nextPoint);
        }
        mRelativeCoord.append(mPoints[i]);
    }
}

QPoint Landscape::getByRelativeCoord(int relativeCoord)
{
    return mRelativeCoord[relativeCoord];
}

bool Landscape::canMove(int relativeCoord)
{
    return (relativeCoord < mRelativeCoord.size() && relativeCoord >= 0);
}

void Landscape::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QColor(139, 69, 19));
    painter->setBrush(QColor(139 , 69, 19));
    const int pointsCount = mPoints.size();
    for (int i = 1; i < pointsCount; i++)
    {
        QPoint area[4] = {mPoints[i - 1], mPoints[i], QPoint(mPoints[i].x(), 300), QPoint(mPoints[i - 1].x(), 300)};
        painter->drawConvexPolygon(area, 4);
    }
    painter->setPen(QColor(139, 69, 19));
    painter->drawPolyline(mPoints);
}

QRectF Landscape::boundingRect() const
{
    return QRectF(QPoint(-300, 0), QPoint(300, 80));
}

QPainterPath Landscape::shape() const
{
    QPainterPath path;
    path.addPolygon(mPoints);
    return path;
}

double Landscape::countDistance(const QPoint &point1, const QPoint &point2) const
{
    return sqrt(pow(point1.x() - point2.x(), 2) + pow(point1.y() - point2.y(), 2));
}

QPoint Landscape::countRelativeCoord(const QPoint &point1, const QPoint &point2, int pointNumber, int pointsCount) const
{
    const double lambda = static_cast<double>(pointNumber) / (pointsCount - pointNumber);
    const double coordX = (point1.x() + lambda * point2.x()) / (1 + lambda);
    const double coordY = (point1.y() + lambda * point2.y()) / (1 + lambda);
    return QPoint(coordX, coordY);
}
