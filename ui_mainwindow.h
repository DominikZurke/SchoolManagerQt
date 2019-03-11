/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTableView *tableView;
    QTextEdit *Imie;
    QTextEdit *Nazwisko;
    QTextEdit *NrGrupy;
    QTextEdit *Srednia;
    QTextEdit *Data;
    QTextEdit *WysStypendium;
    QTextEdit *Pkt;
    QTextEdit *Dyscyplina;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1115, 344);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 210, 75, 23));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(120, 20, 951, 181));
        Imie = new QTextEdit(centralWidget);
        Imie->setObjectName(QStringLiteral("Imie"));
        Imie->setGeometry(QRect(130, 220, 104, 31));
        Nazwisko = new QTextEdit(centralWidget);
        Nazwisko->setObjectName(QStringLiteral("Nazwisko"));
        Nazwisko->setGeometry(QRect(250, 220, 104, 31));
        NrGrupy = new QTextEdit(centralWidget);
        NrGrupy->setObjectName(QStringLiteral("NrGrupy"));
        NrGrupy->setGeometry(QRect(370, 220, 104, 31));
        Srednia = new QTextEdit(centralWidget);
        Srednia->setObjectName(QStringLiteral("Srednia"));
        Srednia->setGeometry(QRect(490, 220, 104, 31));
        Data = new QTextEdit(centralWidget);
        Data->setObjectName(QStringLiteral("Data"));
        Data->setGeometry(QRect(730, 220, 104, 31));
        WysStypendium = new QTextEdit(centralWidget);
        WysStypendium->setObjectName(QStringLiteral("WysStypendium"));
        WysStypendium->setGeometry(QRect(610, 220, 104, 31));
        Pkt = new QTextEdit(centralWidget);
        Pkt->setObjectName(QStringLiteral("Pkt"));
        Pkt->setGeometry(QRect(850, 220, 104, 31));
        Dyscyplina = new QTextEdit(centralWidget);
        Dyscyplina->setObjectName(QStringLiteral("Dyscyplina"));
        Dyscyplina->setGeometry(QRect(970, 220, 104, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 240, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1115, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Dodaj Ucznia", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Usu\305\204 Ucznia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
