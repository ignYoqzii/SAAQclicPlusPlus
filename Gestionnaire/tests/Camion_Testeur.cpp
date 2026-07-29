#include <gtest/gtest.h>
#include "classes/Camion.h"
#include "contrat/ContratException.h"
#include <string>

using namespace saaq;
using std::string;

/**
 * @brief Test du constructeur de Camion.
 * Cas valide : paramètres conformes (poids supérieur à 3000 kg,
 * nombre d'essieux d'au moins 2 et immatriculation valide).
 * Cas invalides :
 * - Poids insuffisant (PreconditionException).
 * - Nombre d'essieux insuffisant (PreconditionException).
 * - Immatriculation invalide (PreconditionException).
 */
TEST(CamionTest, Constructeur_ParametresValides_ObjetValide)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 4);
    
    ASSERT_EQ(unCamion.reqPoids(), 20000);
    ASSERT_EQ(unCamion.reqNbEssieux(), 4);
    ASSERT_EQ(unCamion.reqImmatriculation(), "L000000");
    ASSERT_EQ(unCamion.reqNIV(), "3AK5641C9SH571177");
}

TEST(CamionTest, Constructeur_PoidsInvalide_PreconditionException)
{
    ASSERT_THROW(Camion unCamion("3AK5641C9SH571177", "L000000", 2000, 4), PreconditionException);
}

TEST(CamionTest, Constructeur_NbEssieuxInvalide_PreconditionException)
{
    ASSERT_THROW(Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 1), PreconditionException);
}

TEST(CamionTest, Constructeur_ImmatriculationInvalide_PreconditionException)
{
    ASSERT_THROW(Camion unCamion("3AK5641C9SH571177", "ABC 123", 20000, 4), PreconditionException);
}

/**
 * @class UnCamion
 * @brief Fixture pour les tests nécessitant un objet Camion déjà instancié.
 */
class UnCamion : public ::testing::Test
{
public:
    UnCamion() : f_camion("3AK5641C9SH571177", "L000000", 20000, 4) {}
    Camion f_camion;
};

/**
 * @brief Test de l'accesseur du poids.
 * Cas valide : Le poids est bien celui qui avait été passé au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnCamion, reqPoids_ObjetValide_PoidsValide)
{ 
    ASSERT_EQ(f_camion.reqPoids(), 20000);
}

/**
 * @brief Test de l'accesseur du nombre d'essieux.
 * Cas valide : Le nombre d'essieux est bien celui qui avait été passé au constructeur.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnCamion, reqNbEssieux_ObjetValide_NbEssieuxValide)
{ 
    ASSERT_EQ(f_camion.reqNbEssieux(), 4);
}

/**
 * @brief Test de la méthode reqVehiculeFormate.
 * Cas valide : La chaîne de caractère est bien formatée et valide.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnCamion, reqVehiculeFormate_ObjetValide_ChaineFormateeCorrecte)
{
    string attendu = "Camion\n"
                     "Numéro d'identification : 3AK5641C9SH571177\n"
                     "Numéro d'immatriculation : L000000\n"
                     "Nombre d'essieux : 4\n"
                     "Poids : 20000\n"
                     "Paiement : 2626.57$\n";
    ASSERT_EQ(f_camion.reqVehiculeFormate(), attendu);
}

/**
 * @brief Test de la méthode clone.
 * Cas valide : Le camion original est le même que sa copie.
 * Cas invalide : Aucun d'identifié.
 */
TEST_F(UnCamion, clone_ObjetValide_CopieIdentique)
{
    auto copieCamion = f_camion.clone();
    
    // Possible, car l'opérateur d'égalité est défini dans la classe de base
    ASSERT_TRUE(f_camion == *copieCamion);
}

/**
 * @brief Test de la méthode asgImmatriculation.
 * Cas valide : L'immatriculation à changer est valide et l'assignation fonctionne.
 * Cas invalide : L'immatriculation à changer est invalide (PreconditionException).
 */
TEST_F(UnCamion, asgImmatriculation_ImmatriculationValide_AssignationCorrecte)
{
    f_camion.asgImmatriculation("L111111");
    ASSERT_EQ(f_camion.reqImmatriculation(), "L111111");
}

TEST_F(UnCamion, asgImmatriculation_ImmatriculationInvalide_PreconditionException)
{
    ASSERT_THROW(f_camion.asgImmatriculation("000 ABC"), PreconditionException);
}

/**
 * @brief Test de la méthode calculerTarificationAnnuelle.
 * Cas valide : Le tarif retourné est le bon selon le poids et le nombre d'essieux.
 * Cas invalide : Aucun d'identifié.
 */
TEST(CamionTest, calculerTarificationAnnuelle_2EssieuxPetitPoids_TarifCorrect)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 3500, 2);
    ASSERT_EQ(unCamion.calculerTarificationAnnuelle(), 673.69);
}

TEST(CamionTest, calculerTarificationAnnuelle_2EssieuxGrandPoids_TarifCorrect)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 2);
    ASSERT_EQ(unCamion.calculerTarificationAnnuelle(), 1067.69);
}

TEST(CamionTest, calculerTarificationAnnuelle_3Essieux_TarifCorrect)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 3);
    ASSERT_EQ(unCamion.calculerTarificationAnnuelle(), 1871.57);
}

TEST(CamionTest, calculerTarificationAnnuelle_4Essieux_TarifCorrect)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 4);
    ASSERT_EQ(unCamion.calculerTarificationAnnuelle(), 2626.57);
}

TEST(CamionTest, calculerTarificationAnnuelle_5Essieux_TarifCorrect)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 5);
    ASSERT_EQ(unCamion.calculerTarificationAnnuelle(), 3320.07);
}

TEST(CamionTest, calculerTarificationAnnuelle_6Essieux_TarifCorrect)
{
    Camion unCamion("3AK5641C9SH571177", "L000000", 20000, 6);
    ASSERT_EQ(unCamion.calculerTarificationAnnuelle(), 4391.07);
}
