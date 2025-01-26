/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionPolacz;
    QAction *actionWyjd;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *lstMessages;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lnMessage;
    QPushButton *btnSend;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(522, 413);
        actionPolacz = new QAction(MainWindow);
        actionPolacz->setObjectName("actionPolacz");
        actionWyjd = new QAction(MainWindow);
        actionWyjd->setObjectName("actionWyjd");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        lstMessages = new QListWidget(groupBox);
        lstMessages->setObjectName("lstMessages");

        verticalLayout->addWidget(lstMessages);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lnMessage = new QLineEdit(centralwidget);
        lnMessage->setObjectName("lnMessage");

        horizontalLayout->addWidget(lnMessage);

        btnSend = new QPushButton(centralwidget);
        btnSend->setObjectName("btnSend");

        horizontalLayout->addWidget(btnSend);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 522, 21));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionPolacz);
        menuOptions->addAction(actionWyjd);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Client", nullptr));
        actionPolacz->setText(QCoreApplication::translate("MainWindow", "Po\305\202\304\205cz", nullptr));
        actionWyjd->setText(QCoreApplication::translate("MainWindow", "Wyjd\305\272", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Wiadomosci", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Message", nullptr));
        btnSend->setText(QCoreApplication::translate("MainWindow", "Wyslij", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("MainWindow", "Opcje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
