#include <iostream>
#include "stdlib.h"
#include "sousProgrammes.h"

using namespace std;

int main()
{
    string nomSystemeFicSource;      // nom système du fichier à crypter
    string nomSystemeFicCible;      // nom système du fichier crypté produit
    string nomSystemeFicCodes;      // nom système du fichier contenant les codes 
                                    // de cryptage (facultatif)
    char choix ;            // réponse de l'utilisateur au menu
    string kk;              // pour arrêter le défilement écran

    do
    {
        // AfficherMenu - Saisie-verif reponse >> choix
        do
        {
            // effacer écran
            system("cls");
            cout << endl << "FEUILLES DE TD 7 & TP 7 - FICHIERS TEXTE - EXERCICE 3 - CRYPTAGE" << endl << endl;

            // afficher menu
            cout << "S) Cryptage Simple " << endl;
            cout << "F) Cryptage avec Fichier de Codes " << endl;
            cout << "Q) Quitter"<< endl;

            // saisie réponse >> choix
            cout << endl << "votre choix ? " ;
            cin >> choix;
            cout << " " << endl;
        }
        while (!
                ((toupper(choix) == 'Q') || (toupper(choix) == 'S') || (toupper(choix) == 'F'))
              );

        if (toupper(choix) != 'Q')
        {
            // choix >> traiter action demandee
            switch (toupper(choix))
            {
                case 'S' :  // Cryptage Simple - cas A.-
                            // saisie nomSystème fichier à Crypter >> nomSystemeFicSource
                            cout << "Entrer le nom systeme du fichier a crypter : " ;
                            cin >> nomSystemeFicSource;

                            // affichage du nom du fichier crypté 
                            nomSystemeFicCible = cryptage(nomSystemeFicSource);
                            cout << "Nom systeme du fichier crypte cree : " << nomSystemeFicCible << endl;
                            break;
                case 'F' : // Cryptage avec fichier de Codes - cas B.-
                            // saisie nomSystème fichier à Crypter >> nomSystemeFicSource
                            cout << "Entrer le nom systeme du fichier a crypter : " ;
                            cin >> nomSystemeFicSource;

                            // saisie nomSystème fichier des Codes de cryptage >> nomSystemeFicCodes
                            cout << "Entrer le nom systeme du fichier contenant les codes de cryptage : " ;
                            cin >> nomSystemeFicCodes;

                            // affichage du nom du fichier crypté 
                            nomSystemeFicCible = cryptage(nomSystemeFicSource, nomSystemeFicCodes);
                            cout << "Nom systeme du fichier crypte cree : " << nomSystemeFicCible << endl;

                            break;
                default : break;
            }

            // pause avant de revenir au menu
            cout << endl << "       ... <entree> pour continuer...";
            std::cin.ignore(100, '\n');
            getline(cin, kk);
        }
    }
    while ( !(toupper(choix) == 'Q'));

    // terminer
    cout << endl << "...au revoir..." << endl;
    return 0;
}

