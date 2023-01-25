#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "../affichage/affichage.h"
#include "./fonctionnementJeu.h"


/*Fonction pour jouer contre une pseudo IA*/
int Ia(int nombreDeCellulesParLigne){
  int indicateur=0;
  taille conteneur={1000,1000};
  position posConteneur={0,0}, grille, cellule, dernierePosPionV, dernierePosPionJ;
  Liste *pointeur;

  /*Initialisation du plateau de jeu*/
  EffacerEcran(CouleurParNom("white"));
  grille=DessinerGrille(nombreDeCellulesParLigne, 80, 1000);

  /*Initialisation de la partie*/
  /*Les deux joueurs placent leur pion chacun leur tour*/
  centrerEcrireTexteVertical(&conteneur,"JOUEUR 1 (VIOLET) PLACE SON PREMIER PION...",&posConteneur,CouleurParNom("black"),2,0,100);
  do{
    cellule=CoordonnesCaseCliquee(nombreDeCellulesParLigne,grille);
  }while(
    /*Le pion ne peut pas être placé en dehors de la grille*/
    CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
  );
  DessinerPionViolet(cellule);
  dernierePosPionV=cellule;
  EffacerTexte();

  /*Le deuxième joueur ne peut pas placer son pion sur le premier*/
  centrerEcrireTexteVertical(&conteneur,"JOUEUR 2 (JAUNE) PLACE SON PREMIER PION...",&posConteneur,CouleurParNom("black"),2,0,100);
  /*On donne une position de départ "manuellement" au pion qui varie si l'autre pion la lui vole*/
  do{
    cellule.x=grille.x+2*80;
    cellule.y=grille.y;
    if(cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y){
      cellule.x=grille.x+2*80;
      cellule.y=grille.y+(nombreDeCellulesParLigne-1)*80;
    }

  }while(
    (cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y)
    /*Le pion ne peut pas être placé en dehors de la grille*/
    || CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
  );
  DelaiPourIa(80);
  DessinerPionJaune(cellule);
  dernierePosPionJ=cellule;
  EffacerTexte();

  /*Le premier joueur pose une croix*/
  centrerEcrireTexteVertical(&conteneur,"JOUEUR 1 (VIOLET) PLACE SA PREMIERE CROIX...",&posConteneur,CouleurParNom("black"),2,0,100);
  do{
    cellule=CoordonnesCaseCliquee(nombreDeCellulesParLigne,grille);
  }while(
    /*La croix ne peut pas être posée sur un pion*/
    (cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y)
    || (cellule.x==dernierePosPionJ.x && cellule.y==dernierePosPionJ.y)
    /*La croix ne peut pas être placée en dehors de la grille;*/
    || CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
  );
  DessinerCroixViolet(cellule);
  pointeur=InitPrison(cellule);
  EffacerTexte();

  /*Le deuxième joueur pose sa croix*/
  centrerEcrireTexteVertical(&conteneur,"JOUEUR 2 (JAUNE) PLACE SA PREMIERE CROIX...",&posConteneur,CouleurParNom("black"),2,0,100);
  do{
    cellule=CaseChoisieParIa(nombreDeCellulesParLigne, dernierePosPionV, grille);
  }while(
    /*La croix ne peut pas être posée sur un pion*/
    (cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y)
    || (cellule.x==dernierePosPionJ.x && cellule.y==dernierePosPionJ.y)
    /*La croix ne peut pas être posée sur une case déjà occupée*/
    || VerifierCondamnation(pointeur, cellule)
    /*La croix ne peut pas être placée en dehors de la grille;*/
    || CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
  );
  DelaiPourIa(80);
  DessinerCroixJaune(cellule);
  AjouterCaseCondamnee(pointeur, cellule);
  EffacerTexte();

  /*Les positions de cases invisibles autour du plateau sont condamnées
  au cas où un des joueur serait bloqué contre un bord de la grille*/
  CondamnerCasesAutour(grille, nombreDeCellulesParLigne, pointeur);

  /*Début de la partie*/
  do{
    /*On teste constamment si personne n'a gagné au car sinon, si j2 gagne il faut attendre que j1 joue pour que ca se termine*/
    if(TestVictoire(dernierePosPionJ, dernierePosPionV, pointeur)==0
      && TestVictoire(dernierePosPionV, dernierePosPionJ, pointeur)==0){
        /*Le premier joueur place son pion*/
        centrerEcrireTexteVertical(&conteneur,"JOUEUR 1 (VIOLET) PLACE SON PION ET SA CROIX...",&posConteneur,CouleurParNom("black"),2,0,100);
        do{
          cellule=CoordonnesCaseCliquee(nombreDeCellulesParLigne,grille);
        }while(
          /*Le pion ne peut pas être posé sur un pion, ni rester à la même place*/
          (cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y)
          || (cellule.x==dernierePosPionJ.x && cellule.y==dernierePosPionJ.y)
          /*Le pion ne peut pas être posé sur une case déjà occupée*/
          || VerifierCondamnation(pointeur, cellule)
          /*Le pion ne peut pas être placé en dehors de la grille*/
          || CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
          /*Le pion doit se déplacer sur une case adjacente*/
          || (
              (
                  cellule.x!=dernierePosPionV.x+80
                  && cellule.x!=dernierePosPionV.x-80
                  && cellule.x!=dernierePosPionV.x
                )
                ||
                (
                  cellule.y!=dernierePosPionV.y-80
                  && cellule.y!=dernierePosPionV.y+80
                  && cellule.y!=dernierePosPionV.y
                )
              )
        );
        EffacerCellule(dernierePosPionV);
        DessinerPionViolet(cellule);
        dernierePosPionV=cellule;

        /*Puis il place une croix*/
        do{
          cellule=CoordonnesCaseCliquee(nombreDeCellulesParLigne,grille);
        }while(
          /*La croix ne peut pas être posée sur un pion*/
          (cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y)
          || (cellule.x==dernierePosPionJ.x && cellule.y==dernierePosPionJ.y)
          /*La croix ne peut pas être posée sur une case déjà occupée*/
          || VerifierCondamnation(pointeur, cellule)
          /*La croix ne peut pas être placée en dehors de la grille;*/
          || CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
        );
        DessinerCroixViolet(cellule);
        AjouterCaseCondamnee(pointeur, cellule);
        EffacerTexte();
      }

      /*On teste constamment si personne n'a gagné au car sinon, si j2 gagne il faut attendre que j1 joue pour que ca se termine*/
      if(TestVictoire(dernierePosPionJ, dernierePosPionV, pointeur)==0
        && TestVictoire(dernierePosPionV, dernierePosPionJ, pointeur)==0){
          /*Le deuxième joueur place son pion à son tour*/
          centrerEcrireTexteVertical(&conteneur,"JOUEUR 2 (JAUNE) PLACE SON PION ET SA CROIX...",&posConteneur,CouleurParNom("black"),2,0,100);
          do{
            cellule=CaseChoisieParIa(nombreDeCellulesParLigne, dernierePosPionJ, grille);
          }while(
            /*Le pion ne peut pas être posé sur un pion, ni rester à la même place*/
            (cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y)
            || (cellule.x==dernierePosPionJ.x && cellule.y==dernierePosPionJ.y)
            /*Le pion ne peut pas être posé sur une case déjà occupée*/
            || VerifierCondamnation(pointeur, cellule)
            /*Le pion ne peut pas être placé en dehors de la grille*/
            || CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
            /*Le pion doit se déplacer sur une case adjacente*/
            || (
                (
                    cellule.x!=dernierePosPionJ.x+80
                    && cellule.x!=dernierePosPionJ.x-80
                    && cellule.x!=dernierePosPionJ.x
                  )
                  ||
                  (
                    cellule.y!=dernierePosPionJ.y-80
                    && cellule.y!=dernierePosPionJ.y+80
                    && cellule.y!=dernierePosPionJ.y
                  )
                )
          );
          DelaiPourIa(80);
          EffacerCellule(dernierePosPionJ);
          DessinerPionJaune(cellule);
          dernierePosPionJ=cellule;

          /*Puis il place une croix*/
          do{
            cellule=CaseChoisieParIa(nombreDeCellulesParLigne, dernierePosPionV, grille);
          }while(
            /*La croix ne peut pas être posée sur un pion*/
            (cellule.x==dernierePosPionV.x && cellule.y==dernierePosPionV.y)
            || (cellule.x==dernierePosPionJ.x && cellule.y==dernierePosPionJ.y)
            /*La croix ne peut pas être posée sur une case déjà occupée*/
            || VerifierCondamnation(pointeur, cellule)
            /*La croix ne peut pas être placée en dehors de la grille;*/
            || CelluleDehors(cellule, grille, nombreDeCellulesParLigne)
          );
          DelaiPourIa(80);
          DessinerCroixJaune(cellule);
          AjouterCaseCondamnee(pointeur, cellule);
          EffacerTexte();
        }

  /*A la fin du tour on teste si un des joueurs est bloqué*/
  }while(
    TestVictoire(dernierePosPionJ, dernierePosPionV, pointeur)==0
    && TestVictoire(dernierePosPionV, dernierePosPionJ, pointeur)==0
  );

  /*Affichage des résultats*/
  if(TestVictoire(dernierePosPionV, dernierePosPionJ, pointeur) && TestVictoire(dernierePosPionJ, dernierePosPionV, pointeur)==0){
    centrerEcrireTexteVertical(&conteneur,"JOUEUR 2 (JAUNE) REMPORTE LA VICTOIRE!",&posConteneur,CouleurParNom("black"),2,0,100);
    indicateur=4;
  }
  if(TestVictoire(dernierePosPionJ, dernierePosPionV, pointeur) && TestVictoire(dernierePosPionV, dernierePosPionJ, pointeur)==0){
    centrerEcrireTexteVertical(&conteneur,"JOUEUR 1 (VIOLET) REMPORTE LA VICTOIRE!",&posConteneur,CouleurParNom("black"),2,0,100);
    indicateur=1;
  }
  if(TestVictoire(dernierePosPionV, dernierePosPionJ, pointeur) && TestVictoire(dernierePosPionJ, dernierePosPionV, pointeur)){
    centrerEcrireTexteVertical(&conteneur,"EGALITE! LES DEUX JOUEURS SE SONT BLOQUES!",&posConteneur,CouleurParNom("black"),2,0,100);
    indicateur=3;
  }
  centrerEcrireTexteVertical(&conteneur,"APPUYER SUR UNE TOUCHE POUR CONTINUER",&posConteneur,CouleurParNom("black"),2,0,900);

  Touche();
  SupprimerPrison(pointeur);
  EffacerEcran(CouleurParNom("white"));
  return indicateur;
}
