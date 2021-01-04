#ifndef THE_BAND_H
#define THE_BAND_H
#include"bandM.h"
#include <QDialog>
#include "singerM.h"
#include "cameraman.h"
#include "traiteur.h"
#include "clothes.h"
#include "compte.h"
#include "personnel.h"
#include "salle.h"
#include "theme.h"
#include "vip_wedding.h"
#include "voiture.h"
#include "reservation.h"
#include "honeymoon.h"
#include "location_voiture.h"

namespace Ui {
class the_band;
}

class the_band : public QDialog
{
    Q_OBJECT

public:
    explicit the_band(QWidget *parent = nullptr);
    ~the_band();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_sortID_clicked();

    void on_pushButton_sortname_clicked();

    void on_pushButton_sorttheme_clicked();

    void on_pushButton_themesearch_clicked();

    void on_pushButton_namesearch_clicked();

    void on_pushButton_adresssearch_clicked();

    void on_pushButton_pront_clicked();

    void on_pushButton_stat_clicked();

    void on_addcar_clicked();

    void on_searchpricecar_clicked();

    void on_searchcolorcar_clicked();

    void on_searchmatriculecar_clicked();

    void on_sortprice_car_clicked();

    void on_sortmatricule_car_clicked();

    void on_sortgreycardcar_clicked();

    void on_pdfcar_clicked();

    void on_printcar_clicked();

    void on_carmodifier_clicked();

    void on_cardelete_id_clicked();

    void on_addsalla_clicked();

    void on_searchsalle1_price_clicked();

    void on_searchsalla2_adress_clicked();

    void on_searchsalla3_capacity_clicked();

    void on_sortadress_salle_clicked();

    void on_sortID_salle_clicked();

    void on_sortcapacity_salle_clicked();

    void on_pdf_salle_clicked();

    void on_print_salle_clicked();

    void on_modifsalle_clicked();

    void on_delete_salle_clicked();

    void on_add_theme_clicked();

    void on_searchprice_theme_2_clicked();

    void on_searchid_theme_2_clicked();

    void on_searchconcept_theme_2_clicked();

    void on_sortid_theme_clicked();

    void on_sortprice_theme_clicked();

    void on_sortconcept_theme_clicked();

    void on_pdf_theme_clicked();

    void on_print_theme_clicked();

    void on_modifier_theme_clicked();

    void on_pushButton_43_clicked();

    void on_add_vip_clicked();

    void on_searchlocation_vip_2_clicked();

    void on_searchname_vip_2_clicked();

    void on_searchprice_vip_2_clicked();

    void on_sortid_vip_clicked();

    void on_sortprice_vip_clicked();

    void on_sortname_vip_clicked();

    void on_pdf_vip_clicked();

    void on_print_vip_clicked();

    void on_vip_modif_clicked();

    void on_vip_delete_clicked();

    void on_add_client_clicked();

    void on_searchcin_client_2_clicked();

    void on_searchname_client_2_clicked();

    void on_sortcin_client_clicked();

    void on_sortname_client_clicked();

    void on_sortsurname_client_clicked();

    void on_pdfclient_clicked();

    void on_print_client_clicked();

    void on_modif_client_clicked();

    void on_delete_client_clicked();

    void on_add_clothes_clicked();

    void on_searchbtype_clothes_clicked();

    void on_searchbprice_clothes_clicked();

    void on_sortid_clothes_clicked();

    void on_sorttype_clothes_clicked();

    void on_sortprice_clothes_clicked();

    void on_pdf_clothes_clicked();

    void on_print_clothes_clicked();

    void on_modify_clothes_clicked();

    void on_clothes_delete_clicked();

    void on_pushButton_clicked();

    void on_pushButton_45_clicked();

    void on_modifyreservation_clicked();

    void on_search_id_reservation_clicked();

    void on_sortID_reservation_clicked();

    void on_print_clicked();

    void on_pdf_clicked();

    void on_pdfsinger_clicked();

    void on_pdfband_clicked();

    void on_pushButton_46_clicked();

    void on_addhoneymoon_clicked();

    void on_pushButton_38_clicked();

    void on_pushButton_37_clicked();

    void on_pushButton_39_clicked();

    void on_pricehoneymoon_sort_clicked();

    void on_sort_hotel_clicked();

    void on_sort_idhoneymoon_clicked();

    void on_print_2_clicked();

    void on_pdf_2_clicked();

    void on_update_honeymoon_clicked();

    void on_delete_honeymoon_clicked();

    void on_add_location_voiture_clicked();

    void on_delete_carreserv_clicked();

    void on_pdfloc_clicked();

    void on_printloc_clicked();

    void on_pushButton_34_clicked();

private:
    Ui::the_band *ui;
    boudinar tmpboudinar;
     drake tmpdrake;
     cameraman tmpcameraman;
     traiteur tmptraiteur;
     clothes tmpclothes;
     Salles tmpsalles;
     compte tmpcompte;
     personnel tmppersonnel;
     theme tmptheme;
     voiture tmpvoiture;
     vip_wedding tmpvip;
     honeymoon tmphoneymoon;


     boudinar c1;
     drake c2;
     reservation cc;
     reservation tmpreservation;
     location_voiture tmploc;
     location_voiture l;


};

#endif // THE_BAND_H
