#include "fonctions_prog.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <time.h>

int main(){
	Liste chemin_a_prendre=NULL; 
	FILE* graphe=NULL;
    char dir[512];   
    long nb_sommets, nb_arcs, i_depart, i_arrivee;
	int choix_recherche;

    int enable_timer = 1,temps_debut_import, temps_fin_import, temps_debut_dijkstra, temps_fin_dijkstra;
	/*initialisation des sommets et des arcs*/
	//printf("Entrez l'adresse du ficher de points : \n");scanf("%s"&nom_fichier);

    char* nom_fichier = sel_graphe(dir);
    if (enable_timer){temps_debut_import = time(NULL);}
    
	graphe=fopen(nom_fichier,"r");

    if (graphe == NULL)
    {
        perror("Impossible d'ouvrir le fichier.\nError ");
        exit(0);
    }
    fscanf(graphe,"%ld %ld", &(nb_sommets), &(nb_arcs));
    SOMMET* liste_sommets = calloc(nb_sommets, sizeof(SOMMET));
	//Initialisation de la table de hachage
	long taille_tab_hach;
	if (nb_sommets>100000) taille_tab_hach=100000;
	else taille_tab_hach=nb_sommets/10;
	Liste tab_hach[taille_tab_hach];
	

	initialisation(graphe, liste_sommets, &nb_sommets, &nb_arcs,tab_hach,taille_tab_hach,&choix_recherche);
	//Fermeture du fichier de graphe
	fclose(graphe);

	if (enable_timer){temps_fin_import = time(NULL);printf("\n\nTemps d'initialisation : ");afficher_secondes(temps_fin_import-temps_debut_import);printf("\n");}

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
	afficher_chemin(chemin_a_prendre, liste_sommets, i_depart, i_arrivee);
	printf("\nNombre de sommets parcourus : %ld",nb_parcourus);
	//Liberation de l'espace memoire du tableau "liste_sommets"
	free(liste_sommets);

	if (enable_timer){temps_fin_dijkstra = time(NULL);printf("\n\nTemps de recherche : ");afficher_secondes(temps_fin_dijkstra-temps_debut_dijkstra);printf("\n\n");}
	return 1;
}
