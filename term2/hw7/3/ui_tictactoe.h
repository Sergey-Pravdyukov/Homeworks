/********************************************************************************
** Form generated from reading UI file 'tictactoe.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICTACTOE_H
#define UI_TICTACTOE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicTacToe
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TicTacToe)
    {
        if (TicTacToe->objectName().isEmpty())
            TicTacToe->setObjectName(QStringLiteral("TicTacToe"));
        TicTacToe->resize(600, 690);
        TicTacToe->setMinimumSize(QSize(400, 490));
        TicTacToe->setMaximumSize(QSize(900, 1035));
        centralWidget = new QWidget(TicTacToe);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setFont(font);
        spinBox->setMinimum(9);
        spinBox->setMaximum(31);

        horizontalLayout->addWidget(spinBox);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        TicTacToe->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TicTacToe);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 34));
        TicTacToe->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TicTacToe);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TicTacToe->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TicTacToe);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TicTacToe->setStatusBar(statusBar);

        retranslateUi(TicTacToe);

        QMetaObject::connectSlotsByName(TicTacToe);
    } // setupUi

    void retranslateUi(QMainWindow *TicTacToe)
    {
        TicTacToe->setWindowTitle(QApplication::translate("TicTacToe", "TicTacToe", 0));
        label->setText(QApplication::translate("TicTacToe", "Play on the big field:", 0));
        pushButton->setText(QApplication::translate("TicTacToe", "Select size", 0));
    } // retranslateUi

};

namespace Ui {
    class TicTacToe: public Ui_TicTacToe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICTACTOE_H
