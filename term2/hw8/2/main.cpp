#include "bash.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Bash window;
    window.show();

    return a.exec();
}

