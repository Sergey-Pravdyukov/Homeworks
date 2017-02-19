#include "eventhandler.h"

EventHandler::EventHandler(const int numberOfButtons):
    numberOfButtons(numberOfButtons){}

void EventHandler::handleEvent(const MyButton *button)
{
    static MyButton *prevButton = button;
    static bool isTimeToCheck = false;
    static int numberOfDisabledButtons = 0;

    if (!isTimeToCheck)
    {
        prevButton = button;
        isTimeToCheck = true;
        return;
    }

    if (button->text() == prevButton->text())
    {
        numberOfDisabledButtons += 2;

        if (numberOfDisabledButtons == numberOfButtons)
            exit(0);
    }
    else
    {
        prevButton->setEnabled(true);
        button->setEnabled(true);
        prevButton->setText("");
        button->setText("");
    }

    prevButton = button;
    isTimeToCheck = false;
}
