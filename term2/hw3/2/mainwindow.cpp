#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <climits>
#include <Qstring>

#include "calculator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->firstOperand, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, MainWindow::calc);
    connect(ui->secondOperand, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, MainWindow::calc);
    connect(ui->comboBox, QComboBox::currentTextChanged, this, MainWindow::calc);
    calc();
}

void MainWindow::calc()
{
    QString operation = ui->comboBox->currentText();
    double firstOperand = ui->firstOperand->value();
    double secondOperand = ui->secondOperand->value();
    const double init = -1e12;
    double result = init;
    char* oper = operation.toLatin1().data();
    switch (oper[0])
    {
    case '+':
    {
        result = firstOperand + secondOperand;
        break;
    }
    case '-':
    {
        result = firstOperand - secondOperand;
        break;
    }
    case '*':
    {
        result = firstOperand * secondOperand;
        break;
    }
    case '/':
    {
        if (secondOperand == 0.0)
        {
            ui->lineEdit->setText("Error");
            return;
        }
        result = firstOperand / secondOperand;
        break;
    }
    }
    ui->lineEdit->setText(QString::number(result));
}

MainWindow::~MainWindow()
{
    delete ui;
}
