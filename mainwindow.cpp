#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    OurModel=new QStandardItemModel(1,9,this);

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
    ViewStudents();

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ViewStudents()
{
    QSqlDatabase m_db;
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("C:/Users/domin/Desktop/SchoolManager/database.db");
    if(m_db.open())
        qDebug() << "baza danych otworzyla sie";
    else
        qDebug() << "baza danych nie otworzyla sie";

    QSqlQuery vSelectQuery("SELECT id, name, surname, nr_group, mean, id_classes FROM students ORDER BY id;");
    int i=0;
    vSelectQuery.first();

    do
    {
        QString id = vSelectQuery.value(0).toString();
        QString name = vSelectQuery.value(1).toString();
        QString surname = vSelectQuery.value(2).toString();
        QString nr_group = vSelectQuery.value(3).toString();
        QString mean = vSelectQuery.value(4).toString();
        QString id_classes = vSelectQuery.value(5).toString();

        OurModel->setItem(i,0,new QStandardItem(id));
        OurModel->setItem(i,1,new QStandardItem(name));
        OurModel->setItem(i,2,new QStandardItem(surname));
        OurModel->setItem(i,3,new QStandardItem(nr_group));
        OurModel->setItem(i,4,new QStandardItem(mean));
        OurModel->setItem(i,5,new QStandardItem(id_classes));
       // OurModel->setItem(i,6,new QStandardItem("12.06.2019"));
       // OurModel->setItem(i,7,new QStandardItem("15"));
       // OurModel->setItem(i,8,new QStandardItem("Koszykówka"));
        i ++;
    } while (vSelectQuery.next());

    ui->tableView->setModel(OurModel);
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
