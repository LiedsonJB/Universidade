main: main.o function.o
	gcc -o main main.o function.o

main.o: main.c function.h
	gcc -g -c main.c

function.o: function.c function.h
	gcc -g -c function.c
