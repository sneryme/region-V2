#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Create_table.h"
#include "sort.h"
#include "variant.h"
#include "Reade_file.h"

Region::Region(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization){
    _year = year;
    _region = region;
    _npg = npg;
    _birth_rate = birth_rate;
    _death_rate = death_rate;
    _gdw = gdw;
    _urbanization = urbanization;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    list = new QList<Region>;
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete list;
    delete ui;
}


void MainWindow::on_Btn_file_clicked()
{
    QString file_path;
    ui->table_region->setRowCount(0);
    list->clear();
    if (ui->line_region->text() != ""){
        if (ui->line_path->text()=="")
            file_path = QFileDialog::getOpenFileName(this,tr("Открыть файл"),"C://","all files(*.*);;text file(*.txt);;table file(*.csv)");
        else
            file_path = ui->line_path->text();
        QMessageBox::information(this,tr("информация"),file_path);
        Vibor1.filePath=file_path;
        Vibor1.region=ui->line_region->text();
        Vibor1.lis=list;
        enter(Vibor1,0);
        //(check == -1) ? QMessageBox::critical(this, "информация","не удалось открыть файл"):QMessageBox::information(this, "информация","удалось открыть файл");
        (Create_table(list) == -1) ? QMessageBox::critical(this, "информация", "не удалось создать таблицу"): QMessageBox::information(this, "информация","удалось создать таблицу");
    }else
        QMessageBox::critical(this, "информация","не введён регион");
}

void MainWindow::on_Btn_stolb_clicked()
{
    ui->label_rez->setText("");
    QString stolb=ui->line_stolb->text();
    double* rez = (double*)calloc(sizeof(double),3);

    Sort(stolb,list,rez);
    ui->label_rez->setText(QString("min: ") + QString::number(rez[0])+
                            QString(" max: ") + QString::number(rez[1])+
                            QString(" mediana: ") + QString::number(rez[2])
                            );
    free(rez);
}




