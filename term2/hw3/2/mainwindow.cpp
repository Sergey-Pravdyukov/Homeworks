#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    const QString operation = ui->comboBox->currentText();
    const double firstOperand = ui->firstOperand->value();
    const double secondOperand = ui->secondOperand->value();
    double result = Calculator::calculate(firstOperand, secondOperand, operation);
    (result == error) ? ui->lineEdit->setText("ERROR!")
                      : ui->lineEdit->setText(QString::number(result));
}

MainWindow::~MainWindow()
{
    delete ui;
}
