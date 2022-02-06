/*
 Programme : 2048
 Date de dernière modification : 16/11/2021
 Auteur : T. MONTBORD
 Programme fini !
*/

#include "deuxMilleQuaranteHuit.h"
#include <iostream>
using namespace std;

int main(void)
{
    // initialisation des variables
    int score = 0;
    int meilleurScore;
    unsigned short int tableauDeJeu[TAILLE_TABLEAU][TAILLE_TABLEAU] = {0};
    bool tableauDouble[TAILLE_TABLEAU][TAILLE_TABLEAU] = {false};
    unsigned short int derniereTouche = 0;
    bool efficace = false;
    bool defaite = false;

    // appel des sous-programmes
    
    meilleurScore = obtenirMeilleurScore();
    ajouterNombre(tableauDeJeu);

    while (defaite == false)
    {
        if (efficace == true){
        ajouterNombre(tableauDeJeu);
        }
        
        afficherTableau(tableauDeJeu);
        cout << "Score total = ";
        afficherNombreEnCouleur(score, rouge, true);

        derniereTouche = static_cast<unsigned short int>(getch());

        while ((derniereTouche != KEY_UP) && (derniereTouche != KEY_DOWN) && (derniereTouche != KEY_LEFT) && (derniereTouche != KEY_RIGHT)){
            derniereTouche = static_cast<unsigned short int>(getch());
        }

        deplacerCases(tableauDeJeu, tableauDouble, derniereTouche, efficace, score);

        defaite = verifDefaite(tableauDeJeu);
        retournerAuDebut();
    }  

    afficherTableau(tableauDeJeu);
    cout << "   P E R D U    ! ! !\n   Score total = ";
    afficherNombreEnCouleur(score, rouge, true);
    cout << "   Ancien meilleursScore = " << meilleurScore;

    if (meilleurScore < score)
    {
        remplacerMeilleurScore(score);
    }

    return 0;
}