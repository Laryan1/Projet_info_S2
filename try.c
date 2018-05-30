#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

void augmentetas(long* tas, int i, SOMMET* liste_sommets){
    long temp=0;
/*Ajouter le nombre d'indice i au tas ; tester s'il est plus grand que son père, si oui, les échanger, réitérer la fonction pour le père dans l'arbre. */
    if (i>0){
        if ( liste_sommets[tas[i]].pcc < liste_sommets[tas[(i-1)/2]].pcc ){

                temp=tas[(i-1)/2];
                tas[(i-1)/2]=tas[i];
                tas[i]=temp;
                augmentetas(tas,((i-1)/2),liste_sommets);
        }
    }
}



void constructiontas(long* tas, int n, SOMMET* liste_sommets){
    int i=0,k;
    for (;i<n;i++){
        augmentetas(tas,i,liste_sommets);
    }
}



void descendretas(long* tas, int i){
    long temp=0;
    int indice=0;
    while (indice<=i/2){
        if (liste_sommets[tas[2*(indice+1)]].pcc < liste_sommets[tas[2*(indice+1)-1]].pcc){
            temp=tas[2*(indice+1)];
            tas[2*(indice+1)]=tas[indice];
            tas[indice]=temp;
            indice=2*(indice+1);
        }
        else {
            temp=tas[2*(indice+1)-1];
            tas[2*(indice+1)-1]=tas[indice];
            tas[indice]=temp;
            indice=2*(indice+1)-1;
        }
    }
}

void suppressiontas(long* tas, int i){
    long temp=0;
    temp=tas[i-1];
    tas[i]=tas[0];
    tas[0]=temp;
    descendretas(tas,i-2);
}

void tri(long* tas, int n) {
  /*  Ma fonction de tri est codée ici */
     /* A FAIRE */
  int i=0;
  printf("tableau AVANT Construction:\n"); int m=0;
  for (m = 0 ; m < 10 ; m++)
  {
      printf("%lf\n", tas[m]);
  }
  constructiontas(tas,n);
  int indice=n;
  printf("tableau AVANT TRI:\n");
  for (m = 0 ; m < 10 ; m++)
  {
      printf("%lf\n", tas[m]);
  }
  while(indice>0){
    suppressiontas(tas,indice);
    indice--;
  }
}
