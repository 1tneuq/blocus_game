#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include"./affichage.h"
#include"../souris/souris.h"

#define POURCENT_X tailleFenetre.l/100
#define POURCENT_Y tailleFenetre.h/100


position positionCentre(taille* element, position* positionElement)
{
	position centre={positionElement->x+element->l/2,positionElement->y+element->h/2};

return centre;
}

position centrerRectangleXY(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur){

	position posRectangle={0,0};/*La structure qui sera retourné*/

    if(tailleConteneur->l < tailleRectangle->l || tailleConteneur->h < tailleRectangle->h ){

    	printf("ERREUR: taille du rectangle > taille du conteneur\n" );
    	return posRectangle;
    }
    	position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */

    	posRectangle.x=(centreConteneur.x-((tailleRectangle->l)/2)); /*on recule l'abscisse du point de depart du rectangle de la moitié de la longueur du rectangle
                                                                       de sorte que le rectangle sois symetrique sur l'axe y */

    	posRectangle.y=(centreConteneur.y-((tailleRectangle->h)/2)); /*on recule l'ordonnée du point de depart du rectangle de la moitié de la hauteur du rectangle
                                                                       de sorte que le rectangle sois symetrique sur l'axe y */


return posRectangle;
}


position centrerRectangleVertical(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur){

	position posRectangle={0,0};/*La structure qui sera retourné*/

    if(tailleConteneur->l < tailleRectangle->l || tailleConteneur->h < tailleRectangle->h ){

    	printf("ERREUR: taille du rectangle > taille du conteneur\n" );
    	return posRectangle;
    }
    	position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */

    	posRectangle.x=(centreConteneur.x-((tailleRectangle->l)/2));/*on recule l'abscisse du point de depart du rectangle de la moitié de la longueur du rectangle
                                                                       de sorte que le rectangle sois symetrique sur l'axe y */

return posRectangle;
}


position centrerRectangleHorizontal(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur){

	position posRectangle={0,0};/*La structure qui sera retourné*/

    if(tailleConteneur->l < tailleRectangle->l || tailleConteneur->h < tailleRectangle->h ){

    	printf("ERREUR: taille du rectangle > taille du conteneur\n" );
    	return posRectangle;
    }
    	position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */

    	posRectangle.y=(centreConteneur.y-((tailleRectangle->h)/2));/*on recule l'ordonnée du point de depart du rectangle de la moitié de la hauteur du rectangle
                                                                       de sorte que le rectangle sois symetrique sur l'axe x */

return posRectangle;
}


position centrerEcrireTexteXY(taille* tailleConteneur,char * texte ,position* posConteneur,couleur couleurTexte,int tailleTexte,int ecran){

	position posTexte={0,0};/*La structure qui sera retourné*/

	taille taTexte={TailleChaineEcran(texte,tailleTexte),TailleSupPolice(tailleTexte)+TailleInfPolice(tailleTexte)}; /*Les dimensions du texte*/

    if(tailleConteneur->l < taTexte.l || tailleConteneur->h < taTexte.h){

    	printf("ERREUR: taille du texte > taille du conteneur du conteneur\n" );
    	return posTexte;
    }
    	position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */


    	posTexte.x=(centreConteneur.x-((taTexte.l)/2)); /*on recule l'abscisse du point d'origine du texte de la moitié de la longueur du texte
                                                                       de sorte que le texte sois symetrique sur l'axe y */

    	posTexte.y=(centreConteneur.y+((taTexte.h)/3)); /*on recule l'ordonnée du point d'origine du texte de la moitié de la hauteur du texte
                                                                       de sorte que le texte sois symetrique sur l'axe y , la division par 3 est uniquement a but estetique*/

        ChoisirEcran(ecran);
        ChoisirCouleurDessin(couleurTexte);

    	EcrireTexte(posTexte.x,posTexte.y,texte,tailleTexte);

return posTexte;
}


position centrerEcrireTexteVertical(taille* tailleConteneur,char * texte ,position* posConteneur,couleur couleurTexte,int tailleTexte,int ecran,int decalementY){

    position posTexte={0,0};/*La structure qui sera retourné*/

    taille taTexte={TailleChaineEcran(texte,tailleTexte),TailleSupPolice(tailleTexte)+TailleInfPolice(tailleTexte)}; /*Les dimensions du texte*/

    if(tailleConteneur->l < taTexte.l || tailleConteneur->h < taTexte.h){

        printf("ERREUR: taille du texte > taille du conteneur du conteneur\n" );
        return posTexte;
    }
        position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */


        posTexte.x=(centreConteneur.x-((taTexte.l)/2)); /*on recule l'abscisse du point d'origine du texte de la moitié de la hauteur du texte
                                                                       de sorte que le texte sois symetrique sur l'axe y */

        posTexte.y=posConteneur->y+decalementY;
        ChoisirEcran(ecran);

        ChoisirCouleurDessin(couleurTexte);

        EcrireTexte(posTexte.x,posTexte.y,texte,tailleTexte);

return posTexte;
}


