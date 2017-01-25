#pragma once

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QTimer>
#include <QCoreApplication>
#include <QTime>
#include "Landscape/landscape.h"
#include "Tank/tank.h"
#include "Shell/smallShell.h"
#include "Shell/bigShell.h"
#include "Explosion/explosionZone.h"

///Class presents the map in a widget
class Map : public QGraphicsView
{
    Q_OBJECT
public:
    ///Enumerator for commands of tank actions
    enum Command
    {
        left,
        right,
        up,
        down,
        fight,
        changeGun
    };
    ///Constructor creates landscape and two tanks: user and enemy
    Map(QWidget * parent = 0);
    ~Map();
    ///Method allows to make the step
    void makeFirst();

signals:
    ///Signal means that user has changed tank's location, or gun's angle, or gun type
    void userChanged(Command command);
    ///Signal means that one tank has won other
    void gameIsOver();

protected:
    ///Method interacts with user by keyboard and user tank
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    ///Slot updates enemy's parameters, such as location, gun's type, gun's angle
    void updateEnemy(Command command);

private:
    ///Enumerator for current shell type
    enum ShellType
    {
        smallShell,
        bigShell
    };
    ///Has ownership
    QGraphicsScene *mScene;
    ///Has ownership
    Landscape *mLandscape;
    ///Has ownership
    Tank *mUserTank;
    ///Has ownership
    Tank *mEnemyTank;
    ///It can be only enemyTank or userTank, so it need not deletion
    Tank *mDefender;
    ///Has current ownership
    Shell *mShell;
    ShellType mShellType;
    ///Has ownership
    QTimer *mTimer;
    bool fShellIsPushed;
    bool fUserStep;
    ///Method pushes a shell from the user tank and defines a defender
    void userFight();
    ///Method pushes a shell from the attacking tank
    void pushShell(Tank *attackingTank);
    ///Method delays explosion deleting
    void delayExplosionDeletion();
    ///Method deletes shell and nulls shell's parameters
    void deleteShell();
    ///Method checks is item on the scene
    bool isOnScene(QGraphicsItem *item) const;
    ///Method create an explosion in the specified place
    void makeExplosion(const QPointF &point);

private slots:
    ///Method checks collidings shell with tanks
    void checkShell();
};
