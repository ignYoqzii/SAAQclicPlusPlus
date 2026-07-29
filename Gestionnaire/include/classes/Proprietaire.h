/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/**
 * @file Proprietaire.h
 * @brief Déclaration de la classe Proprietaire
 * @author Yoan Lévesque
 * @date 2026-03-17
 */

#ifndef PROPRIETAIRE_H
#define PROPRIETAIRE_H

#include "Vehicule.h"
#include <string>
#include <memory>
#include <vector>

namespace saaq
{
    /**
     * @class Proprietaire
     * @brief Classe représentant un propriétaire de véhicules immatriculés à la SAAQ.
     * 
     * La classe Proprietaire regroupe les informations personnelles d'un
     * propriétaire ainsi que la liste des véhicules qu'il possède. Chaque
     * véhicule est stocké sous forme de copie polymorphique afin de préserver
     * l'intégrité du système et d'éviter les effets de bord.
     */
    class Proprietaire
    {
    public:
        Proprietaire(const std::string& p_nom, const std::string& p_prenom, const std::string& p_villeDomicile);
        
        const std::string& reqNom() const;
        
        const std::string& reqPrenom() const;
        
        const std::string& reqVilleDomicile() const;
        
        double reqPaiementTotal() const;
        
        const std::vector<std::unique_ptr<Vehicule>>& reqVecteurVehicules() const;
        
        int reqNbVehicules() const;
        
        std::string reqProprietaireFormate() const;
        
        void ajouterVehicule(const Vehicule& p_nouveauVehicule);
        
        void supprimerVehicule(const std::string& p_niv);
        
        // Constructeur copie de Coplien
        Proprietaire(const Proprietaire& p_proprietaire);
        
        // Opérateur d'assignation de Coplien
        Proprietaire& operator=(const Proprietaire& p_proprietaire);
    private:
        std::string m_nom;
        std::string m_prenom;
        std::string m_villeDomicile;
        double m_paiementTotal;
        
        std::vector<std::unique_ptr<Vehicule>> m_vehicules;
        
        bool VehiculeEstDejaPresent(const std::string& p_niv) const;
        
        void verifierInvariant() const;
    };
} // Fin du namespace saaq

#endif /* PROPRIETAIRE_H */

