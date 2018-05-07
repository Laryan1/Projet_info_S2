typedef int element;

typedef struct _Arbre {			//Structure d'arbre permettant le parcours d'un arbre appele "pere" en passant par les "freres" et le premier fils de chaque noeud.
    element val;			//val stocke le chiffre correspondant au milliers/centaines/dizaines/... (selon "l'etage" de l'arbre) : 0 pour le premier des freres jusqu'a 9 pour le dernier.
    struct _Arbre * frere;		//Stocke l'adresse du frere de l'arbre considere
    struct _Arbre * fils;} * Arbre;	//Stocke l'adresse du premier fils de l'arbre considere

int taille_nbre(double nombre);	//Renvoie la taille d'un nombre, c'est a dire le nombre de chiffres qui le constitue.

Arbre creer_arbre(int indice);	// Cree un arbre ayant pour valeur "indice", et pour fils et frere la valeur NULL.

Arbre creer_fils(int taille_sommets);	//Cree les 10 fils d'un arbre pere, renvoye par la fonction. Si la valeur taille_sommets == 5, alors la fonction est appelee par recursivite 4 fois.
					// Les dizaines de milliers sont crees par creer_chene. Les milliers, centaines, dizaines et unites sont crees automatiquement par creer_fils.

Arbre creer_chene(long nb_sommets);	//Cree l'arbre rassemblant tous les indices des sommets. L'arbre renvoye est l'adresse du premier arbre, correspondant au premier "0" du nombre nb_sommets

Arbre adresse_arbre(long indice, Arbre pere, long nb_sommets);	//Fonction qui renvoie l'adresse de l'arbre d'indice "indice", dans l'arbre d'adresse "pere", pour un arbre contenant "nb_sommets" noeuds.

int est_present(long indice, long nb_sommets, Arbre pere);	//Fonction qui renvoie 1 si l'arbre d'indice "indice" est present dans l'arbre "pere" contenant "nb_sommets" noeuds, renvoie 0 sinon.

void ajouter_arbre(long indice, long nb_sommets, Arbre pere);	//Fonction qui ajoute l'arbre d'indice "indice" a l'arbre "pere" contenant "nb_sommets" noeuds.

void free_arbre(Arbre pere);					//Fonction qui libere l'espace memoire precedemment alloue par les calloc et occupe par les arbres.
