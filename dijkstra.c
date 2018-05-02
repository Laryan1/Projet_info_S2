#include "listes.h"
#include "types.h"

main(){
	/*Initialisation des variables*/
	
	Liste pcc_triee, points_visites;
	
	/*initialisation des sommets et des arcs*/
	
	/*depart + arrivee */
	long depart = 4;
	long arrivee = 10;
	
	pcc_triee = ajout_pcc_triee(depart, pcc_triee, l_sommet);
	
	do{
		long i_pt_courant = pcc_triee->val;				
		//Le point courant est celui de plus petit pcc (Le premier de la liste pcc_triee)
		points_visites = ajout_tete(i_pt_courant, points_visites);
		//On ajoute ce point a la liste des points visités, c'est a dire dont on a trouvé la plus petit pcc
		ARC arc_voisin = l_sommet[i_pt_courant].voisins;
		//C'est le premier voisin a considérer
		while(arc_voisin!=NULL){
			//Grace a ce while, on parcous toute la liste des voisin. A chaque tour de boucle, on remplace arc_voisin par l'arc suivant	
			long i_voisin = arc_voisin->arrivee;
			
			if(l_sommet[i_voisin].pcc > l_sommet[i_pt_courant].pcc + arc_voisin->cout){
				//Si le pcc actuel du voisin est plus grand que la somme du pcc du pt courant et du cout entre les 2 point, on remplace le pcc et le pere
				l_sommet[i_voisin].pcc = l_sommet[i_pt_courant].pcc + arc_voisin->cout;
				l_sommet[i_voisin].pere = i_pt_courant;
			}
			
			arc_voisin = arc_voisin->suiv;
		}
		
	} while(appartient(sommet_visites, arrivee) == 0);
	
	//On a trouvé le chemin le plus court, il faut maintenant "remonter" le chemin entre l'arrivée et le départ
	
}
