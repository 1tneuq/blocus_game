#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "../affichage/affichage.h"
#include "./fonctionnementJeu.h"

/*Fonction qui permet d'ajouter un délai de [tempsDelai] millisecondes avant une action*/
void DelaiPourIa(unsigned int tempsDelai){
     time_t tempsFin=time(NULL)+(time_t)tempsDelai;
     for(;time(NULL)<tempsFin/1000;);
}

/*Fonction qui empêche de placer un élément en dehors du plateau*/
int CelluleDehors(position posCellule, position posGrille, int nbCases){
  position limiteGrille;
  limiteGrille.x=posGrille.x+nbCases*80;
  limiteGrille.y=posGrille.y+nbCases*80;

  if((posCellule.x<posGrille.x || posCellule.x>limiteGrille.x) || (posCellule.y<posGrille.y || posCellule.y>limiteGrille.y)){
    return 1;
  }else{
    return 0;
  }
}

/*Fonction qui renvoie les coordonnées de la case où l'on a cliqué*/
position CoordonnesCaseCliquee(int nbCellulesParLigne, position grille){
  int flag=0;
  position cellule, souris;

  while(flag==0){
    while(SourisCliquee()==0){
      SourisPosition();
      souris.x=_X;
      souris.y=_Y;
    }
  cellule=PositionCellule(souris.x, souris.y, nbCellulesParLigne, grille);
  flag=1;
  }
  return cellule;
}

/*Fonction qui initialise la liste répertoriant les cases occupées*/
Liste *InitPrison(position premiereCroixPosee){
    Liste *liste=malloc(sizeof(*liste));
    Element *element=malloc(sizeof(*element));

    if (liste==NULL || element==NULL){
        exit(EXIT_FAILURE);
    }

    element->coordonnees=premiereCroixPosee;
    element->suivant=NULL;
    liste->premier=element;

    return liste;
}

