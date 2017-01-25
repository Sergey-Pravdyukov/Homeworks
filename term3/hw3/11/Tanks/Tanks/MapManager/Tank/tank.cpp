#include "tank.h"

Tank::Tank(Landscape *landscape, Type type) : mLandscape(landscape), mDirection(right), mCoord(0), mGunType(smallGun),
    mGunAngle(45), mType(type)
{
    setPos(mLandscape->getByRelativeCoord(mCoord));
}

void Tank::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    static const QPoint gun[4] =
    {
        QPoint(0, cGunRadius), QPoint(0, -cGunRadius), QPoint(cGunLength, -cGunRadius), QPoint(cGunLength, cGunRadius)
    };
    int rotateAngle = 0;
    mDirection == right ? rotateAngle = -mGunAngle : rotateAngle = mGunAngle + 180;
    if (mType == enemy)
    {
        painter->setPen(Qt::white);
        painter->setBrush(Qt::black);
    }
    else
    {
        painter->setPen(Qt::black);
        painter->setBrush(Qt::white);
    }
    painter->rotate(rotateAngle);
    painter->drawConvexPolygon(gun, 4);
    painter->rotate(-rotateAngle);
    painter->drawRect(-10, -4, 20, 12);
    painter->drawRect(-5, -6, 10, 6);
}

QRectF Tank::boundingRect() const
{
    return QRectF(QPoint(-20, 20), QPoint(20, -20));
}

QPainterPath Tank::shape() const
{
    QPainterPath path;
    path.addRect(-10, -4, 20, 12);
    path.addRect(-5, -6, 10, 6);
    return path;
}

void Tank::gunUp()
{
    if (mGunAngle < 80)
        mGunAngle += cAngleDelta;
}

void Tank::gunDown()
{
    if (mGunAngle > 0)
        mGunAngle -= cAngleDelta;
}

void Tank::moveRight()
{
    if (mLandscape->canMove(mCoord + 1))
    {
        mCoord++;
        setPos(mLandscape->getByRelativeCoord(mCoord));
        mDirection = right;
    }
}

void Tank::moveLeft()
{
    if (mLandscape->canMove(mCoord - 1))
    {
        mCoord--;
        setPos(mLandscape->getByRelativeCoord(mCoord));
        mDirection = left;
    }
}

void Tank::changeGun()
{
    switch (mGunType)
    {
    case smallGun:
    {
        mGunType = bigGun;
    }
        break;
    case bigGun:
    {
        mGunType = smallGun;
    }
        break;
    }
}

QPoint Tank::countShellPlace() const
{
    const QPointF tankCenter = this->pos();
    const double angleInRadians = qDegreesToRadians(static_cast<double>(mGunAngle));
    return QPoint(tankCenter.x() + cGunLength * getDirectionCoef() * qCos(angleInRadians),
                  tankCenter.y() - cGunLength * qSin(angleInRadians));
}

int Tank::getGunAngle() const
{
    return mGunAngle;
}

int Tank::getDirectionCoef() const
{
    int directionCoef = 0;
    mDirection == right ? directionCoef = 1 : directionCoef = -1;
    return directionCoef;
}

Tank::GunType Tank::getGunType() const
{
    return mGunType;
}
