/**
 * @file main.cpp
 * @author T. MONTBORD - G. CELLE
 * @brief reproduire le jeu du morpion
 * @date 2022-01-08
 * 
 */
#include "morpion.h"
#include "game-tools.h"

int main(void)
{
    /* -------------------------------------------------------------------------- */
    /*                  initialisation des différentes variables                  */
    /* -------------------------------------------------------------------------- */

    unsigned short int nbTour = 0; // contient le nombre de tour de jeu
    char tableauDeJeu[TAILLE_TABLEAU][TAILLE_TABLEAU]; // tableau de jeu
    Joueur joueurUn;    // contient les données concernant le premier joueur
    Joueur joueurDeux;  // contient les données concernant le deuxième joueur
    Joueur joueurActif; // contient les données concernant le joueur effectuant son tour, facilite le changement de tour
    Coordonnee derniereCoordonneeChoisie; // sert a stocker temporairement des coordonées 
    EtatsPossibles partie = normal; // représente l'état de la partie et permet d'arreter la boucle de jeu

    /* -------------------------------------------------------------------------- */
    /*                           EXECUTION DU PROGRAMME                           */
    /* -------------------------------------------------------------------------- */

    /* ----------------------- initialisation de la partie ---------------------- */

    // remplacer toutes les cases du tableau de jeu par des espaces
    for (unsigned short int ligne = 0; ligne < TAILLE_TABLEAU; ligne++)
    {
        for (unsigned short int colonne = 0; colonne < TAILLE_TABLEAU; colonne++)
        {
            tableauDeJeu[ligne][colonne] = ' ';
        }
    }

    initialiserLaPartie(joueurUn, joueurDeux);

    /* ------------------------ déroulement de la partie ------------------------ */

    while (partie == normal) // si partie n'est pas "normal" c'est à cause d'une égalité, d'un abandon ou d'une victoire d'un des joueurs
    {
        nbTour++;
        joueurActif = definirJoueurActif(joueurUn, joueurDeux, nbTour);

        // demander au joueur actif de rentrer des coordonées ou d'abandonner puis les verifier
        effacer();
        cout << "Tour numero : " << nbTour << endl
             << endl;
        afficherTableau(tableauDeJeu);
        saisirCoordonnees(derniereCoordonneeChoisie, joueurActif, partie);

        if (partie != abandon) // Les verifications et modification du tableau ne sont pas nécessaire quand la partie à été abandonée
        {
            if (tableauDeJeu[derniereCoordonneeChoisie.ligne][derniereCoordonneeChoisie.colonne] == ' ')
            {
                tableauDeJeu[derniereCoordonneeChoisie.ligne][derniereCoordonneeChoisie.colonne] = joueurActif.symbole;
            }
            if (verifVictoireJoueur(tableauDeJeu, joueurActif))
            {
                partie = victoireJoueurActif;
            }
            else if (verifEgalite(tableauDeJeu))
            {
                partie = egalite;
            }
        }
    }

    /* ----------------------- affichager la fin de partie ---------------------- */

    effacer();
    cout << "Tour numero : " << nbTour << endl
         << endl;
    afficherTableau(tableauDeJeu);
    afficherFinPartie(joueurUn, joueurDeux, joueurActif, partie, nbTour);
}
