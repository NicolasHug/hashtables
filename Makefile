all: main

main: main.c hashtables
		gcc -Wall main.c hashtables.o -o main

hashtables: hashtables.c hashtables.h
		gcc -c -Wall hashtables.c

clean: 
		rm -r *.o main
