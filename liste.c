#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
Liste creer_liste(void){
	return NULL;
}

int liste_vide(Liste L){
	return(!L);
}

/*
void visualiser(Liste L){
	while(L!=NULL){
		affiche(&(L->val));
		L = L->suiv;
	}
}
*/

Liste ajout_tete(ELEMENT e, Liste L){
	Liste p = calloc(1, sizeof(Liste));
	
	if (p == NULL) return NULL;
	
	p->val = e;
	p->suiv = L;
	
	return(p);
}

Liste supprimer_tete(Liste L){
	Liste p = NULL;
	if (L!=NULL){
		p = L->suiv;
		free(L);
		return p;
	}
	else return NULL;
}

void liberer(Liste L){
	while(L!=NULL){
		L = supprimer_tete(L);
	}
}

// /!\ A continuer


Liste ajout_queue(ELEMENT c, Liste L){
	/*On chercher la fin de la Liste*/
	
	if (!L) return(ajout_tete(c, L));
	
	Liste L_init = L;
	
	while(L->suiv!=NULL){
		L = L->suiv;
	}
	
	Liste p = calloc(1, sizeof(Liste));

	L->suiv = p;

	p->val = c;
	p->suiv = NULL;	
	
	return(L_init);
}


Liste concat(Liste l1, Liste l2){
	
	Liste l3 = copie(l1);
	Liste l3_init = l3;
	
	while (l3->suiv != NULL){
		l3 = l3->suiv;
	}
	
	l3->suiv = l2;
	
	return(l3_init);
}

Liste copie(Liste l){
	Liste l2 = NULL;
	
	while(l!=NULL){
		l2 = ajout_queue(l->val, l2);	
		l = l->suiv;
	}
	return(l2);
}











