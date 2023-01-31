/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *label;
    QPushButton *programStart;
    QPushButton *configure;
    QPushButton *storeConfig;
    QPushButton *armTheSystem;
    QPushButton *doorOpened;
    QPushButton *userGaveCorrectPin;
    QPushButton *userGaveWrongPin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(796, 556);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLineEdit(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(190, 60, 441, 61));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        programStart = new QPushButton(centralwidget);
        programStart->setObjectName(QString::fromUtf8("programStart"));
        programStart->setGeometry(QRect(340, 130, 131, 24));
        configure = new QPushButton(centralwidget);
        configure->setObjectName(QString::fromUtf8("configure"));
        configure->setGeometry(QRect(340, 170, 131, 24));
        storeConfig = new QPushButton(centralwidget);
        storeConfig->setObjectName(QString::fromUtf8("storeConfig"));
        storeConfig->setGeometry(QRect(340, 210, 131, 24));
        armTheSystem = new QPushButton(centralwidget);
        armTheSystem->setObjectName(QString::fromUtf8("armTheSystem"));
        armTheSystem->setGeometry(QRect(340, 250, 131, 24));
        doorOpened = new QPushButton(centralwidget);
        doorOpened->setObjectName(QString::fromUtf8("doorOpened"));
        doorOpened->setGeometry(QRect(340, 290, 131, 24));
        userGaveCorrectPin = new QPushButton(centralwidget);
        userGaveCorrectPin->setObjectName(QString::fromUtf8("userGaveCorrectPin"));
        userGaveCorrectPin->setGeometry(QRect(340, 330, 131, 24));
        userGaveWrongPin = new QPushButton(centralwidget);
        userGaveWrongPin->setObjectName(QString::fromUtf8("userGaveWrongPin"));
        userGaveWrongPin->setGeometry(QRect(340, 370, 131, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 796, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "             Entry to ARMED state!", nullptr));
        programStart->setText(QCoreApplication::translate("MainWindow", "programStart", nullptr));
        configure->setText(QCoreApplication::translate("MainWindow", "Configure", nullptr));
        storeConfig->setText(QCoreApplication::translate("MainWindow", "storeConfig", nullptr));
        armTheSystem->setText(QCoreApplication::translate("MainWindow", "armTheSystem", nullptr));
        doorOpened->setText(QCoreApplication::translate("MainWindow", "doorOpened", nullptr));
        userGaveCorrectPin->setText(QCoreApplication::translate("MainWindow", "userGaveCorrectPin", nullptr));
        userGaveWrongPin->setText(QCoreApplication::translate("MainWindow", "userGaveWrongPin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
