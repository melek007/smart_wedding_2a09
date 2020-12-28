#ifndef RATE_H
#define RATE_H
#include <QString>

class rate
{
    QString id;
    int nbetoiles;

    public:
    rate();
       rate(QString,int);
       ~rate();

       QString getId();
       void setId(QString);
       int getnbetoiles();
       void setnbetoiles(int);


       bool ajouter();


};

#endif // RATE_H
