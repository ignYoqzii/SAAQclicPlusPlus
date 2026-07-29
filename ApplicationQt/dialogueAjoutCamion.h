/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.h to edit this template
 */

/* 
 * File:   dialogueAjoutCamion.h
 * Author: etudiant
 *
 * Created on 16 avril 2026, 23 h 22
 */

#ifndef _DIALOGUEAJOUTCAMION_H
#define _DIALOGUEAJOUTCAMION_H

#include "ui_dialogueAjoutCamion.h"

class dialogueAjoutCamion : public QDialog
{
    Q_OBJECT
public:
    dialogueAjoutCamion();
    explicit dialogueAjoutCamion(QWidget* parent = nullptr);
    virtual ~dialogueAjoutCamion();
    
    QString reqNIV() const;
    QString reqPlaque() const;
    int reqPoids() const;
    int reqEssieux() const;
private:
    Ui::dialogueAjoutCamion widget;
    private slots:
        void mettreAJourBoutonOk();
};

#endif /* _DIALOGUEAJOUTCAMION_H */
