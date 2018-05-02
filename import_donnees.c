#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "import_donnees.h"

void lecture_fichier(FILE* graphe,T_SOMMET* liste_sommets, long* nb_sommets, long* nb_arcs){
	char route[512], nom_sommet[512];
	char str[512];
	long indice_sommet, indice_depart, indice_arrivee;
	double lattitude, longitude, cout;
	int cmpt=0;
	fgets(str,511,graphe);
	fgets(str,511,graphe);
	printf("%s", str);
    for (cmpt; cmpt<(*nb_sommets);cmpt++){
        fscanf(graphe,"%ld %lf %lf %s %s",&indice_sommet, &lattitude, &longitude,route ,nom_sommet);
        printf("%ld %lf %lf %s %s",indice_sommet, lattitude, longitude,route ,nom_sommet);
        puts("");
    }

	fgets(str,511,graphe);
	fgets(str,511,graphe);
	printf("%s", str);

    for (cmpt=0; cmpt<*nb_arcs;cmpt++){
    	fscanf(graphe, "%ld %ld %lf ",&indice_depart, &indice_arrivee, &cout);
        printf("%ld %ld %lf ",indice_depart, indice_arrivee, cout);
        puts("");

    }
    printf("END");
}

void main(){

    FILE* graphe;
    char* nom_fichier="graphe2.txt";
    char ligne[400];
    long nb_sommets, nb_arcs;

    graphe=fopen(nom_fichier,"r");

    fscanf(graphe,"%ld %ld", &(nb_sommets), &(nb_arcs));
    printf("%ld %ld\n", nb_sommets, nb_arcs);
    T_SOMMET liste_sommets[nb_sommets];

	lecture_fichier(graphe, liste_sommets, &nb_sommets, &nb_arcs);

    fclose(graphe);
}
