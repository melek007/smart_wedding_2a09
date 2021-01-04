#ifndef DRAKE_H
#define DRAKE_H
#include"QString"
#include <QSqlQuery>
#include <QSqlQueryModel>

class drake
{
public:
    drake();
    drake(int,QString,QString,QString,int);
       int getIDsinger();
        QString getnom();
         QString getprenom();
          QString gettypechant();
          int getprix();


          void setIDsinger(int );
          void setnom(QString );
          void setprenom(QString );
          void settypechant(QString );
          void setprix(int );
          bool ajoutersinger();
          QSqlQueryModel * affichersinger();
          bool supprimersinger(int);
          bool modifiersinger();
          QSqlQueryModel * trierIDsinger();
            QSqlQueryModel * triernomsinger();
            QSqlQueryModel * trierprixsinger();
            QSqlQueryModel * cherchersinger(QString);
            QSqlQueryModel * cherchernomsinger(QString);
            QSqlQueryModel * chercherprixsinger(int);
         int calculer(QString);

    private:
          QString typechant , nom, prenom;
          int ID,prix;
};

#endif // DRAKE_H
