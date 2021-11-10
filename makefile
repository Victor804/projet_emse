prog: main.o client.o horaire.o file.o 
	gcc -o prog main.o client.o horaire.o file.o -lm

horaire.o: horaire.c
	gcc -c horaire.c -o horaire.o

client.o: client.c
	gcc -c client.c -o client.o

file.o: file.c
	gcc -c file.c -o file.o

main.o: main.c
	gcc -c main.c -o main.o