position centrerEcrireTexteHorizontal(taille* tailleConteneur,char * texte ,position* posConteneur,couleur couleurTexte,int tailleTexte,int ecran,int decalementX){

    position posTexte={0,0};/*La structure qui sera retourné*/

    taille taTexte={TailleChaineEcran(texte,tailleTexte),TailleSupPolice(tailleTexte)+TailleInfPolice(tailleTexte)}; /*Les dimensions du texte*/

    if(tailleConteneur->l < taTexte.l || tailleConteneur->h < taTexte.h){

        printf("ERREUR: taille du texte > taille du conteneur du conteneur\n" );
        return posTexte;
    }
        position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */


        posTexte.y=(centreConteneur.y-((taTexte.h)/3)); /*on recule l'ordonné du point d'origine du texte de la moitié de la longueur du texte
                                                                       de sorte que le texte sois symetrique sur l'axe x  */

        posTexte.x=posConteneur->x+decalementX;
        ChoisirEcran(ecran);

        ChoisirCouleurDessin(couleurTexte);

        EcrireTexte(posTexte.x,posTexte.y,texte,tailleTexte);

return posTexte;
}


position centrerDessinerRectangleXY(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur,int rempliOuVide,couleur couleurDessin,int ecran){

	position posRectangle={0,0};/*La structure qui sera retourné*/

    if(tailleConteneur->l < tailleRectangle->l || tailleConteneur->h < tailleRectangle->h ){

    	printf("ERREUR: taille du rectangle > taille du conteneur\n" );
    	return posRectangle;
    }
    	position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */

    	posRectangle.x=(centreConteneur.x-((tailleRectangle->l)/2)); /*on recule l'abscisse du point de depart du rectangle de la moitié de la longueur du rectangle
                                                                       de sorte que le rectangle sois symetrique sur l'axe y */

    	posRectangle.y=(centreConteneur.y-((tailleRectangle->h)/2)); /*on recule l'ordonnée du point de depart du rectangle de la moitié de la hauteur du rectangle
                                                                       de sorte que le rectangle sois symetrique sur l'axe y */

        ChoisirEcran(ecran);
        ChoisirCouleurDessin(couleurDessin);

    	if(rempliOuVide==0){

            DessinerRectangle(posRectangle.x,posRectangle.y,tailleRectangle->l,tailleRectangle->h);

        }else{
                if(rempliOuVide==1){

                    RemplirRectangle(posRectangle.x,posRectangle.y,tailleRectangle->l,tailleRectangle->h);
                }
             }

return posRectangle;
}


positionCroix centrerDessinerCroixXY(taille* tailleConteneur,position* posConteneur,couleur couleurDessin,int ecran){


        positionCroix posCroix={0,0,0,0,0,0,0,0};

        posCroix.x=posConteneur->x;
        posCroix.y=posConteneur->y;

        posCroix.xx=posConteneur->x+tailleConteneur->l;
        posCroix.yy=posConteneur->y+tailleConteneur->h;


        posCroix.xxx=posConteneur->x+tailleConteneur->l;
        posCroix.yyy=posConteneur->y;

        posCroix.xxxx=posConteneur->x;
        posCroix.yyyy=posConteneur->y+tailleConteneur->h;


        ChoisirEcran(ecran);
        ChoisirCouleurDessin(couleurDessin);
        DessinerSegment(posCroix.x,posCroix.y,posCroix.xx,posCroix.yy);
        DessinerSegment(posCroix.xxx,posCroix.yyy,posCroix.xxxx,posCroix.yyyy);

return posCroix;

}


