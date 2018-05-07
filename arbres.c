#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include "arbres.h"

int taille_nbre(double nombre){						//Renvoie la taille d'un nombre, c'est a dire le nombre de chiffres qui le constitue.
    return ((int) log10(nombre)+1);					//On utilise la fonction log10 qui si on en prend la partie entiere +1 est egale au nombre de chiffre dans un nombre.
}

Arbre creer_arbre(int indice){						//Cree un arbre ayant pour valeur "indice", et pour fils et frere la valeur NULL.
    Arbre new;								//On declare un nouvel arbre "new" qui sera renvoye par la fonction.
    new=calloc(1,sizeof(Arbre*));					//On lui alloue un espace memoire.
    new->val=indice;							//On donne a cet arbre la valeur de "indice" comme souhaite.
    new->frere=NULL;							//On assigne a "frere" et a "fils", la valeur NULL. 
    new->fils=NULL;							//L'adresse du frere et du 1er fils sera initialisee plus tard.
    return new;
}

Arbre creer_fils(int taille_sommets){					//Cree les 10 fils d'un arbre pere, renvoye par la fonction.
									//Si la valeur taille_sommets == 5, alors la fonction est appelee parrecursivite 4 fois.
									//Les dizaines de milliers sont crees par creer_chene.
									//Les milliers, centaines, dizaines et unites sont crees automatiquement par creer_fils.
    taille_sommets-=1;							//Des le debut du programme on decremente la valeur de taille_sommets car celle-ci est volontairement surevaluee.
    int i=0;								//On initialise un compteur pour notre boucle for.
    if (taille_sommets!=0){						//Si la valeur de taille_sommets est differente de 0, et donc si on doit encore creer un "etage" de fils, on effectue ce qui suit :
        Arbre new= creer_arbre(0);					//On commence par creer le premier fils, qui prend donc comme valeur 0.
        Arbre temp=new;							//On declare un tampon nous servant a nous deplacer le long des freres, tout en gardant l'adresse du premier "new" qui sera retournee.
        for (i=1;i<=10;i++){						//Pour chacun des 9 fils restants, on execute le code suivant :
	    if (i!=10) temp->frere=creer_arbre(i);			//Si on traite un frere autre que le dernier, on lui "donne" un frere.
            temp->fils=creer_fils(taille_sommets);			//Ensuite on donne a celui-ci 10 fils.
            temp=temp->frere;						//On passe au frere suivant par le biais du tampon "temp".
        }
    return new;								//Dans le cas ou tout s'est bien deroule, on retourne l'adresse du premier fils "new"
    }
    else return (NULL);							//En cas de probleme on return NULL.
}

Arbre creer_chene(long nb_sommets){					//Cree l'arbre rassemblant tous les indices des sommets.
									//L'arbre renvoye est l'adresse du premier arbre, correspondant au premier "0" du nombre nb_sommets
    int taille_sommets=taille_nbre((double) nb_sommets);		//On declare la variable taille_sommets comme etant le nombre de digits du nombre "nb_sommets".
    Arbre pere=creer_arbre(0);						//On cree le premier arbre dont l'adresse sera celle retournee a la fin du programme, le "pere".
    Arbre temp=pere;							//On declare un pointeur tampon qui nous servira a nous deplacer le long des arbres durant leur creation respective.
    int i=0;								//On declare le compteur de boucle pour notre for.
    int arret=(int) ((nb_sommets/ (int) pow(10,taille_sommets-1))%10);	//On initialise le nombre correspondant a notre condition d'arrêt pour notre boucle for.
    for (i=0;i<=arret;i++){						//On cree dans cette boucle un nombre de frere au premier arbre correspondant au premier chiffre de nb_sommets : 553-> 6 arbres, 5 freres.
        temp->fils=creer_fils(taille_sommets);				//On donne ainsi a chaque frere 10 fils, atteignables en utilisant l'adresse du premier fils puis le pointeur "frere".
	if (i!=arret) temp->frere=creer_arbre(i+1);			//On cree un frere pour chaque arbre, sauf pour le dernier qui n'a donc que des fils.
        temp=temp->frere;						//On passe au frere suivant par le biais du tampon "temp".
    }
    return pere;							//On renvoie finalement l'adresse du tout premier arbre, le pere. 
}



