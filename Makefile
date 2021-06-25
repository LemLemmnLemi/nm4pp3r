#-*- Makefile -*-

CC := gcc

#target: dependencies
#	action

all: nm4pp3r

nm4pp3r: main.o
	$(CC) main.o -o nm4pp3r

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o
