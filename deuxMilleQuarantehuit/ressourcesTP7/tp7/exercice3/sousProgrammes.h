#ifndef SOUSPROGRAMMES_H
#define SOUSPROGRAMMES_H
#include <iostream>
using namespace std;

string cryptage (string nomSysFicSource);
/*
Recopie le contenu d'un fichier texte, dont le nom système nomSysFicSource est fourni 
en paramètre, dans un autre fichier texte.
La copie se fait en modifiant les voyelles, de la manière suivante :
'a' devient 'e', 'e' devient 'i', 'i' devient 'o', … 'y' devient 'a', 'A' devient 'E',
'E' devient 'I', etc…
La copie ne modifie pas les autres caractères que les voyelles.

Le nom système du fichier fabriqué est retourné par la fonction, en ajoutant 
le terme "_crypted" au nom système fourni.
*/

string cryptage (string nomSysFicSource, string nomSysFicCodes);
/*
Recopie le contenu d'un fichier texte, dont le nom système nomSysFicSource est fourni 
en paramètre, dans un autre fichier texte.
La copie se fait en modifiant les caractères selon les correspondances fournies dans 
le fichier dont le nom système nomSysFicCodes est fourni en paramètre, 
et dont le format est spécifié dans le sujet.
La copie ne modifie pas les caractères ne figurant pas dans le fichier de codes.

Le nom système du fichier fabriqué est retourné par la fonction, 
en ajoutant le terme "_crypted" au nom système fourni.  
*/

#endif


