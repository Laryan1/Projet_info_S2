typedef struct lsucc {        // Définition de la structure qui contient l'indice, le coût et le voisin suivant.
long arrivee;                 // Indice de la ville voisine.
double cout ;                 // Coût pour aller de la ville d'origine à la ville voisine.
struct lsucc* suiv ;          // Pointeur vers l'ARC (la ville voisine) suivant(e).
}* ARC;

typedef struct {					// Définition de la structure qui va contenir nos variables.
	char* nom;						// Nom de la ville en question.
	double x,y ;					// Coordonnées (lattitude, longitude) de la ville en question
	ARC voisins;					// Pointeur
	double pcc;						// Coût total pour aller à la ville en question depuis la ville de départ.
	long pere;						// Indice de la ville menant à la ville en question par le chemin le plus court.
} T_SOMMET ;						// int lecture_ligne(FILE* graphe, char* ligne);								//Lit une ligne du fichier "fp" et l'écrit dans la chaine de caractère "ligne".

void lecture_fichier(FILE* graphe,T_SOMMET* liste_sommets, long* nb_sommets, long* nb_arcs);																								//Lit l'intégralité du fichier et récupère et stocke toutes les informations nécessaires.
