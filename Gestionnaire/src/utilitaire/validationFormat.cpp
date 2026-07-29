/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/* 
 * @file:   validationFormat.cpp
 * @brief:  Implantation de fonctions de validation du TP1. L'utilisation de "early returns"
 *         permet d'avoir un code beaucoup plus lisible sans if imbriqués.
 * @author: Yoan Lévesque
 *
 * Created on 5 février 2026, 15 h 07
 */

#include "utilitaire/validationFormat.h"

namespace
{
    enum class TypeCaractere { Lettre, Chiffre };

    constexpr std::array<int, 26> TRANSLITTERATION = {
        1,2,3,4,5,6,7,8,
        -1,1,2,3,4,5,-1,7,-1, // I, O et Q = -1, car invalide.
        9,2,3,4,5,6,7,8,9
    };

    constexpr std::array<int, 17> POIDS = {
        8,7,6,5,4,3,2,10,
        0,9,8,7,6,5,4,3,2
    };
    
    //=========================================
    // FONCTIONS UTILITAIRES PRIVÉES (ANONYMES)
    //=========================================
    
    /**
    * @brief Valide la longueur d'une chaîne de caractères.
    * @param p_chaine
    * @param p_longueur
    * @return true si la longueur est valide, sinon false.
    */
    bool validerLongueurChaine(const std::string& p_chaine, const std::size_t& p_longueur)
    {
        return p_chaine.size() == p_longueur;
    }

    /**
    * @brief Valide qu'un caractère est un chiffre.
    * @param p_caractere
    * @return true si c'est un chiffre, sinon false.
    */
    bool estUnChiffre(const char& p_caractere)
    {
        return std::isdigit(static_cast<unsigned char>(p_caractere));
    }

    /**
    * @brief Valide qu'un caractère du NI est une lettre majuscule autre que I, O ou U.
    * @param p_caractere
    * @return true si la lettre est valide, sinon false.
    */
    bool estUneLettreValideImmatriculation(const char& p_caractere)
    {
        // Doit être une lettre majuscule.
        if (!std::isupper(static_cast<unsigned char>(p_caractere)))
        {
            return false;
        }
        // Les lettres I, O et U ne sont pas autorisées.
        return p_caractere != 'I' && p_caractere != 'O' && p_caractere != 'U';
    }

    /**
    * @brief Valide les 3 chiffres ou lettres consécutifs/consécutives du NI.
    * @param p_immatriculation
    * @param p_debut
    * @param p_type
    * @return true si c'est valide, sinon false.
    */
    bool estTroisCaracteresValidesImmatriculation(const std::string& p_immatriculation,
            int p_debut, TypeCaractere p_type)
    {
        for (int i = p_debut; i < p_debut + 3; ++i)
        {
            char c = p_immatriculation[i];
            if (p_type == TypeCaractere::Lettre && !estUneLettreValideImmatriculation(c))
            {
                return false;
            }
            if (p_type == TypeCaractere::Chiffre && !estUnChiffre(c))
            {
                return false;
            }
        }
        return true;
    }

    /**
    * @brief Translittération des caractères.
    * @param p_caractere
    * @return Le chiffre correspondant de la table, sinon -1 (invalide).
    */
    int translittererCaractere(const char& p_caractere)
    {
        // Si le caractère est un chiffre, on retourne sa valeur initiale.
        if (std::isdigit(static_cast<unsigned char>(p_caractere)))
        {
            return p_caractere - '0';
        }

        // On s'assure que le caractère ASCII est entre A et Z.
        if (p_caractere < 'A' || p_caractere > 'Z')
        {
            return -1; // Invalide.
        }

        // Sinon, on effectue la translittération.
        return TRANSLITTERATION[p_caractere - 'A'];
    }
    
    /**
     * @brief Lit une ligne du flux d'entrée et valide qu'elle n'est pas vide.
     * @param p_is
     * @param p_ligne
     * @return true si la ligne n'est pas vide, sinon false.
     */
    bool lireLigneNonVide(std::istream& p_is, std::string& p_ligne)
    {
        return std::getline(p_is, p_ligne) && !p_ligne.empty();
    }
    
