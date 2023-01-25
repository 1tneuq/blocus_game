#ifndef _AFFICHAGE_H
#define _AFFICHAGE_H

#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"affichage.h"


typedef  struct LH{
		int l;
		int h;
	}taille;

typedef  struct XY{
	int x;
	int y;
}position;

typedef  struct PosSegment{
  int x;
  int y;
  int xx;
  int yy;
}positionSegment;

typedef  struct PosCroix{
  int x;
  int y;
  int xx;
  int yy;  /*Position du premier Segment*/

  int xxx;
  int yyy;
  int xxxx;
  int yyyy; /*Position du deuxieme Segment*/
}positionCroix;

typedef struct parametrePartie
{
  int nombreDeJoueur;
  int tailleGrille;
  
}paramPartie;





position positionCentre(taille* element, position* positionElement);
/*Permet d'afficher les coordonnés du point au centre du rectangle element, ces coordonnées sont renvoyés sous la forme d'une structure position*/



position centrerDessinerRectangleXY(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur,int rempliOuVide,couleur couleurDessin,int ecran);
/*Permet de dessiner un rectangle totalement centrer dans son conteneur(un autre rectangle), renvoit la position du coin en haut a gauche du rectangle dessiner dans une structure position
  rempli ou vide : 1 pour rempli, 0 pour vide
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

position centrerDessinerRectangleVertical(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur,int rempliOuVide,couleur couleurDessin,int ecran,int decalementY);
/*Permet de dessiner un rectangle centrer verticalement dans son conteneur(un autre rectangle), renvoit la position du rectangle dessiner dans une structure position
  decalementY : le decalement vertical par rapport au haut de la fenetre
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

position centrerDessinerRectangleHorizontal(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur,int rempliOuVide,couleur couleurDessin,int ecran,int decalementX);
/*Permet de dessiner un rectangle centrer horizontalement dans son conteneur(un autre rectangle), renvoit la position du coin en haut a gauche du rectangle dessiner dans une structure position
  decalementX : le decalement horizontal par rapport au coté gauche de la fenetre*/

positionCroix centrerDessinerCroixXY(taille* tailleConteneur,position* posConteneur,couleur couleurDessin,int ecran);
/*Permet de centrer une croix dans un conteneur(un rectangle), renvoit la position de la croix dans une structure "positionCroix"*/

position centrerRectangleXY(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur);
/*meme fonctionnement que centrerDessinerRectangleXY pour le conteneur et ce quelle renvoit, la difference est que le rectangle n'est pas affiché
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

position centrerRectangleVertical(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur);
/*meme fonctionnement que centrerDessinerRectangleVertical pour le conteneur et ce quelle renvoit, la difference est que le rectangle n'est pas affiché
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

position centrerRectangleHorizontal(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur);
/*meme fonctionnement que centrerDessinerRectangleHorizontal pour le conteneur et ce quelle renvoit, la difference est que le rectangle n'est pas affiché
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

position centrerEcrireTexteXY(taille* tailleConteneur,char * texte ,position* posConteneur,couleur couleurTexte,int tailleTexte,int ecran);
/*Permet d'ecrire un texte totalement centrer dans son conteneur(un rectangle), renvoit la position du texte dans une structure position
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

position centrerEcrireTexteVertical(taille* tailleConteneur,char * texte ,position* posConteneur,couleur couleurTexte,int tailleTexte,int ecran,int decalementY);
/*Permet d'ecrire un texte centrer verticalement dans son conteneur(un rectangle), renvoit la position du texte dans une structure position
  decalementY : le decalement vertical du texte par rapport au haut de la fenetre
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

position centrerEcrireTexteHorizontal(taille* tailleConteneur,char * texte ,position* posConteneur,couleur couleurTexte,int tailleTexte,int ecran,int decalementX);
/*Permet d'ecrire un texte centrer horizontalement dans son conteneur(un rectangle), renvoit la position du texte dans une structure position
  decalementX: le decalement horizontal du texte par rapport au coté gauche de la fenetre
  la fonction renvoit une structure rempli de 0 si une erreur est detecté*/

void DessinerCellules(int nombreParLigne, int x, int y, int hauteurCase);
/*Fonction qui remplit la grille avec des cases avec comme paramètres le nombre de cases par ligne, les coordonnées de la première case ainsi que la taille de la case en pixels*/

position DessinerGrille(int nombreDeCasesParLigne, int hauteurDuneCase, int tailleFenetre);
/*Fonction qui affiche le contour de la grille, puis fait appel à la première fonction pour la remplir. Cette fonction renvoie également la position de la grille*/

position PositionCellule(int xsouris, int ysouris, int tailleMax, position coordGrille);
/*Permet de récupérer la position (x,y) d'une cellule, à partir d'un clic au sein de cette dernière*/

void DessinerCroixViolet(position croix);
/*Permet de placer une croix violette dans peu importe la cellule où l'on a cliqué*/

void DessinerCroixJaune(position croix);
/*Permet de placer une croix jaune dans peu importe la cellule où l'on a cliqué*/

void DessinerPionJaune(position pion);
/*Pion jaune*/

void DessinerPionViolet(position pion);
/*Pion violet*/

void EffacerCellule(position cellule);
/*"Effacer" une case*/

void EffacerGrille(position posGrille, int nbCellulesParLigne);
/*Pour avoir un ecran tout beau tout propre*/

void EffacerTexte();
/*Pareil avec le texte du haut*/

paramPartie afficherAccueil(int ecran, taille tailleFenetre);
/*Affiche l'ecran d'accueil dans l'ecran passer en parametre*/

int afficherFin(int ecran, int codeVictoire,taille tailleFenetre);
/*Affiche l'ecran de fin dans l'ecran passé en parametre*/

#endif
