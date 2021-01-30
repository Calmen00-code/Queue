#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "queue.h"
#include "header.h"
#define TOL 0.001
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define RESET "\033[0m"

double absolute( double a )
{
    if( a < 0 )
        a *= -1;
    return a;
}

int main()
{
    LinkedList *queue = NULL;
    char *alloc = NULL;
    char *str = "James";
    int id = 24213112;
    int age = 21;
    double mark = 81.5;
    char grade = 'A';
    int empty = 0;
    queue = createQueue();

    enqueue( queue, str, 's' );
    enqueue( queue, &id, 'i' );
    enqueue( queue, &age, 'i' );
    enqueue( queue, &mark, 'd' );
    enqueue( queue, &grade, 'c' );

    printf("Test Dequeue String: ");
    if( strcmp( "James", (char*) dequeue( queue ) ) == 0 )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET); 

    printf("Test Dequeue Integer: ");
    if( *(int *) dequeue( queue ) == id )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Empty: ");
    empty = isQueueEmpty( queue );
    if( empty == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Dequeue Integer: ");
    if( *(int *) dequeue( queue ) == age )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Dequeue Double: ");
    if( absolute( *(double *) dequeue( queue ) - 81.5 ) <= TOL )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Dequeue Character: ");
    if( *(char*) dequeue( queue ) == 'A' )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Test Empty: ");
    empty = isQueueEmpty( queue );
    if( empty == TRUE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("Enqueue after Empty: ");
    alloc = malloc(sizeof(char));
    strcpy( alloc, "test" );
    enqueue( queue, alloc, 's' );
    empty = isQueueEmpty( queue );
    if( empty == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);
    free(alloc); alloc = NULL;

    freeQueue( queue );
    queue = NULL;
        
    queue = createQueue();

    printf("TEST Empty after recreate queue: ");
    if ( isQueueEmpty( queue ) == TRUE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);
 
    printf("TEST EMPTY after enqueue: ");
    enqueue( queue, str, 's' );
    if ( isQueueEmpty( queue ) == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("TEST Empty after dequeue: ");
    dequeue( queue );
    if ( isQueueEmpty( queue ) == TRUE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    printf("TEST Empty after enqueue: ");
    enqueue( queue, &id, 'd' );
    if ( isQueueEmpty( queue ) == FALSE )
        printf("%sPASSED%s\n\n", GREEN, RESET);
    else
        printf("%sFAILED%s\n\n", RED, RESET);

    freeQueue( queue );
    return 0;
}
