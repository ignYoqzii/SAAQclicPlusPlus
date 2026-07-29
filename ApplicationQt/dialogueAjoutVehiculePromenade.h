/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   dialogueAjoutVehiculePromenade.h
 * Author: etudiant
 *
 * Created on 18 avril 2026, 17 h 12
 */

#ifndef _DIALOGUEAJOUTVEHICULEPROMENADE_H
#define _DIALOGUEAJOUTVEHICULEPROMENADE_H

#include "ui_dialogueAjoutVehiculePromenade.h"

class dialogueAjoutVehiculePromenade : public QDialog
{
    Q_OBJECT
public:
    dialogueAjoutVehiculePromenade();
    explicit dialogueAjoutVehiculePromenade(QWidget* parent = nullptr);
    virtual ~dialogueAjoutVehiculePromenade();
    
    QString reqNIV() const;
    QString reqPlaque() const;
    int reqPlaces() const;
private:
    Ui::dialogueAjoutVehiculePromenade widget;
    private slots:
        void mettreAJourBoutonOk();
};

#endif /* _DIALOGUEAJOUTVEHICULEPROMENADE_H */
