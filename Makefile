#-*- Makefile -*-

CC := gcc

#target: dependencies
#	action

all: nmapper

nmapper: main.o
	$(CC) main.o -o nmapper

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o
