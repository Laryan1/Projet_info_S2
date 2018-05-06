
DIRSDL=

CFLAGS=
LDFLAGS=

dijkstra : liste.o fonctions_prog.o dijkstra.o 
	gcc -o $@ $^ $(LDFLAGS)

test_ajout_pcc_triee : liste.o fonctions_prog.o test_ajout_pcc_triee.o 
	gcc -o $@ $^ $(LDFLAGS)

fonctions : fonctions_prog.o
	gcc -o $@ $^ $(LDFLAGS)
	
%.o:%.c 
	gcc -g -c $(CFLAGS)  $^

clean :
	rm *.o dijkstra
