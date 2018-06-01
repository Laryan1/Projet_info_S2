#include <SDL_phelma.h>

	/* Creation d'une fenetre graphique de 
		dimx pixels en horizontal, 

		dimy pixels en vertical

		Couleur sur 32 bits en RougeVertBleuAlpha

		Fond blanc
		Interruption possible par CTRL+C

		Origine du repere (poitn de coordonnees 0,0 ) : en haut a gauche de la fenetre

	*/	
SDL_Surface* newfenetregraphique(int dimx, int dimy) {
  SDL_Surface* f=NULL;
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
  signal(SIGINT, SIG_DFL);

  f = SDL_SetVideoMode(dimx, dimy, 32, SDL_HWSURFACE);
  if (f!=NULL) { 
    SDL_FillRect(f, NULL, SDL_MapRGB(f->format,255,255,255));
    SDL_Flip(f);
  }
  return f;
}

void SDL_phelma_clear(SDL_Surface* f) {
  if (f!=NULL) SDL_FillRect(f, NULL, SDL_MapRGB(f->format,255,255,255));
  SDL_Flip(f);
}
	/* Fonction qui trace une grille en noir  sur la fenetre d’affichage. 

		Cette grille forme un quadrillage de nl lignes, nc colonnes.

 		Chaque case a une dimension de diml pixels en vertical, dimc pixels sur l’axe horizontal.

 		Le coin supérieur gauche de la grille est situé au point de coordonnées offsetx, offesty 

	*/

void Grille(SDL_Surface* f1, int nl, int nc,int diml, int dimc, int offsetx, int offsety) {  int i;

  for (i=0; i<=nl; i++)  /* Lignes horizontales */

    Draw_Line (f1,offsetx,offsety+(i*diml),offsetx+dimc*nc,offsety+(i*diml), 0x00000000);

  for (i=0; i<=nc; i++)  /* Lignes verticales */

    Draw_Line (f1,offsetx+(i*dimc),offsety,offsetx+(i*dimc),offsety+diml*nl, 0x00000000);

}

	/* Cette fonction affiche le master mind dans la fenetre f1 

		Les couleurs sont définies en RVBA par la valeur du tableau tab. 

		nb  est le nombre de pions du master mind, 

		taille est le rayon des pions pour l’affichage graphique

	*/

void Affichemaster(SDL_Surface* f1,int tab[], int nb, int taille) {  int i, coul;

  for (i=0; i<nb; i++) {
    switch(tab[i])  {

        case 0: coul=0x000000FF; break; /* BLEU */

        case 1: coul=0x0000FF00; break; /* VERT */

        case 2: coul=0x00FF0000; break; /* ROUGE*/

        case 3: coul=0x00FFFF00; break;

        case 4: coul=0x0000FFFF; break;

        case 5: coul=0x00FF00FF; break;

        case 6: coul=0x00FFFFFF; break;

        default: coul=0xFFFFFFFF; break;
    }
        /* un pion est représenté par un cercle */

    Draw_FillCircle (f1,i*(3*taille+1)+3*taille/2,3*taille/2,taille,coul) ;
  }
        /* On fait effectivement l’affichage à l’ecran */
  SDL_Flip(f1);
}

