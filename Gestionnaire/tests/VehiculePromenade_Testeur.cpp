#include <gtest/gtest.h>
#include "classes/VehiculePromenade.h"
#include "contrat/ContratException.h"
#include <string>

using namespace saaq;
using std::string;

/**
 * @brief Test du constructeur de VehiculePromenade.
 * Cas valide : paramètres conformes (nombre de places de 1 à 9 et immatriculation valide).
 * Cas invalides :
 * - Nombre de places impossible (0) (PreconditionException).
 * - Nombre de places trop grand (PreconditionException).
 * - Immatriculation invalide (PreconditionException).
 */
TEST(VehiculePromenadeTest, Constructeur_ParametresValides_ObjetValide)
{
    VehiculePromenade unVehiculePromenade("1HGCM82633A004352", "000 ABC", 4);
    
    ASSERT_EQ(unVehiculePromenade.reqNbPlaces(), 4);
    ASSERT_EQ(unVehiculePromenade.reqImmatriculation(), "000 ABC");
    ASSERT_EQ(unVehiculePromenade.reqNIV(), "1HGCM82633A004352");
    ASSERT_EQ(unVehiculePromenade.reqTarifRenouvellementImmatriculation(), 217.41);
    ASSERT_EQ(unVehiculePromenade.reqContributionTransportEnCommun(), 0.0);
    ASSERT_EQ(unVehiculePromenade.reqTaxeLocale(), 0.0);
}

TEST(VehiculePromenadeTest, Constructeur_NbPlacesImpossible_PreconditionException)
{
    ASSERT_THROW(VehiculePromenade unVehiculePromenade("1HGCM82633A004352", "000 ABC", 0), PreconditionException);
}

TEST(VehiculePromenadeTest, Constructeur_NbPlacesTropGrand_PreconditionException)
{
    ASSERT_THROW(VehiculePromenade unVehiculePromenade("1HGCM82633A004352", "000 ABC", 10), PreconditionException);
}

TEST(VehiculePromenadeTest, Constructeur_ImmatriculationInvalide_PreconditionException)
{
    ASSERT_THROW(VehiculePromenade unVehiculePromenade("1HGCM82633A004352", "L000000", 4), PreconditionException);
}

/**
 * \class UnVehiculePromenade
 * \brief Fixture pour les tests nécessitant un objet VehiculePromenade déjà instancié.
 */
class UnVehiculePromenade : public ::testing::Test
{
public:
    UnVehiculePromenade() : f_vehiculePromenade("1HGCM82633A004352", "000 ABC", 4) {}
    VehiculePromenade f_vehiculePromenade;
};

/**
 * @brief Test de l'accesseur du nombre de places.
 * Cas valide : Le nombre de places est bien celui qui avait été passé au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehiculePromenade, reqNbPlaces_ObjetValide_NbPlacesValide)
{ 
    ASSERT_EQ(f_vehiculePromenade.reqNbPlaces(), 4);
}

/**
 * @brief Test de l'accesseur du tarif de renouvellement de l'immatriculation.
 * Cas valide : Le tarif est bien le tarif fixe de 217.41$.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehiculePromenade, reqTarifRenouvellementImmatriculation_ObjetValide_TarifRenouvellementImmatriculationFixe)
{ 
    ASSERT_EQ(f_vehiculePromenade.reqTarifRenouvellementImmatriculation(), 217.41);
}

/**
 * @brief Test de l'accesseur et du mutateur du tarif de contribution au transport en commun.
 * Cas valide : Le tarif est bien le tarif assigné.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehiculePromenade, reqContributionTransportEnCommun_ObjetValide_ContributionTransportEnCommunValide)
{
    f_vehiculePromenade.asgContributionTransportEnCommun(50.00);
    ASSERT_EQ(f_vehiculePromenade.reqContributionTransportEnCommun(), 50.00);
}

/**
 * @brief Test de l'accesseur et du mutateur de la taxe locale.
 * Cas valide : Le tarif est bien le tarif assigné.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehiculePromenade, reqTaxeLocale_ObjetValide_TaxeLocaleValide)
{
    f_vehiculePromenade.asgTaxeLocale(50.00);
    ASSERT_EQ(f_vehiculePromenade.reqTaxeLocale(), 50.00);
}

/**
 * @brief Test de la méthode asgImmatriculation.
 * Cas valide : L'immatriculation à changer est valide et l'assignation fonctionne.
 * Cas invalide : L'immatriculation à changer est invalide (PreconditionException).
 */
TEST_F(UnVehiculePromenade, asgImmatriculation_ImmatriculationValide_AssignationCorrecte)
{
    f_vehiculePromenade.asgImmatriculation("ABC 123");
    ASSERT_EQ(f_vehiculePromenade.reqImmatriculation(), "ABC 123");
}

TEST_F(UnVehiculePromenade, asgImmatriculation_ImmatriculationInvalide_PreconditionException)
{
    ASSERT_THROW(f_vehiculePromenade.asgImmatriculation("L000000"), PreconditionException);
}

/**
 * @brief Test de la méthode calculerTarificationAnnuelle.
 * Cas valide :
 * - Le tarif retourné est le prix fixe du renouvellement de l'immatriculation.
 * - Le tarif retourné est le prix du renouvellement + transport en commun + taxe locale.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehiculePromenade, calculerTarificationAnnuelle_ParDefaut_SommeCorrecte)
{
    ASSERT_EQ(f_vehiculePromenade.calculerTarificationAnnuelle(), 217.41);
}

TEST_F(UnVehiculePromenade, calculerTarificationAnnuelle_AvecAjouts_SommeCorrecte)
{
    f_vehiculePromenade.asgContributionTransportEnCommun(50.00);
    f_vehiculePromenade.asgTaxeLocale(41.10);
    // 217.41 + 50.00 + 41.10 = 308.51
    ASSERT_EQ(f_vehiculePromenade.calculerTarificationAnnuelle(), 308.51);
}

/**
 * @brief Test de la méthode reqVehiculeFormate.
 * Cas valide : La chaîne de caractère est bien formatée et valide.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehiculePromenade, reqVehiculeFormate_ObjetValide_ChaineFormateeCorrecte)
{
    f_vehiculePromenade.asgContributionTransportEnCommun(50.00);
    f_vehiculePromenade.asgTaxeLocale(41.10);
    
    std::string attendu = "Véhicule de promenade\n"
                          "Numéro d'identification : 1HGCM82633A004352\n"
                          "Numéro d'immatriculation : 000 ABC\n"
                          "Nombre de places : 4\n"
                          "Paiement : 308.51$\n";
                          
    ASSERT_EQ(f_vehiculePromenade.reqVehiculeFormate(), attendu);
}

/**
 * @brief Test de la méthode clone.
 * Cas valide : Le véhicule de promenade original est le même que sa copie.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnVehiculePromenade, clone_ObjetValide_CopieIdentique)
{
    auto copieVehiculePromenade = f_vehiculePromenade.clone();
    
    // Possible, car l'opérateur d'égalité est défini dans la classe de base
    ASSERT_TRUE(f_vehiculePromenade == *copieVehiculePromenade);
}