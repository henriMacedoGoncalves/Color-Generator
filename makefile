
CFLAGS=-g -Wall -Wextra -Werror -lm

# additioner _nom_.o pour chaque nouvelle .c dans ligne 5 et 6
# puis additioner après la derniere commande .o ->
# _nom_.o : _nom_.c _nom_.h + les .h utilisé
#		gcc $(CFLAGS) -c _nom_.c

main : main.o pixel.o traitErreur.o
	gcc $(CFLAGS) -o $@ main.o pixel.o traitErreur.o 
	chmod 777 main

main.o : main.c pixel.h traitErreur.h
	gcc $(CFLAGS) -c main.c

pixel.o : pixel.c pixel.h traitErreur.h
	gcc $(CFLAGS) -c pixel.c

archive :
	tar -c *.c *.h makefile-f sda2projet.tar.gz

clean :
	rm *.o main image.ppm