    /**
     * @brief Convertie une chaîne en entier valide.
     * @param p_ligne
     * @param p_valeur
     * @return true si la conversion fonctionne, sinon false.
     */
    bool convertirChaineEnEntier(const std::string& p_ligne, int& p_valeur)
    {
        try
        {
            p_valeur = std::stoi(p_ligne);
            return true;
        }
        catch (...)
        {
            return false;
        }
    }
    
    /**
     * @brief Valide le format de la date provenant du fichier texte (4e ligne).
     * @param p_ligne
     * @return true si la date est valide, sinon false.
     */
    bool validerFormatDate(const std::string& p_ligne)
    {
        int jj, mm, aaaa;
        return (std::istringstream(p_ligne) >> jj >> mm >> aaaa) &&
                (jj > 0 && mm > 0 && aaaa > 0);
    }
    
    /**
     * @brief Valide les informations spécifiques à un camion (poids et essieux).
     * @param p_is
     * @return true si les informations sont valides, sinon false.
     */
    bool validerInformationsCamion(std::istream& p_is)
    {
        std::string ligne;
        int poids;
        int essieux;
        
        if (!lireLigneNonVide(p_is, ligne) || !convertirChaineEnEntier(ligne, poids) ||
                poids < 3000)
        {
            return false;
        }
        
        if (!lireLigneNonVide(p_is, ligne) || !convertirChaineEnEntier(ligne, essieux) ||
                essieux < 2)
        {
            return false;
        }
        
        return true;
    }
    
    /**
     * @brief Valide les informations spécifiques à un véhicule de promenade (places).
     * @param p_is
     * @return true si les informations sont valides, sinon false.
     */
    bool validerInformationsPromenade(std::istream& p_is)
    {
        std::string ligne;
        int places;
        
        if (!lireLigneNonVide(p_is, ligne) || !convertirChaineEnEntier(ligne, places) ||
                places < 1 || places > 9)
        {
            return false;
        }
        
        return true;
    }
} // Fin de namespace.

//=======================
// FONCTIONS PRINCIPALES
//=======================

/**
 * @brief Valide le NI d'un "camion et ensemble de véhicules routiers (plaque L)".
 * @param p_immatriculation
 * @return true si la plaque est valide, sinon false.
 */
bool saaq::validerImmatriculationCamion(const std::string& p_immatriculation)
{
    // L'immatriculation doit être une chaîne de 7 caractères.
    if (!validerLongueurChaine(p_immatriculation, 7))
    {
        return false;
    }
    
    // Le premier caractère doit être "L"
    if (p_immatriculation[0] != 'L')
    {
        return false;
    }
    
    // Les 6 caractères suivants doivent être des chiffres de 0 à 9.
    for (size_t i = 1; i < p_immatriculation.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(p_immatriculation[i])))
        {
            return false;
        }
    }
    
    return true;
}

/**
 * @brief Valide le NI d'un véhicule de promenade. On ne considère que les cas
 * des véhicules de promenade sans préfixe et électriques non personnalisés.
 * @param p_immatriculation
 * @return true si la plaque est valide, sinon false.
 */
bool saaq::validerImmatriculationPromenade(const std::string& p_immatriculation)
{  
    // Cas "SAAQ".
    if (p_immatriculation == "SAAQ")
    {
       return true; 
    }
    
    // Sinon, l'immatriculation doit être une chaîne de 7 caractères.
    if (!validerLongueurChaine(p_immatriculation, 7))
    {
        return false;
    }
    
    // Cas "000 ABC".
    if (estTroisCaracteresValidesImmatriculation(p_immatriculation, 0, TypeCaractere::Chiffre) &&
            p_immatriculation[3] == ' ' &&
            estTroisCaracteresValidesImmatriculation(p_immatriculation, 4, TypeCaractere::Lettre))
    {
        return true;
    }
    
    // Cas "ABC 000".
    if (estTroisCaracteresValidesImmatriculation(p_immatriculation, 0, TypeCaractere::Lettre) &&
            p_immatriculation[3] == ' ' &&
            estTroisCaracteresValidesImmatriculation(p_immatriculation, 4, TypeCaractere::Chiffre))
    {
        return true;
    }
    
    // Cas "000H000".
    if (estTroisCaracteresValidesImmatriculation(p_immatriculation, 0, TypeCaractere::Chiffre) &&
            estUneLettreValideImmatriculation(p_immatriculation[3]) &&
            estTroisCaracteresValidesImmatriculation(p_immatriculation, 4, TypeCaractere::Chiffre))
    {
        return true;
    }
    
    // Cas "A00 ABC".
    if (estUneLettreValideImmatriculation(p_immatriculation[0]) && estUnChiffre(p_immatriculation[1]) &&
            estUnChiffre(p_immatriculation[2]) && p_immatriculation[3] == ' ' &&
            estTroisCaracteresValidesImmatriculation(p_immatriculation, 4, TypeCaractere::Lettre))
    {
        return true;
    }
    
    // Sinon, on retourne false.
    return false;
}

