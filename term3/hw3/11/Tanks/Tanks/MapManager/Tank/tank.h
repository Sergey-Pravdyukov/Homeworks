#pragma once

#include <QGraphicsItem>
#include <QPainter>
#include <QtMath>
#include "../Landscape/landscape.h"

///Class draws tank and keeps track of its movement
class Tank : public QGraphicsItem
{
public:
    ///Enumerator for movement directions
    enum Direction
    {
        left = -1,
        right = 1
    };
    ///Enumerator for types of gun
    enum GunType
    {
        bigGun,
        smallGun
    };
    ///Enumerator for types of tank
    enum Type
    {
        user,
        enemy
    };
    explicit Tank(Landscape *landscape, Type type);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    ///If it is possible, method increases angle of the gun
    void gunUp();
    ///If it is possible, method decreases angle of the gun
    void gunDown();
    ///If it is possible, method moves tank right
    void moveRight();
    ///If it is possible, method moves tank left
    void moveLeft();
    ///Method change type of the gun at the next
    void changeGun();
    ///Method counts QPoint, where shell must be thrown
    QPoint countShellPlace() const;
    ///Method returns angle of the gun
    int getGunAngle() const;
    ///Method returns coordinate coeficient of direction
    int getDirectionCoef() const;
    ///Method returns type of the tank's gun
    GunType getGunType() const;

private:
    Landscape *mLandscape;
    Type mType;
    Direction mDirection;
    int mCoord;
    GunType mGunType;
    double mGunAngle;
    static const int cGunLength = 20;
    static const int cAngleDelta = 5;
    static const int cGunRadius = 2;
};
