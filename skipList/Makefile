CC = gcc
program = main

all: main.c contatinhos.c contatinhos.h
	$(CC) -o $(program) main.c contatinhos.c

clean:
	rm -r *.o $(program)

run:
	$(CC) -o $(program) ./main.c ./contatinhos.c
	./$(program)
