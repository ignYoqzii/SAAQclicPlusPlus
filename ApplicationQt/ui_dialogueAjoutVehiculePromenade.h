/********************************************************************************
** Form generated from reading UI file 'dialogueAjoutVehiculePromenade.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUEAJOUTVEHICULEPROMENADE_H
#define UI_DIALOGUEAJOUTVEHICULEPROMENADE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogueAjoutVehiculePromenade
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nivLabel;
    QLabel *plaqueLabel;
    QLabel *placesLabel;
    QLineEdit *nivLineEdit;
    QLineEdit *plaqueLineEdit;
    QLineEdit *placesLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogueAjoutVehiculePromenade)
    {
        if (dialogueAjoutVehiculePromenade->objectName().isEmpty())
            dialogueAjoutVehiculePromenade->setObjectName(QString::fromUtf8("dialogueAjoutVehiculePromenade"));
        dialogueAjoutVehiculePromenade->resize(402, 170);
        dialogueAjoutVehiculePromenade->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: #dce3ec;\n"
"}"));
        verticalLayout = new QVBoxLayout(dialogueAjoutVehiculePromenade);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nivLabel = new QLabel(dialogueAjoutVehiculePromenade);
        nivLabel->setObjectName(QString::fromUtf8("nivLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font.setBold(true);
        font.setWeight(75);
        nivLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, nivLabel);

        plaqueLabel = new QLabel(dialogueAjoutVehiculePromenade);
        plaqueLabel->setObjectName(QString::fromUtf8("plaqueLabel"));
        plaqueLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, plaqueLabel);

        placesLabel = new QLabel(dialogueAjoutVehiculePromenade);
        placesLabel->setObjectName(QString::fromUtf8("placesLabel"));
        placesLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, placesLabel);

        nivLineEdit = new QLineEdit(dialogueAjoutVehiculePromenade);
        nivLineEdit->setObjectName(QString::fromUtf8("nivLineEdit"));
        nivLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nivLineEdit);

        plaqueLineEdit = new QLineEdit(dialogueAjoutVehiculePromenade);
        plaqueLineEdit->setObjectName(QString::fromUtf8("plaqueLineEdit"));
        plaqueLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, plaqueLineEdit);

        placesLineEdit = new QLineEdit(dialogueAjoutVehiculePromenade);
        placesLineEdit->setObjectName(QString::fromUtf8("placesLineEdit"));
        placesLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, placesLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dialogueAjoutVehiculePromenade);
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
"}\n"
""));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dialogueAjoutVehiculePromenade);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogueAjoutVehiculePromenade, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogueAjoutVehiculePromenade, SLOT(reject()));
        QObject::connect(nivLineEdit, SIGNAL(textChanged(QString)), dialogueAjoutVehiculePromenade, SLOT(mettreAJourBoutonOk()));
        QObject::connect(plaqueLineEdit, SIGNAL(textChanged(QString)), dialogueAjoutVehiculePromenade, SLOT(mettreAJourBoutonOk()));
        QObject::connect(placesLineEdit, SIGNAL(textChanged(QString)), dialogueAjoutVehiculePromenade, SLOT(mettreAJourBoutonOk()));

        QMetaObject::connectSlotsByName(dialogueAjoutVehiculePromenade);
    } // setupUi

    void retranslateUi(QDialog *dialogueAjoutVehiculePromenade)
    {
        dialogueAjoutVehiculePromenade->setWindowTitle(QCoreApplication::translate("dialogueAjoutVehiculePromenade", "Ajouter un v\303\251hicule de promenade", nullptr));
        nivLabel->setText(QCoreApplication::translate("dialogueAjoutVehiculePromenade", "NIV :", nullptr));
        plaqueLabel->setText(QCoreApplication::translate("dialogueAjoutVehiculePromenade", "Plaque :", nullptr));
        placesLabel->setText(QCoreApplication::translate("dialogueAjoutVehiculePromenade", "Places :", nullptr));
        nivLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueAjoutVehiculePromenade", "Entrez un NIV valide", nullptr));
        plaqueLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueAjoutVehiculePromenade", "Entrez un num\303\251ro de plaque valide", nullptr));
        placesLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueAjoutVehiculePromenade", "Entrez un nombre de places assises valide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogueAjoutVehiculePromenade: public Ui_dialogueAjoutVehiculePromenade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUEAJOUTVEHICULEPROMENADE_H
