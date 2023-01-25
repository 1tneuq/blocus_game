#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "./biblio/affichage/affichage.h"
#include "./biblio/fonctionnement/fonctionnementJeu.h"

int main(void){
  int i=0;
  paramPartie choixDebut;
  taille fenetre={1000,1000};
  InitialiserGraphique();
  CreerFenetre(0,0,1000,1000);

  do{
    choixDebut=afficherAccueil(0,fenetre);
    if(choixDebut.nombreDeJoueur==1){
      i=Ia(choixDebut.tailleGrille);
    }else if(choixDebut.nombreDeJoueur==2){
      i=Multijoueur(choixDebut.tailleGrille);
    }
  }while(afficherFin(0,i,fenetre));

 

  FermerGraphique();
  return EXIT_SUCCESS;
}
