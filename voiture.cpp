#include "voiture.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QSqlQueryModel>
#include<QSqlQuery>
voiture::voiture()
{  model=matricule=couleur="" ;
     carte_grise=prixlocation=0;

}

 voiture::voiture(int carte_grise,QString matricule,QString model ,QString couleur,int prixlocation)
 {

this->carte_grise=carte_grise; this->matricule=matricule; this->model=model;this->couleur=couleur;this->prixlocation=prixlocation;

 }
   int voiture:: get_cartegrise(){return carte_grise;}
    QString  voiture::getmodel(){return model;}
    QString  voiture::get_couleur(){return couleur;}
    QString  voiture::get_matricule(){return matricule;}
     int voiture:: getprixlocation(){return prixlocation;}

     void voiture:: set_cartegrise(int carte_grise ){this->carte_grise=carte_grise;}
      void voiture:: setmodel(QString model ){this->model=model;}
      void voiture:: set_couleur(QString couleur ){this->couleur=couleur;}
      void voiture:: set_matricule(QString matricule ){this->matricule=matricule;}

      void voiture:: setprixlocation(int prixlocation){this->prixlocation=prixlocation;}

      bool voiture:: ajoutervo()
      {
           QSqlQuery query;
           QString id_string= QString::number(carte_grise);
           QString location= QString::number(prixlocation);

                  query.prepare("INSERT INTO VOITURE (NUM_CARTE_GRISE, MATRICULE,MARQUE_VOITURE,COULEUR_VOITURE,PRIX_LOCATION) "
                                "VALUES (:num, :mat, :mar, :cou,:price)");
                  query.bindValue(":num",id_string);
                  query.bindValue(":mat", matricule);
                  query.bindValue(":mar", model);
                  query.bindValue(":cou", couleur);

                  query.bindValue(":price", location);

                 return query.exec();}

      bool voiture::supprimervo(int carte_grise)
      {
          QSqlQuery query;
          QString res= QString::number(carte_grise);
          query.prepare(" Delete from voiture where NUM_CARTE_GRISE=:id");
          query.bindValue(":id", res);

              return query.exec();}
      QSqlQueryModel* voiture::affichervo()
      {
        QSqlQueryModel* model=new QSqlQueryModel();


         model->setQuery("SELECT* FROM voiture");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_carte_grise"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_location"));



        return  model;
      }
      bool voiture::modifiervo()

      {

              QSqlQuery query;
              QString id_string= QString::number(carte_grise);
              QString location= QString::number(prixlocation);

             query.prepare(" UPDATE voiture SET NUM_CARTE_GRISE=:num, MATRICULE=:mat,MARQUE_VOITURE=:mar,COULEUR_VOITURE=:cl,PRIX_LOCATION=:prix  where NUM_CARTE_GRISE=:num");
             query.bindValue(":num",id_string);
             query.bindValue(":mat", matricule);
             query.bindValue(":mar", model);
             query.bindValue(":cl", couleur);

             query.bindValue(":prix", location);


                    return query.exec();


      }
      QSqlQueryModel * voiture::cherchercouleur(QString couleur)
       {

          {QSqlQueryModel *model = new QSqlQueryModel;
              model->setQuery("SELECT * FROM voiture WHERE COULEUR_VOITURE ='"+couleur+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_carte_grise"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_location"));
              return model ;
          }

       }


      QSqlQueryModel * voiture::chercherprixlocation(int prixlocation)
       {

          {QSqlQueryModel *model = new QSqlQueryModel;
              QString location= QString::number(prixlocation);
              model->setQuery("SELECT * FROM voiture WHERE PRIX_LOCATION = '"+location+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_carte_grise"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_location"));
              return model ;
          }

       }
      QSqlQueryModel * voiture::cherchermodel(QString matricule)
       {

          {QSqlQueryModel *model = new QSqlQueryModel;

              model->setQuery("SELECT * FROM voiture WHERE MATRICULE ='"+matricule+"'");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_carte_grise"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_location"));
              return model ;
          }

       }

      QSqlQueryModel* voiture:: triermatricule()
      {

          QSqlQueryModel * model=new QSqlQueryModel();
          model->setQuery("select * from voiture order by MATRICULE ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_carte_grise"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_location"));

          return model;
      }

      QSqlQueryModel* voiture:: triercarte_grise()
      {

          QSqlQueryModel * model=new QSqlQueryModel();
          model->setQuery("select * from voiture order by NUM_CARTE_GRISE ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_carte_grise"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_location"));
          return model;
      }
      QSqlQueryModel* voiture:: trierprixvoiture()
      {

          QSqlQueryModel * model=new QSqlQueryModel();
          model->setQuery("select * from voiture order by PRIX_LOCATION  ");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("numero_carte_grise"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("matricule"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("marque"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("couleur"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix_location"));
          return model;
      }


