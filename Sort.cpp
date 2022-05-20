#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "Sort.h"

void MainWindow::Sort(QString stolb, QList<Region>* list, double* rez)
{
    for(int i=0;i<list->size();i++){
        if (stolb.toStdString()=="3")
            sort_list.append(list->at(i)._npg);
        else if (stolb.toStdString()=="4")
            sort_list.append(list->at(i)._birth_rate);
        else if (stolb.toStdString()=="5")
            sort_list.append(list->at(i)._death_rate);
        else if (stolb.toStdString()=="6")
            sort_list.append(list->at(i)._gdw);
        else if (stolb.toStdString()=="7")
            sort_list.append(list->at(i)._urbanization);
        else
            QMessageBox::critical(this, "информация","введён не правельный столбец");
    }
    double median;
    sort(sort_list.begin(),sort_list.end());
    double min = sort_list.at(0);
    double max = sort_list.at(sort_list.size()-1);
    if (sort_list.size()%2 == 1)
        median = sort_list.at(sort_list.size()/2);
    else
        median = (sort_list.at(sort_list.size() / 2)+ sort_list.at((sort_list.size() / 2)-1))/2;
    rez[0]=min;
    rez[1]=max;
    rez[2]=median;
}
