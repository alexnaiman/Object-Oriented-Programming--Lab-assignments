/********************************************************************************
** Form generated from reading UI file 'Lab89GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB89GUI_H
#define UI_LAB89GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab89GUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab89GUIClass)
    {
        if (Lab89GUIClass->objectName().isEmpty())
            Lab89GUIClass->setObjectName(QStringLiteral("Lab89GUIClass"));
        Lab89GUIClass->resize(600, 400);
        menuBar = new QMenuBar(Lab89GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Lab89GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab89GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lab89GUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab89GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Lab89GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab89GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lab89GUIClass->setStatusBar(statusBar);

        retranslateUi(Lab89GUIClass);

        QMetaObject::connectSlotsByName(Lab89GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab89GUIClass)
    {
        Lab89GUIClass->setWindowTitle(QApplication::translate("Lab89GUIClass", "Lab89GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab89GUIClass: public Ui_Lab89GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB89GUI_H
