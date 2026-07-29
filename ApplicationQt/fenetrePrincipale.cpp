/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   fenetrePrincipale.cpp
 * Author: Yoan Lévesque
 *
 * Created on 14 avril 2026, 22 h 24
 */

#include "fenetrePrincipale.h"
#include <limits>
#include "utilitaire/validationFormat.h"
#include "utilitaire/taxesImmatriculationVPQc.h"
#include "classes/Camion.h"
#include "classes/VehiculePromenade.h"
#include "exceptions/VehiculeAbsentException.h"
#include "exceptions/VehiculeDejaPresentException.h"
#include "dialogueInscriptionProprietaire.h"
#include "dialogueSuppressionVehicule.h"
#include "dialogueAjoutCamion.h"
#include "dialogueAjoutVehiculePromenade.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTime>

using std::string;
using std::getline;

fenetrePrincipale::fenetrePrincipale()
{
    widget.setupUi(this);
}

fenetrePrincipale::~fenetrePrincipale()
{
}

/**
 * @brief Construit un objet Proprietaire et ses véhicules à partir d'un flux.
 * @param[out] p_is Flux d'entrée depuis le fichier de données.
 * @return Un pointeur vers un objet Proprietaire rempli.
 */
std::unique_ptr<saaq::Proprietaire> fenetrePrincipale::construireProprietaireDepuisFlux(std::istream& p_is)
{
    string nom;
    string prenom;
    string ville;
    string date; // Inutile.
    getline(p_is, nom);
    getline(p_is, prenom);
    getline(p_is, ville);
    getline(p_is, date); // Consomme la ligne inutile.
    
    auto unProprietaire = std::make_unique<saaq::Proprietaire>(nom, prenom, ville);
    
    string niv;
    
    while (getline(p_is, niv))
    {
        string immatriculation;
        getline(p_is, immatriculation);
        
        // Identification du type de véhicule par sa plaque.
        bool estCamion = saaq::validerImmatriculationCamion(immatriculation);
        bool estPromenade = saaq::validerImmatriculationPromenade(immatriculation);
        
        if (estCamion)
        {
            int poids;
            int nbEssieux;
            p_is >> poids;
            p_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            p_is >> nbEssieux;
            p_is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            
            saaq::Camion unCamion(niv, immatriculation, poids, nbEssieux);
            unProprietaire->ajouterVehicule(unCamion);
        }
        if (estPromenade)
        {
            int nbPlaces;
            p_is >> nbPlaces;
            p_is.ignore(); // Consomme le dernier "\n".
            
            saaq::VehiculePromenade unVehiculePromenade(niv, immatriculation, nbPlaces);
            
            // Ajuster les frais selon la ville.
            double contributionTransportEnCommun = 0.0;
            double taxeLocale = 0.0;
            if (saaq::trouverTaxes(saaq::TAXE_IMMATRICULATION, ville, contributionTransportEnCommun, taxeLocale))
            {
                unVehiculePromenade.asgContributionTransportEnCommun(contributionTransportEnCommun);
                unVehiculePromenade.asgTaxeLocale(taxeLocale);
            }
            unProprietaire->ajouterVehicule(unVehiculePromenade);
        }
    }
    return unProprietaire;
}

/**
 * @brief Affiche les véhicules du vecteur dans le QTreeWidget en tant qu'items.
 */
void fenetrePrincipale::afficherVehiculesDansLaListe()
{
    widget.listeVehicules->clear();
    
    // S'il n'y a aucun véhicule, afficher un message par défaut
    if (m_proprietaire->reqNbVehicules() == 0)
    {
        QTreeWidgetItem* item = new QTreeWidgetItem(widget.listeVehicules);
        item->setText(0, "Aucun véhicule pour le moment.");
        return;
    }
    
    int indexCamion = 1;
    int indexVehiculePromenade = 1;
    
    for (const auto& vehicule : m_proprietaire->reqVecteurVehicules())
    {
        // Vérifier si c'est un camion.
        if (auto camion = dynamic_cast<saaq::Camion*>(vehicule.get()))
        {
            QString titre = QString("Camion %1").arg(indexCamion++);
            QTreeWidgetItem* parent = new QTreeWidgetItem(widget.listeVehicules);
            parent->setText(0, titre);

            // Sous-items
            new QTreeWidgetItem(parent, QStringList() << "NIV : " + QString::fromStdString(camion->reqNIV()));
            new QTreeWidgetItem(parent, QStringList() << "Plaque : " + QString::fromStdString(camion->reqImmatriculation()));
            new QTreeWidgetItem(parent, QStringList() << "Poids : " + QString::number(camion->reqPoids()));
            new QTreeWidgetItem(parent, QStringList() << "Essieux : " + QString::number(camion->reqNbEssieux()));
            new QTreeWidgetItem(parent, QStringList() << "Paiement : "
                    + QString::number(camion->calculerTarificationAnnuelle(), 'f', 2) + " $");
        }
        // Vérifier si c'est un véhicule de promenade
        else if (auto vehiculePromenade = dynamic_cast<saaq::VehiculePromenade*>(vehicule.get()))
        {
            QString titre = QString("Véhicule de promenade %1").arg(indexVehiculePromenade++);
            QTreeWidgetItem* parent = new QTreeWidgetItem(widget.listeVehicules);
            parent->setText(0, titre);

            // Sous-items
            new QTreeWidgetItem(parent, QStringList() << "NIV : " + QString::fromStdString(vehiculePromenade->reqNIV()));
            new QTreeWidgetItem(parent, QStringList() << "Plaque : " + QString::fromStdString(vehiculePromenade->reqImmatriculation()));
            new QTreeWidgetItem(parent, QStringList() << "Places : " + QString::number(vehiculePromenade->reqNbPlaces()));
            new QTreeWidgetItem(parent, QStringList() << "Paiement : "
                    + QString::number(vehiculePromenade->calculerTarificationAnnuelle(), 'f', 2) + " $");
        }
    }
}

