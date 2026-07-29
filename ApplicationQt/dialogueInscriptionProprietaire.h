/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   dialogueInscriptionProprietaire.h
 * Author: etudiant
 *
 * Created on 15 avril 2026, 12 h 18
 */

#ifndef _DIALOGUEINSCRIPTIONPROPRIETAIRE_H
#define _DIALOGUEINSCRIPTIONPROPRIETAIRE_H

#include "ui_dialogueInscriptionProprietaire.h"

class dialogueInscriptionProprietaire : public QDialog
{
    Q_OBJECT
public:
    dialogueInscriptionProprietaire();
    explicit dialogueInscriptionProprietaire(QWidget* parent = nullptr);
    virtual ~dialogueInscriptionProprietaire();
    
    QString reqNom() const;
    QString reqPrenom() const;
    QString reqVille() const;
private:
    Ui::dialogueInscriptionProprietaire widget;
    private slots:
        void mettreAJourBoutonOk();
};

#endif /* _DIALOGUEINSCRIPTIONPROPRIETAIRE_H */
