#ifndef _SOURIS_H
#define _SOURIS_H

#include<stdlib.h>
#include<graph.h>
#include"../affichage/affichage.h"
#include"souris.h"


int clickDansRectangle(position* positionRectangle, taille* tailleRectangle, position* positionSouris, int identifiantBouton);
/* Permet de detecter si l'utilisateur a clické sur un rectangle precis, "identifiantBouton" et un numero quelconque choisi par le developpeur, 
   la fonction renverra cet identifiant si les coordonné du click correspondent a une coordonné dans le rectangle, sinon la fonction renvoi 0*/ 




#endif