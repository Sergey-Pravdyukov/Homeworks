#include <stdlib.h>
#include <ctime>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton.h"
#include "eventhandler.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    int size = 4;
    int numberOfButtons = size * size;

    bool numbers[numberOfButtons];
    int indexes[numberOfButtons];

    for(int i = 0; i < numberOfButtons; i++)
        numbers[i] = false;

    for (int i = 0; i < numberOfButtons / 2; i++)
    {
        indexes[i] = rand() % numberOfButtons;

        while(numbers[indexes[i]])
            indexes[i] = rand() % numberOfButtons;

        numbers[indexes[i]] = true;
    }

    MyButton *button = nullptr;
    EventHandler *eventHandler = new EventHandler(numberOfButtons);

    for(int i = 0; i < numberOfButtons; i++)
    {
        button = new MyButton(QString::number(numbers[i]));

        connect(button, SIGNAL(clicked()), button, SLOT(setTextVisible()));
        connect(button, SIGNAL(clicked()), eventHandler, &EventHandler::handleEvent);
        //connect(button, SIGNAL(clicked()), button, SLOT(buttonClicked()));
        //connect(button, &MyButton::myClicked, eventHandler, &EventHandler::handleEvent);

        ui->gridLayout->addWidget(button, i / size, i % size);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
