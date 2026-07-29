#include <gtest/gtest.h>
#include "classes/Vehicule.h"
#include "contrat/ContratException.h"
#include <string>

using namespace saaq;
using std::string;

/**
 * @class VehiculeDeTest
 * @brief Classe de test permettant de tester la classe abstraite Vehicule.
 */
class VehiculeDeTest : public Vehicule
{
public:
    VehiculeDeTest(const string& p_niv, const string& p_immatriculation) :
    Vehicule(p_niv, p_immatriculation) {}
    
    void asgImmatriculation(const std::string& p_immatriculation) override
    {
        Vehicule::asgImmatriculation(p_immatriculation);
    }
    
    // Méthodes virtuelles pures dans la classe de base Vehicule
    // Elles ne seront pas testées ici
    std::unique_ptr<Vehicule> clone() const override { return nullptr; }
    double calculerTarificationAnnuelle() const override { return 0.0; }
};

/**
 * @brief Test du constructeur de Vehicule via la classe dérivée VehiculePromenade.
 * Cas valide : paramètres conformes (NIV valide et immatriculation non vide).
 * Cas invalides :
 * - NIV invalide (PreconditionException).
 * - Immatriculation vide (PreconditionException).
 */
TEST(VehiculeTest, Constructeur_ParametresValides_VehiculeValide)
{
    // NIV valide : 1HGCM82633A004352
    VehiculeDeTest unVehicule("1HGCM82633A004352", "000 ABC");

    ASSERT_EQ(unVehicule.reqNIV(), "1HGCM82633A004352");
    ASSERT_EQ(unVehicule.reqImmatriculation(), "000 ABC");
}

TEST(VehiculeTest, Constructeur_NIVInvalide_PreconditionException)
{
    ASSERT_THROW(VehiculeDeTest unVehicule("", "000 ABC"), PreconditionException);
}

TEST(VehiculeTest, Constructeur_ImmatriculationVide_PreconditionException)
{
    ASSERT_THROW(VehiculeDeTest unVehicule("1HGCM82633A004352", ""), PreconditionException);
}

/**
 * @class UnVehicule
 * @brief Fixture pour les tests nécessitant un objet Vehicule déjà instancié.
 */
class UnVehicule : public ::testing::Test
{
public:
    UnVehicule() : f_vehicule("1HGCM82633A004352", "000 ABC") {}
    VehiculeDeTest f_vehicule;
};

/**
 * @brief Test de l'accesseur du NIV.
 * Cas valide : Le NIV est bien celui qui avait été passé au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehicule, reqNIV_ObjetValide_NIVValide)
{
    ASSERT_EQ(f_vehicule.reqNIV(), "1HGCM82633A004352");
}

/**
 * @brief Test de l'accesseur de l'immatriculation.
 * Cas valide : L'immatriculation est bien celle qui avait été passée au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehicule, reqImmatriculation_ObjetValide_ImmatriculationValide)
{
    ASSERT_EQ(f_vehicule.reqImmatriculation(), "000 ABC");
}

/**
 * @brief Test de la méthode reqVehiculeFormate.
 * Cas valide : La chaîne de caractère est bien formatée et valide.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehicule, reqVehiculeFormate_ObjetValide_ChaineFormateeCorrecte)
{
    string attendu = "Numéro d'identification : 1HGCM82633A004352\n"
                     "Numéro d'immatriculation : 000 ABC\n";
    ASSERT_EQ(f_vehicule.reqVehiculeFormate(), attendu);
}

/**
 * @brief Test de l'opérateur d'égalité (basé sur le NIV).
 * Cas valide :
 * - Les deux véhicules ont le même NIV.
 * - Les deux véhicules n'ont pas le même NIV.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehicule, operatorEgal_MemeNIV_Vrai)
{
    VehiculeDeTest memeVehicule("1HGCM82633A004352", "ABC 123");
    ASSERT_TRUE(f_vehicule == memeVehicule);
}

TEST_F(UnVehicule, operatorEgal_NIVDifferent_Faux)
{
    VehiculeDeTest autreVehicule("3AK5641C9SH571177", "ABC 123");
    ASSERT_FALSE(f_vehicule == autreVehicule);
}

/**
 * @brief Test de la méthode asgImmatriculation.
 * Cas valide : L'assignation fonctionne.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehicule, asgImmatriculation_ObjetValide_ImmatriculationAssignee)
{
    f_vehicule.asgImmatriculation("ABC 000");
    ASSERT_EQ(f_vehicule.reqImmatriculation(), "ABC 000");
}