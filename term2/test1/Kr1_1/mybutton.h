#pragma once

#include <QPushButton>

#include "eventhandler.h"

//class EventHandler;

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    MyButton(const QString &value);
    ~MyButton() {}

public slots:
    void setTextVisible();
    /*void buttonClicked();

signals:
    void myClicked(MyButton*);*/

private:
    const QString value;
};
