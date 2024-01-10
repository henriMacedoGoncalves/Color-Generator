#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"

typedef struct ListeElem
{
    Pixel px;
    struct ListeElem* suivant;
    struct ListeElem* representant;
}ListeElem;

typedef struct ListeAmeliore
{
    ListeElem* representant;
    ListeElem* tail;
}ListeAmeliore;

//Fonction : MakeSet()
//Brief : Crée un nouvel ensemble d'un seul élement, la valeur du pixel est celle de celui en argument.
//Préconditions : aucune
//Post-conditons : aucune
//Paramètres : un pixel
//Return : Un ensemble set, de 1 élément
ListeAmeliore* MakeSet(Pixel p)
{
    ListeAmeliore* set = (ListeAmeliore*)malloc(sizeof(ListeAmeliore));
    if(set == NULL)
    {
        printf("erreur allocation\n");
        exit(1);
    }
    ListeElem* representant = (ListeElem*)malloc(sizeof(ListeElem));
    if(representant == NULL)
    {
        printf("erreur allocation\n");
        exit(1);
    }
    representant->px = p;
    representant->suivant = NULL;
    representant->representant = representant;

    set->representant = representant;
    set->tail = representant;
    return set;
}

//Fonction : FindSet()
//Brief : retourne un pointeur vers le représentant de l'ensemble contenant l'élément en argument
//Préconditions : aucune
//Post-conditons : aucune
//Paramètres : Un ensemble
//Return : Un élement
ListeElem* FindSet(ListeElem* elem)
{
    return(elem->representant);
}


//Fonction : AddElement()
//Brief : Ajoute l'élement e à la suite de l
//Préconditions : aucune
//Post-conditons : aucune
//Paramètres : Un ensemble et un élement
//Return : void, passage par adresse
void AddElement(ListeAmeliore* l, ListeElem* e)
{
    l->tail->suivant = e;
    l->tail = e;
    e->representant = l->representant;
    e->suivant = NULL;
    return;
}

//Fonction : ConcatList()
//Brief : Ajoute tous les élements de y à la suite de x
//Préconditions : aucune
//Post-conditons : aucune
//Paramètres : Un ensemble x et un ensemble y
//Return : void, passage par adresse
void ConcatList(ListeAmeliore* x, ListeAmeliore* y)
{
    
    ListeAmeliore* j = y;                //on met un autre pointeur sur y afin de pouvoir itéré dessus
    ListeElem* i = j->representant;     // i servira d'iterateur ListeElem, il commence à la tête de j
    do
    {
        AddElement(x,i);
        j->representant = j->representant->suivant;
        i = j->representant;
    }while(i != NULL);
}

//Fonction : ConcatList()
//Brief : Crée un nouvel ensemble qui contient les elements de x et ceux de y et libere x et y
//Préconditions : : les deux ensembles x et y sont disjoints
//Post-conditons : les ensemble x et y sont libérées en mémoire
//Paramètres : Un ensemble x et un ensemble y
//Return : Un nouvel ensemble
ListeAmeliore* Union(ListeAmeliore* x, ListeAmeliore* y)
{
    ListeAmeliore* set = MakeSet(x->representant->px);
    x->representant = x->representant->suivant;     //on decale le representant d'un element car MakeSet a deja pris en compte le premier element
    ConcatList(set,x);
    ConcatList(set,y);
    free(x);
    free(y);
    return set;
}

int main(void)
{
    
    /**
    Test de la fonction MakeSet()
    Pixel p;
    p.couleur[0] = 0;
    p.couleur[1] = 1;
    p.couleur[2] = 1;
    
    ListeAmeliore* set = MakeSet(p);
    printf("les couleurs du pixel du representant sont  :\n");
    printf("%d\n",set->representant->px.couleur[0]);
    printf("%d\n",set->representant->px.couleur[1]);
    printf("%d\n",set->representant->px.couleur[2]);
    **/
}