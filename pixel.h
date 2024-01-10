/**
 * \file pixel.h
 * Header pour les pixels
 */

#ifndef __PIXEL_H
#define __PIXEL_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <string.h>

#define SIZE 1024

#define BLANC 0xFF
#define NOIR 0x00

/**
 * \typedef typedef uint8_t Couleur;
 * typedef Couleur: valeur hexa qui représente une valeur RGB (rouge, vert ou bleu) 
 */
typedef uint8_t Couleur;

/**
 * \typedef typedef struct Pixel{Couleur couleur[3];}Pixel;
 * Structure Pixel: contient la couleur RGB du Pixel pour le fichier ppm
 */
typedef struct Pixel{
    Couleur couleur[3];
}Pixel;

/**
 * \struct struct Tableau{Pixel** tableau; int n; int m;}pointer;
 * structure pointer: contient le tableau de pixel, sa longueur et sa hauteur
 */
struct Tableau{
    Pixel** tableau;
    int n;
    int m;
} pointer;

/**
 * crée un pixel, insère les valeurs du parametre dans pixel et ensuite retourne ce pixel
 * 
 * \param rouge valeur hexa pour la couleur rouge
 * \param vert valeur hexa pour la couleur vert
 * \param bleu valeur hexa pour la couleur bleu
 * \pre rouge,vert,bleu >= 0x00 et rouge,vert,bleu <= 0xFF
 * \post
 * \return Pixel 
 */
Pixel remplirPixel(Couleur rouge, Couleur vert, Couleur bleu);

/**
 * retourne un tableau bidimensionnel de type Pixel à partir d'une image PBM
 * 
 * \param cheminImage l'image qu'on veut lire
 * \pre cheminImage existant
 * \post
 * \return Pixel** 
 */
Pixel** Read(const char* cheminImage);

/**
 *  génère à partir d'un tableau bidimensionnel de type Pixel une image au format PPM
 * 
 * \param tableau tableau bidimensionnel de type Pixel
 * \pre tableau de format PPM
 * \post
 */
void Write(Pixel** tableau);

/**
 * génère une image aléatoire en noir et blanc de taille n * m en format PBM
 * 
 * \param n longueur
 * \param m hauteur
 * \pre n,m > 0
 * \post
 */
void generatePBM(int n, int m);

/**
 * génère une image aléatoire en noir et blanc de taille n * m en format PBM
 * 
 * \param n longueur
 * \param m hauteur
 * \pre n,m > 0
 * \post
 */
void generatePPM(int n, int m);

/**
 * fait appel soit à generatePBM soit à generatePPM dépendant du paramètre p
 * 
 * \param p valeur pour déterminer si on génère une image en format PBM ou PPM
 * \param n longueur
 * \param m hauteur
 * \pre p = "PPM" || p = "PBM"; n,m > 0
 * \post
 */
void Generate(char* p, int n,int m);

#endif