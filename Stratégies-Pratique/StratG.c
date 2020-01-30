#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int k = 5;
int nombretest = 10000;
float nb_perdu = 0;
float nb_gagne = 0;
int randomseed = 0;

int main() {

	int deuxiememeilleur = 0;
	int meilleur = 0;
	int Candidat[10];
	int resultat = 1;

    for(int j = 0; j < nombretest; j++){

    resultat = 1;
	srand (time (NULL) + randomseed);
	for (int i = 0; i < 10; i++) {
		//On met un score à chaque candidat, comme ca pas besoin de mélanger les cnadidats a chaque fois
		Candidat[i] = rand()%100;
		printf("Candidat %d : %d\n",i,Candidat[i]);
	}

	//Stratégie G : on prend le deuxième meilleur sur les k premiers
	//deuxiememeilleur = Candidat[0];
	meilleur = Candidat[0];
	for (int i = 1; i < 5; i++) {
		if (meilleur <= Candidat[i]) {
			deuxiememeilleur = meilleur;
			meilleur = Candidat[i];
		}
		if (meilleur > Candidat[i] >= deuxiememeilleur) {
			deuxiememeilleur = Candidat[i];
		}
	}
	printf("Le deuxieme meilleur parmi k est : %d\n",deuxiememeilleur);
	//Verification sur les candidats restants
	for (int i = k; i < 10; i++) {
		if (deuxiememeilleur <= Candidat[i]) {
			printf("perdu\n");
			resultat = 0;
			nb_perdu++;
			i = 10;
		}
	}
	if(resultat != 0) {
        printf("gagne\n");
        nb_gagne++;
	}
    randomseed++;
    }
    //Fin du for nombretest
    float f = nb_gagne/(nb_gagne+nb_perdu);
    printf("Il y a eu %d test\n Il y a eu %f reussite et %f echec\n Cela donne une proba de reussite de : %f",nombretest,nb_gagne,nb_perdu,f);

}




