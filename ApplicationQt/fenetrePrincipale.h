/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   fenetrePrincipale.h
 * Author: etudiant
 *
 * Created on 14 avril 2026, 22 h 24
 */

#ifndef _FENETREPRINCIPALE_H
#define _FENETREPRINCIPALE_H

#include "ui_fenetrePrincipale.h"
#include "classes/Proprietaire.h"
#include <memory>
#include <fstream>

class fenetrePrincipale : public QMainWindow
{
    Q_OBJECT
public:
    fenetrePrincipale();
    virtual ~fenetrePrincipale();
private:
    Ui::fenetrePrincipale widget;
    
    std::unique_ptr<saaq::Proprietaire> m_proprietaire;
    
    std::unique_ptr<saaq::Proprietaire> construireProprietaireDepuisFlux(std::istream& p_is);
    
    void afficherVehiculesDansLaListe();
    
    QString reqSalutationSelonHeure() const;
    
    void afficherProprietaire();
    
    private slots:
        void chargerProprietaire();
        void inscrireProprietaire();
        void ajouterVehiculePromenade();
        void ajouterCamion();
        void supprimerVehicule();
};

#endif /* _FENETREPRINCIPALE_H */
