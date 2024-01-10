/**
 * \file arbre.h
 * Header pour les arbres
 */

#include "pixel.h"


/**
 * \typedef typedef struct node Node;
 * typedef Node: Implementation d'un noeud
 */
typedef struct node{
    int rang; //la borne supérieure sur la hauteur
   	Pixel value;
	struct node * pere;
} Node;

/**
 * \typedef Node* Tree;
 * typedef Tree: Implementation d'Arbre
 */
typedef Node* Tree;


/**
 * crée un ensemble(Arbre), insere la valeur x dans Arbre.value 
 * 
 * \param x valeur x pixel(couleur), representat de l'ensemble
 * \pre aucune
 * \post aucune
 * \return Arbre 
 */
Tree MakeSet(Pixel x);


/**
 * crée un ensemble(Arbre), insere la valeur x dans Arbre.value 
 * 
 * \param x valeur x pixel(couleur), representat de l'ensemble
 * \pre aucune
 * \post aucune
 * \return Arbre 
 */
Tree FindSet(Tree x);

/**
 * fait l'union des ensembles(Arbres) disjoints Sx et Sy dans un seul ensemble Sxy.
 * Pour choisir le representant entre les deux ensemble, on utilisera le rang, le 
 * representant de l'union donc sera le represntant de l'ensemble qui a le rang le 
 * plus grand 
 * 
 * \param x valeur x pixel(couleur), representat de l'ensemble
 * \pre les deux ensembles Sx et Sy doivent être disjoints.
 * \post aucune
 * \return Arbre union(Sxy)
 */
void Union(Tree x, Tree y);
