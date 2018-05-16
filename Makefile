
DIRSDL=

CFLAGS=
LDFLAGS=

dijkstra : fonctions_prog.o dijkstra.o arbres.o
	gcc -Wall -Wextra -lm -o $@ $^ $(LDFLAGS) -O2

%.o:%.c 
	gcc -Wall -Wextra  -lm -g -c $(CFLAGS)  $^ -O2

clean :
	rm *.o dijkstra