/**
 * @brief Détermine la salutation selon le moment de la journée.
 * @return La chaîne de caractères correspondante.
 */
QString fenetrePrincipale::reqSalutationSelonHeure() const
{
    int heure = QTime::currentTime().hour();

    if (heure < 12)
    {
        return "Bon matin";
    }
    else if (heure < 18)
    {
        return "Bon après-midi";
    }
    else
    {
        return "Bonsoir";
    }
}

/**
 * @brief Met à jour l'interface du propriétaire en entier.
 */
void fenetrePrincipale::afficherProprietaire()
{
    widget.zoneAffichageConsole->setText(
            QString::fromStdString(m_proprietaire->reqProprietaireFormate())
            );

    QString nom = QString::fromStdString(m_proprietaire->reqNom());
    QString prenom = QString::fromStdString(m_proprietaire->reqPrenom());
    QString salutation = reqSalutationSelonHeure();
    QString html = QString(
            "<html><head/><body>"
            "<p>%1, %2 %3 !</p>"
            "<p><span style='font-size:10pt;'>Que voulez-vous faire aujourd'hui ?</span></p>"
            "</body></html>").arg(salutation, prenom, nom);
    widget.bonjourLabel->setText(html);
    
    QString ville = QString::fromStdString(m_proprietaire->reqVilleDomicile());
    widget.villeLabel->setText(QString("Ville de domicile : %1").arg(ville));
    
    double montant = m_proprietaire->reqPaiementTotal();
    widget.paiementTotalLabel->setText(QString("Paiement total : %1 $").arg(QString::number(montant, 'f', 2)));
    
    afficherVehiculesDansLaListe();
}

//===================================
//               SLOTS 
//===================================

void fenetrePrincipale::chargerProprietaire()
{
    QString cheminFichier = QFileDialog::getOpenFileName(
            this,
            "Ouvrir un fichier",
            QString(),
            "Fichiers texte (*.txt);;Tous les fichiers (*.*)"
            );

    if (cheminFichier.isEmpty())
    {
        // L'utilisateur n'a pas sélectionné de fichier.
        return;
    }

    std::ifstream dossierProprietaire(cheminFichier.toStdString());
    if (!dossierProprietaire)
    {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier sélectionné.");
        return;
    }
    
    if (!saaq::validerFormatFichier(dossierProprietaire))
    {
        QMessageBox::warning(this, "Erreur", "Le fichier fourni n'est pas un dossier valide d'un propriétaire.");
        return;
    }
    
    dossierProprietaire.clear();
    dossierProprietaire.seekg(0);

    m_proprietaire = construireProprietaireDepuisFlux(dossierProprietaire);
    
    afficherProprietaire();
    
    statusBar()->showMessage("Dossier du propriétaire chargé avec succès !", 3000);
}

void fenetrePrincipale::inscrireProprietaire()
{
    dialogueInscriptionProprietaire dialogue(this);
    
    if (dialogue.exec() == QDialog::Accepted)
    {
        QString nom = dialogue.reqNom();
        QString prenom = dialogue.reqPrenom();
        QString ville = dialogue.reqVille();
        
        m_proprietaire = std::make_unique<saaq::Proprietaire>(
                nom.toStdString(),
                prenom.toStdString(),
                ville.toStdString()
                );
        
        afficherProprietaire();
        
        statusBar()->showMessage("Propriétaire inscrit avec succès !", 3000);
    }
}

