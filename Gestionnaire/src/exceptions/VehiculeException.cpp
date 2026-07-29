/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "exceptions/VehiculeException.h"

using namespace saaq;
using std::string;

/**
 * Constructeur de la classe d'exception VehiculeException qui appelle le constructeur
 * de la classe de base en passant la raison de l'erreur.
 * @param[out] p_raison
 */
VehiculeException::VehiculeException(const string& p_raison) : std::runtime_error(p_raison) {}

