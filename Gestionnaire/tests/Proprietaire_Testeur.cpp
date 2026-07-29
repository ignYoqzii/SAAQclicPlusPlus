#include <gtest/gtest.h>
#include "classes/Proprietaire.h"
#include "classes/Camion.h"
#include "classes/VehiculePromenade.h"
#include "contrat/ContratException.h"
#include "exceptions/VehiculeAbsentException.h"
#include "exceptions/VehiculeDejaPresentException.h"
#include <string>

using namespace saaq;
using std::string;

/**
 * @brief Test du constructeur de Proprietaire.
 * Cas valide : paramètres conformes (le nom, le prénom et la ville du domicile
 * ne sont pas une chaîne vide).
 * Cas invalides :
 * - Nom vide (PreconditionException).
 * - Prénom vide (PreconditionException).
 * - Ville du domicile vide (PreconditionException).
 */
TEST(ProprietaireTest, Constructeur_ParametresValides_ObjetValide)
{
    Proprietaire unProprietaire("Lévesque", "Yoan", "Québec");
    
    ASSERT_EQ(unProprietaire.reqNom(), "Lévesque");
    ASSERT_EQ(unProprietaire.reqPrenom(), "Yoan");
    ASSERT_EQ(unProprietaire.reqVilleDomicile(), "Québec");
}

TEST(ProprietaireTest, Constructeur_NomVide_PreconditionException)
{   
    ASSERT_THROW(Proprietaire unProprietaire("", "Yoan", "Québec"), PreconditionException);
}

TEST(ProprietaireTest, Constructeur_PrenomVide_PreconditionException)
{   
    ASSERT_THROW(Proprietaire unProprietaire("Lévesque", "", "Québec"), PreconditionException);
}

TEST(ProprietaireTest, Constructeur_VilleDomicileVide_PreconditionException)
{   
    ASSERT_THROW(Proprietaire unProprietaire("Lévesque", "Yoan", ""), PreconditionException);
}

/**
 * @brief Test du constructeur copie de Coplien.
 * Cas valide : La copie est valide.
 * Cas invalides : Aucun d'identifié.
 */
TEST(ProprietaireTest, ConstructeurCopie_ParametresValides_CopieValide)
{
    Proprietaire unProprietaire("Lévesque", "Yoan", "Québec");
    VehiculePromenade unVehiculePromenade("1HGCM82633A004352", "000 ABC", 4);
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 4);
    unProprietaire.ajouterVehicule(unVehiculePromenade);
    unProprietaire.ajouterVehicule(unCamion);

    Proprietaire unAutreProprietaire(unProprietaire); // Constructeur de copie

    // Vérifier que les attributs simples sont copiés
    ASSERT_EQ(unAutreProprietaire.reqNom(), unProprietaire.reqNom());
    ASSERT_EQ(unAutreProprietaire.reqPrenom(), unProprietaire.reqPrenom());
    ASSERT_EQ(unAutreProprietaire.reqVilleDomicile(), unProprietaire.reqVilleDomicile());
    ASSERT_EQ(unAutreProprietaire.reqPaiementTotal(), unProprietaire.reqPaiementTotal());

    // Vérifier que le nombre de véhicules est identique
    ASSERT_EQ(unAutreProprietaire.reqNbVehicules(), unProprietaire.reqNbVehicules());
}


/**
 * @class UnProprietaire
 * @brief Fixture pour les tests nécessitant un objet Proprietaire déjà instancié.
 */
class UnProprietaire : public ::testing::Test
{
public:
    UnProprietaire() : f_proprietaire("Lévesque", "Yoan", "Québec")
    {
        // Création d'un véhicule de promenade
        VehiculePromenade unVehiculePromenade("1HGCM82633A004352", "000 ABC", 4);
        unVehiculePromenade.asgContributionTransportEnCommun(50.00);
        unVehiculePromenade.asgTaxeLocale(41.10);
        // Création d'un camion
        Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 4);

        // Ajout des véhicules au propriétaire
        f_proprietaire.ajouterVehicule(unVehiculePromenade);
        f_proprietaire.ajouterVehicule(unCamion);
    }
    Proprietaire f_proprietaire;
};

/**
 * @brief Test de l'accesseur du nom.
 * Cas valide : Le nom est bien celui qui avait été passé au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnProprietaire, reqNom_ObjetValide_NomValide)
{ 
    ASSERT_EQ(f_proprietaire.reqNom(), "Lévesque");
}

/**
 * @brief Test de l'accesseur du prénom.
 * Cas valide : Le prénom est bien celui qui avait été passé au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnProprietaire, reqPrenom_ObjetValide_PrenomValide)
{ 
    ASSERT_EQ(f_proprietaire.reqPrenom(), "Yoan");
}

/**
 * @brief Test de l'accesseur de la ville du domicile.
 * Cas valide : La ville du domicile est bien celle qui avait été passée au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnProprietaire, reqVilleDomicile_ObjetValide_VilleDomicileValide)
{ 
    ASSERT_EQ(f_proprietaire.reqVilleDomicile(), "Québec");
}

/**
 * @brief Test de l'accesseur du paiement total.
 * Cas valide : Le paiement total est bien celle qui est attendu.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnProprietaire, reqPaiementTotal_ObjetValide_PaiementTotalValide)
{ 
    ASSERT_EQ(f_proprietaire.reqPaiementTotal(), 2935.08);
}

/**
 * @brief Test de l'accesseur du vecteur de véhicules.
 * Cas valide : Le vecteur contient le bon nombre de véhicules, le NIV des véhicules
 * correspond à ceux ajoutés et les types dynamiques des véhicules sont corrects.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnProprietaire, reqVecteurVehicules_ObjetValide_VecteurVehiculesValide)
{
    const auto& vehicules = f_proprietaire.reqVecteurVehicules();

    // Vérifier la taille
    ASSERT_EQ(vehicules.size(), f_proprietaire.reqNbVehicules());

    // Vérifier les NIV
    ASSERT_EQ(vehicules[0]->reqNIV(), "1HGCM82633A004352");
    ASSERT_EQ(vehicules[1]->reqNIV(), "3AK5641C9SH571177");

    // Vérifier les types dynamiques
    ASSERT_NE(dynamic_cast<VehiculePromenade*>(vehicules[0].get()), nullptr);
    ASSERT_NE(dynamic_cast<Camion*>(vehicules[1].get()), nullptr);
}

/**
 * @brief Test de la méthode ajouterVehicule.
 * Cas valide : L'ajout du véhicule fonctionne et le vecteur contient
 * le nombre attendu de véhicules ajoutés.
 * Cas invalide : L'ajout d'un véhicule déjà présent retourne une erreur.
 */