void fenetrePrincipale::ajouterVehiculePromenade()
{
    // Avant toute chose, il faut vérifier que m_proprietaire pointe vers
    // un propriétaire construit valide.
    if (!m_proprietaire)
    {
        QMessageBox::warning(this, "Erreur", "Aucun propriétaire n'est chargé ou inscrit !");
        return;
    }
    
    dialogueAjoutVehiculePromenade dialogue(this);
    
    if (dialogue.exec() == QDialog::Accepted)
    {
        QString niv = dialogue.reqNIV();
        if (!saaq::validerNiv(niv.toStdString()))
        {
            QMessageBox::warning(this, "Erreur", "Le NIV fourni n'est pas valide.");
            return;
        }
        
        QString plaque = dialogue.reqPlaque();
        if (!saaq::validerImmatriculationPromenade(plaque.toStdString()))
        {
            QMessageBox::warning(this, "Erreur", "La plaque d'immatriculation fournie n'est pas valide.");
            return;
        }
        
        int places = dialogue.reqPlaces();
        if (places < 1 || places > 9)
        {
            QMessageBox::warning(this, "Erreur", "Le nombre de places fourni n'est pas valide.");
            return;
        }
        
        try
        {
            saaq::VehiculePromenade unVehiculePromenade(niv.toStdString(), plaque.toStdString(), places);
            // Ajuster les frais selon la ville.
            double contributionTransportEnCommun = 0.0;
            double taxeLocale = 0.0;
            string ville = m_proprietaire->reqVilleDomicile();
            if (saaq::trouverTaxes(saaq::TAXE_IMMATRICULATION, ville, contributionTransportEnCommun, taxeLocale))
            {
                unVehiculePromenade.asgContributionTransportEnCommun(contributionTransportEnCommun);
                unVehiculePromenade.asgTaxeLocale(taxeLocale);
            }
            m_proprietaire->ajouterVehicule(unVehiculePromenade);
            afficherProprietaire();
            statusBar()->showMessage("Véhicule de promenade ajouté avec succès !", 3000);
        }
        catch (const saaq::VehiculeDejaPresentException& e)
        {
            QMessageBox::warning(this, "Erreur", QString(
                    "Le véhicule fait déjà partie du dossier du propriétaire.\n\nDétails : %1").arg(e.what())
                    );
            return;
        }
    }
}

void fenetrePrincipale::ajouterCamion()
{
    // Avant toute chose, il faut vérifier que m_proprietaire pointe vers
    // un propriétaire construit valide.
    if (!m_proprietaire)
    {
        QMessageBox::warning(this, "Erreur", "Aucun propriétaire n'est chargé ou inscrit !");
        return;
    }
    
    dialogueAjoutCamion dialogue(this);
    
    if (dialogue.exec() == QDialog::Accepted)
    {
        QString niv = dialogue.reqNIV();
        if (!saaq::validerNiv(niv.toStdString()))
        {
            QMessageBox::warning(this, "Erreur", "Le NIV fourni n'est pas valide.");
            return;
        }
        
        QString plaque = dialogue.reqPlaque();
        if (!saaq::validerImmatriculationCamion(plaque.toStdString()))
        {
            QMessageBox::warning(this, "Erreur", "La plaque d'immatriculation fournie n'est pas valide.");
            return;
        }
        
        int poids = dialogue.reqPoids();
        if (poids <= 3000)
        {
            QMessageBox::warning(this, "Erreur", "Le poids fourni n'est pas valide.");
            return;
        }
        
        int essieux = dialogue.reqEssieux();
        if (essieux < 2)
        {
            QMessageBox::warning(this, "Erreur", "Le nombre d'essieux fourni n'est pas valide.");
            return;
        }
        
        try
        {
            saaq::Camion unCamion(niv.toStdString(), plaque.toStdString(), poids, essieux);
            m_proprietaire->ajouterVehicule(unCamion);
            afficherProprietaire();
            statusBar()->showMessage("Camion ajouté avec succès !", 3000);
        }
        catch (const saaq::VehiculeDejaPresentException& e)
        {
            QMessageBox::warning(this, "Erreur", QString(
                    "Le véhicule fait déjà partie du dossier du propriétaire.\n\nDétails : %1").arg(e.what())
                    );
            return;
        }
    }
}

void fenetrePrincipale::supprimerVehicule()
{
    // Avant toute chose, il faut vérifier que m_proprietaire pointe vers
    // un propriétaire construit valide.
    if (!m_proprietaire)
    {
        QMessageBox::warning(this, "Erreur", "Aucun propriétaire n'est chargé ou inscrit !");
        return;
    }
    
    dialogueSuppressionVehicule dialogue(this);
    
    if (dialogue.exec() == QDialog::Accepted)
    {
        QString niv = dialogue.reqNIV();
        
        if (!saaq::validerNiv(niv.toStdString()))
        {
            QMessageBox::warning(this, "Erreur", "Le NIV fourni n'est pas valide.");
            return;
        }
        
        try
        {
            m_proprietaire->supprimerVehicule(niv.toStdString());
            afficherProprietaire();
            statusBar()->showMessage("Véhicule retiré avec succès !", 3000);
        }
        catch (const saaq::VehiculeAbsentException& e)
        {
            QMessageBox::warning(this, "Erreur", QString(
                    "Le véhicule ne fait pas partie du dossier du propriétaire.\n\nDétails : %1").arg(e.what())
                    );
            return;
        }
    }
}