/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/**
 * @file VehiculePromenade.h
 * @brief Déclaration de la classe VehiculePromenade
 * @author Yoan Lévesque
 * @date 2026-03-17
 */

#ifndef VEHICULEPROMENADE_H
#define VEHICULEPROMENADE_H

#include "Vehicule.h"

namespace saaq
{
    /**
     * @class VehiculePromenade
     * @brief Classe représentant un véhicule de promenade immatriculé à la SAAQ.
     * 
     * Cette classe dérive de Vehicule et ajoute des attributs propres aux
     * véhicules de promenade, notamment le nombre de places ainsi que les
     * différentes composantes tarifaires associées au renouvellement
     * d'immatriculation.
     */
    class VehiculePromenade : public Vehicule
    {
    public:
        VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, int p_nbPlaces);
        
        int reqNbPlaces() const;
        
        double reqTarifRenouvellementImmatriculation() const;
        
        double reqContributionTransportEnCommun() const;
        
        double reqTaxeLocale() const;
        
        std::string reqVehiculeFormate() const override;
        
        void asgContributionTransportEnCommun(double p_contributionTransportEnCommun);
        
        void asgTaxeLocale(double p_taxeLocale);
        
        double calculerTarificationAnnuelle() const override;
        
        std::unique_ptr<Vehicule> clone() const override;
        
        void asgImmatriculation(const std::string& p_immatriculation) override;
    private:
        int m_nbPlaces;
        double m_tarifRenouvellementImmatriculation;
        double m_contributionTransportEnCommun;
        double m_taxeLocale;
        
        void verifierInvariant() const;
    };
} // Fin du namespace saaq

#endif /* VEHICULEPROMENADE_H */

