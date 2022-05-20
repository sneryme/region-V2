#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <string>
#include "Region.h"
#include <fstream>
#include <string>

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Btn_file_clicked();

    void on_Btn_stolb_clicked();

private:
    QList<Region>* list;
    QList<double> sort_list;
    Ui::MainWindow *ui;

    int Read_file(QString file_path, QString region, QList<Region>* list);
    int Create_table(QList<Region>* list);
    void Sort(QString stolb, QList<Region>* list,double* rez);
    void enter(struct Vibor,int choice);
};
#endif // MAINWINDOW_H
