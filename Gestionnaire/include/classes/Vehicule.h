/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/**
 * @file Vehicule.h
 * @brief Déclaration de la classe Vehicule
 * @author Yoan Lévesque
 * @date 2026-03-17
 */

#ifndef VEHICULE_H
#define VEHICULE_H

#include <string>
#include <memory>

namespace saaq
{
    /**
     * @class Vehicule
     * @brief Classe de base abstraite représentant un véhicule.
     */
    class Vehicule
    {
    public:
        Vehicule(const std::string& p_niv, const std::string& p_immatriculation);
        
        virtual ~Vehicule() {}
        
        const std::string& reqNIV() const;
        
        const std::string& reqImmatriculation() const;
        
        virtual std::string reqVehiculeFormate() const;
        
        bool operator==(const Vehicule& p_vehicule) const;
        
        virtual std::unique_ptr<Vehicule> clone() const = 0;
        
        virtual double calculerTarificationAnnuelle() const = 0;
    protected:
        virtual void asgImmatriculation(const std::string& p_immatriculation);
    private:
        std::string m_niv;
        std::string m_immatriculation;
        
        void verifierInvariant() const;
    };
} // Fin du namespace saaq

#endif /* VEHICULE_H */