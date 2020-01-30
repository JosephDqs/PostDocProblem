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
int top = 0;
int second = 1;
int strat3 = -1;
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

void top_half()
{
	int k,tmp;
	//Premier et second init à 0 et 1 on test si ils sont dans le bon ordre
	// on swap si non.
	if(candidats[second].Note > candidats[top].Note)
	{
		tmp = second;
		second = top;
		top = tmp;
	}
	for(k=2;k<(nombre-1)/2;k++)
	{
		if (candidats[k].Note > candidats[second].Note)
		{
			if(candidats[k].Note > candidats[top].Note)
			{
				second = top;
				top = k;
			}
			else
			{
				second = k;
			}
		}			
	}
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
   // SI LE TEMPS A AJOUTER MAIS COMPLIQUER POUR RIEN
    ////////////////////
	top_half();
	printf("le candidats d'après la stratégie F : premier de la première moitié : %s avec un score de %d \n",&candidats[top].Nom,candidats[top].Note);
    
    printf("le candidats d'après la stratégie G : deuxieme de la première moitié : %s avec un score de %d \n",&candidats[second].Nom,candidats[second].Note);
	
	int k = nombre/2;
	int ZEBEST = top;
	while(k<nombre)
	{
		if(candidats[k].Note > candidats[second].Note)
		{
				if(candidats[k].Note < candidats[ZEBEST].Note)
				{
					strat3 = k;
					break;
				}
				else
				{
					second = ZEBEST;
					ZEBEST = k;
					
				}
		}
		k++;
	}
	if(k>=nombre)
		printf("la stratégie V a échouée, pas de meilleur candidat dans la deuxieme partie \n");
    else
		printf("le candidat d'après la stratégie V : premier 2ieme candidat vis a vis de ses prédécesseurs: %s avec un score de %d \n",&candidats[strat3].Nom,candidats[strat3].Note);

    
    free(candidats);
	return 0;
}
