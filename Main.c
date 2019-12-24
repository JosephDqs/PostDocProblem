#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

struct CANDIDAT{
	char* Nom;
	int Note;
}

typedef struct CANDIDAT candidat;
typedef candidat* ListC  ;
ListC candidats;


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("numbre of arguments is not right : %d \n",argc);
		return 0;
	}
	FILE* Fichier = fopen(argv[1],"r");
	
	if (Fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
		int nombre = 0;
		double tmp = 0;
		fscanf(Fichier,"%d",&nombre);
		printf("Nombre candidats : %d \n",nombre);
		candidats = malloc(nombre * sizeof(candidat));
		for(int i = 0;i<nombre;i++)
		{
			fscanf(Fichier,"%s %d",&candidats[i].Nom,&candidats[i].Note);
			printf("candidats[%d] : %s note : %d \n",i,candidats[i].Nom, candidats[i].Note);
		}
			fclose(f);
	}
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier %s \n",argv[1]);
        return(-1);
    }
	return 0;
}
