/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "exceptions/VehiculeAbsentException.h"

using namespace saaq;
using std::string;

/**
 * Constructeur de la classe d'exception VehiculeAbsentException qui appelle le constructeur
 * de la classe de base en passant la raison de l'erreur.
 * @param[out] p_raison
 */
VehiculeAbsentException::VehiculeAbsentException(const string& p_raison) : VehiculeException(p_raison) {}