#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>
#include <QSignalMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    const int sizeOfMatrix = 2;
    const int counterInit = 0;

    QPushButton *pushButton = new QPushButton();
    QSignalMapper *signalMapper = new QSignalMapper();
    QString array[2][2];
    int counterOfZeroes = counterInit;
    int counterOfUnits = counterInit;
private slots:
    void a(QPushButton *pushButton, const QString &string);
};

