CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
OBJ = btree.o table.o main.o

all: main

main: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

btree.o: btree.c btree.h
	$(CC) $(CFLAGS) -c btree.c

table.o: table.c table.h btree.h
	$(CC) $(CFLAGS) -c table.c

main.o: main.c table.h btree.h
	$(CC) $(CFLAGS) -c main.c

persitence.o : persistance.c persitence.h persistance.h
	$(CC) $(CFLAGS) -c persistance.c

clean:
	rm -f *.o main
