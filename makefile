CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -g
OBJ = queue.o LinkedList.o QueueTest.o print.o
EXEC = main

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

queue.o : queue.c queue.h header.h
	$(CC) $(CFLAGS) -c queue.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

QueueTest.o : QueueTest.c queue.h header.h
	$(CC) $(CFLAGS) -c QueueTest.c

print.o : print.c print.h
	$(CC) $(CFLAGS) -c print.c

clean:
	rm -f $(OBJ) $(EXEC)
