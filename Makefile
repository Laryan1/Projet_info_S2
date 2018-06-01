
DIRSDL=

CFLAGS=
LDFLAGS=

dijkstra : fonctions_prog.o dijkstra.o
	gcc -Wall -Wextra -lm -o $@ $^ $(LDFLAGS)

%.o:%.c 
	gcc -Wall -Wextra  -lm -g -c $(CFLAGS)  $^

clean :
	rm *.o dijkstra
