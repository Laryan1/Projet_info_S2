#include "types.h"
#include "arbres.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

typedef long ELEMENT;

typedef struct _Liste {
	ELEMENT val; 
	struct _Liste * suiv;} * Liste;

ARC creer_arc(long arrivee,double cout);
SOMMET creer_sommet(char* nom_sommet,char* route, double lattitude, double longitude);
Liste ajout_trie(ELEMENT e, Liste L,SOMMET* liste_sommets);
Liste supprimer_trie(Liste L);
Liste ajout_tete(ELEMENT e, Liste L);
Liste remonter_chemin(Liste chemin_a_prendre, long i_arrivee, long i_depart, SOMMET* liste_sommets);
void afficher_sommet(SOMMET s);
char* sel_graphe(char* dir);
void sel_depart_arrivee(long* p_i_depart, long* p_i_arrivee, long nb_sommets, SOMMET* liste_sommets);
int appartient(Liste sommet_visites, long arrivee);
void initialisation(FILE* graphe,SOMMET* liste_sommets, long* nb_sommets, long* nb_arcs);																								//Lit l'intégralité du fichier et récupère et stocke toutes les informations nécessaires.
void dijkstra(SOMMET* liste_sommets,long i_depart, long i_arrivee, long nb_sommets );
long min_pcc(Liste pcc_connus, SOMMET* liste_sommets);

void afficher_chemin(Liste chemin_a_prendre, SOMMET* liste_sommets, long i_depart, long i_arrivee);
void afficher_secondes(int secondes);	

long* ajout_pcc(long* tab, long* taille_tab,long indice, SOMMET* liste_sommets);
long* suppr_pcc(long* tab, long* taille_tab, SOMMET* liste_sommets);
void augmentetas(long* tas, int i, SOMMET* liste_sommets);
void constructiontas(long* tas, int n, SOMMET* liste_sommets);
void suppressiontas(long* tas, int i, SOMMET* liste_sommets);
void descendretas(long *tas, long i, long indice_pere,SOMMET* liste_sommets);
