/**
 * @file morpion.h
 * @author T MONTBORD - G CELLE
 * @brief entête du module morpion.cpp
 * @date 2022-01-08
 *
 */

#ifndef MORPION_H
#define MORPION_H

#include <iostream>
using namespace std;

/* -------------------------------------------------------------------------- */
/*                     initialisation des enregistrements                     */
/* -------------------------------------------------------------------------- */

/**
 * @brief stock les données nécessaires pour utiliser des coordonnées
 *
 */
struct Coordonnee
{
    unsigned char ligne;
    unsigned char colonne;
};

/**
 * @brief stock les données des joueurs
 * 
 */
struct Joueur
{
    string nom;
    char symbole;
};

const unsigned short int TAILLE_TABLEAU = 3; // sert à initialiser le nombre de colonne et de lignes d'un tableau de morpion
const string ESPACE = "     "; // permet de presenter plus facilement le texte dans le terminal

// type permétant de nommer les différents états de la partie
enum EtatsPossibles
{
    normal,
    egalite,
    abandon,
    victoireJoueurActif,
    cordonneesInvalides
};

/* -------------------------------------------------------------------------- */
/*                       Declaration des sous-programmes                      */
/* -------------------------------------------------------------------------- */

/**
 * @brief affiche les règles du morpion puis invite à saisir, verifie et modifie le nom et le symbole des deux joueurs
 * 
 * @param joueurUn 
 * @param joueurDeux 
 */
void initialiserLaPartie(Joueur &joueurUn, Joueur &joueurDeux);

/**
 * @brief definis le joueur qui doit jouer au prochain tour en fonction du nombre de tour passé
 * 
 * @param joueurUn informations du joueur 1
 * @param joueurDeux informations du joueur 2
 * @param nbTour nombre de tour
 * @return Joueur qui contient les information du joueur 1 ou du joueur 2
 */
Joueur definirJoueurActif(Joueur joueurUn, Joueur joueurDeux, unsigned short int nbTour);

/**
 * @brief affiche le tableau en suivant l'interface graphique demandé
 *
 * @param tab contient les informations du tableau
 */
void afficherTableau(const char tab[][TAILLE_TABLEAU]);

/**
 * @brief Invite le joueur à saisir des coordonées et verifie leur validité.
 *        S'il rentre la lettre a ou A à la place, etatDeLaPartie devient abandon.
 * 
 * @param coordonneeChoisie 
 * @param joueur 
 * @param etatDeLaPartie 
 */
void saisirCoordonnees(Coordonnee &coordonneeChoisie, Joueur joueur, EtatsPossibles &etatDeLaPartie);

/**
 * @brief verifie si trois symboles de joueur sont alligné horizontalement, verticalement ou en diagonale dans le tableau tab
 * 
 * @param tab
 * @param joueur
 * @return true
 * @return false
 */
bool verifVictoireJoueur(const char tab[][TAILLE_TABLEAU], Joueur joueur);
// but: renvois un booléen vrai si le joueur à gagné la partie et faux si le joueur n'as pas encore gagné

/**
 * @brief verifie si toutes les cases du tableau sont remplies par un caractère autre que ' '
 * 
 * @param tab tableau de jeu contenant les signes des joueurs ou une case vide
 * @return true si le tableau ne contient aucune case vide
 * @return false si le tableau contient une ou plusieurs cases vides
 */
bool verifEgalite(const char tab[][TAILLE_TABLEAU]);

/**
 * @brief affiche des informations sur la fin de partie (joueur gagnant, joueur perdant, nombre de tour et cause de la fin de partie)
 * en fonction de la condition d'arret et du dernierJoueurActif
 * 
 * @param joueurUn informations du joueur 1
 * @param joueurDeux informations du joueur 2
 * @param dernierJoueurActif informations du joueur actif
 * @param conditionArret condition d'arret de la partie
 * @param nbTour le tour durant lequel la partie c'est terminée
 */
void afficherFinPartie(Joueur joueurUn, Joueur joueurDeux, Joueur dernierJoueurActif, EtatsPossibles conditionArret, unsigned short int nbTour);

#endif