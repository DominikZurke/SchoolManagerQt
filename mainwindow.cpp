#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OurModel=new QStandardItemModel(2,9,this); //5 zamieniłem na 9
    OurModel->setItem(0,0,new QStandardItem("1"));
    OurModel->setItem(0,1,new QStandardItem("Ala"));
    OurModel->setItem(0,2,new QStandardItem("Nowak"));
    OurModel->setItem(0,3,new QStandardItem("1"));
    OurModel->setItem(0,4,new QStandardItem("3,65"));
    OurModel->setItem(0,5,new QStandardItem("200"));
    OurModel->setItem(0,6,new QStandardItem("12.06.2019"));
    OurModel->setItem(0,7,new QStandardItem("15"));
    OurModel->setItem(0,8,new QStandardItem("Koszykówka"));

    OurModel->setItem(1,0,new QStandardItem("2"));
    OurModel->setItem(1,1,new QStandardItem("Ola"));
    OurModel->setItem(1,2,new QStandardItem("Kowalska"));
    OurModel->setItem(1,3,new QStandardItem("3"));
    OurModel->setItem(1,4,new QStandardItem("4,5"));
    OurModel->setItem(1,5,new QStandardItem("350"));
    OurModel->setItem(1,6,new QStandardItem("12.06.2019"));
    OurModel->setItem(1,7,new QStandardItem("30"));
    OurModel->setItem(1,8,new QStandardItem(""));


    OurModel->setHorizontalHeaderItem(0,new QStandardItem(QString("ID")));
    OurModel->setHorizontalHeaderItem(1,new QStandardItem(QString("Imię")));
    OurModel->setHorizontalHeaderItem(2,new QStandardItem(QString("Nazwisko")));
    OurModel->setHorizontalHeaderItem(3,new QStandardItem(QString("Nr grupy")));
    OurModel->setHorizontalHeaderItem(4,new QStandardItem(QString("Średnia")));
    OurModel->setHorizontalHeaderItem(5,new QStandardItem(QString("Wys. stypendium")));
    OurModel->setHorizontalHeaderItem(6,new QStandardItem(QString("Data")));
    OurModel->setHorizontalHeaderItem(7,new QStandardItem(QString("Pkt.")));
    OurModel->setHorizontalHeaderItem(8,new QStandardItem(QString("Dyscypina")));
    ui->tableView->setModel(OurModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Name=ui->Imie->toPlainText();
    ui->Imie->setPlainText("");
    QString Surname=ui->Nazwisko->toPlainText();
    ui->Nazwisko->setPlainText("");
    QString NrGroup=ui->NrGrupy->toPlainText();
    ui->NrGrupy->setPlainText("");
    QString Mean=ui->Srednia->toPlainText();
    ui->Srednia->setPlainText("");
    QString Scholarship=ui->WysStypendium->toPlainText();
    ui->WysStypendium->setPlainText("");
    QString Date=ui->Data->toPlainText();
    ui->Data->setPlainText("");
    QString Points=ui->Pkt->toPlainText();
    ui->Pkt->setPlainText("");
    QString Discipline=ui->Dyscyplina->toPlainText();
    ui->Dyscyplina->setPlainText("");

    if (Name.isEmpty() || Surname.isEmpty() )
    {
        return ;
    }

    Name=Name.toLower();
    Name.replace(0,1,Name.at(0).toUpper());
    Surname=Surname.toLower();
    Surname.replace(0,1,Surname.at(0).toUpper());

    int LiczbaW=OurModel->rowCount();
    LiczbaW++;
    OurModel->setRowCount(LiczbaW);

    OurModel->setItem(LiczbaW-1,0,new QStandardItem(QString::number(LiczbaW)));
    OurModel->setItem(LiczbaW-1,1,new QStandardItem(Name));
    OurModel->setItem(LiczbaW-1,2,new QStandardItem(Surname));
    OurModel->setItem(LiczbaW-1,3,new QStandardItem(NrGroup));
    OurModel->setItem(LiczbaW-1,4,new QStandardItem(Mean));
    OurModel->setItem(LiczbaW-1,5,new QStandardItem(Scholarship));
    OurModel->setItem(LiczbaW-1,6,new QStandardItem(Date));
    OurModel->setItem(LiczbaW-1,7,new QStandardItem(Points));
    OurModel->setItem(LiczbaW-1,8,new QStandardItem(Discipline));


}