position centrerDessinerRectangleVertical(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur,int rempliOuVide,couleur couleurDessin,int ecran,int decalementY){

	position posRectangle={0,0};/*La structure qui sera retourné*/

    if(tailleConteneur->l < tailleRectangle->l || tailleConteneur->h < tailleRectangle->h ){

    	printf("ERREUR: taille du rectangle > taille du conteneur\n" );
    	return posRectangle;
    }

    position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */

    posRectangle.x=(centreConteneur.x-((tailleRectangle->l)/2));/*on recule l'abscisse du point de depart du rectangle de la moitié de la longueur du rectangle
                                                                     de sorte que le rectangle sois symetrique sur l'axe y */
    posRectangle.y=posConteneur->y+decalementY;

		ChoisirEcran(ecran);
    	ChoisirCouleurDessin(couleurDessin);

    if(rempliOuVide==0){

    	DessinerRectangle(posRectangle.x,posRectangle.y,tailleRectangle->l,tailleRectangle->h);
    }else{
    		if(rempliOuVide==1){

    			RemplirRectangle(posRectangle.x,posRectangle.y,tailleRectangle->l,tailleRectangle->h);
    		}

    	 }


return posRectangle;
}


position centrerDessinerRectangleHorizontal(taille* tailleConteneur,taille* tailleRectangle,position* posConteneur,int rempliOuVide,couleur couleurDessin,int ecran,int decalementX){

	position posRectangle={0,0};/*La structure qui sera retourné*/

    if(tailleConteneur->l < tailleRectangle->l || tailleConteneur->h < tailleRectangle->h ){

    	printf("ERREUR: taille du rectangle > taille du conteneur\n" );
    	return posRectangle;
    }
    	position centreConteneur=positionCentre(tailleConteneur, posConteneur);/*on recupere les coordonnés du centre du conteneur et on les affecte a une structure "position" */

    	posRectangle.y=(centreConteneur.y-((tailleRectangle->h)/2));/*on recule l'ordonnée du point de depart du rectangle de la moitié de la hauteur du rectangle
                                                                       de sorte que le rectangle sois symetrique sur l'axe x */
    	posRectangle.x=posConteneur->x +decalementX;

		ChoisirEcran(ecran);
    	ChoisirCouleurDessin(couleurDessin);

    if(rempliOuVide==0){

    	DessinerRectangle(posRectangle.x,posRectangle.y,tailleRectangle->l,tailleRectangle->h);
    }else{
    		if(rempliOuVide==1){

    			RemplirRectangle(posRectangle.x,posRectangle.y,tailleRectangle->l,tailleRectangle->h);
    		}

    	 }
return posRectangle;
}


