#include "pile.h"

int pile_vide(Pile p){
	return(!p);
}

Pile creer_pile(void){
	return(NULL);
}

Pile empiler(ELEMENT e, Pile p){
	/*printf("\nfonction empiler\n");*/
	return((Pile)ajout_tete(e, (Liste)p));
}

Pile supprimer_pile(Pile p){
	return((Pile)supprimer_tete((Liste)p));
} 

ELEMENT sommet(Pile p){
	return(p->val);
}

ELEMENT depiler(Pile * p){
	ELEMENT e = (sommet(*p));
	(*p) = supprimer_pile(*p);
	
	return(e);
}

int taille_pile(Pile p){
	int compteur = 0;
	while(!pile_vide(p)){
		p = p->suivant;
		compteur++;
	}
	
	return(compteur);
}

void visualiser_pile(Pile p){
	if (p == NULL)printf("PILE VIDE\n");
	else{
		while(p!=NULL){
			/*printf("\nfonction visualiser_pile WHILE\n");*/
			affiche(&(p->val));
			p = p->suivant;
			getchar();getchar();
		}
	}
}


