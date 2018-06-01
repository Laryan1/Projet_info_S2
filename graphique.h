#include <stdio.h>
#include <math.h>
#include "SDL_phelma.h"
#include "fonctions_prog.h"

#define RAYON 1
#define CYAN 0x0000FFFF
#define NOIR 0x00000000
#define BLANC 0x00FFFFFF
#define ROUGE 0x00FF0000

typedef struct {
	double max_x;
	double max_y; 
	double min_x; 
	double min_y;
	int dim_x; 
	int dim_y;
	int rayon;
} INFO_GRAPH;

SDL_Surface* newfenetregraphique(int dimx, int dimy);
SDL_Surface * init_graphique(int dim_x, int dim_y);
INFO_GRAPH init_info_graph(SOMMET* liste_sommets, INFO_GRAPH info_graph, int dim_x, int dim_y, long nb_sommets);
int calcul_rayon(INFO_GRAPH info_graph, long nb_sommet);
void calcul_coord_affichage(double x, double y, INFO_GRAPH info_graph, int* new_x, int* new_y);
void afficher_1_sommet(SOMMET s, SDL_Surface * fenetre, INFO_GRAPH info_graph, Uint32 couleur);
void afficher_arcs_depuis_sommet(SOMMET depart,INFO_GRAPH info_graph, SDL_Surface * fenetre, SOMMET* liste_sommets);
void afficher_arc_entre_2_sommets(SOMMET depart, SOMMET arrivee, INFO_GRAPH info_graph, SDL_Surface * fenetre, Uint32 couleur);
void afficher_graph(SOMMET* liste_sommets, long nb_sommets, SDL_Surface *fenetre, INFO_GRAPH info_graph);
void afficher_chemin_g(SOMMET* liste_sommets, SDL_Surface *fenetre, INFO_GRAPH info_graph, Liste chemin_a_prendre);
