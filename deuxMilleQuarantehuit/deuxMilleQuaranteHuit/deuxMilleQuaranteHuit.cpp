#include "deuxMilleQuaranteHuit.h"
#include "fichierTexte.h"

void remplacerMeilleurScore(int score)
{
    UnFichierTexte fich;
    // effacer l'ancien score
    associer(fich, "meilleurScore.txt");
    ouvrir(fich, creation);
    fermer(fich);
    // ajouter le nouveau score
    associer(fich, "meilleurScore.txt");
    ouvrir(fich, extension);
    ecrire(fich, score);
    fermer(fich);
    


}

unsigned int obtenirMeilleurScore()
{
    bool blc;
    int score;
    UnFichierTexte fich;
    associer(fich, "meilleurScore.txt");
    ouvrir(fich, consultation);
    lireMot(fich, score, blc);
    fermer(fich);
    return score;
}

void ajouterNombre(unsigned short int tab[][TAILLE_TABLEAU])
{
    // definir la valeur de newNb
    unsigned short int codeNb = static_cast<unsigned short int>(random(1, 2));
    unsigned short int newNb;
    if (codeNb == 1)
    {
        newNb = 2;
    }
    else
    {
        newNb = 4;
    }

    // definir les coordonnées de newNb
    unsigned short int posX = static_cast<unsigned short int>(random(0, (TAILLE_TABLEAU - 1)));
    unsigned short int posY = static_cast<unsigned short int>(random(0, (TAILLE_TABLEAU - 1)));

    while (tab[posX][posY] != 0)
    {
        posX = static_cast<unsigned short int>(random(0, (TAILLE_TABLEAU - 1)));
        posY = static_cast<unsigned short int>(random(0, (TAILLE_TABLEAU - 1)));
    }

    // ajouter nexNb au tableau
    tab[posX][posY] = newNb;
}

void afficherTableau(unsigned short int tab[][TAILLE_TABLEAU])
{
    const string ESPACE = "     ";
    cout << endl
         << endl
         << ESPACE << " J E U   D U   2 0 4 8 " << endl;
    for (unsigned short int ligne = 0; ligne < TAILLE_TABLEAU; ligne++)
    {
        cout << "\n"
             << ESPACE;
        afficherTexteEnCouleur("+-----+-----+-----+-----+", coteDuTableau);
        cout << "\n"
             << ESPACE;
        afficherTexteEnCouleur("|", coteDuTableau);
        for (unsigned short int colonne = 0; colonne < TAILLE_TABLEAU; colonne++)
        {
            if (tab[ligne][colonne] == 0)
            {
                cout << "     ";
                afficherTexteEnCouleur("|", coteDuTableau);
            }
            else if (tab[ligne][colonne] < 10)
            {
                switch (tab[ligne][colonne])
                {
                case 2:
                    afficherTexteEnCouleur("  ", deux);
                    afficherNombreEnCouleur(tab[ligne][colonne], deux);
                    afficherTexteEnCouleur("  ", deux);
                    break;

                case 4:
                    afficherTexteEnCouleur("  ", quatre);
                    afficherNombreEnCouleur(tab[ligne][colonne], quatre);
                    afficherTexteEnCouleur("  ", quatre);
                    break;
                case 8:
                    afficherTexteEnCouleur("  ", huit);
                    afficherNombreEnCouleur(tab[ligne][colonne], huit);
                    afficherTexteEnCouleur("  ", huit);
                    break;
                }
                afficherTexteEnCouleur("|", coteDuTableau);
            }
            else if (tab[ligne][colonne] < 100)
            {
                switch (tab[ligne][colonne])
                {
                case 16:
                    afficherTexteEnCouleur("  ", huit);
                    afficherNombreEnCouleur(tab[ligne][colonne], huit);
                    afficherTexteEnCouleur(" ", huit);
                    break;

                case 32:
                    afficherTexteEnCouleur("  ", trenteDeux);
                    afficherNombreEnCouleur(tab[ligne][colonne], trenteDeux);
                    afficherTexteEnCouleur(" ", trenteDeux);
                    break;

                case 64:
                    afficherTexteEnCouleur("  ", trenteDeux);
                    afficherNombreEnCouleur(tab[ligne][colonne], trenteDeux);
                    afficherTexteEnCouleur(" ", trenteDeux);
                    break;
                }
                afficherTexteEnCouleur("|", coteDuTableau);
            }
            else if ((tab[ligne][colonne] < 1000))
            {
                afficherTexteEnCouleur(" ", plusDeCent);
                afficherNombreEnCouleur(tab[ligne][colonne], plusDeCent);
                afficherTexteEnCouleur(" ", plusDeCent);
                afficherTexteEnCouleur("|", coteDuTableau);
            }
            else if (tab[ligne][colonne] < 10000)
            {
                if ((tab[ligne][colonne] == 1024)){
                    afficherTexteEnCouleur(" ", plusDeCent);
                    afficherNombreEnCouleur(tab[ligne][colonne], plusDeCent);
                    afficherTexteEnCouleur("|", coteDuTableau);
                }
                else{
                    afficherTexteEnCouleur(" ", plusDeDeuxMille);
                    afficherNombreEnCouleur(tab[ligne][colonne], plusDeDeuxMille);
                    afficherTexteEnCouleur("|", plusDeDeuxMille);
                }
            }
            else
            {
                cout << tab[ligne][colonne] << " ";
                afficherTexteEnCouleur("|", coteDuTableau);
            }
        }
    }
    cout << " \n"
         << ESPACE;
    afficherTexteEnCouleur("+-----+-----+-----+-----+", coteDuTableau);
    cout << "\n";
}