TEST(ProprietaireTest, ajouterVehicule_ObjetValide_VehiculeAjouteEtNbVehiculesValide)
{
    Proprietaire unProprietaire("Lévesque", "Yoan", "Québec");
    VehiculePromenade unVehiculePromenade("1HGCM82633A004352", "000 ABC", 4);
    unProprietaire.ajouterVehicule(unVehiculePromenade);
    
    ASSERT_EQ(unProprietaire.reqNbVehicules(), 1);
}

TEST_F(UnProprietaire, ajouterVehicule_NIVDejaPresent_VehiculeDejaPresentException)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 4);
    
    ASSERT_THROW(f_proprietaire.ajouterVehicule(unCamion), VehiculeDejaPresentException);
}

/**
 * @brief Test de la méthode supprimerVehicule.
 * Cas valide : La suppression du véhicule fonctionne et le vecteur contient
 * le nombre attendu de véhicules restants.
 * Cas invalide : La suppression d'un véhicule absent retourne une erreur.
 */
TEST_F(UnProprietaire, supprimerVehicule_ObjetValide_VehiculeSupprimeEtNbVehiculesValide)
{
    f_proprietaire.supprimerVehicule("3AK5641C9SH571177");
    // Il y a maintenant un seul véhicule dans le vecteur
    ASSERT_EQ(f_proprietaire.reqNbVehicules(), 1);
}

TEST_F(UnProprietaire, supprimerVehicule_NIVAbsent_VehiculeAbsentException)
{ 
    ASSERT_THROW(f_proprietaire.supprimerVehicule("1FUJHWDC6DP000000"), VehiculeAbsentException);
}

/**
 * @brief Test de la méthode reqNbVehicules.
 * Cas valide : Le nombre de véhicules ajoutés est correctement retourné.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnProprietaire, reqNbVehicules_ObjetValide_NbVehiculesValide)
{
    ASSERT_EQ(f_proprietaire.reqNbVehicules(), 2);
}

/**
 * @brief Test de la méthode reqProprietaireFormate.
 * Cas valide : La chaîne de caractère est bien formatée et valide.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnProprietaire, reqProprietaireFormate_ObjetValide_ChaineFormateeCorrecte)
{
    string attendu = "Propriétaire\n"
                     "Nom : Lévesque\n"
                     "Prénom : Yoan\n"
                     "Domicile : Québec\n"
                     "---------------------------------\n"
                     "Véhicule de promenade\n"
                     "Numéro d'identification : 1HGCM82633A004352\n"
                     "Numéro d'immatriculation : 000 ABC\n"
                     "Nombre de places : 4\n"
                     "Paiement : 308.51$\n"
                     "---------------------------------\n"
                     "Camion\n"
                     "Numéro d'identification : 3AK5641C9SH571177\n"
                     "Numéro d'immatriculation : L000000\n"
                     "Nombre d'essieux : 4\n"
                     "Poids : 20000\n"
                     "Paiement : 2626.57$\n"
                     "---------------------------------\n"
                     "Paiement total : 2935.08$\n";
    ASSERT_EQ(f_proprietaire.reqProprietaireFormate(), attendu);
}

/**
 * @brief Test de l'opérateur d'assignation.
 * Cas valide :
 * - Assignation valide.
 * - Auto-assignation valide.
 * Cas invalide : Aucun d'identifié.
 */
TEST(ProprietaireTest, operatorEgal_ObjetValide_AssignationValide)
{
    Proprietaire unProprietaire("Lévesque", "Yoan", "Québec");
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 4);
    unProprietaire.ajouterVehicule(unCamion);

    Proprietaire unAutreProprietaire("Blo", "Joe", "Lévis");
    unAutreProprietaire = unProprietaire; // operator=

    // Attributs simples
    ASSERT_EQ(unAutreProprietaire.reqNom(), unProprietaire.reqNom());
    ASSERT_EQ(unAutreProprietaire.reqPrenom(), unProprietaire.reqPrenom());
    ASSERT_EQ(unAutreProprietaire.reqVilleDomicile(), unProprietaire.reqVilleDomicile());
    ASSERT_EQ(unAutreProprietaire.reqPaiementTotal(), unProprietaire.reqPaiementTotal());

    // Copie profonde
    ASSERT_NE(unAutreProprietaire.reqVecteurVehicules()[0].get(),
              unProprietaire.reqVecteurVehicules()[0].get());
}

TEST(ProprietaireTest, operatorEgal_ObjetValide_AutoAssignationValide)
{
    Proprietaire unProprietaire("Dupont", "Jean", "Québec");
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 4);
    unProprietaire.ajouterVehicule(unCamion);

    ASSERT_NO_THROW(unProprietaire = unProprietaire);

    // L'objet doit être intact
    ASSERT_EQ(unProprietaire.reqNbVehicules(), 1);
}
