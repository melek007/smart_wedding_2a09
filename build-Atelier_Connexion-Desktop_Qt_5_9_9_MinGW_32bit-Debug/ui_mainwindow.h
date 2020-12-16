/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *Espace_Traiteur;
    QTabWidget *tabWidget_2;
    QWidget *Ajouter_Traiteur;
    QLineEdit *le_id;
    QLineEdit *le_adresse;
    QLineEdit *le_prix;
    QLineEdit *le_nom;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *Quitter_Ajoutsalle;
    QPushButton *Ok_Ajoutsalle;
    QFrame *heart;
    QWidget *Affichr_Traiteur;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QTableView *tab_salle;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QComboBox *comboBox;
    QPushButton *imp_tr;
    QPushButton *pdf_tr;
    QWidget *Supprimer_Traiteur;
    QLabel *label_5;
    QLineEdit *le_id_supp;
    QPushButton *pb_supprimer1;
    QWidget *Modifier_Traiteur;
    QLineEdit *lineEdit_nommodifiersalle;
    QLineEdit *lineEdit_adressemodifiersalle;
    QLineEdit *lineEdit_prixmodifiersalle;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *Modifier_Modifiersalle;
    QGroupBox *groupBox;
    QLabel *label_7;
    QLineEdit *lineEdit_idmodifiersalle;
    QWidget *Espace_Cameraman;
    QTabWidget *AfficherTheme;
    QWidget *Ajouter_Cameraman;
    QLineEdit *le_id_theme;
    QLineEdit *le_nom_dec;
    QLineEdit *le_nom_theme;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *le_prix_theme;
    QLabel *label_17;
    QPushButton *Quitter_Ajouttheme;
    QPushButton *Ok_Ajouttheme;
    QLineEdit *le_adresse_dec;
    QLabel *label_18;
    QWidget *tab;
    QGroupBox *groupBox_3;
    QTableView *tab_theme;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QComboBox *comboBox_2;
    QPushButton *imp_ca;
    QPushButton *pdf_ca;
    QPushButton *pushButton_4;
    QWidget *Supprimer_Cameraman;
    QLabel *label_24;
    QLineEdit *le_supp_theme;
    QPushButton *pb_supprimertheme;
    QWidget *Modifier_Cameraman;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lineEdit_nommodifiertheme;
    QLineEdit *lineEdit_nom2modifiertheme;
    QLineEdit *lineEdit_prixmodifiertheme;
    QPushButton *Modifier_Modifiertheme;
    QPushButton *Annuler_Modifiertheme;
    QGroupBox *groupBox_4;
    QLabel *label_9;
    QLineEdit *lineEdit_idmodifiersalle_2;
    QLineEdit *lineEdit_prixmodifiertheme_2;
    QLabel *label_23;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(747, 466);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 10, 801, 411));
        tabWidget->setStyleSheet(QLatin1String("font: 75 italic 11pt \"Times New Roman\";\n"
"color: rgb(192, 137, 255);"));
        tabWidget->setTabPosition(QTabWidget::North);
        Espace_Traiteur = new QWidget();
        Espace_Traiteur->setObjectName(QStringLiteral("Espace_Traiteur"));
        tabWidget_2 = new QTabWidget(Espace_Traiteur);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 731, 381));
        tabWidget_2->setStyleSheet(QLatin1String("font: 75 italic 11pt \"Times New Roman\";\n"
"color: rgb(160, 170, 117);"));
        Ajouter_Traiteur = new QWidget();
        Ajouter_Traiteur->setObjectName(QStringLiteral("Ajouter_Traiteur"));
        le_id = new QLineEdit(Ajouter_Traiteur);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(100, 30, 141, 21));
        le_adresse = new QLineEdit(Ajouter_Traiteur);
        le_adresse->setObjectName(QStringLiteral("le_adresse"));
        le_adresse->setGeometry(QRect(100, 110, 141, 21));
        le_prix = new QLineEdit(Ajouter_Traiteur);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(100, 160, 141, 21));
        le_nom = new QLineEdit(Ajouter_Traiteur);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(100, 70, 141, 21));
        label = new QLabel(Ajouter_Traiteur);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 61, 16));
        label->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(Ajouter_Traiteur);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 70, 81, 16));
        label_2->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_3 = new QLabel(Ajouter_Traiteur);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 61, 16));
        label_3->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_4 = new QLabel(Ajouter_Traiteur);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 160, 91, 20));
        label_4->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        Quitter_Ajoutsalle = new QPushButton(Ajouter_Traiteur);
        Quitter_Ajoutsalle->setObjectName(QStringLiteral("Quitter_Ajoutsalle"));
        Quitter_Ajoutsalle->setGeometry(QRect(260, 90, 71, 23));
        Quitter_Ajoutsalle->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        Ok_Ajoutsalle = new QPushButton(Ajouter_Traiteur);
        Ok_Ajoutsalle->setObjectName(QStringLiteral("Ok_Ajoutsalle"));
        Ok_Ajoutsalle->setGeometry(QRect(260, 40, 71, 23));
        Ok_Ajoutsalle->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        heart = new QFrame(Ajouter_Traiteur);
        heart->setObjectName(QStringLiteral("heart"));
        heart->setGeometry(QRect(660, 0, 51, 41));
        heart->setStyleSheet(QStringLiteral("image: url(:/heart.png);"));
        heart->setFrameShape(QFrame::StyledPanel);
        heart->setFrameShadow(QFrame::Raised);
        tabWidget_2->addTab(Ajouter_Traiteur, QString());
        Affichr_Traiteur = new QWidget();
        Affichr_Traiteur->setObjectName(QStringLiteral("Affichr_Traiteur"));
        pushButton_2 = new QPushButton(Affichr_Traiteur);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 210, 75, 23));
        pushButton_2->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"MS Shell Dlg 2\";"));
        groupBox_2 = new QGroupBox(Affichr_Traiteur);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 621, 271));
        groupBox_2->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        tab_salle = new QTableView(groupBox_2);
        tab_salle->setObjectName(QStringLiteral("tab_salle"));
        tab_salle->setGeometry(QRect(170, 20, 421, 211));
        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 80, 113, 20));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 110, 81, 23));
        pushButton->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"MS Shell Dlg 2\";"));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(10, 140, 81, 23));
        pushButton_5->setStyleSheet(QStringLiteral("color: rgb(9, 9, 9);"));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(21, 50, 71, 22));
        imp_tr = new QPushButton(groupBox_2);
        imp_tr->setObjectName(QStringLiteral("imp_tr"));
        imp_tr->setGeometry(QRect(10, 200, 81, 23));
        pdf_tr = new QPushButton(groupBox_2);
        pdf_tr->setObjectName(QStringLiteral("pdf_tr"));
        pdf_tr->setGeometry(QRect(10, 230, 81, 23));
        tabWidget_2->addTab(Affichr_Traiteur, QString());
        Supprimer_Traiteur = new QWidget();
        Supprimer_Traiteur->setObjectName(QStringLiteral("Supprimer_Traiteur"));
        label_5 = new QLabel(Supprimer_Traiteur);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 60, 61, 16));
        label_5->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        le_id_supp = new QLineEdit(Supprimer_Traiteur);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(110, 60, 141, 21));
        pb_supprimer1 = new QPushButton(Supprimer_Traiteur);
        pb_supprimer1->setObjectName(QStringLiteral("pb_supprimer1"));
        pb_supprimer1->setGeometry(QRect(270, 70, 71, 23));
        pb_supprimer1->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        tabWidget_2->addTab(Supprimer_Traiteur, QString());
        Modifier_Traiteur = new QWidget();
        Modifier_Traiteur->setObjectName(QStringLiteral("Modifier_Traiteur"));
        lineEdit_nommodifiersalle = new QLineEdit(Modifier_Traiteur);
        lineEdit_nommodifiersalle->setObjectName(QStringLiteral("lineEdit_nommodifiersalle"));
        lineEdit_nommodifiersalle->setGeometry(QRect(220, 130, 141, 21));
        lineEdit_adressemodifiersalle = new QLineEdit(Modifier_Traiteur);
        lineEdit_adressemodifiersalle->setObjectName(QStringLiteral("lineEdit_adressemodifiersalle"));
        lineEdit_adressemodifiersalle->setGeometry(QRect(220, 170, 141, 21));
        lineEdit_prixmodifiersalle = new QLineEdit(Modifier_Traiteur);
        lineEdit_prixmodifiersalle->setObjectName(QStringLiteral("lineEdit_prixmodifiersalle"));
        lineEdit_prixmodifiersalle->setGeometry(QRect(220, 200, 141, 21));
        label_8 = new QLabel(Modifier_Traiteur);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(120, 130, 81, 16));
        label_8->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_11 = new QLabel(Modifier_Traiteur);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(130, 170, 61, 16));
        label_11->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_12 = new QLabel(Modifier_Traiteur);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(150, 200, 61, 16));
        label_12->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        Modifier_Modifiersalle = new QPushButton(Modifier_Traiteur);
        Modifier_Modifiersalle->setObjectName(QStringLiteral("Modifier_Modifiersalle"));
        Modifier_Modifiersalle->setGeometry(QRect(440, 160, 71, 23));
        Modifier_Modifiersalle->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        groupBox = new QGroupBox(Modifier_Traiteur);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 0, 341, 111));
        groupBox->setStyleSheet(QLatin1String("color: rgb(255, 85, 127);\n"
"font: italic 8pt \"MS Sans Serif\";"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 30, 61, 16));
        label_7->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_idmodifiersalle = new QLineEdit(groupBox);
        lineEdit_idmodifiersalle->setObjectName(QStringLiteral("lineEdit_idmodifiersalle"));
        lineEdit_idmodifiersalle->setGeometry(QRect(70, 50, 141, 21));
        tabWidget_2->addTab(Modifier_Traiteur, QString());
        tabWidget->addTab(Espace_Traiteur, QString());
        Espace_Cameraman = new QWidget();
        Espace_Cameraman->setObjectName(QStringLiteral("Espace_Cameraman"));
        AfficherTheme = new QTabWidget(Espace_Cameraman);
        AfficherTheme->setObjectName(QStringLiteral("AfficherTheme"));
        AfficherTheme->setGeometry(QRect(0, 30, 751, 331));
        AfficherTheme->setStyleSheet(QLatin1String("font: 75 italic 11pt \"Times New Roman\";\n"
"color: rgb(160, 170, 117);"));
        Ajouter_Cameraman = new QWidget();
        Ajouter_Cameraman->setObjectName(QStringLiteral("Ajouter_Cameraman"));
        le_id_theme = new QLineEdit(Ajouter_Cameraman);
        le_id_theme->setObjectName(QStringLiteral("le_id_theme"));
        le_id_theme->setGeometry(QRect(130, 30, 141, 21));
        le_nom_dec = new QLineEdit(Ajouter_Cameraman);
        le_nom_dec->setObjectName(QStringLiteral("le_nom_dec"));
        le_nom_dec->setGeometry(QRect(130, 70, 141, 21));
        le_nom_theme = new QLineEdit(Ajouter_Cameraman);
        le_nom_theme->setObjectName(QStringLiteral("le_nom_theme"));
        le_nom_theme->setGeometry(QRect(130, 110, 141, 21));
        label_14 = new QLabel(Ajouter_Cameraman);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 30, 101, 20));
        label_14->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_15 = new QLabel(Ajouter_Cameraman);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 70, 121, 20));
        label_15->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_16 = new QLabel(Ajouter_Cameraman);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(20, 110, 101, 20));
        label_16->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        le_prix_theme = new QLineEdit(Ajouter_Cameraman);
        le_prix_theme->setObjectName(QStringLiteral("le_prix_theme"));
        le_prix_theme->setGeometry(QRect(130, 180, 141, 21));
        label_17 = new QLabel(Ajouter_Cameraman);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(20, 180, 101, 20));
        label_17->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        Quitter_Ajouttheme = new QPushButton(Ajouter_Cameraman);
        Quitter_Ajouttheme->setObjectName(QStringLiteral("Quitter_Ajouttheme"));
        Quitter_Ajouttheme->setGeometry(QRect(300, 120, 71, 23));
        Quitter_Ajouttheme->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        Ok_Ajouttheme = new QPushButton(Ajouter_Cameraman);
        Ok_Ajouttheme->setObjectName(QStringLiteral("Ok_Ajouttheme"));
        Ok_Ajouttheme->setGeometry(QRect(300, 90, 71, 23));
        Ok_Ajouttheme->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        le_adresse_dec = new QLineEdit(Ajouter_Cameraman);
        le_adresse_dec->setObjectName(QStringLiteral("le_adresse_dec"));
        le_adresse_dec->setGeometry(QRect(130, 150, 141, 21));
        label_18 = new QLabel(Ajouter_Cameraman);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 150, 101, 20));
        label_18->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        AfficherTheme->addTab(Ajouter_Cameraman, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 20, 621, 271));
        groupBox_3->setStyleSheet(QLatin1String("color: rgb(255, 85, 127);\n"
"font: italic 8pt \"MS Sans Serif\";"));
        tab_theme = new QTableView(groupBox_3);
        tab_theme->setObjectName(QStringLiteral("tab_theme"));
        tab_theme->setGeometry(QRect(170, 20, 421, 211));
        lineEdit_2 = new QLineEdit(groupBox_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(10, 70, 113, 20));
        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 110, 81, 23));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        pushButton_6 = new QPushButton(groupBox_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 140, 81, 23));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        comboBox_2 = new QComboBox(groupBox_3);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(40, 30, 62, 22));
        imp_ca = new QPushButton(groupBox_3);
        imp_ca->setObjectName(QStringLiteral("imp_ca"));
        imp_ca->setGeometry(QRect(10, 200, 75, 23));
        imp_ca->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        pdf_ca = new QPushButton(groupBox_3);
        pdf_ca->setObjectName(QStringLiteral("pdf_ca"));
        pdf_ca->setGeometry(QRect(10, 230, 75, 23));
        pdf_ca->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(650, 180, 75, 23));
        pushButton_4->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 75 10pt \"MS Shell Dlg 2\";"));
        AfficherTheme->addTab(tab, QString());
        Supprimer_Cameraman = new QWidget();
        Supprimer_Cameraman->setObjectName(QStringLiteral("Supprimer_Cameraman"));
        label_24 = new QLabel(Supprimer_Cameraman);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(40, 80, 101, 20));
        label_24->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        le_supp_theme = new QLineEdit(Supprimer_Cameraman);
        le_supp_theme->setObjectName(QStringLiteral("le_supp_theme"));
        le_supp_theme->setGeometry(QRect(160, 80, 141, 21));
        pb_supprimertheme = new QPushButton(Supprimer_Cameraman);
        pb_supprimertheme->setObjectName(QStringLiteral("pb_supprimertheme"));
        pb_supprimertheme->setGeometry(QRect(340, 110, 71, 23));
        pb_supprimertheme->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        AfficherTheme->addTab(Supprimer_Cameraman, QString());
        Modifier_Cameraman = new QWidget();
        Modifier_Cameraman->setObjectName(QStringLiteral("Modifier_Cameraman"));
        label_20 = new QLabel(Modifier_Cameraman);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 130, 121, 20));
        label_20->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_21 = new QLabel(Modifier_Cameraman);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 170, 101, 20));
        label_21->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        label_22 = new QLabel(Modifier_Cameraman);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(30, 250, 101, 20));
        label_22->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_nommodifiertheme = new QLineEdit(Modifier_Cameraman);
        lineEdit_nommodifiertheme->setObjectName(QStringLiteral("lineEdit_nommodifiertheme"));
        lineEdit_nommodifiertheme->setGeometry(QRect(150, 120, 141, 31));
        lineEdit_nom2modifiertheme = new QLineEdit(Modifier_Cameraman);
        lineEdit_nom2modifiertheme->setObjectName(QStringLiteral("lineEdit_nom2modifiertheme"));
        lineEdit_nom2modifiertheme->setGeometry(QRect(150, 160, 141, 31));
        lineEdit_prixmodifiertheme = new QLineEdit(Modifier_Cameraman);
        lineEdit_prixmodifiertheme->setObjectName(QStringLiteral("lineEdit_prixmodifiertheme"));
        lineEdit_prixmodifiertheme->setGeometry(QRect(150, 250, 141, 31));
        Modifier_Modifiertheme = new QPushButton(Modifier_Cameraman);
        Modifier_Modifiertheme->setObjectName(QStringLiteral("Modifier_Modifiertheme"));
        Modifier_Modifiertheme->setGeometry(QRect(330, 130, 71, 23));
        Modifier_Modifiertheme->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        Annuler_Modifiertheme = new QPushButton(Modifier_Cameraman);
        Annuler_Modifiertheme->setObjectName(QStringLiteral("Annuler_Modifiertheme"));
        Annuler_Modifiertheme->setGeometry(QRect(330, 170, 71, 23));
        Annuler_Modifiertheme->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	background: transparent;\n"
