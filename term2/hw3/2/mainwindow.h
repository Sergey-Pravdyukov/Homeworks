#pragma once

#include <QMainWindow>
#include <climits>

#include "calculator.h"

namespace Ui {
class MainWindow;
}

/*!
 * \brief The MainWindow class that calculated value of arithmetic expression
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    /*!
     * \brief calculates binary expression
     */
    void calc();
};
