#include <stdlib.h>
#include <stdio.h>
#include </usr/include/graph.h>
#include "./affichage.h"


position PositionCellule(int xsouris, int ysouris, int tailleMax, position coordGrille){
  position posSortie;
  int i=1, j=1;
  for(i=coordGrille.x;i<coordGrille.x+tailleMax*80;i=i+80){
    if(xsouris>=i){
      posSortie.x=i;
    }
  }
  for(j=coordGrille.x;j<coordGrille.x+tailleMax*80;j=j+80){
    if(ysouris>=j){
      posSortie.y=j;
    }
  }
  posSortie.x=posSortie.x;
  posSortie.y=posSortie.y;
  return posSortie;
}


void DessinerCroixViolet(position croix){
  int croixViolet;
  croixViolet=ChargerSprite("./sprites/croixviolet90px.png");
  AfficherSprite(croixViolet,croix.x-5,croix.y-5);
  LibererSprite(croixViolet);
  /*return croix;*/
}

void DessinerCroixJaune(position croix){
  int croixJaune;
  croixJaune=ChargerSprite("./sprites/croixjaune90px.png");
  AfficherSprite(croixJaune,croix.x-5,croix.y-5);
  LibererSprite(croixJaune);
  /*return croix;*/
}

void DessinerPionJaune(position pion){
  int pionJaune;
  pionJaune=ChargerSprite("./sprites/pionjaune90px.png");
  AfficherSprite(pionJaune,pion.x-5,pion.y-5);
  LibererSprite(pionJaune);
  /*return pion;*/
}

void DessinerPionViolet(position pion){
  int pionViolet;
  pionViolet=ChargerSprite("./sprites/pionviolet90px.png");
  AfficherSprite(pionViolet,pion.x-5,pion.y-5);
  LibererSprite(pionViolet);
  /*return pion;*/
}

void DessinerCellules(int nombreParLigne, int x, int y, int hauteurCase){
  taille cellule;
  int i=1, j=1;
  cellule.h=hauteurCase;
  cellule.l=cellule.h;
  for(j=0;j<(nombreParLigne*hauteurCase);j=j+hauteurCase){
    for(i=0;i<(nombreParLigne*hauteurCase);i=i+hauteurCase){
      DessinerRectangle(x+i,y+j,hauteurCase,hauteurCase);
    }
  }
}


position DessinerGrille(int nombreDeCasesParLigne, int hauteurDuneCase, int tailleFenetre){
  taille grille={nombreDeCasesParLigne*hauteurDuneCase,nombreDeCasesParLigne*hauteurDuneCase}, cellule, fenetre;
  position coordGrille, coordFenetre;

  cellule.h=hauteurDuneCase;
  cellule.l=cellule.h;
  fenetre.h=tailleFenetre;
  fenetre.l=fenetre.h;
  coordFenetre.x=0;
  coordFenetre.y=0;

  coordGrille=centrerRectangleXY(&fenetre,&grille,&coordFenetre);
  ChoisirCouleurDessin(CouleurParComposante(0,0,0));
  DessinerRectangle(coordGrille.x,coordGrille.y,grille.h,grille.l);
  DessinerCellules(grille.h/cellule.h,coordGrille.x,coordGrille.y,cellule.h);
  return coordGrille;
}

void EffacerCellule(position cellule){
  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(cellule.x+1,cellule.y+1,79,79);
}

void EffacerGrille(position posGrille, int nbCellulesParLigne){
  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(posGrille.x,posGrille.y,(nbCellulesParLigne+5)*80,(nbCellulesParLigne+5)*80);
}

void EffacerTexte(){
  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(0,60,1000,50);
}
