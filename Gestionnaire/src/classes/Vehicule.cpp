/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/**
 * @file Vehicule.cpp
 * @brief Implémentation de la classe Vehicule
 * @author Yoan Lévesque
 * @date 2026-03-17
 */

#include "classes/Vehicule.h"
#include "contrat/ContratException.h"
#include "utilitaire/validationFormat.h"
#include <sstream>

using namespace saaq;
using std::string;

/**
 * @brief Constructeur avec paramètres.
 *
 * Initialise un objet Vehicule à partir d'un numéro d'identification du véhicule (NIV)
 * et d'un numéro d'immatriculation. Les valeurs fournies doivent être valides.
 *
 * @pre Le NIV fourni doit être valide.
 * @pre Le numéro d'immatriculation ne doit pas être une chaîne vide.
 *
 * @post Le NIV de l'objet correspond à celui fourni en paramètre.
 * @post Le numéro d'immatriculation de l'objet correspond à celui fourni en paramètre.
 *
 * @param[in] p_niv Le numéro d'identification du véhicule (NIV).
 * @param[in] p_immatriculation Le numéro d'immatriculation du véhicule.
 */
Vehicule::Vehicule(const string& p_niv, const string& p_immatriculation) : m_niv(p_niv), m_immatriculation(p_immatriculation)
{
    PRECONDITION(validerNiv(p_niv));
    PRECONDITION(!p_immatriculation.empty());
    
    POSTCONDITION(m_niv == p_niv);
    POSTCONDITION(m_immatriculation == p_immatriculation);
    
    INVARIANTS();
}

/**
 * @brief Accesseur du numéro d'identification du véhicule.
 *
 * @return Le NIV du véhicule.
 */
const string& Vehicule::reqNIV() const
{
    return m_niv;
}

/**
 * @brief Accesseur du numéro d'immatriculation du véhicule.
 *
 * @return Le numéro d'immatriculation du véhicule.
 */
const string& Vehicule::reqImmatriculation() const
{
    return m_immatriculation;
}

/**
 * @brief Retourne une représentation formatée du véhicule.
 *
 * @return Une chaîne contenant les informations formatées du véhicule.
 */
string Vehicule::reqVehiculeFormate() const
{
    std::ostringstream oss;
    oss << "Numéro d'identification : " << m_niv << "\n"
        << "Numéro d'immatriculation : " << m_immatriculation << "\n";
    return oss.str();
}

/**
 * @brief Opérateur d'égalité.
 *
 * Deux véhicules sont considérés égaux si leur NIV est identique.
 *
 * @param[in] p_vehicule Le véhicule à comparer.
 * @return true si les deux véhicules ont le même NIV, false sinon.
 */
bool Vehicule::operator==(const Vehicule& p_vehicule) const
{
    return m_niv == p_vehicule.m_niv;
}

/**
 * @brief Assigne un nouveau numéro d'immatriculation.
 *
 * Méthode protégée afin d'être utilisée uniquement par les classes dérivées.
 * 
 * @post L'immatriculation est bien assignée.
 *
 * @param[in] p_immatriculation Le nouveau numéro d'immatriculation.
 */
void Vehicule::asgImmatriculation(const string& p_immatriculation)
{
    m_immatriculation = p_immatriculation;
    POSTCONDITION(m_immatriculation == p_immatriculation);
    INVARIANTS();
}

/**
 * @brief Vérifie les invariants de la classe Vehicule.
 *
 * Cette méthode valide que le NIV est conforme et que le numéro
 * d'immatriculation n'est pas vide. Elle est appelée automatiquement
 * par les macros d'invariants.
 */
void Vehicule::verifierInvariant() const
{
    INVARIANT(validerNiv(m_niv));
    INVARIANT(!m_immatriculation.empty());
}