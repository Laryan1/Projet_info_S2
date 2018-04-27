#ifndef _Pile
#define _Pile
#include <stdio.h>
#include "carte.h"
#include "liste.h"

typedef Liste Pile;

/* Prototypes  */
/* ATTENTION:  plusieurs de ces fonctions n'ont pas de sens avec une pile vide	*/

int pile_vide(Pile p);	/* une pile vide sera representée par NULL*/
Pile creer_pile(void);	/* une pile vide sera representée par NULL*/
Pile empiler(ELEMENT,Pile); /* Ajoute une carte (UN ELEMENT) au sommet de la pile */
Pile supprimer_pile(Pile); /* Supprime le sommet de pile */
ELEMENT sommet(Pile);	/* Retourne la carte au sommet SANS modifier la pile */
ELEMENT depiler(Pile *);	/* Retourne la carte au sommet et la supprime de la pile */
int taille_pile(Pile p); /* Nombre d'elements de la pile */
void visualiser_pile(Pile p); /* Affichage de tous les elements de la pile sans la modifier */
#endif
