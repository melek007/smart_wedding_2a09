#include "salle.h"
#include <QDebug>
           salle::salle()
            {
                ID_salle="";
                capacite=0;
                adresse="";
                prix=0;

            }

            salle::salle(QString ID_salle,int capacite,QString adresse,float prix)
            {
              this->ID_salle = ID_salle;
              this->capacite= capacite;
              this->adresse =adresse;
              this->prix=prix;
            }
            QString salle::get_ID_salle(){return ID_salle;}
            int salle::get_capacite(){return  capacite;}
            QString salle::get_adresse(){return adresse;}
            float salle::get_prix(){return  prix;}

            bool salle::ajouter()
            {
            QSqlQuery query;
            query.prepare("INSERT INTO salle (ID,CAPACITE,ADRESSE,PRIX) "
                                 "VALUES (:ID_salle,:capacite,:adresse,:prix)");
            query.bindValue(":ID_salle", ID_salle);
            query.bindValue(":capacite", capacite);
            query.bindValue(":adresse", adresse);
            query.bindValue(":prix", prix);

            return    query.exec();
            }
            QSqlQueryModel * salle::afficher()
            {QSqlQueryModel * model= new QSqlQueryModel();

            model->setQuery("select * from salle");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPACITE"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));

                return model;
            }
            bool salle::supprimer(QString)
            {
            QSqlQuery query;
            query.prepare("Delete from salle where ID = :ID_salle ");
            query.bindValue(":id", ID_salle);
            return    query.exec();
            }
            bool salle::modifier(QString ID_salle)
            {
                QSqlQuery query;
               QString res= QString::number(prix);
               QString rese=QString::number(capacite);
               query.prepare("UPDATE DEP SET ID=:ID_salle,CAPACITE=:capacite,ADRESSE=:adresse,PRIX=:prix WHERE ID=:ID_salle");
               query.bindValue(":ID_salle", ID_salle);
               query.bindValue(":capacite", capacite);
               query.bindValue(":adresse",adresse);
               query.bindValue(":prix", prix);

                return  query.exec();
            }
            QSqlQueryModel *salle::rechercher_salle(const QString &ID_salle)
            {
                QSqlQueryModel *model=new QSqlQueryModel();
               model->setQuery("select * from salle where(ID LIKE '"+ID_salle+"')");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("CAPACITE"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("PRIX"));
                return model;
            }


