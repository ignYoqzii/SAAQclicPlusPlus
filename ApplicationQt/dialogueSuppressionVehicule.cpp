/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   dialogueSuppressionVehicule.cpp
 * Author: etudiant
 *
 * Created on 15 avril 2026, 12 h 11
 */

#include "dialogueSuppressionVehicule.h"
#include <QPushButton>

dialogueSuppressionVehicule::dialogueSuppressionVehicule()
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
}

dialogueSuppressionVehicule::dialogueSuppressionVehicule(QWidget* parent) : QDialog(parent)
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
}

dialogueSuppressionVehicule::~dialogueSuppressionVehicule()
{
}

void dialogueSuppressionVehicule::mettreAJourBoutonOk()
{
    widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!widget.nivLineEdit->text().isEmpty());
    widget.buttonBox->button(QDialogButtonBox::Ok)->setText("Supprimer");
}

QString dialogueSuppressionVehicule::reqNIV() const
{
    return widget.nivLineEdit->text();
}
