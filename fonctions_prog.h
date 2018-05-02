#include "types.h"
#include "liste.h"

Liste ajout_pcc_triee(long i, Liste pcc_triee, SOMMET * l_sommet);
ARC creer_arc(long arrivee,	double cout);
void ajouter_arc(ARC arc_init, ARC arc_a_ajouter);
SOMMET creer_sommet(char* nom, double x, double y ,ARC voisins);
int appartient(Liste sommet_visites, long arrivee);