"	border-style:solid;\n"
"	border-radius:7px;\n"
"	border-width:1px;\n"
"border-color: rgb(50, 53, 57);\n"
"	color:rgb(0,0,0);\n"
"	font-size:16px;\n"
"font-family:Calibri;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #00000000;\n"
"	border-color: rgb(30, 227, 0);\n"
"	/*color:rgb(30, 227, 0);*/\n"
"}\n"
"\n"
"QPushButton:focus\n"
"{\n"
"	background-color:  rgb(30, 227, 0);\n"
"	border-color: rgba(30, 227, 0,0);\n"
"	color:rgb(255, 255, 255);\n"
"}"));
        groupBox_4 = new QGroupBox(Modifier_Cameraman);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 0, 341, 111));
        groupBox_4->setStyleSheet(QLatin1String("color: rgb(255, 85, 127);\n"
"font: italic 8pt \"MS Sans Serif\";"));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 30, 111, 16));
        label_9->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        lineEdit_idmodifiersalle_2 = new QLineEdit(groupBox_4);
        lineEdit_idmodifiersalle_2->setObjectName(QStringLiteral("lineEdit_idmodifiersalle_2"));
        lineEdit_idmodifiersalle_2->setGeometry(QRect(70, 50, 141, 21));
        lineEdit_prixmodifiertheme_2 = new QLineEdit(Modifier_Cameraman);
        lineEdit_prixmodifiertheme_2->setObjectName(QStringLiteral("lineEdit_prixmodifiertheme_2"));
        lineEdit_prixmodifiertheme_2->setGeometry(QRect(150, 210, 141, 31));
        label_23 = new QLabel(Modifier_Cameraman);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 210, 141, 20));
        label_23->setStyleSheet(QLatin1String("font: 75 11pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 0, 0);"));
        AfficherTheme->addTab(Modifier_Cameraman, QString());
        tabWidget->addTab(Espace_Cameraman, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 747, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);
        AfficherTheme->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        le_id->setText(QString());
        label->setText(QApplication::translate("MainWindow", "ID Traiteur:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", " nom Traiteur:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Adresse :", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Prix_location :", Q_NULLPTR));
        Quitter_Ajoutsalle->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        Ok_Ajoutsalle->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Ajouter_Traiteur), QApplication::translate("MainWindow", "Ajouter Traiteur", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Affichage", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "TRIER", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id_tr", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom_tr", Q_NULLPTR)
         << QApplication::translate("MainWindow", "adresse_tr", Q_NULLPTR)
        );
        imp_tr->setText(QApplication::translate("MainWindow", "imprimer", Q_NULLPTR));
        pdf_tr->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Affichr_Traiteur), QApplication::translate("MainWindow", "Afficher Traiteur", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ID Traiteur :", Q_NULLPTR));
        le_id_supp->setText(QString());
        pb_supprimer1->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(Supprimer_Traiteur), QApplication::translate("MainWindow", "Supprimer Traiteur", Q_NULLPTR));
        lineEdit_nommodifiersalle->setText(QString());
        lineEdit_adressemodifiersalle->setText(QString());
        lineEdit_prixmodifiersalle->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", " nom Traiteur :", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Adresse :", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "Prix :", Q_NULLPTR));
        Modifier_Modifiersalle->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Entrer identidiant", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "ID Traiteur :", Q_NULLPTR));
        lineEdit_idmodifiersalle->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(Modifier_Traiteur), QApplication::translate("MainWindow", "Modifier Traiteur", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Espace_Traiteur), QApplication::translate("MainWindow", "Espace Traiteur", Q_NULLPTR));
        le_id_theme->setText(QString());
        le_nom_dec->setText(QString());
        le_nom_theme->setText(QString());
        label_14->setText(QApplication::translate("MainWindow", "ID Cameraman :", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Nom Cameraman :", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Nom Theme :", Q_NULLPTR));
        le_prix_theme->setText(QString());
        label_17->setText(QApplication::translate("MainWindow", "Prix :", Q_NULLPTR));
        Quitter_Ajouttheme->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        Ok_Ajouttheme->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        le_adresse_dec->setText(QString());
        label_18->setText(QApplication::translate("MainWindow", "Adresse :", Q_NULLPTR));
        AfficherTheme->setTabText(AfficherTheme->indexOf(Ajouter_Cameraman), QApplication::translate("MainWindow", "Ajouter Cameraman", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Affichage", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "TRIER", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "id", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "adrese", Q_NULLPTR)
        );
        imp_ca->setText(QApplication::translate("MainWindow", "imprimer", Q_NULLPTR));
        pdf_ca->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        AfficherTheme->setTabText(AfficherTheme->indexOf(tab), QApplication::translate("MainWindow", "Afficher Cameraman", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "ID Cameraman :", Q_NULLPTR));
        le_supp_theme->setText(QString());
        pb_supprimertheme->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        AfficherTheme->setTabText(AfficherTheme->indexOf(Supprimer_Cameraman), QApplication::translate("MainWindow", "Supprimer Cameraman", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Nom Cameraman :", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Nom Theme :", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Prix :", Q_NULLPTR));
        lineEdit_nommodifiertheme->setText(QString());
        lineEdit_nom2modifiertheme->setText(QString());
        lineEdit_prixmodifiertheme->setText(QString());
        Modifier_Modifiertheme->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        Annuler_Modifiertheme->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Entrer identidiant", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "ID Cameraman:", Q_NULLPTR));
        lineEdit_idmodifiersalle_2->setText(QString());
        lineEdit_prixmodifiertheme_2->setText(QString());
        label_23->setText(QApplication::translate("MainWindow", "Adresse cameraman", Q_NULLPTR));
        AfficherTheme->setTabText(AfficherTheme->indexOf(Modifier_Cameraman), QApplication::translate("MainWindow", "Modifier Cameraman", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Espace_Cameraman), QApplication::translate("MainWindow", "Espace Cameraman", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
