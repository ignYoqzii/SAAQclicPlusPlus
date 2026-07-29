/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   dialogueSuppressionVehicule.h
 * Author: etudiant
 *
 * Created on 15 avril 2026, 12 h 11
 */

#ifndef _DIALOGUESUPPRESSIONVEHICULE_H
#define _DIALOGUESUPPRESSIONVEHICULE_H

#include "ui_dialogueSuppressionVehicule.h"

class dialogueSuppressionVehicule : public QDialog
{
    Q_OBJECT
public:
    dialogueSuppressionVehicule();
    explicit dialogueSuppressionVehicule(QWidget* parent = nullptr);
    virtual ~dialogueSuppressionVehicule();
    
    QString reqNIV() const;
private:
    Ui::dialogueSuppressionVehicule widget;
    private slots:
        void mettreAJourBoutonOk();
};

#endif /* _DIALOGUESUPPRESSIONVEHICULE_H */
