#ifndef _File
#define _File
#include <stdio.h>
#include "carte.h"
#include "liste.h"

typedef Liste File;
typedef CARTE ELEMENT;

File creer_file(void); /* Créer une file vide*/
int file_vide(File ); /*Teste si la file est vide */
void visualiser_file(File ); 
File enfiler(ELEMENT , File ); /*Ajoute une carte à la file par la queue*/
ELEMENT defiler(File* ); /*Renvoie la carte en tete de file ET la supprime de la file */

#endif

