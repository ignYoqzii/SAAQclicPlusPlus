/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/**
 * @file VehiculePromenade.h
 * @brief Déclaration de la classe VehiculeDejaPresentException.
 * @author Yoan Lévesque
 * @date 2026-04-13
 */

#ifndef VEHICULEDEJAPRESENTEXCEPTION_H
#define VEHICULEDEJAPRESENTEXCEPTION_H

#include "VehiculeException.h"

namespace saaq
{
    /**
     * @class VehiculeDejaPresentException
     * @brief Exception indiquant qu'un véhicule est déjà présent.
     *
     * Cette exception spécialisée est utilisée pour signaler qu'un véhicule
     * que l'on tente d'ajouter au vecteur est déjà enregistré.
     * Elle hérite de VehiculeException et permet de fournir un message
     * explicatif décrivant la nature de l'erreur.
     */
    class VehiculeDejaPresentException : public VehiculeException
    {
    public:
        VehiculeDejaPresentException(const std::string& p_raison);
    };
} // Fin du namespace saaq.

#endif /* VEHICULEDEJAPRESENTEXCEPTION_H */

