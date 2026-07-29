/********************************************************************************
** Form generated from reading UI file 'dialogueSuppressionVehicule.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUESUPPRESSIONVEHICULE_H
#define UI_DIALOGUESUPPRESSIONVEHICULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogueSuppressionVehicule
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *nivLabel;
    QLineEdit *nivLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogueSuppressionVehicule)
    {
        if (dialogueSuppressionVehicule->objectName().isEmpty())
            dialogueSuppressionVehicule->setObjectName(QString::fromUtf8("dialogueSuppressionVehicule"));
        dialogueSuppressionVehicule->resize(416, 109);
        dialogueSuppressionVehicule->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: #dce3ec;\n"
"}"));
        verticalLayout = new QVBoxLayout(dialogueSuppressionVehicule);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 9);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        nivLabel = new QLabel(dialogueSuppressionVehicule);
        nivLabel->setObjectName(QString::fromUtf8("nivLabel"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Sans Mono"));
        font.setBold(true);
        font.setWeight(75);
        nivLabel->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, nivLabel);

        nivLineEdit = new QLineEdit(dialogueSuppressionVehicule);
        nivLineEdit->setObjectName(QString::fromUtf8("nivLineEdit"));
        nivLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #f6f8fa;\n"
"    border: 1px solid #BBBBBB;\n"
"    border-radius: 10px;\n"
"    padding: 6px 10px;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nivLineEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(dialogueSuppressionVehicule);
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


        retranslateUi(dialogueSuppressionVehicule);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialogueSuppressionVehicule, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialogueSuppressionVehicule, SLOT(reject()));
        QObject::connect(nivLineEdit, SIGNAL(textChanged(QString)), dialogueSuppressionVehicule, SLOT(mettreAJourBoutonOk()));

        QMetaObject::connectSlotsByName(dialogueSuppressionVehicule);
    } // setupUi

    void retranslateUi(QDialog *dialogueSuppressionVehicule)
    {
        dialogueSuppressionVehicule->setWindowTitle(QCoreApplication::translate("dialogueSuppressionVehicule", "Supression d'un v\303\251hicule", nullptr));
        nivLabel->setText(QCoreApplication::translate("dialogueSuppressionVehicule", "NIV du v\303\251hicule \303\240 retirer :", nullptr));
        nivLineEdit->setPlaceholderText(QCoreApplication::translate("dialogueSuppressionVehicule", "Entrez un NIV valide", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogueSuppressionVehicule: public Ui_dialogueSuppressionVehicule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUESUPPRESSIONVEHICULE_H
