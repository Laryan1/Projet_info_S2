#include "fonctions_prog.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_DOUBLE 9007199254740993


/* ######################################## */
/* ##### CREATION DES ARCS ET SOMMETS ##### */
/* ######################################## */

ARC creer_arc(long arrivee,	double cout){
	//Permet de créer un arc. De base il ne contient pas d'arc suivant
	// On peut ajouter des arcs avec la fonction "ajouter_arc"
	ARC a = calloc(1, sizeof(*a));

	a->arrivee = arrivee;
	a->cout = cout;
	a->suiv = NULL;

	return(a);
}

void ajouter_arc(ARC arc_init, ARC arc_a_ajouter){
	//Permet d'ajouter un arc suivant(déjà existant) a un arc existant
	arc_init->suiv = arc_a_ajouter;
}

SOMMET creer_sommet(char* nom, double x, double y ,ARC voisins, double pcc,	long pere){
	//Permet de créer un sommet
	SOMMET a;
	a.nom = nom;
	a.x =x;
	a.y = y;
	a.voisins = voisins;								
	a.pcc =	MAX_DOUBLE;
	a.pere = -1;

	return a;
}


/* ######################################## */
/* ################ FONCTIONS ############# */
/* ######################################## */

Liste ajout_pcc_triee(long i, Liste pcc_triee, SOMMET * l_sommet){
	// i est l'indice du pcc a ajouter. La liste est triée en fonction des valeurs de pcc mais contient les indices de pcc dans la la liste des tous les sommets.
	Liste pcc_init = pcc_triee;

	// Si la liste est vide ou si le sommet considéré a une valeur de pcc plus petite que le premier élément de pcc_triee
	if(!pcc_triee || l_sommet[i].pcc < l_sommet[pcc_triee->val].pcc) return(ajout_tete(i, pcc_triee));

	//Tant que la valeur de pcc du commet considérer est plus grande que celle du comme d'indie j dans la liste pcc_triee, on passe au sommet suivant dans la liste pcc_triee
	while(l_sommet[i].pcc > l_sommet[pcc_triee->val].pcc){
		pcc_triee = pcc_triee->suiv;
	}

	Liste liste_a_ajouter;

	liste_a_ajouter->val = i;
	liste_a_ajouter->suiv = pcc_triee->suiv;

	pcc_triee->suiv = liste_a_ajouter;

	return pcc_init;
}

int appartient(Liste sommet_visites, long arrivee){
	//sommet_visites contient les indices des sommets visités 
	while (sommet_visites->suiv != NULL){
		if (arrivee == points_visites->val) return 1;
	}
	return 0;
}
