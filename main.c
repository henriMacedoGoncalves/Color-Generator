#include "pixel.h"
#include "traitErreur.h"

/*****  fonction read *****/
#define TAILLE_LIGNE 80


char** allocationTableau(int hauteur, int largueur){
	// allocation du tableau
	char** tableau = (char**) malloc(hauteur*sizeof(char*));
	for(int i = 0;i<hauteur;i++){
		tableau[i] = (char*) malloc(largueur*sizeof(char));
	}
	return tableau;
}

void liberationTableau(Pixel **tableau, int hauteur){
	for(int i=0;i<hauteur;i++){
		free(tableau[i]);
	}
	free(tableau);
}

int ReadTest(const char* img_path){
	FILE* file = fopen(img_path, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", img_path);
		exit(-1);
	}

	char ligne[TAILLE_LIGNE] = {0};
	//int nombreLignes = 0; // Nombre de ligne
	int nombreColonnes = 0; // Nombre de colonne

	//verification de magic number P1
	fgets(ligne, TAILLE_LIGNE, file);
	if(strcmp(ligne,"P1\n")!=0){
		printf("error\n");
		printf("%s\n",ligne);
	}

	//recuperation des dimensions
	fgets(ligne,TAILLE_LIGNE,file);
	sscanf(ligne, "%d %d", &pointer.n, &pointer.m);

	//creation de tableau bidimensional
	char** tableau = allocationTableau(pointer.n,pointer.m);

	int ligneActuelle = 0;
	int colonneTableau = 0;
	int ligneTableau = 0;
	//On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(ligne, TAILLE_LIGNE, file) != NULL){
		char *buffer = ligne;
		//printf("%ld\n",strlen(buffer));
		int colonneActuelle = 0;
		//while (colonneActuelle<70 && buffer[colonneActuelle] != "\n") //probleme pour les images que finissent pas complete a 70 caractere, faut modifier
		{
			tableau[ligneTableau][colonneTableau]=buffer[colonneActuelle];
			colonneTableau++;
			colonneActuelle++;
			if (colonneTableau >= nombreColonnes){
				ligneTableau++;
				colonneTableau=0;
			}
			
			// if(ligneTableau>=nombreLignes){
			// 	printf("Error\n");
			// 	exit(1);
			// }
		}	
		ligneActuelle += 1;
	}
	//printf("%d \n%s\n",strlen(tableau[0]),tableau[0]);

	//printf("%d %d\n",colonneTableau, ligneTableau);
	//liberation du tableau
	//liberationTableau(tableau, nombreLignes);


	// Fermeture du fichier
	fclose(file);
    return 0;
}



/***** fin fonction read *****/

int main(int argc, char *argv[])
{

    if(argc != 2) raler("usage: main <fichier>");

    Pixel** tableau = Read(argv[1]);

    pointer.tableau = tableau;
    Write(tableau);

    for (int i = 0; i < pointer.n; i++)
    {
        free(tableau[i]);
    }
    free(tableau);

    return 0;
}

