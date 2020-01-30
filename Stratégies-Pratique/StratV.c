#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int k = 0;
int nombretest =100000;
float nb_perdu = 0;
float nb_gagne = 0;
int randomseed = 0;

int main() {

	int deuxiememeilleur = -1;
	int meilleur = -1;
	int solution = -1;
	int Candidat[10];
	int resultat = 1;
	int i,tmp;
    for(int j = 0; j < nombretest; j++){

    resultat = 1;
    solution = -1;
	srand (time (NULL) + randomseed);
	for (i = 0; i < 10; i++) {
		//On met un score à chaque candidat, comme ca pas besoin de mélanger les cnadidats a chaque fois 
		Candidat[i] = rand()%100;
		printf("Candidat %d : %d\n",i,Candidat[i]);
	}

	//Stratégie V : on prend le premier deuxième meilleur parmis ses prédecessesseur
		deuxiememeilleur = Candidat[0];
		meilleur = Candidat[1];
		if(deuxiememeilleur > meilleur)
		{
			tmp = deuxiememeilleur;
			deuxiememeilleur = meilleur;
			meilleur = tmp;
		}
	
	for (i = 2; i < k; i++) {
		if (meilleur < Candidat[i]) {
			deuxiememeilleur = meilleur;
			meilleur = Candidat[i];
		}
		else
		{
			if (Candidat[i] >= deuxiememeilleur) {
				deuxiememeilleur = Candidat[i];
			}
		}
	}
	printf("< K meilleur : %d deuxieme : %d \n",meilleur,deuxiememeilleur);
	for(i=k ;i<10;i++)
	{
		if(meilleur <= Candidat[i]){
			deuxiememeilleur = meilleur;
			meilleur = Candidat[i];
		}
		else 
		{
			if(Candidat[i] >deuxiememeilleur)
			{
				solution = Candidat[i];
				i = 10;
			}
		}
	}
	
	printf("l'elu est : %d \n",solution);
	//Verification sur tous les candidats 
	if(solution == -1) // fin d'iteration sans candidat elu
	{
		printf("perdu car no election \n");
		nb_perdu++;
	}
	else //on regarde le deuxieme vrai deuxieme meilleur brutalement
	{
		deuxiememeilleur = Candidat[0];
		meilleur = Candidat[1];
		if (meilleur < deuxiememeilleur) {
			tmp = deuxiememeilleur ;
			deuxiememeilleur= meilleur;
			meilleur = tmp;
		}
		for (i = 2; i < 10; i++) {
			if (meilleur <= Candidat[i]) {
				deuxiememeilleur = meilleur;
				meilleur = Candidat[i];
			}
			else
			{
				if (Candidat[i] >= deuxiememeilleur) {
					deuxiememeilleur = Candidat[i];
				}
			}
		}
		if(deuxiememeilleur == solution)
		{
			printf("gagne \n");
			nb_gagne++;
		}
		else
		{
			printf("perdu car mauvaise election \n");
			nb_perdu++;
		}
	}
    randomseed++;
    } 
    //Fin du for nombretest
    float f = nb_gagne/(nb_gagne+nb_perdu);
    printf("Il y a eu %d test\n Il y a eu %f reussite et %f echec\n Cela donne une proba de reussite de : %f \n",nombretest,nb_gagne,nb_perdu,f);

}
