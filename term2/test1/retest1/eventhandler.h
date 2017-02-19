#pragma once

#include "mybutton.h"

class MyButton;

class EventHandler : public QObject
{
public:
    EventHandler(const int numberOfButtons);
    ~EventHandler() {}

public slots:
    void handleEvent(MyButton * const button);

private:
    const int numberOfButtons;
};
