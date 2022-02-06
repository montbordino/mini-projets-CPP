#ifndef deuxMilleQuaranteHuit_h 
#define deuxMilleQuaranteHuit_h
#include "game-tools.h"
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

const unsigned short int TAILLE_TABLEAU = 4;

void remplacerMeilleurScore(int score);

unsigned int obtenirMeilleurScore();
// renvoie le score situé dans le fichier "meilleurScore.txt" 

void ajouterNombre(unsigned short int tab[][4]);
// ajoute 2 ou 4 dans le tableau tab

void afficherTableau(unsigned short int tab[][4]);
// affiche le tableau tab 

void deplacerCases(unsigned short int tab[][4], bool tableauDouble[][4], unsigned short int clef, bool &efficace, int& score);
// déplace toutes les cases du tableau tab en fontion de la touhe clef utilisé

bool verifDefaite(const unsigned short int tab[][4]);
// revois un booléen, vrai si le joueur n'a plus de coup possible et faux si il peut encore jouer

void retournerAuDebut();

#endif