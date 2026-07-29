/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/**
 * @file Proprietaire.cpp
 * @brief Implémentation de la classe Proprietaire
 * @author Étudiant
 * \date 2026-03-31
 */

#include "classes/Proprietaire.h"
#include "contrat/ContratException.h"
#include "exceptions/VehiculeAbsentException.h"
#include "exceptions/VehiculeDejaPresentException.h"
#include "utilitaire/validationFormat.h"
#include <iomanip>
#include <algorithm>

using namespace saaq;
using std::string;

/**
 * @brief Constructeur avec paramètres.
 *
 * Construit un objet Proprietaire à partir d'un nom, d'un prénom et
 * d'une ville de domicile.
 *
 * @pre Le nom ne doit pas être une chaîne vide.
 * @pre Le prénom ne doit pas être une chaîne vide.
 * @pre La ville de domicile ne doit pas être une chaîne vide.
 *
 * @post Le nom de l'objet correspond à celui fourni.
 * @post Le prénom de l'objet correspond à celui fourni.
 * @post La ville de domicile de l'objet correspond à celle fournie.
 * @post Le paiement total est initialisé à 0.00.
 * @post La liste des véhicules est initialement vide.
 *
 * @param[in] p_nom Le nom du propriétaire.
 * @param[in] p_prenom Le prénom du propriétaire.
 * @param[in] p_villeDomicile La ville de domicile du propriétaire.
 */
Proprietaire::Proprietaire(const string& p_nom, const string& p_prenom,
        const string& p_villeDomicile) : m_nom(p_nom), m_prenom(p_prenom),
        m_villeDomicile(p_villeDomicile),
        m_paiementTotal(0.00)
{
    PRECONDITION(!p_nom.empty());
    PRECONDITION(!p_prenom.empty());
    PRECONDITION(!p_villeDomicile.empty());

    POSTCONDITION(m_nom == p_nom);
    POSTCONDITION(m_prenom == p_prenom);
    POSTCONDITION(m_villeDomicile == p_villeDomicile);
    POSTCONDITION(m_paiementTotal == 0.00);
    POSTCONDITION(m_vehicules.empty());

    INVARIANTS();
}

/**
 * @brief Constructeur copie de Coplien.
 * 
 * @param[in] p_proprietaire Le propriétaire à copier.
 */
Proprietaire::Proprietaire(const Proprietaire& p_proprietaire) :
        m_nom(p_proprietaire.m_nom), m_prenom(p_proprietaire.m_prenom),
        m_villeDomicile(p_proprietaire.m_villeDomicile),
        m_paiementTotal(p_proprietaire.m_paiementTotal)
{
    for (const auto& vehicule : p_proprietaire.m_vehicules)
    {
        m_vehicules.push_back(vehicule->clone());
    }
}

/**
 * @brief Accesseur du nom du propriétaire.
 *
 * @return Le nom du propriétaire.
 */
const string& Proprietaire::reqNom() const
{
    return m_nom;
}

/**
 * @brief Accesseur du prénom du propriétaire.
 *
 * @return Le prénom du propriétaire.
 */
const string& Proprietaire::reqPrenom() const
{
    return m_prenom;
}

/**
 * @brief Accesseur de la ville de domicile.
 *
 * @return La ville de domicile du propriétaire.
 */
const string& Proprietaire::reqVilleDomicile() const
{
    return m_villeDomicile;
}

/**
 * @brief Accesseur du paiement total.
 *
 * @return Le paiement total.
 */
double Proprietaire::reqPaiementTotal() const
{
    return m_paiementTotal;
}

/**
 * @brief Accesseur du vecteur de véhicules.
 *
 * @return Le vecteur contenant des véhicules.
 */
const std::vector<std::unique_ptr<Vehicule>>& Proprietaire::reqVecteurVehicules() const
{
    return m_vehicules;
}

/**
 * @brief Retourne le nombre de véhicules enregistrés au propriétaire.
 *
 * @return Le nombre de véhicules.
 */
int Proprietaire::reqNbVehicules() const
{
    return static_cast<int>(m_vehicules.size());
}

/**
 * @brief Ajoute un véhicule au propriétaire.
 *
 * Le véhicule est ajouté sous forme de copie polymorphique via la
 * méthode clone() de la classe Vehicule.
 * 
 * Conditions initiales :
 * - nbVehiculesAvant
 * - paiementTotalAvant
 *
 * @post reqNbVehicules() == nbVehiculesAvant + 1
 * @post m_paiementTotal == paiementTotalAvant +
 *       p_nouveauVehicule.calculerTarificationAnnuelle()
 *
 * @param[in] p_nouveauVehicule Le véhicule à ajouter.
 */
void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule)
{
    if (VehiculeEstDejaPresent(p_nouveauVehicule.reqNIV()))
    {
        throw VehiculeDejaPresentException(
                "Le véhicule avec le NIV " +
                p_nouveauVehicule.reqNIV() +
                " est déjà présent dans le dossier."
                );
    }
    
    CONDITION_INITIALE(int nbVehiculesAvant = reqNbVehicules());
    CONDITION_INITIALE(double paiementTotalAvant = m_paiementTotal);
    m_vehicules.push_back(p_nouveauVehicule.clone());
    m_paiementTotal += p_nouveauVehicule.calculerTarificationAnnuelle();
    POSTCONDITION(reqNbVehicules() == nbVehiculesAvant + 1);
    POSTCONDITION(m_paiementTotal == paiementTotalAvant +
            p_nouveauVehicule.calculerTarificationAnnuelle());
    INVARIANTS();
}

