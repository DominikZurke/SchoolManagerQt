#include "AddStudentDialog.h"
#include "ui_AddStudentDialog.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractButton>

AddStudentDialog::AddStudentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentDialog)
{
    ui->setupUi(this);
}

AddStudentDialog::~AddStudentDialog()
{
    delete ui;
}

void AddStudentDialog::on_pushButton_clicked()
{


}

void AddStudentDialog::on_buttonBox_clicked(QAbstractButton *button)
{

    QString Name=ui->Imie->toPlainText();
    ui->Imie->setPlainText("");
    QString Surname=ui->Nazwisko->toPlainText();
    ui->Nazwisko->setPlainText("");
    QString NrGroup=ui->NrGrupy->toPlainText();
    ui->NrGrupy->setPlainText("");
    QString Mean=ui->Srednia->toPlainText();
    ui->Srednia->setPlainText("");
    QString IdClasses=ui->IdClasses->toPlainText();
    ui->IdClasses->setPlainText("");

    if (Name.isEmpty() || Surname.isEmpty() )
    {
        return ;
    }

    Name=Name.toLower();
    Name.replace(0,1,Name.at(0).toUpper());
    Surname=Surname.toLower();
    Surname.replace(0,1,Surname.at(0).toUpper());

    QSqlQuery vInsertQuery;
    vInsertQuery.prepare("INSERT INTO students ( name, surname, nr_group, mean, id_classes)"
                            "VALUES ( :name, :surname, :nr_group, :mean, :id_classes);");

    qDebug()<<Name<<" "<<Surname<<" "<<NrGroup<<" "<<Mean<<" "<<IdClasses;
    vInsertQuery.bindValue(":name" , Name);
    vInsertQuery.bindValue(":surname" , Surname);
    vInsertQuery.bindValue(":nr_group" , NrGroup);
    vInsertQuery.bindValue(":mean" , Mean);
    vInsertQuery.bindValue(":id_classes" , IdClasses);

    if(vInsertQuery.exec())
         emit DatabaseChanged();
}
