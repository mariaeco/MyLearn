all: main

main: main.o hash.o hashv.o
	gcc main.o hash.o hashv.o -o main

main.o: main.c hash.h
	gcc -c main.c -o main.o

hash.o: hash.c hash.h
	gcc -c hash.c -o hash.o

hashv.o: hashv.c hash.h
	gcc -c hashv.c -o hashv.o

clean:
	rm -f *.o main