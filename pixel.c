/**
 * \file pixel.c
 * code pour la création et/ou modification des pixels
 *      pour lire et/ou écrire les images PPM/PBM
 */

#include "pixel.h"
#include "traitErreur.h"

Pixel remplirPixel(Couleur rouge, Couleur vert, Couleur bleu){
    struct Pixel tmp;
    tmp.couleur[0] = rouge;
    tmp.couleur[1] = vert;
    tmp.couleur[2] = bleu;
    return tmp;
}

Pixel** Read(const char* cheminImage){
    FILE* fichier;
    if((fichier = fopen(cheminImage,"r"))==NULL) raler("fopen fichier\n");

    char magicNumber[3];
    fscanf(fichier,"%s\n%d %d\n",magicNumber,&pointer.n,&pointer.m);
    if(strcmp(magicNumber,"P1") != 0) raler("Mauvais format magicNumber\n");
    printf("N: %d M: %d\n",pointer.n,pointer.m);

    Pixel** tableau = (Pixel**)malloc(pointer.n * sizeof(Pixel*));
    for(int i = 0; i < pointer.n;i++){
        tableau[i] = (Pixel*)malloc(pointer.m * sizeof(Pixel));
    }
    
    int num;
    int compteur = 0;
    for (int i = 0; i < pointer.n; i++)
    {
        for (int j = 0; j < pointer.m; j++)
        {
            num = fgetc(fichier);
            compteur++;
            if(num == '\n'){
                if(compteur == 71){
                    compteur = 0;
                    num = fgetc(fichier);
                    compteur++;
                }
                else raler("mauvais format compteur\n");
            }
            if(num == '0') tableau[i][j] = remplirPixel(0xFF,0xFF,0xFF);
            else if(num == '1') tableau[i][j] = remplirPixel(0x00,0x00,0x00);
        }    
    }
    if(fclose(fichier)!=0) raler("fclose fichier\n");
    return tableau;
}

void Write(Pixel** tableau){
    FILE* fichier;    // ouvrir fichier de type pbm
    if((fichier = fopen("image.ppm","wb")) == NULL) raler("fopen fichier");
    fprintf(fichier,"P3\n%d %d\n255\n# 5 pixels par ligne\n",pointer.n,pointer.m);         // inserer format P3
    int compteur = 0;

    for (int i = 0; i < pointer.n; i++)
    {
        for (int j = 0; j < pointer.m; j++)
        {
            fprintf(fichier,"%d %d %d",tableau[i][j].couleur[0],tableau[i][j].couleur[1],tableau[i][j].couleur[2]);
            compteur++;
            if(compteur == 5) {
                fprintf(fichier,"\n");
                compteur = 0;
            }
            else fprintf(fichier," ");
        }
        
    }
    fclose(fichier); 
}

void generatePBM(int n, int m){

    srand(time(NULL)); // initialise le générateur d'entiers aléatoires
    int compteur = 0;  // nécessaire pour mettre à la ligne après 70 chiffres

    FILE* fichier = fopen("image.pbm","wb");    // ouvrir fichier de type pbm
    fprintf(fichier,"P1\n%d %d\n",n,m);         // inserer format P1

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fprintf(fichier,"%d",rand()%3);
            compteur++;
            if(compteur == 70){
                fprintf(fichier,"\n");
                compteur = 0;
            }
        }   
    }
    fclose(fichier);
}

void generatePPM(int n, int m){

    srand(time(NULL)); // initialise le générateur d'entiers aléatoires
    int compteur = 0;  // nécessaire pour mettre à la ligne après 70 chiffres

    FILE* fichier = fopen("image.ppm","wb");    // ouvrir fichier de type pbm
    fprintf(fichier,"P3\n%d %d\n255\n# 5 pixels par ligne\n",n,m);         // inserer format P3

    Pixel pixel;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(rand()%2) pixel = remplirPixel(BLANC,BLANC,BLANC);
            else pixel = remplirPixel(NOIR,NOIR,NOIR);
            fprintf(fichier,"%d %d %d",pixel.couleur[0],pixel.couleur[1],pixel.couleur[2]);
            compteur++;
            if(compteur==5){
                fprintf(fichier,"\n");
                compteur=0;
            }
            else fprintf(fichier," ");
        }
    }

    fclose(fichier);
}

void Generate(char* p, int n,int m){
    
    if (strcmp(p,"P1")) generatePBM(n,m);
    else generatePPM(n,m);
}