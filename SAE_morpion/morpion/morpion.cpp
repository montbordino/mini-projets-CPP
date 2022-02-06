/**
 * @file morpion.cpp
 * @author T MONTBORD - G CELLE
 * @brief permet de definir les sous-programmes du module morpion.h
 * @date 2021-11-20
 *
 */

#include "morpion.h"
#include <iostream>
using namespace std;

void initialiserLaPartie(Joueur &joueurUn, Joueur &joueurDeux)
{
    // TITRE DU JEU:
    cout << "--------------------- M O R P I O N -----------------------\n"
         << endl;

    /* -------------------------- AFFICHAGE DES REGLES -------------------------- */

    // Paragraphe 1
    cout << endl
         << "Jeu avec 2 joueurs humains et une grille de 9 cases : 3 lignes et 3 colonnes.\nChaque joueur joue a tour de role.\nLe but du jeu est d'aligner, avant son adversaire, 3 symboles identiques, horizontalement, verticalement ou en diagonale." << endl;

    // Paragraphe 2
    cout << "La partie se termine :\n- quand l'un des joueurs a aligne ses 3 symboles, et il gagne, \n- quand la grille est complete, il y a egalite \n- quand l'un des joueurs abandonne, c'est l'autre qui gagne. \nChaque joueur a donc son propre symbole" << endl;

    // Paragraphe 3
    cout << endl
         << "Dans cette version du Morpion, une phase prealable de personnalisation permet a chaque joueur de saisir son prenom et le symbole \nchoisi pour jouer\n";
    cout << "Losqu'arrive son tour de jouer, un joueur peut : \n- saisir la position de la case ou placer so symbole, sous la forme Ligne puis Colonne (LigneColonne exemple: 12 pour Ligne 1 et Colonne 2) \n- saisir A (ou a) pour abandonner la partie" << endl;

    /* ---------------------- CHOIX DES NOMS ET CARACTERES ---------------------- */

    // SEPARATION REGLE/PERSONNALISATION
    cout << "-----------------------------------------------------------\n";

    // TITRE PERSONNALISATION
    cout << endl
         << "---  Phase de personnalisation  --- " << endl;

    // Joueur 1
    cout << "JOUEUR 1, entrez votre nom : ";
    cin >> joueurUn.nom;
    cout << "\n"
         << joueurUn.nom << ", entrez votre symbole (1 lettre ou 1 chifre) : ";
    cin >> joueurUn.symbole;

    // Joueur 2
    do
    {
        cout << endl
             << "\n JOUEUR 2, entrez votre prenom, autre que '" << joueurUn.nom << "' : ";
        cin >> joueurDeux.nom;
    }

    while (joueurUn.nom == joueurDeux.nom);

    do
    {
        cout << "\n"
             << joueurDeux.nom << " entrez un symbole (1 lettre ou 1 chiffre), autre que '" << joueurUn.symbole << "' : ";
        cin >> joueurDeux.symbole;
    }

    while (joueurDeux.symbole == joueurUn.symbole);
}

Joueur definirJoueurActif(Joueur joueurUn, Joueur joueurDeux, unsigned short int nombreDeTour)
{
    if (nombreDeTour % 2 == 0) // joueurDeux joue quand quand nbTour est pair
    {
        return joueurDeux;
    }
    else // joueurUn joue quand nbTour est impair
    {
        return joueurUn;
    }
}

void saisirCoordonnees(Coordonnee &coordonneeChoisie, Joueur joueur, EtatsPossibles &etatDeLaPartie)
{
    const unsigned short int UN = 49; // cette constante représente le code du caractère 1

    do
    {
        /* --------------- inviter le joueur a saisir des coordonnées --------------- */

        cout << "--> " << joueur.nom << ", entrez :\n"
             << endl
             << ESPACE << "Une coordonnee (LigneColonne, ex : 12 pour ligne 1 et colonne 2), ou bien abandonnez avec 'A'.\n"
             << endl
             << ESPACE << "Votre choix ? ";

        cin >> coordonneeChoisie.ligne;

        if (coordonneeChoisie.ligne == 'a' || coordonneeChoisie.ligne == 'A')
        {
            etatDeLaPartie = abandon;
        }
        else
        {
            cin >> coordonneeChoisie.colonne;

            /* convertion des coordonnées en chiffres plus simples à manipuler dans un tableau*/
            coordonneeChoisie.ligne = static_cast<unsigned char>(coordonneeChoisie.ligne - UN);
            coordonneeChoisie.colonne = static_cast<unsigned char>(coordonneeChoisie.colonne - UN);

            // verification des coordonnées
            if ((coordonneeChoisie.ligne < TAILLE_TABLEAU) && (coordonneeChoisie.colonne < TAILLE_TABLEAU))
            {
                etatDeLaPartie = normal;
            }
            else
            {
                etatDeLaPartie = cordonneesInvalides;
            }
        }
    } while (etatDeLaPartie == cordonneesInvalides);
}