void deplacerCases(unsigned short int tab[][TAILLE_TABLEAU], bool tabDouble[][TAILLE_TABLEAU], unsigned short int clef, bool &efficace, int& score)
{
    for (unsigned short int i = 0; i < TAILLE_TABLEAU; i++)
    {
        for (unsigned short int k = 0; k < TAILLE_TABLEAU; k++)
        {
            tabDouble[i][k] = false;
        }
    }
    efficace = false;
    bool premierTour = true; // permet de faire au moins un tour de boucle
    bool auMoinsUnDeplacement = false;
    while ((auMoinsUnDeplacement == true) || (premierTour == true))
    {
        if (premierTour == false)
        {
            efficace = true;
        }
        auMoinsUnDeplacement = false;
        premierTour = false;

        if ((clef == KEY_LEFT) || (clef == KEY_UP))
        {
            for (unsigned short int ligne = 0; ligne < TAILLE_TABLEAU; ligne++)
            {
                for (unsigned short int colonne = 0; colonne < TAILLE_TABLEAU; colonne++)
                {
                    if (tab[ligne][colonne] != 0)
                    {
                        if (clef == KEY_LEFT)
                        {
                            const short int arrivee = static_cast<short int>(colonne - 1);
                            if (arrivee >= 0)
                            {
                                if (tab[ligne][arrivee] == 0)
                                {
                                    tab[ligne][arrivee] = tab[ligne][colonne];
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;

                                }
                                if ((tab[ligne][colonne] == tab[ligne][arrivee]) && (tabDouble[ligne][arrivee] == false))
                                {
                                    tab[ligne][arrivee] = static_cast<unsigned short int>(2 * tab[ligne][colonne]);
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;
                                    tabDouble[ligne][arrivee] = true;
                                    if (arrivee - 1 >= 0)
                                    {
                                        tabDouble[ligne][arrivee - 1] = true;
                                    }
                                    score += tab[ligne][arrivee];
                                }
                            }
                        }
                        if (clef == KEY_UP)
                        {
                            const short int arrivee = static_cast<short int>(ligne - 1);
                            if (arrivee >= 0)
                            {
                                if (tab[arrivee][colonne] == 0)
                                {
                                    tab[arrivee][colonne] = tab[ligne][colonne];
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;
                                }
                                if ((tab[ligne][colonne] == tab[arrivee][colonne]) && (tabDouble[arrivee][colonne] == false))
                                {
                                    tab[arrivee][colonne] = static_cast<unsigned short int>(2 * tab[ligne][colonne]);
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;
                                    tabDouble[arrivee][colonne] = true;
                                    if (arrivee - 1 >= 0)
                                    {
                                        tabDouble[arrivee - 1][colonne] = true;
                                    }
                                    score += tab[arrivee][colonne];
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            for (short int ligne = static_cast<short int>(TAILLE_TABLEAU - 1); ligne >= 0; ligne--)
            {
                for (short int colonne = static_cast<short int>(TAILLE_TABLEAU - 1); colonne >= 0; colonne--)
                {
                    if (tab[ligne][colonne] != 0)
                    {
                        if (clef == KEY_RIGHT)
                        {
                            const unsigned short int arrivee = static_cast<unsigned short int>(colonne + 1);
                            if (arrivee < TAILLE_TABLEAU)
                            {
                                if (tab[ligne][arrivee] == 0)
                                {
                                    tab[ligne][arrivee] = tab[ligne][colonne];
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;
                                }
                                if ((tab[ligne][colonne] == tab[ligne][arrivee]) && (tabDouble[ligne][arrivee] == false))
                                {
                                    tab[ligne][arrivee] = static_cast<unsigned short int>(2 * tab[ligne][colonne]);
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;
                                    tabDouble[ligne][arrivee] = true;
                                    if (arrivee + 1 < TAILLE_TABLEAU)
                                    {
                                        tabDouble[ligne][arrivee + 1] = true;
                                    }
                                    score += tab[ligne][arrivee];
                                }
                            }
                        }
                        if (clef == KEY_DOWN)
                        {
                            const unsigned short int arrivee = static_cast<unsigned short int>(ligne + 1);
                            if (arrivee < TAILLE_TABLEAU)
                            {
                                if (tab[arrivee][colonne] == 0)
                                {
                                    tab[arrivee][colonne] = tab[ligne][colonne];
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;
                                }
                                if ((tab[ligne][colonne] == tab[arrivee][colonne]) && (tabDouble[arrivee][colonne] == false))
                                {
                                    tab[arrivee][colonne] = static_cast<unsigned short int>(2 * tab[ligne][colonne]);
                                    tab[ligne][colonne] = 0;
                                    auMoinsUnDeplacement = true;
                                    tabDouble[arrivee][colonne] = true;
                                    if (arrivee + 1 < TAILLE_TABLEAU)
                                    {
                                        tabDouble[arrivee + 1][colonne] = true;
                                    }
                                    score += tab[arrivee][colonne];
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void retournerAuDebut(){
    HANDLE idTerminal;
    COORD coordonneesOrigine = {0, 0};
    idTerminal = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(idTerminal, coordonneesOrigine);
    if (idTerminal == INVALID_HANDLE_VALUE)
    {
        return;
    }
}

bool verifDefaite(const unsigned short int tab[][4]){
    bool resultat = true;
    for (unsigned short int ligne = 0; ligne < TAILLE_TABLEAU; ligne++){
        for (unsigned short int colonne = 0; colonne < TAILLE_TABLEAU; colonne++){
            if (tab[ligne][colonne] == 0){
                ligne = TAILLE_TABLEAU; colonne = TAILLE_TABLEAU;
                resultat = false;
            }
            const short int arrivee = static_cast<short int>(colonne - 1);
            if (arrivee >= 0){
                if (tab[ligne][colonne] == tab[ligne][arrivee]){
                    ligne = TAILLE_TABLEAU; colonne = TAILLE_TABLEAU;
                    resultat = false;
                }
            }
        }
    }
    return resultat;
}