# Projet_info_S2
Projet d'info 1A - S2 PHELMA - Chemin le Plus Court - Dijkstra

Auteurs : BAILLY Romain -- LAFFONT Florian

Version du Projet : 1.7.2

Fichiers nécessaires au projet : 

    Attention, avant de procéder plus loin, veuillez noter que le fonctionnement des programmes du projet nécessite un environnement linux disposant d'un terminal, de librairies de base et selon cas de SDL(s).
    Librairies nécessaires : 
        - string.h
        - stdio.h
        - stdlib.h
        - float.h
        - math.h
        - time.h
        - unistd.h
  
Compilation du projet :

    Afin de compiler le projet, vérifiez d'abord la présence des SDL suivantes : SDL et SDL_Draw. Renseignez ensuite leur chemin d'accès dans le fichier "Makefile" en modifiant la première ligne "DIRSDL". Si les fichiers sont placés dans des dossiers différents vous devrez peut-être modifier les champs "CFLAGS" et "LDFLAGS".
    Deux options de compilation s'offrent à vous:
        -Vous pouvez compiler seulement un programme n'utilisant pas d'interface graphique à l'aide de la commande "make dijkstra".
        -Vous pouvez aussi compiler une version graphique en utilisant la commande "make dijkstra_graphique".
    Enfin la commande "make clean" vous permet (en cas de problème) de nettoyer les fichiers ".o" et l'executable, pensez à l'utiliser avant chaque nouvelle compilation pour vous assurer du bon fonctionnement du programme.
    
Utilisation du projet :

    Une fois le projet compilé, il vous faudra pour lancer le programme de recherche du plus court chemin, spécifier dans un terminal la commande suivante : "CHEMIN_D'ACCES/dijkstra" pour la version textuelle, "CHEMIN_D'ACCES/dijkstra_graphique" pour la version graphique. "CHEMIN_D'ACCES" correspond au chemin pour acceder aux fichiers. Si vous executez le terminal dans le dossier des fichiers, "CHEMIN_D'ACCES"==".".
    
Version Textuelle : 

    Une fois lancé, le programme vous demande tout d'abord de renseigner le dossier dans lequel se trouvent les fichiers de graphes en ".txt" ou ".csv". Pour cela, le programme vous permet de rensigner le chemin vers ce dossier en adressage absolu (depuis la racine) ou en adressage relatif (depuis le dossier d'execution du projet). Le choix "1" permet la selection du chemin en absolu, le choix "2" celle du chemin en relatif. Attention à ne pas oublier de rensigner le dernier "/" à la fin du chemin.
    
    Le programme vous affiche ensuite une liste non exhaustive des graphes utilisés pour tester le programme et vérifier son bon fonctionnement. Ces graphes, numérotés de 1 à 9, permettent une sélection rapide du fichier. Sinon reste la possibilité de renseigner directement un nom de graphe différent, en choisissant "0". Le programme s'attend donc à ce que l'utilisateur entre un chiffre comrpis entre 0 et 9.
    
    Pour la suite, les cas diffèrent selon le graphe sélectionné. Si le graphe sélectionné présente plus de 100 000 sommets, la création d'une table de hachage n'est pas proposée, car cela pose problème quand les noms des sommets sont semblables, et ne sert à rien.
    Dans le cas où le graphe présente moins de 100 000 sommets, le programme demande à l'utilisateur s'il doit permettre ou non la recherche par nom. Renseigner "1" pour oui, et "2" pour non, comme explicité dans le programme. Choisir la seconde option rejoint le cas où le graphe présente plus de 100 000 sommets, la recherche du plus court chemin n'est alors possible qu'en renseignant les indices des sommets choisis.
    Dans le cas où la recherche par nom est permise, un dernier choix est laissé à l'utilisateur, pour confirmer la recherche par indice de sommet (choix "1") ou par nom (choix "2").
    
    Premier cas : recherche par indice de sommet. L'utilisateur doit entrer d'abord l'indice du point de départ, puis l'indice du point d'arrivée. L'indice doit être compris entre 0 et le nombre maximal de sommets.
    
    Second cas : recherche par nom de sommet. L'utilisateur doit entrer le nom du sommet de départ puis celui du sommet d'arrivé. Le nom du sommet doit être exactement celui spécifié dans le fichier de graphe, il faut respecter casse, accents et ponctuations. En cas d'erreur lors de l'entrée du nom de sommet, si celui-ci n'est pas reconnu, l'utilisateur peut à nouveau entrer un nom.
    
    Une fois ceci fait, le programme de recherche du plus court chemin s'exécute. Une fois la recherche terminée, s'affichent à l'écran diverses informations : le temps de recherche (en secondes), si le chemin entre les deux sommets a été trouvé, les informations des deux sommets, et enfin la route à prendre du sommet de départ à celui d'arrivé avec les informations des sommets traversés, et le coût correspondant. S'affiche donc pour le dernier sommet le coût total, suivi du nombre de sommets parcourus par le programme pour trouver le plus court chemin.
    
Version Graphique :

    La version graphique du programme diffère peu par son utilisation, en fait, elle permet l'affichage après l'initialisation d'une carte représentant tous les sommets et arcs du graphe. Et après avoir calculé le plus court chemin entre deux sommets, la version graphique trace en rouge sur la carte, le chemin à suivre pour aller du sommet de départ au sommet d'arrivé.
    Il n'est pas possible de modifier la taille de la fenetre pendant l'execution. Néanmoins, si l'envie vous prend, il est possible de modifier les variables "dim_x" et "dim_y" pour cette dernière.
    
    Le temps d'exécution de cette version du programme est plus long.