paramPartie afficherAccueil(int ecran, taille tailleFenetre) {

	position poNull={0,0};
	paramPartie option={1,3};

	couleur violet;
	violet=CouleurParComposante(85,24,96);

	couleur jaune;
	jaune=CouleurParComposante(255,213,36);

	couleur noir;
	noir=CouleurParComposante(0,0,0);

	taille taConteneur={tailleFenetre.l/2,tailleFenetre.h/2};
	taille taContTitre={tailleFenetre.l/2,tailleFenetre.h/10};
	taille taSignature={tailleFenetre.l/2,tailleFenetre.h/20};

	taille taConteneurGrille={taConteneur.l-2*POURCENT_X,(taConteneur.h/2)-2*POURCENT_Y};
	taille taAfficherGrille={taConteneurGrille.l/2,taConteneurGrille.h/4};
	taille taConteneurSigne={taAfficherGrille.h,taAfficherGrille.h};

	taille taConteneurJoueur={taConteneur.l-2*POURCENT_X,(taConteneur.h/2)-2*POURCENT_Y};
	taille taConteneurNombreJoueur={taConteneurJoueur.l/2-1*POURCENT_X,taConteneurJoueur.h};

	taille taConteneurStart={tailleFenetre.l/6,tailleFenetre.h/14};



	position poContTitre=centrerDessinerRectangleVertical(&tailleFenetre,&taContTitre,&poNull,1,violet,0,5*POURCENT_Y);
	ChargerImage("images/titreBlocus.png",poContTitre.x,poContTitre.y,0,0,taContTitre.l,taContTitre.h);

	position poConteneur=centrerDessinerRectangleVertical(&tailleFenetre,&taConteneur,&poNull,1,noir,0,25*POURCENT_Y);

	position poConteneurGrille=centrerDessinerRectangleVertical(&taConteneur,&taConteneurGrille,&poConteneur,1,violet,0,POURCENT_Y);
	centrerEcrireTexteVertical(&taConteneurGrille,"Taille de la grille",&poConteneurGrille,jaune,2,0,4*POURCENT_Y);
	position poAfficherGrille=centrerDessinerRectangleXY(&taConteneurGrille,&taAfficherGrille,&poConteneurGrille,1,jaune,0);
	centrerEcrireTexteXY(&taAfficherGrille,"3 X 3",&poAfficherGrille,violet,2,0);
	position poSigneLess=centrerDessinerRectangleHorizontal(&taConteneurGrille,&taConteneurSigne,&poConteneurGrille,0,jaune,0,3*POURCENT_X);
	ChargerImage("images/less.png",poSigneLess.x,poSigneLess.y,0,0,taConteneurSigne.l,taConteneurSigne.h);
	position poSigneMore=centrerDessinerRectangleHorizontal(&taConteneurGrille,&taConteneurSigne,&poConteneurGrille,0,jaune,0,taConteneurGrille.l-taConteneurSigne.l- 3*POURCENT_X );
	ChargerImage("images/more.png",poSigneMore.x+4,poSigneMore.y+4,0,0,taConteneurSigne.l,taConteneurSigne.h);

	position poConteneurJoueur=centrerDessinerRectangleVertical(&taConteneur,&taConteneurJoueur,&poConteneur,1,noir,0,taConteneur.h/2+POURCENT_Y);
	position poConteneurUnJoueur=centrerDessinerRectangleHorizontal(&taConteneurJoueur,&taConteneurNombreJoueur ,&poConteneurJoueur,1,jaune,0,0);
	position poConteneurDeuxJoueur=centrerDessinerRectangleHorizontal(&taConteneurJoueur,&taConteneurNombreJoueur ,&poConteneurJoueur,1,violet,0,taConteneurNombreJoueur.l+2*POURCENT_X);

	centrerEcrireTexteXY(&taConteneurNombreJoueur,"Jouer contre l'IA",&poConteneurUnJoueur,violet,1,0);
	centrerEcrireTexteXY(&taConteneurNombreJoueur,"Jouer contre un autre joueur",&poConteneurDeuxJoueur,jaune,1,0);


	position poContSignature=centrerDessinerRectangleVertical(&tailleFenetre,&taSignature,&poNull,1,violet,0,93*POURCENT_Y);
	centrerEcrireTexteXY(&taSignature,"Projet fini le 14/01/2021 et realise par Adam MEDDAHI et Quentin LACOMBE", &poContSignature ,jaune,0,0);

	position poConteneurStart=centrerDessinerRectangleVertical(&tailleFenetre,&taConteneurStart,&poNull,1,violet,0,80*POURCENT_Y);
	centrerEcrireTexteXY(&taConteneurStart,"Lancer",&poConteneurStart,jaune,2,0);


position posSouris={0,0};
int start=0;
int valeurGrille=0;
int nombreJoueur=1;
char *tailleGrille[7]={"3 X 3","4 X 4","5 X 5","6 X 6","7 X 7","8 X 8","9 X 9"};

while(start == 0){

	while(!SourisCliquee()){}

		SourisPosition();
			posSouris.x=_X;
			posSouris.y=_Y;

	int code = clickDansRectangle(&poSigneLess, &taConteneurSigne, &posSouris,1) + clickDansRectangle(&poSigneMore, &taConteneurSigne, &posSouris,2) + clickDansRectangle(&poConteneurUnJoueur, &taConteneurNombreJoueur, &posSouris,3) + clickDansRectangle(&poConteneurDeuxJoueur, &taConteneurNombreJoueur, &posSouris,4) + clickDansRectangle(&poConteneurStart, &taConteneurStart, &posSouris,5);


	switch (code) {

		case 1:

			if(valeurGrille>0){

				valeurGrille--;
				centrerDessinerRectangleXY(&taConteneurGrille,&taAfficherGrille,&poConteneurGrille,1,jaune,0);
				centrerEcrireTexteXY(&taAfficherGrille,tailleGrille[valeurGrille],&poAfficherGrille,violet,2,0);
				option.tailleGrille=valeurGrille+3;
			}
			break;



		case 2:

			if(valeurGrille<6){
				valeurGrille++;
				centrerDessinerRectangleXY(&taConteneurGrille,&taAfficherGrille,&poConteneurGrille,1,jaune,0);
				centrerEcrireTexteXY(&taAfficherGrille,tailleGrille[valeurGrille],&poAfficherGrille,violet,2,0);
				option.tailleGrille=valeurGrille+3;
			}
			break;

		case 3:

			if(nombreJoueur==2){

				centrerDessinerRectangleHorizontal(&taConteneurJoueur,&taConteneurNombreJoueur ,&poConteneurJoueur,1,violet,0,taConteneurNombreJoueur.l+2*POURCENT_X);
				centrerEcrireTexteXY(&taConteneurNombreJoueur,"Jouer contre un autre joueur",&poConteneurDeuxJoueur,jaune,1,0);
				centrerDessinerRectangleHorizontal(&taConteneurJoueur,&taConteneurNombreJoueur ,&poConteneurJoueur,1,jaune,0,0);
				centrerEcrireTexteXY(&taConteneurNombreJoueur,"Jouer contre l'IA",&poConteneurUnJoueur,violet,1,0);
				nombreJoueur=1;
				option.nombreDeJoueur=1;
			}

			break;

		case 4:

			if(nombreJoueur==1){


				centrerDessinerRectangleHorizontal(&taConteneurJoueur,&taConteneurNombreJoueur ,&poConteneurJoueur,1,violet,0,0);
				centrerEcrireTexteXY(&taConteneurNombreJoueur,"Jouer contre l'IA",&poConteneurUnJoueur,jaune,1,0);
				centrerDessinerRectangleHorizontal(&taConteneurJoueur,&taConteneurNombreJoueur ,&poConteneurJoueur,1,jaune,0,taConteneurNombreJoueur.l+2*POURCENT_X);
				centrerEcrireTexteXY(&taConteneurNombreJoueur,"Jouer contre un autre joueur",&poConteneurDeuxJoueur,violet,1,0);
				nombreJoueur=2;
				option.nombreDeJoueur=2;
			}
			break;

		case 5:
		start++;

			break;
	}
}


EffacerEcran(CouleurParNom("white"));
return option;
}



