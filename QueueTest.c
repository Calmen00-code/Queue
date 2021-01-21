#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "queue.h"
#include "header.h"
#define TOL 0.001

double absolute( double a )
{
    if( a < 0 )
        a *= -1;
    return a;
}

int main()
{
    LinkedList *queue = NULL;
    char * str = "James";
    int id = 24213112;
    int age = 21;
    double mark = 81.5;
    char grade = 'A';
    int empty = 0;
    queue = createLinkedList();

    enqueue( queue, str );
    enqueue( queue, &id );
    enqueue( queue, &age );
    enqueue( queue, &mark );
    enqueue( queue, &grade );

    printf("Test Dequeue String: ");
    if( strcmp( "James", (char*) dequeue( queue ) ) == 0 )
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n"); 

    printf("Test Dequeue Integer: ");
    if( *(int *) dequeue( queue ) == id )
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n"); 

    printf("Test Empty: ");
    empty = isEmpty( queue );
    if( empty == FALSE )
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n");

    printf("Test Dequeue Integer: ");
    if( *(int *) dequeue( queue ) == age )
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n"); 

    printf("Test Dequeue Double: ");
    if( absolute( *(double *) dequeue( queue ) - 81.5 ) <= TOL )
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n"); 

    printf("Test Dequeue Character: ");
    if( *(char*) dequeue( queue ) == grade )
        printf("PASSED\n\n"); 
    else
        printf("FAILED\n\n"); 

    printf("Test Dequeue String: ");
    enqueue( queue, "Wong" );
    if( strcmp( "Wong", (char *) dequeue( queue ) ) == 0 )
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n");

    printf("Test Empty: ");
    empty = isEmpty( queue );
    if( empty == TRUE )
        printf("PASSED\n\n");
    else
        printf("FAILED\n\n");
        
    freeQueue( queue );

    return 0;
}
