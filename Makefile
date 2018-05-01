
DIRSDL=/users/prog1a/C/librairie/2011

CFLAGS=-g -I$(DIRSDL)/include -I$(DIRSDL)/include/SDL -I/usr/local/include -I/usr/local/include/SDL -I/usr/include/SDL
LDFLAGS=-L$(DIRSDL)/lib -lSDL -lSDL_ttf -lSDL_image -lSDL_draw -lX11

test_ajout_pcc_triee : liste.o fonctions_prog.o test_ajout_pcc_triee.o 
	gcc -o $@ $^ $(LDFLAGS)

fonctions : fonctions_prog.o
	gcc -o $@ $^ $(LDFLAGS)
	
exemple: exemple.o  
	gcc -o $@ $^ $(LDFLAGS)

%.o:%.c 
	gcc -g -c $(CFLAGS)  $^

clean :
	rm *.o test_ajout_pcc_triee