int afficherFin(int ecran, int codeVictoire, taille tailleFenetre){

    taille taConteneurMessage={tailleFenetre.l/2,tailleFenetre.h/8};
    taille taConteneurBouton={tailleFenetre.l/2,tailleFenetre.h/6};
    taille taBouton={(taConteneurBouton.l/2)-2*POURCENT_Y,taConteneurBouton.h- POURCENT_Y};

    position poNull={0,0};

    couleur violet;
        violet=CouleurParComposante(85,24,96);
    couleur jaune;
        jaune=CouleurParComposante(255,213,36);
    couleur noir;
        noir=CouleurParComposante(0,0,0);


    position poConteneurMessage=centrerDessinerRectangleVertical(&tailleFenetre,&taConteneurMessage,&poNull,1,violet,0,5*POURCENT_Y);

    position poConteneurBouton=centrerDessinerRectangleXY(&tailleFenetre,&taConteneurBouton,&poNull,1,noir,0);
        position poBoutonRejouer=centrerDessinerRectangleHorizontal(&taConteneurBouton,&taBouton,&poConteneurBouton,1,jaune,0,POURCENT_X);
            centrerEcrireTexteXY(&taBouton,"Rejouer",&poBoutonRejouer,violet,2,0);
        position poBoutonQuitter=centrerDessinerRectangleHorizontal(&taConteneurBouton,&taBouton,&poConteneurBouton,1,jaune,0,taBouton.l+3*POURCENT_X);
             centrerEcrireTexteXY(&taBouton,"Quitter",&poBoutonQuitter,violet,2,0);

    switch (codeVictoire){

        case 1:

            centrerEcrireTexteXY(&taConteneurMessage,"Victoire du joueur 1",&poConteneurMessage,jaune,2,0);;

        break;


        case 2:

            centrerEcrireTexteXY(&taConteneurMessage,"Victoire du joueur 2",&poConteneurMessage,jaune,2,0);
        break;


        case 3:

            centrerEcrireTexteXY(&taConteneurMessage,"Match nul",&poConteneurMessage,jaune,2,0);
        break;


        case 4:

            centrerEcrireTexteXY(&taConteneurMessage,"Victoire de l'IA",&poConteneurMessage,jaune,2,0);
        break;
    }



    position posSouris={0,0};
    int codeRetour=0;
    int quit=0;
    
    while(quit == 0){

        while(!SourisCliquee()){}

          SourisPosition();
            posSouris.x=_X;
            posSouris.y=_Y;

        int code = clickDansRectangle(&poBoutonRejouer, &taBouton, &posSouris,1) + clickDansRectangle(&poBoutonQuitter, &taBouton, &posSouris,2);


        switch (code){

            case 1:

                codeRetour++;
                quit++;
            break;

            case 2:

                quit++;
            break;
        }
}

    return codeRetour;
}
