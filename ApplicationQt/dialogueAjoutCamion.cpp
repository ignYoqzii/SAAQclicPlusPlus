/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   dialogueAjoutCamion.cpp
 * Author: etudiant
 *
 * Created on 16 avril 2026, 23 h 22
 */

#include "dialogueAjoutCamion.h"
#include <QPushButton>
#include <QValidator>

dialogueAjoutCamion::dialogueAjoutCamion()
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
    widget.poidsLineEdit->setValidator(new QIntValidator(3001, 999999, this));
    widget.essieuxLineEdit->setValidator(new QIntValidator(2, 10, this));
}

dialogueAjoutCamion::dialogueAjoutCamion(QWidget* parent) : QDialog(parent)
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
    widget.poidsLineEdit->setValidator(new QIntValidator(3001, 999999, this));
    widget.essieuxLineEdit->setValidator(new QIntValidator(2, 10, this));
}

dialogueAjoutCamion::~dialogueAjoutCamion()
{
}

// Slot
void dialogueAjoutCamion::mettreAJourBoutonOk()
{
    bool active = !widget.nivLineEdit->text().isEmpty() &&
    !widget.plaqueLineEdit->text().isEmpty() &&
    !widget.poidsLineEdit->text().isEmpty() &&
    !widget.essieuxLineEdit->text().isEmpty();
    
    widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(active);
    widget.buttonBox->button(QDialogButtonBox::Ok)->setText("Ajouter");
}

QString dialogueAjoutCamion::reqNIV() const
{
    return widget.nivLineEdit->text();
}

QString dialogueAjoutCamion::reqPlaque() const
{
    return widget.plaqueLineEdit->text();
}

int dialogueAjoutCamion::reqPoids() const
{
    return widget.poidsLineEdit->text().toInt();
}

int dialogueAjoutCamion::reqEssieux() const
{
    return widget.essieuxLineEdit->text().toInt();
}
