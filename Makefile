all: main

main: main.c hashtables
		gcc -Wall main.c hashtables.o entry_chaining.o common.o -o main -g

hashtables: hashtables.c hashtables.h entry_chaining common
		gcc -c -Wall hashtables.c

entry_chaining: entry_chaining.c entry_chaining.h common
		gcc -c -Wall entry_chaining.c

common: common.c common.h
		gcc -c -Wall common.c

clean: 
		rm -r *.o main
