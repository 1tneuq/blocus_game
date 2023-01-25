#ifndef _FONCTIONNEMENTJEU_H
#define _FONCTIONNEMENTJEU_H

#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "../affichage/affichage.h"
#include "fonctionnementJeu.h"

/*Structures pour la liste chainée*/
typedef struct Element Element;
struct Element{
    position coordonnees;
    Element *suivant;
};

typedef struct Liste{
    Element *premier;
}Liste;

/*Structure pour des cellules temporaires qui serviront au test de la victoire*/
typedef struct CelluleTemporaire{
  position c1;
  position c2;
  position c3;
  position c4;
  position c5;
  position c6;
  position c7;
  position c8;
}celTemp;

void DelaiPourIa(unsigned int tempsDelai);
/*Rajoute un délai de [tempsDelai] millisecondes à une action*/

int CelluleDehors(position posCellule, position posGrille, int nbCases);
/*Fonction qui empêche de placer un élément en dehors du plateau*/

position CoordonnesCaseCliquee(int nbCellulesParLigne, position grille);
/*Fonction qui renvoie les coordonnées de la case où l'on a cliqué*/

Liste *InitPrison(position premiereCroixPosee);
/*Fonction qui initialise la liste répertoriant les cases occupées*/

void AjouterCaseCondamnee(Liste *liste, position nouvelleCaseCondamnee);
/*Fonction qui remplit au fur et à mesure la liste répertoriant les cases occupées*/

int VerifierCondamnation(Liste *liste, position caseAVerifier);
/*Fonction qui vérifie si une case est occupée*/

void SupprimerPrison(Liste *liste);
/*Fonction qui libère l'espace mémoire occupé par la "prison" de cases*/

void CondamnerCasesAutour(position positionGrille, int nombreDeCasesParLigne, Liste *p);
/*Fonction qui permet de condamner les cases qui entourent le plateau de jeu*/

int TestVictoire(position dernierePosPion,position dernierePosAutrePion, Liste *p);
/*Fonction qui teste si une case est entourée de cases condamnée*/

int NombreAleatCase();
/*Fonction pour simplifier les calculs du choix de case "aléatoire", et ainsi rendre le jeu plus réactif et limiter la charge su cpu*/

position CaseChoisieParIa(int nbCasesLigne, position unPion, position positionGrille);
/*L'"IA" choisit une case aléatoire*/

int Multijoueur(int nombreDeCellulesParLigne);
/*Fonction pour jouer en mode multijoueur à 2*/

int Ia(int nombreDeCellulesParLigne);
/*Fonction pour jouer en 1v1 contre une pseudo IA*/

#endif
