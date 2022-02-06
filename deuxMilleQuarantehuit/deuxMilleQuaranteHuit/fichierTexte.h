#ifndef FICHIERSTEXTE_H
#define FICHIERSTEXTE_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


enum UnModeOuverture {consultation, creation, extension};
struct UnFichierTexte
{
    string nom;                    // Nom syst�me du fichier
    UnModeOuverture modeOuverture; // Pr�cise le mode d'ouverture : consultation, creation, ...
    bool modeOuvertureDefini;      // Indique si le mode d'ouverture du fichier est d�fini ou pas
    fstream donnees;               // les donn�es du fichier
} ;

void associer ( UnFichierTexte& f,
                string nom);
/* relie le NOM LOGIQUE du fichier (ou "fichier logique") � son NOM SYSTEME
  -- (ou "fichier physique")
  -- : ne peut occasionner aucune erreur
*/

void ouvrir ( UnFichierTexte& f,
              UnModeOuverture mode);
/*rend le fichier disponible pour les Entr�es/Sorties autoris�es
  -- : peut occasionner erreurDeStatut si le fichier est d�j� ouvert,
  --                    erreurDeNomOuUsage : le fichier n'a pu �tre ouvert,
  --                          * DeNom, si le nom est ill�gal ou le fichier inexistant,
  --                          * DUsage, si les protections du fichiers rendent l'op�ration ill�gale
*/

void fermer ( UnFichierTexte& f);
/*rend le mode du fichier ind�fini, et donc le fichier indisponible pour toutes
  -- les Entr�es/Sorties
  -- : peut occasionner erreurDeStatut si le fichier n'est pas ouvert
  -- :                  erreurInconnue si la fermeture n'a pu se faire (fichier corrompu...)
*/

void lireLigne ( UnFichierTexte& f,
                 string& chaine,
                 bool& finFichier);
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a une ligne suivante (chaine suivie d'un caract�re FIN_DE_LIGNE ou FIN_DE_FICHIER) :
  --		son contenu est affect� au param�tre chaine
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas de ligne suivante (uniquement le caract�re FIN_DE_FICHIER trouv�):
  --		le param�tre chaine n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/

void lireCar ( UnFichierTexte& f,
               char& item,
               bool& finFichier);
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�e):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/

void lireMot ( UnFichierTexte& f,
               string& item,
               bool& finFichier);
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�e):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/

void lireMot ( UnFichierTexte& f,
               int& item,
               bool& finFichier);
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�e):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/

void lireMot ( UnFichierTexte& f,
               float& item,
               bool& finFichier);
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�e):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/

void lireMot ( UnFichierTexte& f,
               bool& item,
               bool& finFichier);
/*pour les modes consultation (et Modification NON FAIT), 2 cas de retour
  -- 	S'il y a un item suivant (item suivi d'un caract�re s�parateur) :
  --		son contenu est affect� au param�tre item
  --		le param�tre finFichier est retourn� � Faux
  -- 	S'il n'y a pas d'item (fin de fichier  trouv�e):
  --		le param�tre item n'est pas modifi�
  --		le param�tre finFichier est retourn� � Vrai
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit la consultation,
  --                    erreurInconnue si la consultation s'est mal d�roul�e (fichier corrompu...)
*/

void ecrireLigne ( UnFichierTexte& f,
                   string item);
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier, suivi d'un caract�re FIN_DE_LIGNE
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              string item);
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              char* item);
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)

  ATTENTION
  Cette version surcharg�e de la proc�dure est n�cessaire pour pouvoir prendre en charge l'appel :
  ecrire(monFichier, "bonjour");
    car, par d�faut, les constantes litt�rales cha�nes sont consid�r�es comme des bool.
         car C++ consid�re la constante string litt�rale comme un char* ...  puis comme bool (cf. document stackOverflow ci-joint)

  Si on ne met pas � disposition cette proc�dure, il faudrait forcer le typage de la constante litt�rale string au moment
  de l'appel de la proc�dure ecrire(  UnFichierTexte& f, string item) de la mani�re suivante :
  ecrire (monFichier, (string) "bonjour");

  Ce probl�me ne se pose pas lorsque la chaine se trouve dans une variable string pr�alablement d�clar�e.
  string maChaine = "bonjour";
  ecrire (monFichier, maChaine);  ... fait appel � la bonne proc�dure surcharg�e ayant le param�tre string item.

*/

void ecrire ( UnFichierTexte& f,
              char item);
/*pour les modes creation et extension, le contenu du param�tre chaine
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              int item);
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              float item);
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/

void ecrire ( UnFichierTexte& f,
              bool item);
/*pour les modes creation et extension, le contenu du param�tre item
  -- est enregistr� en fin de fichier
  -- : peut occasionner erreurDeMode si le mode d'ouverture interdit l'�criture,
  --                    erreurInconnue si l'�criture s'est mal d�roul�e (plus d'espace disque, fichier corrompu...)
*/

bool estOuvert (UnFichierTexte& f);
/* retourne VRAI si le fichier est ouvert, FAUX sinon */

string nomSysteme (UnFichierTexte& f);
/* retourne le nom du fichier sur le disque */

void renommer (UnFichierTexte& f, string nouveauNom);
/* Change le nom du fichier f.nom par nouveauNom, o� f est le nom logique d'un fichier texte.
   Op�ration effectu�e directement sur le fichier, sans utilisation de flot C++.
   Si f.nom et nouveauNom pr�cisent diff�rentes localisations (r�pertoires),
   le syst�me d�place le fichier vers le nouvel emplacement.
   Si nouveauNom fait r�f�rence � un fichier existant, la fonction peut �chouer ou �craser
   le fichier existant, cela d�pend du syst�me d'exploitation.
   Le fichier f doit �tre *ferm�* pour que l'op�ration r�ussisse.
  -- : peut occasionner ereurInconnue si l'op�ration �choue
*/

void supprimer (UnFichierTexte& f)  ;
/* Supprime le fichier de nom syst�me associ� au fichier logique f.
   Op�ration effectu�e directement sur le fichier, sans utilisation de flot C++.
   Le fichier doit �tre *ferm�* pour que l'op�ration r�ussisse.
  -- : peut occasionner ereurInconnue si l'op�ration �choue
*/

/**Exceptions
  erreurDeStatut, erreurDeMode, erreurDeNomOuUsage, erreurInconnue;
  erreurDUsage (pour primitive r��crire non impl�ment�e)
**/

#endif //FICHIERSTEXTE_H

