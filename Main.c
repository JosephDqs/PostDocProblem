#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

struct CANDIDAT{
	char Nom[32];
	int Note;
};

typedef struct CANDIDAT candidat;

typedef candidat* ListC;

ListC candidats;
int nombre = 0;
candidat init_Candidat()
{
	candidat c1;
	strcpy(c1.Nom,"default");
	c1.Note = 0;
	return c1;
}

ListC init_ListC(int taille){
	ListC L;
	int i = 0;
	L = malloc(taille * sizeof(candidat));
	for(i=0;i<taille;i++)
	{
		L[i] = init_Candidat();
	}
	return L ;
}


int main(int argc, char **argv)
{
	// partie lecture fichier
	if(argc != 2)
	{
		printf("numbre of arguments is not right : %d \n",argc);
		return 0;
	}
	FILE* Fichier = fopen(argv[1],"r");
	
	if (Fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
		candidat c;
		fscanf(Fichier,"%d",&nombre);
		printf("Nombre candidats : %d \n",nombre);
		candidats = init_ListC(nombre);
		for(int i = 0;i<nombre;i++)
		{
			c = init_Candidat();
			fscanf(Fichier,"%s %d",&c.Nom,&c.Note);
			candidats[i] = c;
			printf("candidats[%d] : %s note : %d \n",i,candidats[i].Nom, candidats[i].Note);
		}
			fclose(Fichier);
	}
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier %s \n",argv[1]);
        return(-1);
    }
    ////////////////////
    // Shuffle des candidats ( ordre aléatoire)
    
    
    free(candidats);
	return 0;
}
