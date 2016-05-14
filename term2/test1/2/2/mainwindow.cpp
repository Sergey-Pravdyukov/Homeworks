#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));

    QPushButton *pushButton = new QPushButton();
    const int numberOfDigit = sizeOfMatrix * sizeOfMatrix / 2;
    for (int i = 0; i < sizeOfMatrix; ++i)
        for (int j = 0; j < sizeOfMatrix; ++j)
        {
            int value = rand() % 2;
            if (value == 1 && counterOfUnits >= numberOfDigit) value = 0;
            if (value == 0 && counterOfZeroes >= numberOfDigit) value = 1;
            (value == 0) ? counterOfZeroes++ : counterOfUnits++;
            array[i][j] = QString::number(value);
            pushButton = new QPushButton();

            ui->gridLayout->addWidget(pushButton, i, j, 1, 1);
            connect(pushButton, SIGNAL(clicked()), pushButton, SLOT(setHidden(bool true)));
        }

}

void MainWindow::a(QPushButton *pushButton, const QString &string)
{
    pushButton->setText(string);
}

MainWindow::~MainWindow()
{
    delete ui;
}
