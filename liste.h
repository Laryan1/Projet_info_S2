typedef long ELEMENT;

typedef struct _Liste {
	ELEMENT val; 
	struct _Liste * suiv;} * Liste;

Liste creer_liste(void);
int liste_vide(Liste L);
void visualiser(Liste L);
Liste ajout_tete(ELEMENT c, Liste L);
Liste supprimer_tete(Liste L) ;
void liberer(Liste L);
Liste ajout_queue(ELEMENT c, Liste L);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);
