#include "fonctions_prog.h"

/* ######################################## */
/* ################ FONCTIONS ############# */
/* ######################################## */

ARC creer_arc(long arrivee,	double cout){
	//Permet de creer un arc. De base il ne contient pas d'arc suivant
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
    sommet.nom = strdup(nom_sommet);
    sommet.x=lattitude;
    sommet.y=longitude;
    sommet.voisins=nouvel_arc;
    sommet.pcc=DBL_MAX;
    sommet.pere=-1;
    return sommet;
}

char* sel_graphe(char* dir){
	/*
Liste des graphes disponibles : 
1 : graphe1.txt				4 : grapheFloride.csv		7 : grapheUSACentral.csv
2 : graphe2.txt				5 : grapheGrandLacs.csv		8 : grapheUSAOuest.csv
3 : grapheColorado.csv		6 : grapheNewYork.csv		9 : metroetu.csv
*/	
	printf("\n\n########## LISTE DES GRAPHES DISPONIBLES ##########\n\n");
	printf("1 : graphe1.txt			4 : grapheFloride.csv		7 : grapheUSACentral.csv\n");
	printf("2 : graphe2.txt			5 : grapheGrandLacs.csv		8 : grapheUSAOuest.csv\n");
	printf("3 : grapheColorado.csv		6 : grapheNewYork.csv		9 : metroetu.csv\n");

	int choix = 0;
	while(choix<1 || choix>9){
		printf("\nChoisissez un graphe : ");scanf("%d", &choix);
	}

	char nom_fichier[50];
	switch (choix){
		case 1: strcpy(nom_fichier, "graphe1.txt"); break;
		case 2: strcpy(nom_fichier, "graphe2.txt"); break;
		case 3: strcpy(nom_fichier, "grapheColorado.csv"); break;
		case 4: strcpy(nom_fichier, "grapheFloride.csv"); break;
		case 5: strcpy(nom_fichier, "grapheGrandLacs.csv"); break;
		case 6: strcpy(nom_fichier, "grapheNewYork.csv"); break;
		case 7: strcpy(nom_fichier, "grapheUSACentral.csv"); break;
		case 8: strcpy(nom_fichier, "grapheUSAOuest.csv"); break;
		case 9: strcpy(nom_fichier, "metroetu.csv"); break;
	}

	strcat(dir, nom_fichier);
	printf("\ndir: %s",dir);
	return dir;
	
}

void sel_depart_arrivee(long* p_i_depart, long* p_i_arrivee, long nb_sommets, SOMMET* liste_sommets){
	nb_sommets -=1; // l'indice max est le nb de sommet -1
	printf("\nQuel est l'indice du point de depart : ");
	do{
		scanf("%ld",p_i_depart);
		if(*p_i_depart > nb_sommets)printf("\n/!\\ Ce sommet n'existe pas : l'indice du dernier sommet est %ld /!\\\nVeuillez en rentrer un nouveau depart : ", nb_sommets);
	}while(*p_i_depart > nb_sommets);
	printf("\nQuel est l'indice du point d'arrivee : ");
	
	do{
		scanf("%ld",p_i_arrivee);
		if(*p_i_arrivee > nb_sommets)printf("\n/!\\ Ce sommet n'existe pas : l'indice du dernier sommet est %ld /!\\\nVeuillez en rentrer une nouvelle arrivee : ", nb_sommets);
	}while(*p_i_arrivee > nb_sommets);
	printf("\n");

	liste_sommets[*p_i_depart].pcc = 0;
	liste_sommets[*p_i_depart].pere = *p_i_depart;
}

void afficher_sommet(SOMMET s){
	printf("nom : %s\tlattitude : %.2lf\tlongitute %.2lf", s.nom, s.x, s.y);
}

