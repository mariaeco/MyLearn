all: main

main: main.o sortingmethods.o
	gcc main.o sortingmethods.o -o main

main.o: main.c funcoes.h
	gcc -c main.c -o main.o

sortingmethods.o: sortingmethods.c funcoes.h
	gcc -c sortingmethods.c -o sortingmethods.o

clean:
	rm -f *.o main 
