/********************************************************************************
** Form generated from reading UI file 'dialogueInscriptionProprietaire.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUEINSCRIPTIONPROPRIETAIRE_H
#define UI_DIALOGUEINSCRIPTIONPROPRIETAIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogueInscriptionProprietaire
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nomLabel;
    QLabel *prenomLabel;
    QLabel *villeLabel;
    QLineEdit *nomLineEdit;
    QLineEdit *prenomLineEdit;
    QLineEdit *villeLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogueInscriptionProprietaire)
    {
        if (dialogueInscriptionProprietaire->objectName().isEmpty())
            dialogueInscriptionProprietaire->setObjectName(QString::fromUtf8("dialogueInscriptionProprietaire"));
        dialogueInscriptionProprietaire->resize(401, 213);
        dialogueInscriptionProprietaire->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: #dce3ec;\n"
"}"));
        verticalLayout = new QVBoxLayout(dialogueInscriptionProprietaire);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(30);
        nomLabel = new QLabel(dialogueInscriptionProprietaire);
        nomLabel->setObjectName(QString::fromUtf8("nomLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font.setBold(true);
        font.setWeight(75);
        nomLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, nomLabel);

        prenomLabel = new QLabel(dialogueInscriptionProprietaire);
        prenomLabel->setObjectName(QString::fromUtf8("prenomLabel"));
        prenomLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, prenomLabel);

        villeLabel = new QLabel(dialogueInscriptionProprietaire);
        villeLabel->setObjectName(QString::fromUtf8("villeLabel"));
        villeLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, villeLabel);

        nomLineEdit = new QLineEdit(dialogueInscriptionProprietaire);
        nomLineEdit->setObjectName(QString::fromUtf8("nomLineEdit"));
        nomLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nomLineEdit);

        prenomLineEdit = new QLineEdit(dialogueInscriptionProprietaire);
        prenomLineEdit->setObjectName(QString::fromUtf8("prenomLineEdit"));
        prenomLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, prenomLineEdit);

        villeLineEdit = new QLineEdit(dialogueInscriptionProprietaire);
        villeLineEdit->setObjectName(QString::fromUtf8("villeLineEdit"));
        villeLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, villeLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dialogueInscriptionProprietaire);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #F2F2F2;   /* Blanc-gris */\n"
"    color: #333333;\n"
"    border-radius: 8px;\n"
"    padding: 6px 14px;\n"
"    border: 1px solid #D0D0D0;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #E6E6E6;   /* Gris un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #D9D9D9;   /* Encore un peu plus fonc\303\251 */\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #E0E0E0;\n"
"    color: #A0A0A0;\n"
"    border: 1px solid #C8C8C8;\n"
"}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dialogueInscriptionProprietaire);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogueInscriptionProprietaire, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogueInscriptionProprietaire, SLOT(reject()));
        QObject::connect(nomLineEdit, SIGNAL(textChanged(QString)), dialogueInscriptionProprietaire, SLOT(mettreAJourBoutonOk()));
        QObject::connect(prenomLineEdit, SIGNAL(textChanged(QString)), dialogueInscriptionProprietaire, SLOT(mettreAJourBoutonOk()));
        QObject::connect(villeLineEdit, SIGNAL(textChanged(QString)), dialogueInscriptionProprietaire, SLOT(mettreAJourBoutonOk()));

        QMetaObject::connectSlotsByName(dialogueInscriptionProprietaire);
    } // setupUi

    void retranslateUi(QDialog *dialogueInscriptionProprietaire)
    {
        dialogueInscriptionProprietaire->setWindowTitle(QCoreApplication::translate("dialogueInscriptionProprietaire", "Inscription", nullptr));
        nomLabel->setText(QCoreApplication::translate("dialogueInscriptionProprietaire", "Nom :", nullptr));
        prenomLabel->setText(QCoreApplication::translate("dialogueInscriptionProprietaire", "Pr\303\251nom :", nullptr));
        villeLabel->setText(QCoreApplication::translate("dialogueInscriptionProprietaire", "Ville :", nullptr));
        nomLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueInscriptionProprietaire", "Entrez votre nom", nullptr));
        prenomLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueInscriptionProprietaire", "Entrez votre pr\303\251nom", nullptr));
        villeLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueInscriptionProprietaire", "Entrez votre ville de domicile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogueInscriptionProprietaire: public Ui_dialogueInscriptionProprietaire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUEINSCRIPTIONPROPRIETAIRE_H
