/**
 * \file traitErreur.c
 * Code pour traiter les erreurs
 */

#include "traitErreur.h"

void perror(const char* msg){
	fprintf(stderr, "%s: ", msg);
	switch(errno){
		case EPERM:
			fprintf(stderr, "Operation not permitted\n");
			break;
		case ENOENT:
			fprintf(stderr, "No such file or directory\n");
			break;
	}
}

void raler(const char* msg){
    perror(msg);
    exit(1);
}