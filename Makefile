all: main

main: main.c hashtables
		gcc -Wall main.c hashtables.o entries.o common.o -o main

hashtables: hashtables.c hashtables.h entries common
		gcc -c -Wall hashtables.c

entries: entries.c entries.h common
		gcc -c -Wall entries.c

common: common.c common.h
		gcc -c -Wall common.c

clean: 
		rm -r *.o main
