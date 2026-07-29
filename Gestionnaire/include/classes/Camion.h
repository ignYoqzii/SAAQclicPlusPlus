/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/**
 * @file Camion.h
 * @brief Déclaration de la classe Camion
 * @author Yoan Lévesque
 * @date 2026-03-17
 */

#ifndef CAMION_H
#define CAMION_H

#include "Vehicule.h"

namespace saaq
{
    /**
     * @class Camion
     * @brief Classe représentant un camion immatriculé à la SAAQ.
     * 
     * La classe Camion dérive de Vehicule et ajoute des attributs propres aux
     * véhicules lourds, notamment le poids nominal et le nombre d'essieux.
     * Ces informations influencent directement la tarification annuelle.
     */
    class Camion : public Vehicule
    {
    public:
        Camion(const std::string& p_niv, const std::string& p_immatriculation, int p_poids, int p_nbEssieux);
        
        int reqPoids() const;
        
        int reqNbEssieux() const;
        
        std::string reqVehiculeFormate() const override;
        
        double calculerTarificationAnnuelle() const override;
        
        std::unique_ptr<Vehicule> clone() const override;
        
        void asgImmatriculation(const std::string& p_immatriculation) override;
    private:
        int m_poids;
        int m_nbEssieux;
        
        void verifierInvariant() const;
    };
} // Fin du namespace saaq

#endif /* CAMION_H */

