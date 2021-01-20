CC = gcc
CFLAGS = -Wall -Werror -ansi -pedantic -g
OBJ = queue.o LinkedList.o QueueTest.o
EXEC = main

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

queue.o : queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

LinkedList.o : LinkedList.c LinkedList.h
	$(CC) $(CFLAGS) -c LinkedList.c

QueueTest.o : QueueTest.c queue.h
	$(CC) $(CFLAGS) -c QueueTest.c

clean:
	rm -f $(OBJ) $(EXEC)
