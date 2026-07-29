# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/GNU-Linux
TARGET = ApplicationQt
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += dialogueAjoutCamion.cpp dialogueAjoutVehiculePromenade.cpp dialogueInscriptionProprietaire.cpp dialogueSuppressionVehicule.cpp fenetrePrincipale.cpp main.cpp
HEADERS += dialogueAjoutCamion.h dialogueAjoutVehiculePromenade.h dialogueInscriptionProprietaire.h dialogueSuppressionVehicule.h fenetrePrincipale.h
FORMS += dialogueAjoutCamion.ui dialogueAjoutVehiculePromenade.ui dialogueInscriptionProprietaire.ui dialogueSuppressionVehicule.ui fenetrePrincipale.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/GNU-Linux
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += ../Gestionnaire/include 
LIBS += ../Gestionnaire/dist/Release/GNU-Linux/libgestionnaire.a  