Arbre adresse_arbre(long indice, Arbre pere, long nb_sommets){		//Fonction qui renvoie l'adresse de l'arbre d'indice "indice", dans l'arbre d'adresse "pere", pour un arbre contenant "nb_sommets" noeuds.
    Arbre adresse=pere;							//On declare un pointeur "adresse" vers l'adresse du pere tout d'abord, mais qui va au final pointer sur l'arbre voulu.
    int i=0;								//On declare le compteur de boucle pour notre for.
    int taille_sommets=taille_nbre((double)nb_sommets);			//On declare la variable taille_sommets comme etant le nombre de digits du nombre "nb_sommets".
    for (i=taille_sommets;i>0;i--){					//Cette boucle for permet de "naviguer" dans les arbres en profondeur jusqu'a ce qu'on arrive aux arbres des unites.
        while((adresse->frere)!=NULL){					//La boucle while permet elle de naviguer a l'horizontale, jusqu'a trouver l'arbre frere donc la valeur est celle recherchee.
	    int vale=(indice/pow(10,i-1));				//On donne a "vale" la valeur de l'indice recherche divise par le nombre d'etages parcourus en profondeur.
            if ((adresse->val)==vale%10) break;				//On fait un modulo de 10 de la valeur "vale" pour ne garder que le digit qui nous interesse (unites,dizaines,centaines, milliers,etc...)
									//Si la valeur correspond a celle de l'arbre pointe par "adresse", on sort du while et on progresse vers son fils (progression verticale).
            adresse=adresse->frere;					//On passe au frere suivant par le biais du tampon "temp".
        }
        if(i==1) return adresse;					//Si on est a l'etage des unites (i==1) et que la valeur de l'arbre pointe est la bonne, on peut renvoyer l'adresse "adresse".
        else adresse=adresse->fils;					//Sinon, on passe au fils de l'arbre en question, on passe donc des centaines aux dizaines, ou des dizaines aux unites,etc ...
    }
return NULL;								//En cas de probleme, on renvoie NULL.
}

int est_present(long indice, long nb_sommets, Arbre pere){		//Fonction qui renvoie 1 si l'arbre d'indice "indice" est present dans l'arbre "pere" contenant "nb_sommets" noeuds, renvoie 0 sinon.
	Arbre new = adresse_arbre(indice, pere, nb_sommets);		//On declare un pointeur sur l'adresse de l'arbre d'indice "indice".
	if ((new->fils)==NULL) return 0;				//Si le pointeur contenu dans le champ "fils" de l'arbre est NULL, cela signifie que l'arbre n'appartient pas a l'arbre "pere". 
	else return 1;							//Dans le cas contraire, c'est qu'il lui appartient, on renvoie donc 1.
}

void ajouter_arbre(long indice, long nb_sommets, Arbre pere){		//Fonction qui ajoute l'arbre d'indice "indice" a l'arbre "pere" contenant "nb_sommets" noeuds.
	Arbre new = adresse_arbre(indice, pere, nb_sommets);		//On declare un pointeur sur l'adresse de l'arbre d'indice "indice".
	new->fils=creer_arbre(-1);					//On donne a l'arbre pointe un fils,qui aura la valeur "-1", afin d'eviter tout probleme mais de quand même marquer l'appartennance.
}

void free_arbre(Arbre pere){						//Fonction qui libere l'espace memoire precedemment alloue par les calloc et occupe par les arbres.
	if ((pere->fils)!=NULL) free_arbre(pere->fils);
	if ((pere->frere)!=NULL) free_arbre(pere->frere);
	pere->fils=NULL;
	pere->frere=NULL;
	free(pere);

}

