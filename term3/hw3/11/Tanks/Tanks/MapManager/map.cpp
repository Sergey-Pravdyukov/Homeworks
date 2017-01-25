#include "map.h"

Map::Map(QWidget *parent) : QGraphicsView(parent), mUserTank(nullptr), mEnemyTank(nullptr), mDefender(nullptr),
    mShell(nullptr), mShellType(smallShell), fShellIsPushed(false), fUserStep(false)
{
    mScene = new QGraphicsScene(this);
    mScene->setSceneRect(-300, -300, 600, 400);
    setScene(mScene);
    setBackgroundBrush(Qt::white);
    QPolygon points;
    points << QPoint(-300, -20) << QPoint(-250, -10) << QPoint(-200, -150) << QPoint(-150, -110) << QPoint(-100, -140)
           << QPoint(-50, -30) << QPoint(0, 0) << QPoint(50, -70) << QPoint(100, -20) << QPoint(150, -50)
           << QPoint(200, -90) << QPoint(250, -25) << QPoint(300, 0);
    mLandscape = new Landscape(points);
    mScene->addItem(mLandscape);
    mUserTank = new Tank(mLandscape, Tank::Type::user);
    mScene->addItem(mUserTank);
    mEnemyTank = new Tank(mLandscape, Tank::Type::enemy);
    mScene->addItem(mEnemyTank);
    mTimer = new QTimer(this);
    connect(mTimer, &QTimer::timeout, this, &Map::checkShell);
}

Map::~Map()
{
    delete mScene;
    delete mLandscape;
    delete mUserTank;
    delete mEnemyTank;
    delete mTimer;
}

void Map::makeFirst()
{
    fUserStep = true;
}

void Map::keyPressEvent(QKeyEvent *event)
{
    if (!fShellIsPushed && fUserStep)
    {
        switch (event->key())
        {
        case Qt::Key_Left:
        {
            mUserTank->moveLeft();
            emit userChanged(left);
        }
            break;
        case Qt::Key_Right:
        {
            mUserTank->moveRight();
            emit userChanged(right);
        }
            break;
        case Qt::Key_Up:
        {
            mUserTank->gunUp();
            emit userChanged(up);
        }
            break;
        case Qt::Key_Down:
        {
            mUserTank->gunDown();
            emit userChanged(down);
        }
            break;
        case Qt::Key_Enter:
        {
            userFight();
        }
            break;
        case Qt::Key_Return:
        {
            userFight();
        }
            break;
        case Qt::Key_Space:
        {
            mUserTank->changeGun();
            emit userChanged(changeGun);
        }
            break;
        }
        viewport()->update();
    }
}

void Map::updateEnemy(Command command)
{
    switch (command)
    {
    case left:
    {
        mEnemyTank->moveLeft();
    }
        break;
    case right:
    {
        mEnemyTank->moveRight();
    }
        break;
    case up:
    {
        mEnemyTank->gunUp();
    }
        break;
    case down:
    {
        mEnemyTank->gunDown();
    }
        break;
    case fight:
    {
        mDefender = mUserTank;
        fUserStep = true;
        pushShell(mEnemyTank);
    }
        break;
    case changeGun:
    {
        mEnemyTank->changeGun();
    }
        break;
    }
    viewport()->update();
}

void Map::userFight()
{
    mDefender = mEnemyTank;
    fUserStep = false;
    pushShell(mUserTank);
    emit userChanged(fight);
}

void Map::pushShell(Tank *attackingTank)
{
    fShellIsPushed = true;
    const QPoint gunEnd = attackingTank->countShellPlace();
    switch (attackingTank->getGunType())
    {
    case Tank::smallGun:
    {
        mShell = new SmallShell(gunEnd, attackingTank->getGunAngle(), attackingTank->getDirectionCoef());
        mShellType = smallShell;
    }
        break;
    case Tank::bigGun:
    {
        mShell = new BigShell(gunEnd, attackingTank->getGunAngle(), attackingTank->getDirectionCoef());
        mShellType = bigShell;
    }
        break;
    }
    mScene->addItem(mShell);
    mTimer->start(40);
}

void Map::checkShell()
{
    if (mShell->collidesWithItem(mDefender))
    {
        emit gameIsOver();
        deleteShell();
    }
    else if (mShell->collidesWithItem(mLandscape))
    {
        if (mShellType == bigShell)
            makeExplosion(mShell->pos());
        deleteShell();
    }
    else if (!isOnScene(mShell))
        deleteShell();
    else
        mShell->updateCoordinates();
    viewport()->update();
}

void Map::delayExplosionDeletion()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Map::deleteShell()
{
    fShellIsPushed = false;
    mTimer->stop();
    mDefender = nullptr;
    delete mShell;
}

bool Map::isOnScene(QGraphicsItem *item) const
{
    return (mScene->sceneRect().contains(item->pos()));
}

void Map::makeExplosion(const QPointF &point)
{
    ExplosionZone *explosion = new ExplosionZone(point);
    mScene->addItem(explosion);
    viewport()->update();
    delayExplosionDeletion();
    if (explosion->collidesWithItem(mDefender))
        emit gameIsOver();
    delete explosion;
}
