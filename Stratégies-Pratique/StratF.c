#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int k = 10;
int nombretest = 10000;
float nb_perdu = 0;
float nb_gagne = 0;
int randomseed = 0;

int main() {

	int deuxiememeilleur = 0;
	int meilleur = 0;
	int Candidat[10];
	int resultat = 1;
	int deja_battu = 0;

    for(int j = 0; j < nombretest; j++){

    resultat = 1;
    deja_battu = 0;
	srand (time (NULL) + randomseed);
	for (int i = 0; i < 10; i++) {
		//On met un score à chaque candidat, comme ca pas besoin de mélanger les cnadidats a chaque fois
		Candidat[i] = rand()%100;
		printf("Candidat %d : %d\n",i,Candidat[i]);
	}

	//Stratégie F : on prend le meilleur sur les k premiers

	deuxiememeilleur = Candidat[0];
	meilleur = Candidat[0];
	for (int i = 1; i < k; i++) {
		if (meilleur <= Candidat[i]) {
			deuxiememeilleur = meilleur;
			meilleur = Candidat[i];
		}
		if (meilleur > Candidat[i] >= deuxiememeilleur) {
			deuxiememeilleur = Candidat[i];
		}
	}
	printf("Le meilleur parmi k est : %d\n",meilleur);
	//Verification sur les candidats restants
	for (int i = k; i < 10; i++) {
		if ((meilleur <= Candidat[i]) && (deja_battu == 1)) {
			printf("perdu\n");
			resultat = 0;
			nb_perdu++;
			i = 10;
		}
		else if (meilleur <= Candidat[i]) { deja_battu++; }
	}
	if((resultat != 0) && (deja_battu == 1)) {
        printf("gagne\n");
        nb_gagne++;
	}
	else { nb_perdu++; printf("perdu\n"); }
    randomseed++;
    }
    //Fin du for nombretest
    float f = nb_gagne/(nb_gagne+nb_perdu);
    printf("Il y a eu %d test\n Il y a eu %f reussite et %f echec\n Cela donne une proba de reussite de : %f",nombretest,nb_gagne,nb_perdu,f);

}