void initialisation(FILE* graphe,SOMMET* liste_sommets, long* nb_sommets, long* nb_arcs){
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

Liste ajout_trie(ELEMENT e, Liste L,SOMMET* liste_sommets){
	Liste p = calloc(1, sizeof(Liste));											//On alloue l'espace memoire pour le nouvel element "p" de la liste "L". 
	if (p == NULL) return NULL;													//On verifie la bonne allocation de l'espace memoire.
	p->val = e;		
															//On attribue a la valeur de "p", l'element e, correspondant a l'indice du sommet.
	p->suiv=NULL;
	if(!L) return (p);
	if (liste_sommets[p->val].pcc<=liste_sommets[L->val].pcc){				
	//On teste si la valeur "e" donne deja acces au sommet de plus petit pcc.
		p->suiv=L;
		return (p);															
	//Si c'est le cas, on renvoie directement la liste "p" ayant pour suite la liste "L".
	}

	Liste temp=L;								
								//On cree un tampon nous permettant de nous deplacer le long de "L".
	while(temp->suiv!=NULL){
		if (liste_sommets[p->val].pcc<=liste_sommets[(temp->suiv)->val].pcc){	//Si le sommet d'indice "e" a un pcc plus grand que le sommet de l'indice indique par le suivant du tampon.
			p->suiv=temp->suiv;					
								//On place a la suite du tampon, la liste "p", on l'insere a l'interieur de la liste "L".
			temp->suiv=p;
			return(L);															//Et on retourne la liste "L".
		}
		temp=temp->suiv;														//On passe a l'element suivant.
	}
	temp->suiv=p;	
															//Si on traite le sommet au plus grand pcc, on l'ajoute donc a la fin de la liste.
	return (L);
}

Liste supprimer_trie(Liste L){	//Dans cette fonction on supprimer le premier element de la liste L, donc on libere l'espace memoire alloue et on retourne l'element suivant.
	Liste temp=L->suiv;							
	free(L);
	return (temp);
}

Liste ajout_tete(ELEMENT e, Liste L){
	Liste p = calloc(1, sizeof(Liste));
	
	if (p == NULL) return NULL;
	
	p->val = e;
	p->suiv = L;
	
	return(p);
}

void dijkstra(SOMMET* liste_sommets, Liste pcc_connus,long i_depart, long i_arrivee,long nb_sommets ){
	Arbre sommet_visites=creer_chene(nb_sommets);
//#################################################################################
	pcc_connus = ajout_trie(i_depart, pcc_connus,liste_sommets);
//#################################################################################
	long compteur = 0;
	int tmps = time(NULL);
	printf("Nombre de points parcourus : 0");

	do{
		long i_pt_courant = pcc_connus->val;
		//Le point courant est celui de plus petit pcc (Le premier de la liste pcc_connus)
		pcc_connus = supprimer_trie(pcc_connus);
		//On supprime donc le point courant de la liste des pcc connus
		if (est_present(i_pt_courant,nb_sommets,sommet_visites)==0){

			ajouter_arbre(i_pt_courant, nb_sommets, sommet_visites);
			//On ajoute ce point a la liste des points visites, c'est a dire dont on a trouve la plus petit pcc
			ARC arc_voisin = liste_sommets[i_pt_courant].voisins;
			//C'est le premier voisin a considerer
			while(arc_voisin!=NULL){
				//Grace a ce while, on parcous toute la liste des voisin. A chaque tour de boucle, on remplace arc_voisin par l'arc suivant	
				long i_voisin = arc_voisin->arrivee;

				if(liste_sommets[i_voisin].pcc > liste_sommets[i_pt_courant].pcc + arc_voisin->cout){
					//Si le pcc actuel du voisin est plus grand que la somme du pcc du pt courant et du cout entre les 2 point, on remplace le pcc et le pere
					liste_sommets[i_voisin].pcc = liste_sommets[i_pt_courant].pcc + arc_voisin->cout;
					liste_sommets[i_voisin].pere = i_pt_courant;
				}
				
		//#################################################################################
				if (est_present(i_voisin,nb_sommets,sommet_visites)==0){
					//Si le point n'a pas deja ete visite, on l'ajoute a la liste des pcc.
					pcc_connus = ajout_trie(i_voisin, pcc_connus,liste_sommets); 
				}
		//#################################################################################
				arc_voisin = arc_voisin->suiv;
			}

			/*Affichage du nombre de points parcourus toutes les secondes : */
			compteur ++;
			if (tmps+1>= time(NULL)){
				printf("\rNombre de points parcourus : %ld", compteur);
				tmps = time(NULL);
			}
		}
	} while(est_present(i_arrivee,nb_sommets,sommet_visites)==0 && pcc_connus != NULL);

	while(pcc_connus) pcc_connus=supprimer_trie(pcc_connus);
	free_arbre(sommet_visites);
}


Liste remonter_chemin(Liste chemin_a_prendre, long i_arrivee, long i_depart, SOMMET* liste_sommets){
	if(liste_sommets[i_arrivee].pere == -1) return ajout_tete(-1, chemin_a_prendre);

	chemin_a_prendre = ajout_tete(i_arrivee, chemin_a_prendre);

	while(chemin_a_prendre->val != i_depart){ // tant que le premier sommet de la liste n'est pas le point de depart
		chemin_a_prendre = ajout_tete(liste_sommets[chemin_a_prendre->val].pere, chemin_a_prendre); //On prend le sommet que l'on considere et l'on ajoute en tete son pere
	}
	return(chemin_a_prendre);
}

void afficher_chemin(Liste chemin_a_prendre, SOMMET* liste_sommets, long i_depart, long i_arrivee){
	if (chemin_a_prendre->val == -1){
		printf("\n##########################\n######### DESOLE #########\n##########################\n\n");
		printf("\nImpossible de relier les points :\n");
		printf("Point de depart :\n\t"); afficher_sommet(liste_sommets[i_depart]);printf("\n");
		printf("Point d'arrivee :\n\t"); afficher_sommet(liste_sommets[i_arrivee]);printf("\n");
	}
	else{
		printf("\n##########################\n##### CHEMIN TROUVE! #####\n##########################\n\n");
		printf("Point de depart : "); afficher_sommet(liste_sommets[i_depart]);printf("\n");
		printf("Point d'arrivee : "); afficher_sommet(liste_sommets[i_arrivee]);printf("\n");

		printf("\n##########################\n#### Route a prendre: ####\n##########################\n\n");

		double cout_precedent = liste_sommets[chemin_a_prendre->val].pcc;

		while(chemin_a_prendre!=NULL){
			double cout_courant = liste_sommets[chemin_a_prendre->val].pcc;
			afficher_sommet(liste_sommets[chemin_a_prendre->val]); printf("\tCout = %.2lf \tCout total = %.2lf\n", cout_courant - cout_precedent, cout_courant);
			cout_precedent = cout_courant;
			chemin_a_prendre = chemin_a_prendre->suiv;
		}
	}

}

void afficher_secondes(int secondes){
	int minutes, heures;
	minutes = secondes / 60; //division d'entiers
	secondes %= 60; //reste de la divion euclidienne pas 60
	heures = minutes / 60;
	minutes %= 60;

	if (heures > 0){printf("%dh ",heures);}
	if (minutes > 0){printf("%dmin ",minutes);}
	printf("%ds\n",secondes);
}
