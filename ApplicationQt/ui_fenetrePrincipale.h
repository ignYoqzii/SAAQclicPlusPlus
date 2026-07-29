/********************************************************************************
** Form generated from reading UI file 'fenetrePrincipale.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPRINCIPALE_H
#define UI_FENETREPRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fenetrePrincipale
{
public:
    QAction *actionCharger_un_propri_taire;
    QAction *actionSupprimer_un_v_hicule;
    QAction *actionV_hicule_de_promenade;
    QAction *actionCamion;
    QAction *actionQuitter;
    QAction *actionInscription;
    QAction *actionAjouter_un_v_hicule_de_promenade;
    QAction *actionAjouter_un_camion;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *consoleLabel;
    QFrame *line;
    QTextEdit *zoneAffichageConsole;
    QVBoxLayout *verticalLayout;
    QLabel *bonjourLabel;
    QLabel *villeLabel;
    QFrame *line_2;
    QLabel *vehiculesLabel;
    QTreeWidget *listeVehicules;
    QFrame *line_3;
    QLabel *paiementTotalLabel;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuV_hicule;
    QMenu *menuAjouter_un_v_hicule;
    QMenu *menuPropri_taire;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *fenetrePrincipale)
    {
        if (fenetrePrincipale->objectName().isEmpty())
            fenetrePrincipale->setObjectName(QString::fromUtf8("fenetrePrincipale"));
        fenetrePrincipale->resize(993, 699);
        fenetrePrincipale->setAutoFillBackground(false);
        fenetrePrincipale->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #dce3ec;\n"
"}"));
        actionCharger_un_propri_taire = new QAction(fenetrePrincipale);
        actionCharger_un_propri_taire->setObjectName(QString::fromUtf8("actionCharger_un_propri_taire"));
        actionSupprimer_un_v_hicule = new QAction(fenetrePrincipale);
        actionSupprimer_un_v_hicule->setObjectName(QString::fromUtf8("actionSupprimer_un_v_hicule"));
        actionV_hicule_de_promenade = new QAction(fenetrePrincipale);
        actionV_hicule_de_promenade->setObjectName(QString::fromUtf8("actionV_hicule_de_promenade"));
        actionCamion = new QAction(fenetrePrincipale);
        actionCamion->setObjectName(QString::fromUtf8("actionCamion"));
        actionQuitter = new QAction(fenetrePrincipale);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionInscription = new QAction(fenetrePrincipale);
        actionInscription->setObjectName(QString::fromUtf8("actionInscription"));
        actionAjouter_un_v_hicule_de_promenade = new QAction(fenetrePrincipale);
        actionAjouter_un_v_hicule_de_promenade->setObjectName(QString::fromUtf8("actionAjouter_un_v_hicule_de_promenade"));
        actionAjouter_un_camion = new QAction(fenetrePrincipale);
        actionAjouter_un_camion->setObjectName(QString::fromUtf8("actionAjouter_un_camion"));
        centralwidget = new QWidget(fenetrePrincipale);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"    background-color: #dce3ec;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: transparent;\n"
"    width: 8px;\n"
"    margin: 2px 0 2px 0;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #C8C8C8;\n"
"    min-height: 20px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #A0A0A0;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    height: 0;\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical,\n"
"QScrollBar::sub-page:vertical {\n"
"    background: transparent;\n"
"}"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(10);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        consoleLabel = new QLabel(centralwidget);
        consoleLabel->setObjectName(QString::fromUtf8("consoleLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font.setBold(true);
        font.setWeight(75);
        consoleLabel->setFont(font);
        consoleLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}\n"
"       "));

        gridLayout->addWidget(consoleLabel, 0, 2, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 0, 1, 2, 1);

        zoneAffichageConsole = new QTextEdit(centralwidget);
        zoneAffichageConsole->setObjectName(QString::fromUtf8("zoneAffichageConsole"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font1.setPointSize(10);
        zoneAffichageConsole->setFont(font1);
        zoneAffichageConsole->setStyleSheet(QString::fromUtf8("QTextEdit {\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"    background-color: #f6f8fa;\n"
"}"));
        zoneAffichageConsole->setReadOnly(true);

        gridLayout->addWidget(zoneAffichageConsole, 1, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        bonjourLabel = new QLabel(centralwidget);
        bonjourLabel->setObjectName(QString::fromUtf8("bonjourLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(bonjourLabel->sizePolicy().hasHeightForWidth());
        bonjourLabel->setSizePolicy(sizePolicy);
        bonjourLabel->setMinimumSize(QSize(0, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        bonjourLabel->setFont(font2);
        bonjourLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));
        bonjourLabel->setWordWrap(true);

        verticalLayout->addWidget(bonjourLabel);

        villeLabel = new QLabel(centralwidget);
        villeLabel->setObjectName(QString::fromUtf8("villeLabel"));
        villeLabel->setFont(font);
        villeLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        verticalLayout->addWidget(villeLabel);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        vehiculesLabel = new QLabel(centralwidget);
        vehiculesLabel->setObjectName(QString::fromUtf8("vehiculesLabel"));
        vehiculesLabel->setFont(font);
        vehiculesLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        verticalLayout->addWidget(vehiculesLabel);

        listeVehicules = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        listeVehicules->setHeaderItem(__qtreewidgetitem);
        new QTreeWidgetItem(listeVehicules);
        listeVehicules->setObjectName(QString::fromUtf8("listeVehicules"));
        listeVehicules->setEnabled(true);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font3.setBold(false);
        font3.setWeight(50);
        listeVehicules->setFont(font3);
        listeVehicules->setFocusPolicy(Qt::NoFocus);
        listeVehicules->setStyleSheet(QString::fromUtf8("QTreeWidget {\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 10px;\n"
"    background-color: #f6f8fa;\n"
"}\n"
"\n"
"QTreeWidget::item {\n"
"    padding: 8px 12px;\n"
"	border-bottom: 1px solid #EEEEEE;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QTreeWidget::item:hover {\n"
"    background-color: rgba(0, 0, 0, 0.06);\n"
"    border-radius: 6px;\n"
"}"));
        listeVehicules->setProperty("showDropIndicator", QVariant(false));
        listeVehicules->setSelectionMode(QAbstractItemView::NoSelection);
        listeVehicules->setSelectionBehavior(QAbstractItemView::SelectItems);
        listeVehicules->setIconSize(QSize(0, 0));
        listeVehicules->setAnimated(true);
        listeVehicules->header()->setVisible(false);

        verticalLayout->addWidget(listeVehicules);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        paiementTotalLabel = new QLabel(centralwidget);
        paiementTotalLabel->setObjectName(QString::fromUtf8("paiementTotalLabel"));
        paiementTotalLabel->setFont(font);
        paiementTotalLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        verticalLayout->addWidget(paiementTotalLabel);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        fenetrePrincipale->setCentralWidget(centralwidget);
        menubar = new QMenuBar(fenetrePrincipale);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 993, 37));
        menubar->setFont(font3);
        menubar->setStyleSheet(QString::fromUtf8("QMenuBar {\n"
"    background: white;\n"
"    color: #333;\n"
"    padding: 4px;\n"
"    border-bottom: 1px solid #D0D0D0;\n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    background: transparent;\n"
"    padding: 6px 10px;\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"    background: #E6E6E6;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QMenu {\n"
"    background: #FFFFFF;\n"
"    color: #333;\n"
"    border: 1px solid #CFCFCF;\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background: #E6E6E6;\n"
"}"));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuV_hicule = new QMenu(menubar);
        menuV_hicule->setObjectName(QString::fromUtf8("menuV_hicule"));
        menuAjouter_un_v_hicule = new QMenu(menuV_hicule);
        menuAjouter_un_v_hicule->setObjectName(QString::fromUtf8("menuAjouter_un_v_hicule"));
        menuPropri_taire = new QMenu(menubar);
        menuPropri_taire->setObjectName(QString::fromUtf8("menuPropri_taire"));
        fenetrePrincipale->setMenuBar(menubar);
        statusbar = new QStatusBar(fenetrePrincipale);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setStyleSheet(QString::fromUtf8("QStatusBar {\n"
"	background-color: #f6f8fa;\n"
"}"));
        fenetrePrincipale->setStatusBar(statusbar);
        toolBar = new QToolBar(fenetrePrincipale);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setStyleSheet(QString::fromUtf8("QToolBar {\n"
"    background: #f6f8fa;\n"
"    border-bottom: 1px solid #D0D0D0;\n"
"    spacing: 4px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QToolBar::separator {\n"
"    background: #D0D0D0;\n"
"    width: 1px;\n"
"    margin: 4px;\n"
"}\n"
"\n"
"QToolButton {\n"
"    background: transparent;\n"
"    color: #333;\n"
"    padding: 6px 10px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QToolButton:hover {\n"
"    background: #E6E6E6;\n"
"}\n"
"\n"
"QToolButton:pressed {\n"
"    background: #DADADA;\n"
"}"));
        fenetrePrincipale->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuPropri_taire->menuAction());
        menubar->addAction(menuV_hicule->menuAction());
        menuFichier->addAction(actionCharger_un_propri_taire);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuV_hicule->addAction(menuAjouter_un_v_hicule->menuAction());
        menuV_hicule->addAction(actionSupprimer_un_v_hicule);
        menuAjouter_un_v_hicule->addAction(actionV_hicule_de_promenade);
        menuAjouter_un_v_hicule->addAction(actionCamion);
        menuPropri_taire->addAction(actionInscription);
        toolBar->addAction(actionCharger_un_propri_taire);
        toolBar->addSeparator();
        toolBar->addAction(actionSupprimer_un_v_hicule);
        toolBar->addAction(actionAjouter_un_v_hicule_de_promenade);
        toolBar->addAction(actionAjouter_un_camion);

        retranslateUi(fenetrePrincipale);
        QObject::connect(actionQuitter, SIGNAL(triggered()), fenetrePrincipale, SLOT(close()));
        QObject::connect(actionCharger_un_propri_taire, SIGNAL(triggered()), fenetrePrincipale, SLOT(chargerProprietaire()));
        QObject::connect(actionInscription, SIGNAL(triggered()), fenetrePrincipale, SLOT(inscrireProprietaire()));
        QObject::connect(actionCamion, SIGNAL(triggered()), fenetrePrincipale, SLOT(ajouterCamion()));
        QObject::connect(actionV_hicule_de_promenade, SIGNAL(triggered()), fenetrePrincipale, SLOT(ajouterVehiculePromenade()));
        QObject::connect(actionSupprimer_un_v_hicule, SIGNAL(triggered()), fenetrePrincipale, SLOT(supprimerVehicule()));
        QObject::connect(actionAjouter_un_v_hicule_de_promenade, SIGNAL(triggered()), fenetrePrincipale, SLOT(ajouterVehiculePromenade()));
        QObject::connect(actionAjouter_un_camion, SIGNAL(triggered()), fenetrePrincipale, SLOT(ajouterCamion()));

        QMetaObject::connectSlotsByName(fenetrePrincipale);
    } // setupUi

    void retranslateUi(QMainWindow *fenetrePrincipale)
    {
        fenetrePrincipale->setWindowTitle(QCoreApplication::translate("fenetrePrincipale", "SAAQclic++", nullptr));
        actionCharger_un_propri_taire->setText(QCoreApplication::translate("fenetrePrincipale", "Charger un propri\303\251taire", nullptr));
        actionSupprimer_un_v_hicule->setText(QCoreApplication::translate("fenetrePrincipale", "Supprimer un v\303\251hicule", nullptr));
        actionV_hicule_de_promenade->setText(QCoreApplication::translate("fenetrePrincipale", "V\303\251hicule de promenade", nullptr));
        actionCamion->setText(QCoreApplication::translate("fenetrePrincipale", "Camion", nullptr));
        actionQuitter->setText(QCoreApplication::translate("fenetrePrincipale", "Quitter", nullptr));
        actionInscription->setText(QCoreApplication::translate("fenetrePrincipale", "Inscription", nullptr));
        actionAjouter_un_v_hicule_de_promenade->setText(QCoreApplication::translate("fenetrePrincipale", "Ajouter un v\303\251hicule de promenade", nullptr));
        actionAjouter_un_camion->setText(QCoreApplication::translate("fenetrePrincipale", "Ajouter un camion", nullptr));
        consoleLabel->setText(QCoreApplication::translate("fenetrePrincipale", "Console (Terminal) :", nullptr));
        zoneAffichageConsole->setPlaceholderText(QCoreApplication::translate("fenetrePrincipale", "Charger le dossier d'un propri\303\251taire ou inscrivez-vous pour commencer.", nullptr));
        bonjourLabel->setText(QCoreApplication::translate("fenetrePrincipale", "<html><head/><body><p>Bienvenue sur SAAQclic++ !</p><p><span style=\" font-size:10pt;\">Qu'attendez-vous ? Inscrivez-vous maintenant !</span></p></body></html>", nullptr));
        villeLabel->setText(QCoreApplication::translate("fenetrePrincipale", "Ville de domicile : N/A", nullptr));
        vehiculesLabel->setText(QCoreApplication::translate("fenetrePrincipale", "Vos v\303\251hicules :", nullptr));

        const bool __sortingEnabled = listeVehicules->isSortingEnabled();
        listeVehicules->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem = listeVehicules->topLevelItem(0);
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("fenetrePrincipale", "Aucun propri\303\251taire n'est enregistr\303\251.", nullptr));
        listeVehicules->setSortingEnabled(__sortingEnabled);

        paiementTotalLabel->setText(QCoreApplication::translate("fenetrePrincipale", "Paiement total : N/A", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("fenetrePrincipale", "Fichier", nullptr));
        menuV_hicule->setTitle(QCoreApplication::translate("fenetrePrincipale", "V\303\251hicule", nullptr));
        menuAjouter_un_v_hicule->setTitle(QCoreApplication::translate("fenetrePrincipale", "Ajouter un v\303\251hicule", nullptr));
        menuPropri_taire->setTitle(QCoreApplication::translate("fenetrePrincipale", "Propri\303\251taire", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("fenetrePrincipale", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fenetrePrincipale: public Ui_fenetrePrincipale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPRINCIPALE_H
