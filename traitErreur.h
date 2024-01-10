/**
 * \file traitErreur.h
 * Header pour traitErreur
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

/**
 * affiche l'erreur et le type d'erreur
 * 
 * \param msg message d'erreur
 */
void perror(const char* msg);

/**
 * fait appel à perror et arrête le programme
 * 
 * \param msg message d'erreur
 */
void raler(const char* msg);