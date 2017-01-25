#pragma once

#include <QGraphicsItem>
#include <QPolygon>
#include <QPainter>

///Class describes landscape in the map
class Landscape : public QGraphicsItem
{
public:
    explicit Landscape(const QPolygon &points);
    ///Method returns coordinates on the scene using relative coordinates. Before using need
    /// to check move ability with "canMove"
    QPoint getByRelativeCoord(int relativeCoord);
    ///Method checks can an object removes in this relative coord
    bool canMove(int relativeCoord);
    ///Method draws landcape line and fill area under this line
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

private:
    QPolygon mPoints;
    QPolygon mRelativeCoord;
    ///Method counts the distance between two points
    double countDistance(const QPoint &point1, const QPoint &point2) const;
    ///We have an interval(because we know two points) and we want to know point on it, that devides it in relation
    /// (pointNumber : (pointsCount - pointNumber))
    QPoint countRelativeCoord(const QPoint &point1, const QPoint &point2, int pointNumber, int pointsCount) const;
};
