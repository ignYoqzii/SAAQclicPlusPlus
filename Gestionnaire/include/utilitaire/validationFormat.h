/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * @file:   validationFormat.h
 * @author: Yoan Lévesque
 *
 * Created on 5 février 2026, 15 h 07
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>
#include <array>
#include <sstream>
#include <iostream>

namespace saaq
{
    bool validerImmatriculationCamion(const std::string& p_immatriculation);
    bool validerImmatriculationPromenade(const std::string& p_immatriculation);
    bool validerNiv(const std::string& p_niv);
    bool validerFormatFichier(std::istream& p_is);
} // Fin du namespace saaq

#endif /* VALIDATIONFORMAT_H */
