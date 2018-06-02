#include "fonctions_prog.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>

int main(){
	/*DECLARATIONS DES VARIABLES*/
	Liste chemin_a_prendre=NULL; 
	FILE* graphe=NULL;
    char dir[512];   
    long nb_sommets, nb_arcs, i_depart, i_arrivee;
	int choix_recherche;

    int enable_timer = 1,temps_debut_import, temps_fin_import, temps_debut_dijkstra, temps_fin_dijkstra;
	
    SDL_Surface* fenetre;
    int dim_x = 1100, dim_y = 900; /* TAille de la fenetre graphique*/
	INFO_GRAPH info_graph;

	/*############################################*/
	/*#########DEBUT DES INTITIALISATIONS#########*/
	/*############################################*/
	
	// Initialisation des sommets et des arcs
    char* nom_fichier = sel_graphe(dir);
    if (enable_timer){temps_debut_import = time(NULL);}
	graphe=fopen(nom_fichier,"r");
    if (graphe == NULL){
        perror("Impossible d'ouvrir le fichier.\nError ");
        exit(0);
    }
    fscanf(graphe,"%ld %ld", &(nb_sommets), &(nb_arcs));
    SOMMET* liste_sommets = calloc(nb_sommets, sizeof(SOMMET));

	// Initialisation de la table de hachage
	long taille_tab_hach;
	if (nb_sommets>100000) taille_tab_hach=100000;
	else taille_tab_hach=nb_sommets/10;
	Liste tab_hach[taille_tab_hach];
	
	initialisation(graphe, liste_sommets, &nb_sommets, &nb_arcs,tab_hach,taille_tab_hach,&choix_recherche);
	// Fermeture du fichier de graphe
	fclose(graphe);

	// Initialisation graphique 
	info_graph = init_info_graph(liste_sommets, info_graph, dim_x, dim_y, nb_sommets);
	
	fenetre = init_graphique(dim_x, dim_y);
	
	afficher_graph(liste_sommets, nb_sommets, fenetre, info_graph);

	// Timer
	if (enable_timer){temps_fin_import = time(NULL);printf("\n\nTemps d'initialisation : ");afficher_secondes(temps_fin_import-temps_debut_import);printf("\n");}
	
	/*############################################*/
	/*##########FIN DES INTITIALISATIONS##########*/
	/*############################################*/
	
	//Selection du depart et de l'arrivee 
	sel_depart_arrivee(&i_depart, &i_arrivee, nb_sommets, liste_sommets, tab_hach,taille_tab_hach, choix_recherche);

	//dijkstra
	if (enable_timer){temps_debut_dijkstra = time(NULL);}

	long nb_parcourus=dijkstra(liste_sommets, i_depart, i_arrivee, nb_sommets);

	//On a trouve le chemin le plus court, il faut maintenant "remonter" le chemin entre l'arrivee et le depart
	//Pour cela on utilise  une liste ou l'on va ajouter en tete les peres de l'arrivee jusqu'au point de depart
	//En parcourant cette liste dans le sens "normal" on aura ainsi acces au trajet a suivre
	//Cette liste contient (comme toute les autres listes...) les indices dans liste_sommets des sommets a emprunter pour aller du depart a l'arrivee
	
	chemin_a_prendre = remonter_chemin(chemin_a_prendre, i_arrivee, i_depart, liste_sommets);
	
	if (enable_timer){temps_fin_dijkstra = time(NULL);printf("\n\nTemps de recherche : ");afficher_secondes(temps_fin_dijkstra-temps_debut_dijkstra);printf("\n\n");}

	afficher_chemin(chemin_a_prendre, liste_sommets, i_depart, i_arrivee);

	afficher_chemin_g(liste_sommets, fenetre, info_graph, chemin_a_prendre); //Version graphique (d'ou le 'g')
	
	printf("\nNombre de sommets parcourus : %ld\n",nb_parcourus);
	
	getchar();getchar();
	
	//Liberation de l'espace memoire du tableau "liste_sommets"	
	free(liste_sommets);

	SDL_FreeSurface(fenetre);
    SDL_Quit();
	return 1;
}
