#include "graphique.h"

SDL_Surface* newfenetregraphique(int dimx, int dimy) {
  SDL_Surface* f=NULL;
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
  signal(SIGINT, SIG_DFL);

  f = SDL_SetVideoMode(dimx, dimy, 32, SDL_HWSURFACE);
  if (f!=NULL) { 
    SDL_FillRect(f, NULL, SDL_MapRGB(f->format,0,0,0));
    SDL_Flip(f);
  }
  return f;
}
/*
void SDL_phelma_clear(SDL_Surface* f) {
  if (f!=NULL) SDL_FillRect(f, NULL, SDL_MapRGB(f->format,255,255,255));
  SDL_Flip(f);
}
*/
SDL_Surface * init_graphique(int dim_x, int dim_y){
	SDL_Surface* fenetre;
	fenetre=newfenetregraphique(dim_x, dim_y) ;
        SDL_FillRect(fenetre, NULL, SDL_MapRGB(fenetre->format,0,0,0));
	
	return(fenetre);
}



INFO_GRAPH init_info_graph(SOMMET* liste_sommets, INFO_GRAPH info_graph, int dim_x, int dim_y, long nb_sommets){
	long i;
	double max_x = liste_sommets[0].x, max_y = liste_sommets[0].y , min_x = liste_sommets[0].x ,min_y = liste_sommets[0].y;
	
	/*
	if (info_graph == NULL){
		info_graph = calloc(1, sizeof(info_graph));
	}*/
	
	for (i = 1; i< nb_sommets; i++){
		if (liste_sommets[i].x > max_x) max_x = liste_sommets[i].x;
		if (liste_sommets[i].y > max_y) max_y = liste_sommets[i].y;
		if (liste_sommets[i].x < min_x) min_x = liste_sommets[i].x;
		if (liste_sommets[i].y < min_y) min_y = liste_sommets[i].y;
	}
	
	info_graph.max_x = max_x;
	info_graph.max_y = max_y;
	info_graph.min_x = min_x;
	info_graph.min_y = min_y;
	info_graph.dim_x = dim_x;
	info_graph.dim_y = dim_y;
	
	info_graph.rayon = calcul_rayon(info_graph, nb_sommets);
	return info_graph;
}

int calcul_rayon(INFO_GRAPH info_graph, long nb_sommets){ /*Retourne le rayon des sommets en fonction du nb se points*/
	int R = 1 + 0.1*sqrt((info_graph.dim_x*info_graph.dim_y)/nb_sommets);
	if (R>10) return(10);
	return(R);
}

void calcul_coord_affichage(double x, double y, INFO_GRAPH info_graph, int* new_x, int* new_y){
	double etendue_x, etendue_y, coeff_x, coeff_y;
	
	etendue_x = info_graph.max_x - info_graph.min_x;
	etendue_y = info_graph.max_y - info_graph.min_y;
	
	coeff_x = info_graph.dim_x / etendue_x;
	coeff_y = info_graph.dim_y / etendue_y; 
	
	*new_x = (int)(x * coeff_x);
	*new_y = (int)(y * coeff_y);
	
	/*On rajoute l'offset pour que toutes les valeurs soient dans le positif*/
	*new_x  = *new_x - (info_graph.min_x * coeff_x) ;
	*new_y  = *new_y - (info_graph.min_y * coeff_y) ; 
	
	/* On ne peut pas ecrire hors de la fenetre */
	if (*new_x < info_graph.rayon) *new_x = info_graph.rayon+1;
	if (*new_x > info_graph.dim_x-info_graph.rayon) *new_x = info_graph.dim_x - info_graph.rayon+1;
	if (*new_y < info_graph.rayon) *new_y = info_graph.rayon+1;
	if (*new_y > info_graph.dim_y-info_graph.rayon) *new_y = info_graph.dim_y - info_graph.rayon+1;
	/* /!\ On inverse y  car y = 0 est dans le coin en haut a gauche et pas en bas a gauche comme classiquement*/
	
	*new_y = info_graph.dim_y - *new_y;
}

void afficher_1_sommet(SOMMET s, SDL_Surface * fenetre, INFO_GRAPH info_graph, Uint32 couleur){ 
	int x, y;
	calcul_coord_affichage(s.x, s.y, info_graph, &x, &y);
	
	Draw_FillCircle(fenetre, x, y, info_graph.rayon, couleur);
	
}

void afficher_arcs_depuis_sommet(SOMMET depart,INFO_GRAPH info_graph, SDL_Surface * fenetre, SOMMET* liste_sommets){
	ARC pointeur_arc = depart.voisins;
	int x_init, y_init,  x_fin, y_fin;
	calcul_coord_affichage(depart.x, depart.y, info_graph, &x_init, &y_init);
	
	while (pointeur_arc!=NULL){
		calcul_coord_affichage(liste_sommets[pointeur_arc->arrivee].x, liste_sommets[pointeur_arc->arrivee].y, info_graph, &x_fin, &y_fin);
		
		Draw_Line(fenetre, x_init, y_init, x_fin, y_fin, BLANC); 
		pointeur_arc = pointeur_arc->suiv;
	}
}

void afficher_arc_entre_2_sommets(SOMMET depart, SOMMET arrivee, INFO_GRAPH info_graph, SDL_Surface * fenetre, Uint32 couleur){
	int x_init, y_init,  x_fin, y_fin;
	calcul_coord_affichage(depart.x, depart.y, info_graph, &x_init, &y_init);
	calcul_coord_affichage(arrivee.x, arrivee.y, info_graph, &x_fin, &y_fin);
	
	Draw_Line(fenetre, x_init, y_init, x_fin, y_fin, couleur);
}

void afficher_graph(SOMMET* liste_sommets, long nb_sommets, SDL_Surface *fenetre, INFO_GRAPH info_graph){
	long i;
	for(i=0; i<nb_sommets; i++){
		afficher_1_sommet(liste_sommets[i], fenetre, info_graph, BLANC);
		afficher_arcs_depuis_sommet(liste_sommets[i], info_graph, fenetre, liste_sommets);
	}
	
	SDL_Flip(fenetre);
}

void afficher_chemin_g(SOMMET* liste_sommets, SDL_Surface *fenetre, INFO_GRAPH info_graph, Liste chemin_a_prendre){

	while (chemin_a_prendre->suiv !=NULL){
		afficher_1_sommet(liste_sommets[chemin_a_prendre->val], fenetre, info_graph, ROUGE);
		afficher_arc_entre_2_sommets(liste_sommets[chemin_a_prendre->val], liste_sommets[chemin_a_prendre->suiv->val], info_graph, fenetre, ROUGE);
		chemin_a_prendre = chemin_a_prendre->suiv;
	}	
	afficher_1_sommet(liste_sommets[chemin_a_prendre->val], fenetre, info_graph, ROUGE);
	SDL_Flip(fenetre);
}