/**
 * @brief Valide le numéro d'identification d'un véhicule (NIV). On se limite
 * aux véhicules d'Amérique du Nord.
 * @param p_niv
 * @return true si le NIV est valide, sinon false.
 */
bool saaq::validerNiv(const std::string& p_niv)
{
    // Le NI doit être une chaîne de 17 caractères.
    if (!validerLongueurChaine(p_niv, 17))
    {
        return false;
    }

    // Le caractère de contrôle est le 9e caractère du NIV.
    char caractereControle = p_niv[8];
    
    // Le caractère de contrôle peut être un chiffre ou "X".
    if (!(std::isdigit(static_cast<unsigned char>(caractereControle)) ||
            caractereControle == 'X'))
    {
        return false;
    }

    // Application de l'algorithme.
    int somme = 0;
    for (int i = 0; i < 17; ++i)
    {
        int valeur = translittererCaractere(p_niv[i]);

        // Il ne doit pas y avoir de caractères invalides.
        if (valeur == -1)
        {
            return false;
        }

        somme += valeur * POIDS[i];
    }

    // Calcul du reste.
    int reste = somme % 11;

    // Détermination du caractère de contrôle attendu.
    // Si le reste est de 10, le caractère de contrôle attendu est "X".
    // Sinon, le caractère de contrôle attendu est simplement la valeur initiale.
    char attendu = (reste == 10 ? 'X' : char('0' + reste));

    // Vérification du caractère de contrôle.
    return caractereControle == attendu;
}

/**
 * @brief Valide le format du fichier de données texte lu
 * par l’intermédiaire d’un flux d’entrée passé en paramètre.
 * Le fichier ne doit contenir aucune ligne vide.
 * @param p_is
 * @return true si le fichier est valide, sinon false.
 */
bool saaq::validerFormatFichier(std::istream& p_is)
{
    // Lecture ligne par ligne du flux.
    std::string ligne;

    // Validation de l'en-tête (Nom, Prénom, Ville).
    for (int i = 0; i < 3; ++i)
    { 
        if (!lireLigneNonVide(p_is, ligne))
        { 
            return false;
        }
    }

    // Validation de la date (entiers strictement positifs).
    // Pas nécessaire de valider que la date est réelle.. ?
    // Ici, "99 99 9999" serait valide...
    if (!lireLigneNonVide(p_is, ligne) || !validerFormatDate(ligne))
    {
        return false;
    }

    // Informations sur des véhicules.
    while (getline(p_is, ligne))
    {
        // Une ligne vide n'est jamais permise dans le fichier
        if (ligne.empty())
        {
            return false;
        }
        // Validation du NIV.
        if(!validerNiv(ligne))
        {
            return false;
        }
        
        // Lecture de la plaque d'immatriculation.
        if (!lireLigneNonVide(p_is, ligne))
        {
            return false;
        }

        // Identification du type de véhicule par sa plaque.
        bool estCamion = validerImmatriculationCamion(ligne);
        bool estPromenade = validerImmatriculationPromenade(ligne);
        
        // Doit être exactement un des deux.
        // true == true ne devrait jamais arriver...
        if (estCamion == estPromenade)
        {
            return false;
        }
        
        // Deux cas possibles :
        // 1. C'est un camion.
        // 2. C'est un véhicule de promenade.
        if (estCamion && !validerInformationsCamion(p_is))
        {
            return false;
        }
        if (estPromenade && !validerInformationsPromenade(p_is))
        {
            return false;
        }
    }
    
    // Si tout est valide, on retourne true.
    return true;
}