/*Fonction qui remplit au fur et à mesure la liste répertoriant les cases occupées*/
void AjouterCaseCondamnee(Liste *liste, position nouvelleCaseCondamnee){
    /* Création du nouvel élément */
    Element *nouveau=malloc(sizeof(*nouveau));
    if (liste==NULL || nouveau==NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->coordonnees=nouvelleCaseCondamnee;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant=liste->premier;
    liste->premier=nouveau;
}

/*Fonction qui vérifie si une case est occupée*/
int VerifierCondamnation(Liste *liste, position caseAVerifier){
    int indicateur=0;
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while(actuel != NULL){
        if(caseAVerifier.x==actuel->coordonnees.x && caseAVerifier.y==actuel->coordonnees.y){
          indicateur=1;
        }
        actuel = actuel->suivant;
    }
    return indicateur;
}

/*Fonction qui libère l'espace mémoire occupé par la "prison" de cases*/
void SupprimerPrison(Liste *liste){
    if (liste==NULL){
        exit(EXIT_FAILURE);
    }

    if (liste->premier!=NULL){
        Element *aSupprimer=liste->premier;
        liste->premier=liste->premier->suivant;
        free(aSupprimer);
    }
}

/*Fonction qui permet de condamner les cases qui entourent le plateau de jeu*/
void CondamnerCasesAutour(position positionGrille, int nombreDeCasesParLigne, Liste *p){
  int i=0;
  position limiteGrille, condamnee;
  limiteGrille.x=positionGrille.x+nombreDeCasesParLigne*80;
  limiteGrille.y=positionGrille.y+nombreDeCasesParLigne*80;

  for(i=0;i<nombreDeCasesParLigne*80;i=i+80){
    condamnee.x=positionGrille.x+i;
    condamnee.y=positionGrille.y-80;
    AjouterCaseCondamnee(p, condamnee);
    /*ChoisirCouleurDessin(CouleurParNom("red"));
    RemplirRectangle(condamnee.x,condamnee.y,80,80);*/

    condamnee.x=positionGrille.x-80;
    condamnee.y=positionGrille.y+i;
    AjouterCaseCondamnee(p, condamnee);


    condamnee.x=positionGrille.x+i;
    condamnee.y=limiteGrille.y;
    AjouterCaseCondamnee(p, condamnee);

    condamnee.x=limiteGrille.x;
    condamnee.y=positionGrille.y+i;
    AjouterCaseCondamnee(p, condamnee);
  }

  condamnee.x=limiteGrille.x;
  condamnee.y=limiteGrille.y;
  AjouterCaseCondamnee(p, condamnee);

  condamnee.x=positionGrille.x-80;
  condamnee.y=positionGrille.y-80;
  AjouterCaseCondamnee(p, condamnee);

  condamnee.x=positionGrille.x-80;
  condamnee.y=limiteGrille.y;
  AjouterCaseCondamnee(p, condamnee);

  condamnee.x=limiteGrille.x;
  condamnee.y=positionGrille.y-80;
  AjouterCaseCondamnee(p, condamnee);

}

/*Fonction qui teste si une case est entourée de cases condamnée*/
int TestVictoire(position dernierePosPion, position dernierePosAutrePion, Liste *p){
  celTemp celluleTest;

  /*Initialisation de toutes les cellules temporaires*/
  celluleTest.c1.x=dernierePosPion.x;
  celluleTest.c1.y=dernierePosPion.y-80;
  celluleTest.c2.x=dernierePosPion.x+80;
  celluleTest.c2.y=dernierePosPion.y-80;
  celluleTest.c3.x=dernierePosPion.x+80;
  celluleTest.c3.y=dernierePosPion.y;
  celluleTest.c4.x=dernierePosPion.x+80;
  celluleTest.c4.y=dernierePosPion.y+80;
  celluleTest.c5.x=dernierePosPion.x;
  celluleTest.c5.y=dernierePosPion.y+80;
  celluleTest.c6.x=dernierePosPion.x-80;
  celluleTest.c6.y=dernierePosPion.y+80;
  celluleTest.c7.x=dernierePosPion.x-80;
  celluleTest.c7.y=dernierePosPion.y;
  celluleTest.c8.x=dernierePosPion.x-80;
  celluleTest.c8.y=dernierePosPion.y-80;

  /*Test pour voir si les cases adjacentes sont occupees*/
  if(VerifierCondamnation(p, celluleTest.c1)==1
  && VerifierCondamnation(p, celluleTest.c2)==1
  && VerifierCondamnation(p, celluleTest.c3)==1
  && VerifierCondamnation(p, celluleTest.c4)==1
  && VerifierCondamnation(p, celluleTest.c5)==1
  && VerifierCondamnation(p, celluleTest.c6)==1
  && VerifierCondamnation(p, celluleTest.c7)==1
  && VerifierCondamnation(p, celluleTest.c8)==1){
    return 1;
  }else if((celluleTest.c1.x==dernierePosAutrePion.x && celluleTest.c1.y==dernierePosAutrePion.y)
    && VerifierCondamnation(p, celluleTest.c2)==1
    && VerifierCondamnation(p, celluleTest.c3)==1
    && VerifierCondamnation(p, celluleTest.c4)==1
    && VerifierCondamnation(p, celluleTest.c5)==1
    && VerifierCondamnation(p, celluleTest.c6)==1
    && VerifierCondamnation(p, celluleTest.c7)==1
    && VerifierCondamnation(p, celluleTest.c8)==1){
      return 1;
    }else if(VerifierCondamnation(p, celluleTest.c1)==1
      && (celluleTest.c2.x==dernierePosAutrePion.x && celluleTest.c2.y==dernierePosAutrePion.y)
      && VerifierCondamnation(p, celluleTest.c3)==1
      && VerifierCondamnation(p, celluleTest.c4)==1
      && VerifierCondamnation(p, celluleTest.c5)==1
      && VerifierCondamnation(p, celluleTest.c6)==1
      && VerifierCondamnation(p, celluleTest.c7)==1
      && VerifierCondamnation(p, celluleTest.c8)==1){
        return 1;
      }else if(VerifierCondamnation(p, celluleTest.c1)==1
        && VerifierCondamnation(p, celluleTest.c2)==1
        && (celluleTest.c3.x==dernierePosAutrePion.x && celluleTest.c3.y==dernierePosAutrePion.y)
        && VerifierCondamnation(p, celluleTest.c4)==1
        && VerifierCondamnation(p, celluleTest.c5)==1
        && VerifierCondamnation(p, celluleTest.c6)==1
        && VerifierCondamnation(p, celluleTest.c7)==1
        && VerifierCondamnation(p, celluleTest.c8)==1){
          return 1;
        }else if(VerifierCondamnation(p, celluleTest.c1)==1
          && VerifierCondamnation(p, celluleTest.c2)==1
          && VerifierCondamnation(p, celluleTest.c3)==1
          && (celluleTest.c4.x==dernierePosAutrePion.x && celluleTest.c4.y==dernierePosAutrePion.y)
          && VerifierCondamnation(p, celluleTest.c5)==1
          && VerifierCondamnation(p, celluleTest.c6)==1
          && VerifierCondamnation(p, celluleTest.c7)==1
          && VerifierCondamnation(p, celluleTest.c8)==1){
            return 1;
          }else if(VerifierCondamnation(p, celluleTest.c1)==1
            && VerifierCondamnation(p, celluleTest.c2)==1
            && VerifierCondamnation(p, celluleTest.c3)==1
            && VerifierCondamnation(p, celluleTest.c4)==1
            && (celluleTest.c5.x==dernierePosAutrePion.x && celluleTest.c5.y==dernierePosAutrePion.y)
            && VerifierCondamnation(p, celluleTest.c6)==1
            && VerifierCondamnation(p, celluleTest.c7)==1
            && VerifierCondamnation(p, celluleTest.c8)==1){
              return 1;
            }else if(VerifierCondamnation(p, celluleTest.c1)==1
              && VerifierCondamnation(p, celluleTest.c2)==1
              && VerifierCondamnation(p, celluleTest.c3)==1
              && VerifierCondamnation(p, celluleTest.c4)==1
              && VerifierCondamnation(p, celluleTest.c5)==1
              && (celluleTest.c6.x==dernierePosAutrePion.x && celluleTest.c6.y==dernierePosAutrePion.y)
              && VerifierCondamnation(p, celluleTest.c7)==1
              && VerifierCondamnation(p, celluleTest.c8)==1){
                return 1;
              }else if(VerifierCondamnation(p, celluleTest.c1)==1
                && VerifierCondamnation(p, celluleTest.c2)==1
                && VerifierCondamnation(p, celluleTest.c3)==1
                && VerifierCondamnation(p, celluleTest.c4)==1
                && VerifierCondamnation(p, celluleTest.c5)==1
                && VerifierCondamnation(p, celluleTest.c6)==1
                && (celluleTest.c7.x==dernierePosAutrePion.x && celluleTest.c7.y==dernierePosAutrePion.y)
                && VerifierCondamnation(p, celluleTest.c8)==1){
                  return 1;
                }else if(VerifierCondamnation(p, celluleTest.c1)==1
                  && VerifierCondamnation(p, celluleTest.c2)==1
                  && VerifierCondamnation(p, celluleTest.c3)==1
                  && VerifierCondamnation(p, celluleTest.c4)==1
                  && VerifierCondamnation(p, celluleTest.c5)==1
                  && VerifierCondamnation(p, celluleTest.c6)==1
                  && VerifierCondamnation(p, celluleTest.c7)==1
                  && (celluleTest.c8.x==dernierePosAutrePion.x && celluleTest.c8.y==dernierePosAutrePion.y)){
                    return 1;
                  }else{
                    return 0;
                  }
}

/*Fonction pour simplifier les calculs du choix de case "aléatoire", et ainsi rendre le jeu plus réactif et limiter la charge su cpu*/
int NombreAleatCase(){
  srand(time(NULL));
  int nombre, nombreFin;

  nombre=rand()%(2+1);
  if(nombre==0){
    nombreFin=-80;
  }else if(nombre==1){
    nombreFin=0;
  }else{
    nombreFin=80;
  }

  return nombreFin;
}

/*Fonction pour simuler un clic aléatoire sur une case adjacente d'un pion*/
position CaseChoisieParIa(int nbCasesLigne, position unPion, position positionGrille){
  srand(time(NULL));
  position intermediaire, celluleAleat;


  intermediaire.x=unPion.x+NombreAleatCase();
  intermediaire.y=unPion.y+NombreAleatCase();
  celluleAleat=PositionCellule(intermediaire.x, intermediaire.y, nbCasesLigne, positionGrille);
  return celluleAleat;
}
