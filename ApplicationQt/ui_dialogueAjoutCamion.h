/********************************************************************************
** Form generated from reading UI file 'dialogueAjoutCamion.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUEAJOUTCAMION_H
#define UI_DIALOGUEAJOUTCAMION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogueAjoutCamion
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nivLabel;
    QLabel *plaqueLabel;
    QLabel *poidsLabel;
    QLabel *essieuxLabel;
    QLineEdit *nivLineEdit;
    QLineEdit *plaqueLineEdit;
    QLineEdit *poidsLineEdit;
    QLineEdit *essieuxLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogueAjoutCamion)
    {
        if (dialogueAjoutCamion->objectName().isEmpty())
            dialogueAjoutCamion->setObjectName(QString::fromUtf8("dialogueAjoutCamion"));
        dialogueAjoutCamion->resize(366, 208);
        dialogueAjoutCamion->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: #dce3ec;\n"
"}"));
        verticalLayout = new QVBoxLayout(dialogueAjoutCamion);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nivLabel = new QLabel(dialogueAjoutCamion);
        nivLabel->setObjectName(QString::fromUtf8("nivLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font.setBold(true);
        font.setWeight(75);
        nivLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, nivLabel);

        plaqueLabel = new QLabel(dialogueAjoutCamion);
        plaqueLabel->setObjectName(QString::fromUtf8("plaqueLabel"));
        plaqueLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, plaqueLabel);

        poidsLabel = new QLabel(dialogueAjoutCamion);
        poidsLabel->setObjectName(QString::fromUtf8("poidsLabel"));
        poidsLabel->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, poidsLabel);

        essieuxLabel = new QLabel(dialogueAjoutCamion);
        essieuxLabel->setObjectName(QString::fromUtf8("essieuxLabel"));
        essieuxLabel->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, essieuxLabel);

        nivLineEdit = new QLineEdit(dialogueAjoutCamion);
        nivLineEdit->setObjectName(QString::fromUtf8("nivLineEdit"));
        nivLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nivLineEdit);

        plaqueLineEdit = new QLineEdit(dialogueAjoutCamion);
        plaqueLineEdit->setObjectName(QString::fromUtf8("plaqueLineEdit"));
        plaqueLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::FieldRole, plaqueLineEdit);

        poidsLineEdit = new QLineEdit(dialogueAjoutCamion);
        poidsLineEdit->setObjectName(QString::fromUtf8("poidsLineEdit"));
        poidsLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::FieldRole, poidsLineEdit);

        essieuxLineEdit = new QLineEdit(dialogueAjoutCamion);
        essieuxLineEdit->setObjectName(QString::fromUtf8("essieuxLineEdit"));
        essieuxLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(3, QFormLayout::FieldRole, essieuxLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dialogueAjoutCamion);
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


        retranslateUi(dialogueAjoutCamion);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogueAjoutCamion, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogueAjoutCamion, SLOT(reject()));
        QObject::connect(nivLineEdit, SIGNAL(textChanged(QString)), dialogueAjoutCamion, SLOT(mettreAJourBoutonOk()));
        QObject::connect(plaqueLineEdit, SIGNAL(textChanged(QString)), dialogueAjoutCamion, SLOT(mettreAJourBoutonOk()));
        QObject::connect(poidsLineEdit, SIGNAL(textChanged(QString)), dialogueAjoutCamion, SLOT(mettreAJourBoutonOk()));
        QObject::connect(essieuxLineEdit, SIGNAL(textChanged(QString)), dialogueAjoutCamion, SLOT(mettreAJourBoutonOk()));

        QMetaObject::connectSlotsByName(dialogueAjoutCamion);
    } // setupUi

    void retranslateUi(QDialog *dialogueAjoutCamion)
    {
        dialogueAjoutCamion->setWindowTitle(QCoreApplication::translate("dialogueAjoutCamion", "Ajouter un camion", nullptr));
        nivLabel->setText(QCoreApplication::translate("dialogueAjoutCamion", "NIV :", nullptr));
        plaqueLabel->setText(QCoreApplication::translate("dialogueAjoutCamion", "Plaque :", nullptr));
        poidsLabel->setText(QCoreApplication::translate("dialogueAjoutCamion", "Poids :", nullptr));
        essieuxLabel->setText(QCoreApplication::translate("dialogueAjoutCamion", "Essieux :", nullptr));
        nivLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueAjoutCamion", "Entrez un NIV valide", nullptr));
        plaqueLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueAjoutCamion", "Entrez un num\303\251ro de plaque valide", nullptr));
        poidsLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueAjoutCamion", "Entrez un poids valide", nullptr));
        essieuxLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueAjoutCamion", "Entrez un nombre d'essieux valide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogueAjoutCamion: public Ui_dialogueAjoutCamion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUEAJOUTCAMION_H
