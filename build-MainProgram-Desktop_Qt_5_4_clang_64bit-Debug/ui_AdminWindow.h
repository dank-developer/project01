/********************************************************************************
** Form generated from reading UI file 'AdminWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QAction *actionHelp;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *welcome_label;
    QLabel *user_name_label;
    QVBoxLayout *verticalLayout;
    QPushButton *view_activated_customers;
    QPushButton *back_button;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *mainMenu;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(549, 329);
        actionHelp = new QAction(AdminWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        centralWidget = new QWidget(AdminWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 60, 491, 150));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        welcome_label = new QLabel(layoutWidget);
        welcome_label->setObjectName(QStringLiteral("welcome_label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setBold(true);
        font.setWeight(75);
        welcome_label->setFont(font);

        verticalLayout_2->addWidget(welcome_label);

        user_name_label = new QLabel(layoutWidget);
        user_name_label->setObjectName(QStringLiteral("user_name_label"));
        user_name_label->setFont(font);

        verticalLayout_2->addWidget(user_name_label);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        view_activated_customers = new QPushButton(layoutWidget);
        view_activated_customers->setObjectName(QStringLiteral("view_activated_customers"));

        verticalLayout->addWidget(view_activated_customers);

        back_button = new QPushButton(layoutWidget);
        back_button->setObjectName(QStringLiteral("back_button"));

        verticalLayout->addWidget(back_button);


        verticalLayout_2->addLayout(verticalLayout);

        AdminWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(AdminWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AdminWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdminWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AdminWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(AdminWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 549, 22));
        mainMenu = new QMenu(menuBar);
        mainMenu->setObjectName(QStringLiteral("mainMenu"));
        AdminWindow->setMenuBar(menuBar);

        menuBar->addAction(mainMenu->menuAction());
        mainMenu->addAction(actionHelp);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "MainWindow", 0));
        actionHelp->setText(QApplication::translate("AdminWindow", "Help", 0));
        welcome_label->setText(QApplication::translate("AdminWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">Welcome, </span></p></body></html>", 0));
        user_name_label->setText(QApplication::translate("AdminWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">UserName</span></p></body></html>", 0));
        view_activated_customers->setText(QApplication::translate("AdminWindow", "View Customers", 0));
        back_button->setText(QApplication::translate("AdminWindow", "Back ", 0));
        mainMenu->setTitle(QApplication::translate("AdminWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