void afficherTableau(const char tab[][TAILLE_TABLEAU])
{
    for (unsigned short int ligne = 0; ligne < TAILLE_TABLEAU; ligne++)
    {
        // création de la marge à gauche
        cout << ESPACE;
        for (unsigned short int colonne = 0; colonne < TAILLE_TABLEAU; colonne++)
        {
            // afficher la premiere case de la colonne
            if (colonne == 0)
            {
                cout << '[' << tab[ligne][colonne] << '|';
            }
            // afficher la dernière case de la colonne
            else if (colonne == (TAILLE_TABLEAU - 1))
            {
                cout << tab[ligne][colonne] << ']';
            }
            // afficher une case centrale
            else
            {
                cout << tab[ligne][colonne] << '|';
            }
        }
        cout << "\n"; // retour à la ligne
    }
    // sauter des lignes pour la propreté
    cout << endl
         << endl;
}

bool verifVictoireJoueur(const char tab[][TAILLE_TABLEAU], Joueur joueur)
{
    bool victoire = true; // on part du principe que le joueur à gagné

    for (unsigned short int i = 0; i < TAILLE_TABLEAU; i++)
    {
        // verification des lignes
        if ((tab[i][0] == joueur.symbole) && (tab[i][1] == joueur.symbole) && (tab[i][2] == joueur.symbole))
        {
            return victoire;
        }

        // verification des colonnes
        if ((tab[0][i] == joueur.symbole) && (tab[1][i] == joueur.symbole) && (tab[2][i] == joueur.symbole))
        {
            return victoire;
        }
    }

    // verification des diagonales
    if ((tab[0][0] == joueur.symbole) && (tab[1][1] == joueur.symbole) && (tab[2][2] == joueur.symbole))
    {
        return victoire;
    }

    if ((tab[2][0] == joueur.symbole) && (tab[1][1] == joueur.symbole) && (tab[0][2] == joueur.symbole))
    {
        return victoire;
    }

    // le joueur n'a pas gagné car il est arrivé au bout du code
    victoire = false;
    return victoire;
}

void afficherFinPartie(Joueur joueurUn, Joueur joueurDeux, Joueur dernierJoueur, EtatsPossibles conditionArret, unsigned short int nombreDeTour)
{
    string gagnant;
    
    // signaler la fin de la partie
    cout << " --- Fin de la partie --- \n"
         << endl;

    // afficher un message en fonction de la condition d'arrêt

    if (conditionArret == egalite)
    {
        // afficher la phrase
        cout << "Egalite car grille complete";
    }
    else if (conditionArret == abandon)
    {
        // definir gagnant
        if (dernierJoueur.nom == joueurDeux.nom)
        {
            gagnant = joueurUn.nom;
        }
        else
        {
            gagnant = joueurDeux.nom;
        }

        // afficher phrase
        cout << "Partie gagnee par " << gagnant << " suite a l'abandon de " << dernierJoueur.nom << " au tour numero " << nombreDeTour;
    }
    else
    {
        // afficher phrase
        cout << "Partie gagnee par " << dernierJoueur.nom << " au tour numero " << nombreDeTour;
    }
}

bool verifEgalite(const char tab[][TAILLE_TABLEAU])
{
    bool egalite = true; // on part du principe que le tableau est remplis

    // parcour de tout le tableau
    for (unsigned short int ligne = 0; ligne < TAILLE_TABLEAU; ligne++)
    {
        for (unsigned short int colonne = 0; colonne < TAILLE_TABLEAU; colonne++)
        {
            if (tab[ligne][colonne] == ' ')
            {
                egalite = false;
            }
        }
    }
    return egalite;
}