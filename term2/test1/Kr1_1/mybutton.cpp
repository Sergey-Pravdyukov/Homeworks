#include "mybutton.h"

MyButton::MyButton(const QString &value):
    value(value)
{}

void MyButton::setTextVisible()
{
    setText(value);
    setEnabled(false);
}
/*
void MyButton::buttonClicked()
{
    emit myClicked(this);
}
*/
