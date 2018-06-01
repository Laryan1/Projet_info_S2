#include <signal.h>

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_draw.h>
#include <SDL_audio_manip.h>
#include <SDL_tab.h>
#include <SDL_courbes.h>

#include <image.h>

#ifndef _SDL_PHELMA
#define _SDL_PHELMA

#ifndef _MACOS
#define SDL_PH_ROUGE 	0x00FF0000
#define SDL_PH_VERT 	0x0000FF00
#define SDL_PH_BLEU	0x000000FF
#define SDL_PH_NOIR	0x00000000
#else

#define SDL_PH_ROUGE    0x0000FF00
#define SDL_PH_VERT     0x00FF0000
#define SDL_PH_BLEU     0xFF000000
#define SDL_PH_NOIR	0x00000000
#endif

#define SDL_PH_JAUNE	(SDL_PH_ROUGE|SDL_PH_VERT)
#define SDL_PH_MAGENTA  (SDL_PH_ROUGE|SDL_PH_BLEU)
#define SDL_PH_CYAN	(SDL_PH_BLEU|SDL_PH_VERT)
#define SDL_PH_BLANC 	(SDL_PH_BLEU|SDL_PH_VERT|SDL_PH_ROUGE)

#ifdef __cplusplus 

extern "C" {
#endif
SDL_Surface* newfenetregraphique(int dimx, int dimy) ;
void Grille(SDL_Surface* f1, int nl, int nc,int diml, int dimc, int offsetx, int offsety);

void Affichemaster(SDL_Surface* f1,int tab[], int nb, int taille) ;

void SDL_phelma_clear(SDL_Surface* f);
#ifdef __cplusplus

}
#endif
#endif
