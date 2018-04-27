#include "file.h"
#include <stdlib.h>

File creer_file(void){
	return(NULL);
}

int file_vide(File f){
	return(!f);
}

void visualiser_file(File f){
	File f_init = f;
	do {
		affiche(&(f->val));
		printf("\n");
		f = f->suivant;
	} while(f!=f_init);
} 

File enfiler(ELEMENT e, File f){
	File f2 = calloc(1, sizeof(*f2));
	f2->val = e;
	if(f == NULL){
		f2->suivant = f2;
	}
	else{
		f2->suivant = f->suivant;
		f->suivant = f2;
	}
	return f2;
}


ELEMENT defiler(File* f){
	File f_premier = (*f)->suivant;
	
	ELEMENT e = f_premier->val;
	(*f)->suivant = f_premier->suivant;
	free(f_premier);
	
	return(e);
}


