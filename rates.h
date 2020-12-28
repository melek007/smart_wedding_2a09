#ifndef RATES_H
#define RATES_H
#include <QString>

class Rates
{
    QString id;
    int nbetoiles;

    public:
    Rates();
       Rates(QString,int);
       ~Rates();

       QString getId();
       void setId(QString);
       int getnbetoiles();
       void setnbetoiles(int);


       bool ajouter();

};

#endif // RATES_H
