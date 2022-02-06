#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>
using namespace std;

void viderFichierTexte(string nomSysFic);
// Si le fichier de nom système nomSysFic existe déjà, le vide de ses éléments,
// Si le fichier n'existe pas, le crée vide.
// = Exemple du cours

void afficherFichierTexte (string nomSysFic);
// affiche à l'écran le contenu d'un fichier de texte de nom systeme nomFic

void afficherInverseFichierTexte(string nomSysFic);
// affiche à l'écran le contenu d'un fichier de texte de nom systeme nomFic.
// L'affichage est à l'envers, cad :
// dernière ligne du fichier texte --> 1ere ligne écran
//...
// 1ère ligne du fichier texte --> derniere ligne de l'écran

void etendreFichierTexte(string nomSysFicSource, string nomSysFicCible);
// transfère le contenu d'un fichier de texte nomSysFicSource en fin d'un autre fichier 
// de texte nomSysFicCible.
// Les fichiers sont identifiés par leurs noms système


#endif
