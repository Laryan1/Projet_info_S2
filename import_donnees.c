#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "import_donnees.h"

ARC creer_arc(long arrivee,	double cout){
	//Permet de cr?r un arc. De base il ne contient pas d'arc suivant
	// On peut ajouter des arcs avec la fonction "ajouter_arc"
	ARC a = calloc(1, sizeof(*a));

	a->cout = cout;
	a->arrivee = arrivee;
	a->suiv = NULL;

	return(a);
}

SOMMET creer_sommet(char* nom_sommet, double lattitude, double longitude, long cpmt){
    SOMMET sommet;
    ARC nouvel_arc=NULL;
	sommet.nom=strdup(nom_sommet);
    sommet.x=lattitude;
    sommet.y=longitude;
    sommet.voisins=nouvel_arc;
    sommet.pcc=DBL_MAX;
    sommet.pere=-1;
    return sommet;
}

void lecture_fichier(FILE* graphe,SOMMET* liste_sommets, long* nb_sommets, long* nb_arcs){
	char route[512], nom_sommet[511];
	char str[512];
	long indice_sommet, indice_depart, indice_arrivee;
	double lattitude, longitude, cout;
	long cmpt=0;
	ARC temp_arc;

	fgets(str,511,graphe);
	fgets(str,511,graphe);

    for (cmpt; cmpt<(*nb_sommets);cmpt++){
        fscanf(graphe,"%ld %lf %lf %s %s",&indice_sommet, &lattitude, &longitude,route ,nom_sommet);
        liste_sommets[cmpt]=creer_sommet(nom_sommet,lattitude,longitude,cmpt);
        printf("SOMMET N%d, indice %d: %s\n",cmpt+1, cmpt, liste_sommets[0].nom);

    }

	fgets(str,511,graphe);
	fgets(str,511,graphe);

    for (cmpt=0; cmpt<*nb_arcs;cmpt++){
    	fscanf(graphe, "%ld %ld %lf ",&indice_depart, &indice_arrivee, &cout);

    	if (liste_sommets[indice_depart].voisins==NULL) liste_sommets[indice_depart].voisins=creer_arc(indice_arrivee, cout);

    	else {
            temp_arc=liste_sommets[indice_depart].voisins; //On prend le premier voisin qui est celui dans le sommet
            while(temp_arc->suiv != NULL) temp_arc=temp_arc->suiv; // On parcours tous les arcs jusqu'a ce que le suivant soit nul, on peut alors ajouter notre nouvel arc
            temp_arc->suiv = creer_arc(indice_arrivee,cout); // On ajoute notre arc nouvellement cr?r a la fin de la liste des voisins
    	}

    }
}

void main(){
    FILE* graphe;
    char* nom_fichier="graphe1.txt";
    char ligne[400];
    long nb_sommets, nb_arcs;

    graphe=fopen(nom_fichier,"r");

    fscanf(graphe,"%ld %ld", &(nb_sommets), &(nb_arcs));
    printf("%ld %ld\n", nb_sommets, nb_arcs);
    SOMMET liste_sommets[nb_sommets];

	lecture_fichier(graphe, liste_sommets, &nb_sommets, &nb_arcs);
    fclose(graphe);
}
