#pragma once

#include "mybutton.h"

//class MyButton;

class EventHandler : public QObject
{
public:
    EventHandler(const int numberOfButtons);
    ~EventHandler() {}

public slots:
    void handleEvent(const MyButton *button);

private:
    const int numberOfButtons;
};
