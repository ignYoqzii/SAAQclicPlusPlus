/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   dialogueAjoutVehiculePromenade.cpp
 * Author: etudiant
 *
 * Created on 18 avril 2026, 17 h 12
 */

#include "dialogueAjoutVehiculePromenade.h"
#include <QPushButton>
#include <QValidator>

dialogueAjoutVehiculePromenade::dialogueAjoutVehiculePromenade()
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
    widget.placesLineEdit->setValidator(new QIntValidator(1, 9, this));
}

dialogueAjoutVehiculePromenade::dialogueAjoutVehiculePromenade(QWidget* parent) : QDialog(parent)
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
    widget.placesLineEdit->setValidator(new QIntValidator(1, 9, this));
}

dialogueAjoutVehiculePromenade::~dialogueAjoutVehiculePromenade()
{
}

// Slot
void dialogueAjoutVehiculePromenade::mettreAJourBoutonOk()
{
    bool active = !widget.nivLineEdit->text().isEmpty() &&
    !widget.plaqueLineEdit->text().isEmpty() &&
    !widget.placesLineEdit->text().isEmpty();
    
    widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(active);
    widget.buttonBox->button(QDialogButtonBox::Ok)->setText("Ajouter");
}

QString dialogueAjoutVehiculePromenade::reqNIV() const
{
    return widget.nivLineEdit->text();
}

QString dialogueAjoutVehiculePromenade::reqPlaque() const
{
    return widget.plaqueLineEdit->text();
}

int dialogueAjoutVehiculePromenade::reqPlaces() const
{
    return widget.placesLineEdit->text().toInt();
}