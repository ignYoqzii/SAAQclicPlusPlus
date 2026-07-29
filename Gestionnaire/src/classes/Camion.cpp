/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/**
 * @file Camion.cpp
 * @brief Implémentation de la classe Camion
 * @author Yoan Lévesque
 * @date 2026-03-17
 */

#include "classes/Camion.h"
#include "contrat/ContratException.h"
#include "utilitaire/validationFormat.h"
#include <iomanip>

using namespace saaq;
using std::string;

const double TARIF_2ESSIEUX_3001_4000 = 673.69;
const double TARIF_2ESSIEUX_4001_PLUS = 1067.69;
const double TARIF_3ESSIEUX = 1871.57;
const double TARIF_4ESSIEUX = 2626.57;
const double TARIF_5ESSIEUX = 3320.07;
const double TARIF_6ESSIEUX_PLUS = 4391.07;

/**
 * @brief Constructeur avec paramètres.
 *
 * Construit un objet Camion à partir d'un NIV, d'un numéro
 * d'immatriculation, d'un poids nominal et d'un nombre d'essieux.
 *
 * @pre Le poids nominal doit être supérieur à 3000 kilogrammes.
 * @pre Le camion doit posséder au moins deux essieux.
 * @pre Le numéro d'immatriculation doit être valide pour un camion.
 *
 * @post Le poids nominal de l'objet correspond à celui fourni.
 * @post Le nombre d'essieux de l'objet correspond à celui fourni.
 *
 * @param[in] p_niv Le numéro d'identification du véhicule (NIV).
 * @param[in] p_immatriculation Le numéro d'immatriculation du camion.
 * @param[in] p_poids Le poids nominal du camion en kilogrammes.
 * @param[in] p_nbEssieux Le nombre d'essieux du camion.
 */
Camion::Camion(const string& p_niv,
        const string& p_immatriculation,
        int p_poids, int p_nbEssieux) : Vehicule(p_niv, p_immatriculation),
        m_poids(p_poids), m_nbEssieux(p_nbEssieux)
{
    PRECONDITION(p_poids > 3000);
    PRECONDITION(p_nbEssieux >= 2);
    PRECONDITION(validerImmatriculationCamion(p_immatriculation));
    
    POSTCONDITION(m_poids == p_poids)
    POSTCONDITION(m_nbEssieux == p_nbEssieux)
    
    INVARIANTS();
}

/**
 * @brief Accesseur du poids nominal du camion.
 *
 * @return Le poids du camion en kilogrammes.
 */
int Camion::reqPoids() const
{
    return m_poids;
}

/**
 * @brief Accesseur du nombre d'essieux.
 *
 * @return Le nombre d'essieux du camion.
 */
int Camion::reqNbEssieux() const
{
    return m_nbEssieux;
}

/**
 * @brief Assigne un nouveau numéro d'immatriculation.
 *
 * Redéfinition de la méthode protégée de la classe de base afin
 * d'appliquer les règles spécifiques aux camions.
 *
 * @pre validerImmatriculationCamion(p_immatriculation) == true
 * @post reqImmatriculation() == p_immatriculation
 *
 * @param[in] p_immatriculation Le nouveau numéro d'immatriculation.
 */
void Camion::asgImmatriculation(const string& p_immatriculation)
{
    PRECONDITION(validerImmatriculationCamion(p_immatriculation));
    Vehicule::asgImmatriculation(p_immatriculation);
    POSTCONDITION(Vehicule::reqImmatriculation() == p_immatriculation);
    INVARIANTS();
}

/**
 * @brief Clone polymorphique du camion.
 *
 * Permet de copier un camion sans connaître son type concret.
 *
 * @return Un pointeur intelligent vers une copie du camion.
 */
std::unique_ptr<Vehicule> Camion::clone() const
{
    return std::make_unique<Camion>(*this);
}

/**
 * @brief Calcule la tarification annuelle du camion.
 *
 * La tarification dépend du poids et du nombre d'essieux, selon les
 * règles établies par la SAAQ. Cette méthode redéfinit la méthode
 * virtuelle pure de la classe de base.
 *
 * @pre m_nbEssieux >= 2
 * @pre m_poids > 3000
 *
 * @return La tarification annuelle du camion.
 */
double Camion::calculerTarificationAnnuelle() const
{
    PRECONDITION(m_nbEssieux >= 2);
    PRECONDITION(m_poids > 3000);
    
    if (m_nbEssieux == 2)
    {
        return (m_poids <= 4000) ? TARIF_2ESSIEUX_3001_4000 : TARIF_2ESSIEUX_4001_PLUS;
    }
    
    switch (m_nbEssieux)
    {
        case 3: return TARIF_3ESSIEUX;
        case 4: return TARIF_4ESSIEUX;
        case 5: return TARIF_5ESSIEUX;
        default: return TARIF_6ESSIEUX_PLUS;
    }
}

/**
 * @brief Retourne une représentation formatée du camion.
 *
 * Cette méthode redéfinit celle de la classe de base afin d'inclure
 * les informations propres aux camions (poids et essieux).
 *
 * @return Une chaîne contenant les informations formatées du camion.
 */
string Camion::reqVehiculeFormate() const
{
    std::ostringstream oss;
    oss << "Camion\n"
        << Vehicule::reqVehiculeFormate()
        << "Nombre d'essieux : " << m_nbEssieux << "\n"
        << "Poids : " << m_poids << "\n"
        << "Paiement : "
        << std::fixed << std::setprecision(2)
        << calculerTarificationAnnuelle() << "$\n";
    return oss.str();
}

/**
 * @brief Vérifie les invariants de la classe Camion.
 *
 * Cette méthode s'assure que le poids, le nombre d'essieux et
 * l'immatriculation du camion respectent les règles définies.
 */
void Camion::verifierInvariant() const
{
    INVARIANT(m_poids > 3000);
    INVARIANT(m_nbEssieux >= 2);
    INVARIANT(validerImmatriculationCamion(reqImmatriculation()));
}
