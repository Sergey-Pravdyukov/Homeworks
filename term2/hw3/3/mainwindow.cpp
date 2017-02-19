#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "calculator.h"
#include "parser.h"

int getColumnForDigits(const int i)
{
    return (i - 1) % 3;
}

int getRowForDigits(const int i)
{
    return 4 - ((i - 1) / 3);
}

int getRow(const int i)
{
    return i + 2;
}

int getColumnForOperations()
{
    return 3;
}

int getColumnForOtherButtons()
{
    return 4;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->gridLayout->addWidget(lineEdit, 0, 0, 1, 5);

    const int numberOfDigits = 10;
    for (int i = 0; i < numberOfDigits; ++i)
    {
        pushButton = new QPushButton(QString::number(i));
        signalMapper->setMapping(pushButton, QString::number(i));
        connect(pushButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
        (i == 0) ? ui->gridLayout->addWidget(pushButton, 5, 0, 1, 2)
                 : ui->gridLayout->addWidget(pushButton, getRowForDigits(i), getColumnForDigits(i));
    }

    const int numberOfOperations = 5;
    const QChar operations[numberOfOperations] = {'+', '-', '*', '/', '='};
    for (int i = 0; i < numberOfOperations - 1; ++i)
    {
        pushButton = new QPushButton(operations[i]);
        signalMapper->setMapping(pushButton, operations[i]);
        connect(pushButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
        ui->gridLayout->addWidget(pushButton, getRow(i), getColumnForOperations());
    }

    pushButton = new QPushButton(operations[numberOfOperations - 1]);
    ui->gridLayout->addWidget(pushButton, 5, 2);
    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(calculate()));

    const int numberOfOtherButtons = 4;
    const QString otherButtons[numberOfOtherButtons] = {"(", ")", ".", "CE"};
    for (int i = 0; i < numberOfOtherButtons - 1; ++i)
    {
        pushButton = new QPushButton(otherButtons[i]);
        signalMapper->setMapping(pushButton, otherButtons[i]);
        connect(pushButton, SIGNAL(clicked()), signalMapper, SLOT(map()));
        ui->gridLayout->addWidget(pushButton, getRow(i), getColumnForOtherButtons());
    }

    pushButton = new QPushButton(otherButtons[numberOfOtherButtons - 1]);
    ui->gridLayout->addWidget(pushButton, getRow(numberOfOtherButtons - 1), getColumnForOtherButtons());
    connect(pushButton, SIGNAL(clicked(bool)), this, SLOT(clear()));

    connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(clicked(QString)));
}

void MainWindow::clear()
{
    lineEdit->clear();
}

void MainWindow::clicked(const QString &text)
{
    lineEdit->insert(text);
}

void MainWindow::calculate()
{
    QString displayText = lineEdit->displayText();
    QVector<QString> expression = Parser::haveParseDisplayTextToExpressions(displayText);
    lineEdit->clear();
    lineEdit->insert(QString::number(Calculator::calculate(expression)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
