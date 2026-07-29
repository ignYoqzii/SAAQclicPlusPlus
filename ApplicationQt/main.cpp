/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/qtFiles/main.cc to edit this template
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 13 avril 2026, 20 h 12
 */

#include "fenetrePrincipale.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    fenetrePrincipale fenetre;
    fenetre.show();
    return app.exec();
}
