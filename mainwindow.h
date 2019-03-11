#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QSqlQuery>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void DatabaseChanged();

private:
    QSqlDatabase *m_db;
    Ui::MainWindow *ui;
    QStandardItemModel *OurModel;
    void ViewStudents();

};

#endif // MAINWINDOW_H
