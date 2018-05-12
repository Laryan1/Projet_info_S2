
DIRSDL=

CFLAGS=
LDFLAGS=

dijkstra : fonctions_prog.o dijkstra.o arbres.o
	gcc -lm -o $@ $^ $(LDFLAGS)

fonctions : fonctions_prog.o
	gcc -lm -o $@ $^ $(LDFLAGS)
	
%.o:%.c 
	gcc -lm -g -c $(CFLAGS)  $^

clean :
	rm *.o dijkstra
