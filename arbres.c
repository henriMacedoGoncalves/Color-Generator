#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbres.h"





/****** make set Arbre  ********/
Tree MakeSet(Pixel x){
    Tree new_emsemble;
    new_emsemble = malloc(sizeof(Tree));

    if(new_emsemble == NULL){
		fprintf(stderr,"Impossible d'allouer le noeud");
		return NULL;
	}
    new_emsemble->value = x;
    new_emsemble->pere = new_emsemble;
    new_emsemble->rang  = 0;

    return new_emsemble;
}




/****** FindSet Arbre  ********/

Tree FindSet(Tree x){
    if(x->pere==x)
        return x;
    else{
        return FindSet(x->pere);
    }
}


/****** Union Arbre  ********/

void Union(Tree x, Tree y){
    Tree rootTreeX = FindSet(x);
    Tree rootTreeY = FindSet(y);

    //x and y sont egaux=
    if (rootTreeX == rootTreeY)
    {
        exit(0);// rootTreeX;
    }

    //le rang de x est inferieur au rang de y
    if (rootTreeX->rang<rootTreeY->rang){
        rootTreeX->pere = rootTreeY;
    }
    //le rang de x est superieur au rang de y
    else if(rootTreeX->rang>rootTreeY->rang){
        rootTreeY->pere = rootTreeX;
    }
    //le rang de x et de y sont egaux
    else{
        rootTreeY->pere = rootTreeX;
        rootTreeX->rang = rootTreeX->rang+1;
    }
}


void testMakeSet(int n){
    int i;
    Pixel S[n];
    Tree S2[n];

    //creation d'une colection de Pixeles 
    for(i=0;i<n;i++){
        S[i].couleur[0]=(i+1)%255;
        S[i].couleur[1]=(i+1)%255;
        S[i].couleur[2]=(i+1)%255;

        printf("Pixel %d = %d%d%d\n", i, S[i].couleur[0], S[i].couleur[1], S[i].couleur[2]);
    }
    
    //creation d'un foret ou colection d'arbres (sous-ensembles)  
    for(i=0;i<n;i++){
        S2[i] = MakeSet(S[i]);
        printf("Set %d = %d%d%d rang = %d \n", i+1, S2[i]->value.couleur[0], S2[i]->value.couleur[1], S2[i]->value.couleur[2], S2[i]->rang);
    }
}

void testFindSet(int n, int m){
    int i;
    Pixel S[n];
    Tree S2[n];
    Tree representant;

    //creation d'une colection de Pixeles et un foret cad une colection d'arbres (m sous-ensembles) 
    for(i=0;i<n;i++){
        S[i].couleur[0]=(i+1)%255;
        S[i].couleur[1]=(i+1)%255;
        S[i].couleur[2]=(i+1)%255;
        S2[i] = MakeSet(S[i]);
    }

    //fixer le premier arbre comme la racine du premier sous-ensemble
    representant = FindSet(S2[0]);
    printf("Le representant de l'arbre 1 est = %d%d%d\n", representant->value.couleur[0], 
            representant->value.couleur[1], representant->value.couleur[2]);

    int j=1;
    for(i=1;i<n;i++){
        //l'arbre précédent devient le parent de l'arbre actuel
        if(j<m){
            S2[i]->pere = S2[i-1];
            j++;
        }
        //l'arbre actuelle ne change pas, c'est mantien comme la racine d'un sous-ensemble
        else{
            j=1;
        }

        representant = FindSet(S2[i]);
        printf("Le representant de l'arbre %d est = %d%d%d\n", S2[i]->value.couleur[0],
         representant->value.couleur[0], representant->value.couleur[1], representant->value.couleur[2]);
    }


}


int main(){
    testMakeSet(10);
    testFindSet(10, 5);
    return 0;
}
