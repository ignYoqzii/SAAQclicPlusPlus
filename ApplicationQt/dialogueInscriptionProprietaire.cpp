/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/form.cc to edit this template
 */

/*
 * File:   dialogueInscriptionProprietaire.cpp
 * Author: etudiant
 *
 * Created on 15 avril 2026, 12 h 18
 */

#include "dialogueInscriptionProprietaire.h"
#include <QPushButton>

dialogueInscriptionProprietaire::dialogueInscriptionProprietaire()
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
}

dialogueInscriptionProprietaire::dialogueInscriptionProprietaire(QWidget* parent) : QDialog(parent)
{
    widget.setupUi(this);
    mettreAJourBoutonOk();
}

dialogueInscriptionProprietaire::~dialogueInscriptionProprietaire()
{
}

// Slot
void dialogueInscriptionProprietaire::mettreAJourBoutonOk()
{
    bool active = !widget.nomLineEdit->text().isEmpty() &&
    !widget.prenomLineEdit->text().isEmpty() &&
    !widget.villeLineEdit->text().isEmpty();
    
    widget.buttonBox->button(QDialogButtonBox::Ok)->setEnabled(active);
    widget.buttonBox->button(QDialogButtonBox::Ok)->setText("S'inscrire");
}

QString dialogueInscriptionProprietaire::reqNom() const
{
    return widget.nomLineEdit->text();
}

QString dialogueInscriptionProprietaire::reqPrenom() const
{
    return widget.prenomLineEdit->text();
}

QString dialogueInscriptionProprietaire::reqVille() const
{
    return widget.villeLineEdit->text();
}
