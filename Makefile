DIRSDL=/users/prog1a/C/librairie/2011

CFLAGS=-g -I$(DIRSDL)/include -I$(DIRSDL)/include/SDL -I/usr/local/include -I/usr/include/SDL
#LDFLAGS= -L$(DIRSDL)/lib -L/usr/local/lib -lSDL -lSDL_ttf -lSDL_image -lSDL_draw -lSDL_phelma -lX11
LDFLAGS=-L$(DIRSDL)/lib -L/usr/local/lib -lSDL -lSDL_draw -lSDL_phelma -lX11

dijkstra : fonctions_prog.o dijkstra.o
	gcc -Wall -Wextra -lm -o $@ $^

dijkstra_graphique: fonctions_prog.o dijkstra_graphique.o graphique.o
	gcc -Wall -Wextra -lm -o $@ $(LDFLAGS) $^

%.o:%.c 
	gcc -Wall -Wextra -g $^ -c $(CFLAGS) 

clean :
	rm *.o dijkstra
