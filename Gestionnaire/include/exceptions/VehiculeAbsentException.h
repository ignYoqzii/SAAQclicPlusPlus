/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/**
 * @file VehiculePromenade.h
 * @brief Déclaration de la classe VehiculeAbsentException.
 * @author Yoan Lévesque
 * @date 2026-04-13
 */

#ifndef VEHICULEABSENTEXCEPTION_H
#define VEHICULEABSENTEXCEPTION_H

#include "VehiculeException.h"

namespace saaq
{
    /**
     * @class VehiculeAbsentException
     * @brief Exception indiquant qu'un véhicule est absent.
     *
     * Cette exception spécialisée est utilisée lorsqu'une opération échoue
     * parce que le véhicule ciblé n'existe pas dans le vecteur. Elle hérite
     * de VehiculeException et permet de fournir un message explicatif
     * décrivant la nature de l'erreur.
     */
    class VehiculeAbsentException : public VehiculeException
    {
    public:
        VehiculeAbsentException(const std::string& p_raison);
    };
} // Fin du namespace saaq.

#endif /* VEHICULEABSENTEXCEPTION_H */

