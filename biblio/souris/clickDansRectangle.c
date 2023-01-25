#include<stdlib.h>
#include<graph.h>
#include"./souris.h"

int clickDansRectangle(position* positionRectangle, taille* tailleRectangle, position* positionSouris, int identifiantBouton) {

	int compteurL=0, compteurH=0;
	int retourIdentifiant=0;
	int verifPosition=0;

	for(compteurL=positionRectangle->x;compteurL<positionRectangle->x+tailleRectangle->l;compteurL++){/*On compare toute les x et tout les y dans le bouton aux x et y de la souris*/

			if(positionSouris->x==compteurL){
				verifPosition++;
			}
		}

		for(compteurH=positionRectangle->y; compteurH < (positionRectangle->y+tailleRectangle->h); compteurH++){

			if(positionSouris->y==compteurH){
				verifPosition++;
			}
		}

		if (verifPosition==2) retourIdentifiant=identifiantBouton; 
  
return retourIdentifiant;
}