/**
 * @brief Supprime un véhicule du propriétaire à partir de son NIV.
 *
 * Cette méthode recherche dans la collection interne un véhicule dont le
 * numéro d'identification (NIV) correspond à celui fourni. Si le véhicule
 * est trouvé, il est retiré de la liste et le montant total des paiements
 * annuels du propriétaire est ajusté en conséquence.
 *
 * Si aucun véhicule ne correspond au NIV fourni, une exception de type
 * VehiculeAbsentException est lancée.
 *
 * @pre Le NIV doit être valide.
 *
 * @post Le véhicule correspondant au NIV ne doit plus être présent.
 * @post Le nombre total de véhicules doit avoir diminué de un.
 * @post Le montant total des paiements doit être ajusté correctement.
 * 
 * @param[in] p_niv Le numéro d'identification du véhicule à supprimer.
 */
void Proprietaire::supprimerVehicule(const string& p_niv)
{
    PRECONDITION(validerNiv(p_niv));
    CONDITION_INITIALE(int nbVehiculesAvant = reqNbVehicules());
    CONDITION_INITIALE(double paiementTotalAvant = m_paiementTotal);
    auto iter = std::find_if(
            m_vehicules.begin(),
            m_vehicules.end(),
            [&](const auto& vehicule) { return vehicule->reqNIV() == p_niv; }
            );
    if (iter == m_vehicules.end()) {
        throw VehiculeAbsentException(
                "Le propriétaire n'a pas de véhicule avec ce NIV : " + p_niv + "."
                );
    }
    double montantARetirer = (*iter)->calculerTarificationAnnuelle();
    m_vehicules.erase(iter);
    m_paiementTotal -= montantARetirer;
    POSTCONDITION(!VehiculeEstDejaPresent(p_niv));
    POSTCONDITION(reqNbVehicules() == nbVehiculesAvant - 1);
    POSTCONDITION(m_paiementTotal == paiementTotalAvant - montantARetirer);
    INVARIANTS();
}

/**
 * @brief Retourne une représentation formatée du propriétaire.
 *
 * Cette représentation inclut les informations personnelles du
 * propriétaire ainsi que la liste formatée de tous ses véhicules.
 *
 * @return Une chaîne contenant les informations formatées.
 */
std::string Proprietaire::reqProprietaireFormate() const
{
    std::ostringstream oss;
    oss << "Propriétaire" << "\n"
        << "Nom : " << m_nom << "\n"
        << "Prénom : " << m_prenom << "\n"
        << "Domicile : " << m_villeDomicile << "\n"
        << "---------------------------------" << "\n";
    for (const auto& vehicule : m_vehicules)
    {
        oss << vehicule->reqVehiculeFormate()
            << "---------------------------------" << "\n";
    }
    oss << "Paiement total : " << std::fixed << std::setprecision(2)
        << m_paiementTotal << "$\n";
    return oss.str();
}

/**
 * @brief Vérifie si un véhicule est déjà présent dans la collection du propriétaire.
 *
 * Cette méthode parcourt le vecteur des véhicules associés au propriétaire et
 * détermine si l'un d'eux possède le même numéro d'identification (NIV) que
 * celui fourni en paramètre.
 *
 * @pre Le NIV doit être valide.
 *
 * @return true si un véhicule avec le NIV spécifié est présent, false sinon. 
 * 
 * @param[in] p_niv Le numéro d'identification du véhicule recherché.
 */
bool Proprietaire::VehiculeEstDejaPresent(const string& p_niv) const
{
    PRECONDITION(validerNiv(p_niv));
    return std::any_of(
            m_vehicules.begin(),
            m_vehicules.end(),
            [&](const auto& vehicule) { return vehicule->reqNIV() == p_niv; }
            );
}

/**
 * @brief Opérateur de copie de Coplien.
 *
 * @return La copie par référence.
 * 
 * @param[in] p_proprietaire Le propriétaire à assigner.
 */
Proprietaire& Proprietaire::operator=(const Proprietaire& p_proprietaire)
{
    if (this != &p_proprietaire)
    {
        m_nom = p_proprietaire.m_nom;
        m_prenom = p_proprietaire.m_prenom;
        m_villeDomicile = p_proprietaire.m_villeDomicile;
        m_paiementTotal = p_proprietaire.m_paiementTotal;
        m_vehicules.clear();
        for (const auto& vehicule : p_proprietaire.m_vehicules)
        {
            m_vehicules.push_back(vehicule->clone());
        }
    }
    return *this;
}

/**
 * @brief Vérifie les invariants de la classe Proprietaire.
 *
 * Cette méthode s'assure que les informations personnelles du
 * propriétaire ainsi que le montant total payé respectent les
 * contraintes définies.
 */
void Proprietaire::verifierInvariant() const
{
    INVARIANT(!m_nom.empty());
    INVARIANT(!m_prenom.empty());
    INVARIANT(!m_villeDomicile.empty());
    INVARIANT(m_paiementTotal >= 0.00);
}
