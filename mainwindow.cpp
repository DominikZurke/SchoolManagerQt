#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AddStudentDialog.h"

#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>


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
    OurModel->setHorizontalHeaderItem(5,new QStandardItem(QString("ID Klasa")));
    /*
    OurModel->setHorizontalHeaderItem(5,new QStandardItem(QString("Wys. stypendium")));
    OurModel->setHorizontalHeaderItem(6,new QStandardItem(QString("Data")));
    OurModel->setHorizontalHeaderItem(7,new QStandardItem(QString("Pkt.")));
    OurModel->setHorizontalHeaderItem(8,new QStandardItem(QString("Dyscypina")));
    */
    ui->tableView->setModel(OurModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    m_db = new QSqlDatabase();
    *m_db=QSqlDatabase :: addDatabase("QSQLITE");
    m_db->setDatabaseName("C:/Users/domin/Desktop/SchoolManager/database.db");
    if(m_db->open())
        qDebug() << "baza danych otworzyla sie";
    else{
        qDebug() << "baza danych nie otworzyla sie";
        qDebug() << m_db->lastError().text();
        qDebug() << QSqlDatabase::drivers();
    }
    ViewStudents();

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ViewStudents()
{
    QSqlQuery vSelectQuery("SELECT id, name, surname, nr_group, mean, id_classes FROM students ORDER BY id;");
    int i=0;
    vSelectQuery.first();
    delete OurModel;
    OurModel=new QStandardItemModel(1,9,this);
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
        i ++;
    } while (vSelectQuery.next());

    ui->tableView->setModel(OurModel);
}

void MainWindow::on_pushButton_clicked()
{

    AddStudentDialog aDialog;
    QObject::connect(&aDialog, SIGNAL(DatabaseChanged()),
                                     this, SLOT(DatabaseChanged()));
    aDialog.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    QModelIndexList select = ui->tableView->selectionModel()->selectedRows();
    if (select.count() == 1)
    {

        qDebug()<<select.at(0).row();
        QStandardItem *item = OurModel->itemFromIndex(select.at(0));

        qDebug()<<item->data(2);


        QSqlQuery vDeleteQuery;
        QString id = item->data(2).toString();
        vDeleteQuery.prepare("DELETE FROM students WHERE id = :id;"  );
        vDeleteQuery.bindValue(":id", id);
       // qDebug()<<vDeleteQuery
        if(vDeleteQuery.exec())
             ViewStudents();
    }

}

void MainWindow::DatabaseChanged()
{
    ViewStudents();
}
