/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/**
 * @file VehiculePromenade.cpp
 * @brief Implémentation de la classe VehiculePromenade
 * @author Yoan Lévesque
 * @date 2026-03-17
 */

#include "classes/VehiculePromenade.h"
#include "contrat/ContratException.h"
#include "utilitaire/validationFormat.h"
#include <iomanip>

using namespace saaq;
using std::string;

const double TARIF_PROMENADE_FIXE = 217.41;

/**
 * @brief Constructeur avec paramètres.
 *
 * Construit un objet VehiculePromenade à partir d'un NIV, d'un numéro
 * d'immatriculation et d'un nombre de places.
 *
 * @pre Le nombre de places doit être supérieur à 0 et ne pas dépasser 9.
 * @pre Le numéro d'immatriculation doit être valide pour un véhicule de promenade.
 *
 * @post Le nombre de places de l'objet correspond à celui fourni.
 * @post Le tarif de renouvellement est initialisé à la valeur fixe prévue.
 * @post La contribution au transport en commun est initialisée à 0.0.
 * @post La taxe locale est initialisée à 0.0.
 *
 * @param[in] p_niv Le numéro d'identification du véhicule (NIV).
 * @param[in] p_immatriculation Le numéro d'immatriculation du véhicule.
 * @param[in] p_nbPlaces Le nombre de places assises dans le véhicule.
 */
VehiculePromenade::VehiculePromenade(const string& p_niv,
        const string& p_immatriculation,
        int p_nbPlaces) : Vehicule(p_niv, p_immatriculation),
        m_nbPlaces(p_nbPlaces),
        m_tarifRenouvellementImmatriculation(TARIF_PROMENADE_FIXE),
        m_contributionTransportEnCommun(0.0),
        m_taxeLocale(0.0)
{
    PRECONDITION(p_nbPlaces > 0 && p_nbPlaces <= 9);
    PRECONDITION(validerImmatriculationPromenade(p_immatriculation));
    
    POSTCONDITION(m_nbPlaces == p_nbPlaces);
    POSTCONDITION(m_tarifRenouvellementImmatriculation == TARIF_PROMENADE_FIXE);
    POSTCONDITION(m_contributionTransportEnCommun == 0.0);
    POSTCONDITION(m_taxeLocale == 0.0);

    INVARIANTS();
}

/**
 * @brief Accesseur du nombre de places.
 *
 * @return Le nombre de places assises du véhicule.
 */
int VehiculePromenade::reqNbPlaces() const
{
    return m_nbPlaces;
}

/**
 * @brief Accesseur du tarif de renouvellement d'immatriculation.
 *
 * @return Le tarif de renouvellement d'immatriculation.
 */
double VehiculePromenade::reqTarifRenouvellementImmatriculation() const
{
    return m_tarifRenouvellementImmatriculation;
}

/**
 * @brief Accesseur de la contribution au transport en commun.
 *
 * @return Le montant de la contribution au transport en commun.
 */
double VehiculePromenade::reqContributionTransportEnCommun() const
{
    return m_contributionTransportEnCommun;
}

/**
 * @brief Accesseur de la taxe locale.
 *
 * @return Le montant de la taxe locale.
 */
double VehiculePromenade::reqTaxeLocale() const
{
    return m_taxeLocale;
}

/**
 * @brief Assigne une nouvelle contribution au transport en commun.
 *
 * Le montant doit être positif ou nul. En cas de valeur invalide,
 * une erreur de contrat doit être générée.
 *
 * @pre p_contribution >= 0
 * @post m_contributionTransportEnCommun == p_contribution
 *
 * @param[in] p_contribution Le nouveau montant.
 */
void VehiculePromenade::asgContributionTransportEnCommun(double p_contribution)
{
    PRECONDITION(p_contribution >= 0);
    m_contributionTransportEnCommun = p_contribution;
    POSTCONDITION(m_contributionTransportEnCommun == p_contribution);
    INVARIANTS();
}

/**
 * @brief Assigne une nouvelle taxe locale.
 *
 * Le montant doit être positif ou nul. En cas de valeur invalide,
 * une erreur de contrat doit être générée.
 *
 * @pre p_taxe >= 0
 * @post m_taxeLocale == p_taxe
 *
 * @param[in] p_taxe Le nouveau montant.
 */
void VehiculePromenade::asgTaxeLocale(double p_taxe)
{
    PRECONDITION(p_taxe >= 0);
    m_taxeLocale = p_taxe;
    POSTCONDITION(m_taxeLocale == p_taxe);
    INVARIANTS();
}

/**
 * @brief Assigne un nouveau numéro d'immatriculation.
 *
 * Redéfinition de la méthode protégée de la classe de base afin
 * d'appliquer les règles spécifiques aux véhicules de promenade.
 *
 * @pre validerImmatriculationPromenade(p_immatriculation) == true
 * @post reqImmatriculation() == p_immatriculation
 *
 * @param[in] p_immatriculation Le nouveau numéro d'immatriculation.
 */
void VehiculePromenade::asgImmatriculation(const string& p_immatriculation)
{
    PRECONDITION(validerImmatriculationPromenade(p_immatriculation));
    Vehicule::asgImmatriculation(p_immatriculation);
    POSTCONDITION(Vehicule::reqImmatriculation() == p_immatriculation);
    INVARIANTS();
}

/**
 * @brief Calcule la tarification annuelle du véhicule de promenade.
 *
 * La tarification est composée de plusieurs éléments :
 * - Tarif de renouvellement d'immatriculation
 * - Contribution au transport en commun
 * - Taxe locale
 *
 * Cette méthode redéfinit la méthode virtuelle pure de la classe de base.
 *
 * @return La tarification annuelle totale.
 */
double VehiculePromenade::calculerTarificationAnnuelle() const
{
    return m_tarifRenouvellementImmatriculation +
           m_contributionTransportEnCommun +
           m_taxeLocale;
    
    INVARIANTS();
}

/**
 * @brief Clone polymorphique du véhicule de promenade.
 *
 * Permet de copier un véhicule de promenade sans connaître son type concret.
 *
 * @return Un pointeur intelligent vers une copie du véhicule.
 */
std::unique_ptr<Vehicule> VehiculePromenade::clone() const
{
    return std::make_unique<VehiculePromenade>(*this);
}

/**
 * @brief Retourne une représentation formatée du véhicule de promenade.
 *
 * Cette méthode redéfinit celle de la classe de base afin d'inclure
 * les informations propres aux véhicules de promenade.
 *
 * @return Une chaîne contenant les informations formatées.
 */
std::string VehiculePromenade::reqVehiculeFormate() const
{
    std::ostringstream oss;
    oss << "Véhicule de promenade\n"
        << Vehicule::reqVehiculeFormate()
        << "Nombre de places : " << m_nbPlaces << "\n"
        << "Paiement : "
        << std::fixed << std::setprecision(2)
        << calculerTarificationAnnuelle() << "$\n";
    return oss.str();
}

/**
 * @brief Vérifie les invariants de la classe VehiculePromenade.
 *
 * Cette méthode s'assure que le nombre de places, les montants
 * financiers et l'immatriculation respectent les règles définies
 * pour un véhicule de promenade.
 */
void VehiculePromenade::verifierInvariant() const
{
    INVARIANT(m_nbPlaces > 0 && m_nbPlaces <= 9);
    INVARIANT(m_tarifRenouvellementImmatriculation == TARIF_PROMENADE_FIXE);
    INVARIANT(m_contributionTransportEnCommun >= 0);
    INVARIANT(m_taxeLocale >= 0);
    INVARIANT(validerImmatriculationPromenade(reqImmatriculation()));
}
