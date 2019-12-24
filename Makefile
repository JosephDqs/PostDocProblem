#Nom de l'exécutable
EXEC = Main

#Liste des fichiers sources et objets
SRC = $(wildcard *.c)
OBJ = $(SRC:.o=.c)

#Edition de liens / génération de l'exécutable
all: $(EXEC)
$(EXEC) : $(OBJ)
	@gcc -o $@ $^ -lm
	

#Compilation des .c
Main.o :

%.o : %.c 
	@gcc $(CFLAGS) -o $@ -c $< 

#Nettoyage du projet

clean:
	rm -rf *.o

mrproper: clean
	rm -rf Main
