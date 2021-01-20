#ifndef QUEUE
#define QUEUE

#include "LinkedList.h"

LinkedList* createQueue();
void enqueue( LinkedList*, void* );
void* dequeue( LinkedList* );
void* peek( LinkedList* );
void freeQueue();

#endif
