prog: main.o client.o horaire.o file.o fichier.o analyse.o
	gcc -o prog main.o client.o horaire.o file.o  fichier.o analyse.o -lm

horaire.o: horaire.c
	gcc -c horaire.c -o horaire.o

client.o: client.c
	gcc -c client.c -o client.o

file.o: file.c
	gcc -c file.c -o file.o

main.o: main.c main.h
	gcc -c main.c -o main.o

fichier.o: fichier.c
	gcc -c fichier.c -o fichier.o

analyse.o: analyse.c
	gcc -c analyse.c -o analyse.o -lm
