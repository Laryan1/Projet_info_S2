typedef struct sommet{ 			// Définition de la structure qui va contenir nos variables.

	char* nom; 				// Nom de la ville en question.
	double x,y ; 				// Coordonnées (lattitude, longitude) de la ville en question
	ARC voisins; 				// Pointeur vers : - l'indice de la ville d'arrivée,
						//		   - le coût pour y aller depuis la ville en question,
						//		   - l'adresse du voisin suivant
	double pcc; 				// Coût total pour aller à la ville en question depuis la ville de départ.
	long pere; 				// Indice de la ville menant à la ville en question par le chemin le plus court.
	struct sommet * suiv;    		//Sommet suivant 

}* T_SOMMET ;



typedef struct larc { 				// Définition de la structure qui contient l'indice, le coût et le voisin suivant.

	long arrivee;				// Indice de la ville voisine.
	double cout ; 				// Coût pour aller de la ville d'origine à la ville voisine.
	struct larc *suiv ; 			// Pointeur vers l'ARC (la ville voisine) suivant(e).

}* ARC;

