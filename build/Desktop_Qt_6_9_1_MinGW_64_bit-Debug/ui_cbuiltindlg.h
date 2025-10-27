/********************************************************************************
** Form generated from reading UI file 'cbuiltindlg.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBUILTINDLG_H
#define UI_CBUILTINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cbuiltindlg
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *cbuiltindlg)
    {
        if (cbuiltindlg->objectName().isEmpty())
            cbuiltindlg->setObjectName("cbuiltindlg");
        cbuiltindlg->resize(800, 600);
        centralwidget = new QWidget(cbuiltindlg);
        centralwidget->setObjectName("centralwidget");
        cbuiltindlg->setCentralWidget(centralwidget);
        menubar = new QMenuBar(cbuiltindlg);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        cbuiltindlg->setMenuBar(menubar);
        statusbar = new QStatusBar(cbuiltindlg);
        statusbar->setObjectName("statusbar");
        cbuiltindlg->setStatusBar(statusbar);

        retranslateUi(cbuiltindlg);

        QMetaObject::connectSlotsByName(cbuiltindlg);
    } // setupUi

    void retranslateUi(QMainWindow *cbuiltindlg)
    {
        cbuiltindlg->setWindowTitle(QCoreApplication::translate("cbuiltindlg", "cbuiltindlg", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cbuiltindlg: public Ui_cbuiltindlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBUILTINDLG_H
