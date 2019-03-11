/********************************************************************************
** Form generated from reading UI file 'AddStudentDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTDIALOG_H
#define UI_ADDSTUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddStudentDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *Imie;
    QTextEdit *Nazwisko;
    QTextEdit *NrGrupy;
    QTextEdit *Srednia;
    QTextEdit *IdClasses;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *AddStudentDialog)
    {
        if (AddStudentDialog->objectName().isEmpty())
            AddStudentDialog->setObjectName(QStringLiteral("AddStudentDialog"));
        AddStudentDialog->resize(609, 130);
        buttonBox = new QDialogButtonBox(AddStudentDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(420, 90, 161, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        Imie = new QTextEdit(AddStudentDialog);
        Imie->setObjectName(QStringLiteral("Imie"));
        Imie->setGeometry(QRect(10, 20, 104, 31));
        Nazwisko = new QTextEdit(AddStudentDialog);
        Nazwisko->setObjectName(QStringLiteral("Nazwisko"));
        Nazwisko->setGeometry(QRect(130, 20, 104, 31));
        NrGrupy = new QTextEdit(AddStudentDialog);
        NrGrupy->setObjectName(QStringLiteral("NrGrupy"));
        NrGrupy->setGeometry(QRect(250, 20, 104, 31));
        Srednia = new QTextEdit(AddStudentDialog);
        Srednia->setObjectName(QStringLiteral("Srednia"));
        Srednia->setGeometry(QRect(370, 20, 104, 31));
        IdClasses = new QTextEdit(AddStudentDialog);
        IdClasses->setObjectName(QStringLiteral("IdClasses"));
        IdClasses->setGeometry(QRect(490, 20, 104, 31));
        label = new QLabel(AddStudentDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 21, 16));
        label_2 = new QLabel(AddStudentDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 60, 47, 13));
        label_3 = new QLabel(AddStudentDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(280, 60, 47, 13));
        label_4 = new QLabel(AddStudentDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 60, 47, 13));
        label_5 = new QLabel(AddStudentDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(520, 60, 47, 13));
        pushButton = new QPushButton(AddStudentDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 80, 75, 31));

        retranslateUi(AddStudentDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddStudentDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddStudentDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddStudentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStudentDialog)
    {
        AddStudentDialog->setWindowTitle(QApplication::translate("AddStudentDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("AddStudentDialog", "Imie", nullptr));
        label_2->setText(QApplication::translate("AddStudentDialog", "Nazwisko", nullptr));
        label_3->setText(QApplication::translate("AddStudentDialog", "Nr Grupy", nullptr));
        label_4->setText(QApplication::translate("AddStudentDialog", "\305\232rednia", nullptr));
        label_5->setText(QApplication::translate("AddStudentDialog", "ID Klasy", nullptr));
        pushButton->setText(QApplication::translate("AddStudentDialog", "Dodaj Ucznia", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudentDialog: public Ui_AddStudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTDIALOG_H
