/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/**
 * @file VehiculePromenade.h
 * @brief Déclaration de la classe VehiculeException.
 * @author Yoan Lévesque
 * @date 2026-04-13
 */

#ifndef VEHICULEEXCEPTION_H
#define VEHICULEEXCEPTION_H

#include <stdexcept>
#include <string>

namespace saaq
{
    /**
     * @class VehiculeException
     * @brief Exception spécialisée pour les erreurs liées aux véhicules.
     *
     * Cette classe représente une exception lancée lorsqu'une opération
     * concernant un véhicule immatriculé à la SAAQ échoue ou mène à une
     * situation invalide. Elle permet de fournir un message explicatif
     * décrivant la nature de l'erreur.
     */
    class VehiculeException : public std::runtime_error
    {
    public:
        VehiculeException(const std::string& p_raison);
    };
} // Fin du namespace saaq.

#endif /* VEHICULEEXCEPTION_H */

