#ifndef REGION_H
#define REGION_H
#include <QString>

struct Region{
    int _year;
    QString _region;
    double _npg;
    double _birth_rate;
    double _death_rate;
    double _gdw;
    double _urbanization;
    Region(int year, QString region,double npg,double birth_rate,double death_rate,double gdw, double urbanization);
};
#endif // REGION_H
