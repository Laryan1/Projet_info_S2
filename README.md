# Projet_info_S2
Projet d'info 1A - S2 PHELMA - Chemin le Plus Court


Les types de données utiles ressembleront à :
Les sommets : T_SOMMET est une structure

typedef struct {              // Définition de la structure qui va contenir nos variables.

char* nom;                    // Nom de la ville en question.

double x,y ;                  // Coordonnées (lattitude, longitude) de la ville en question

ARC voisins;                  // Pointeur vers : - l'indice de la ville d'arrivée,

                                                 - le coût pour y aller depuis la ville en question,

                                                 - l'adresse du voisin suivant

double pcc;                   // Coût total pour aller à la ville en question depuis la ville de départ.

long pere;                    // Indice de la ville menant à la ville en question par le chemin le plus court.

} T_SOMMET ;                  // 


Les listes de successeurs : une liste classique avec un suivant; 

les valeurs sont l'indice de la ville d'arrivée  et le coût pour y aller.

typedef struct lsucc {        // Définition de la structure qui contient l'indice, le coût et le voisin suivant.

long arrivee;                 // Indice de la ville voisine.

double cout ;                 // Coût pour aller de la ville d'origine à la ville voisine.

struct lsucc* suiv ;          // Pointeur vers l'ARC (la ville voisine) suivant(e).

}* ARC;



Algorithme de Dijkstra

1.début

2.  pour tous les sommets i de G[X,A] faire pcc[i] ß +∞; pere[i]=-1 ;

3.  pcc[d] ß 0

4.  S <= {}

5.  C <= X

6.  faire

7.    Sélectionner le sommet j de C de plus petite valeur pcc[j]

8.    C <= C \ j                                                            // supprimer j de l’ensemble C

9.    S <= S ∪ j                                                            // ajouter j à l’ensemble S

10.   pour tous les sommets k adjacents à j faire                           // les successeurs de j

11.     si pcc[k] > pcc[j] + c[j][k]                                        // c(j,k) est le coût pour aller de j à k

12.     alors

13.       pcc[k] = pcc[j] + c[j][k];                                        w// Passer par j est plus court

14.       pere[k]=j ; // pour aller de a en k

15.     fin si

16.   fin pour

17. tant que a∉ S et pcc[j]!=+∞

18.fin
