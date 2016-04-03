#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSignalMapper>

#include "calculator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void clicked(const QString &text);
    void calculate();
    void clear();

private:
    Ui::MainWindow *ui;
    QLineEdit *lineEdit = new QLineEdit();
    QSignalMapper *signalMapper = new QSignalMapper();
    QPushButton *pushButton = new QPushButton();
    Calculator *calculator = new Calculator();
};

