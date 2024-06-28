#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void display ( int *T, int N ) {
    for ( int *p = T; p < T + N; p++ )
        printf(" %d", *p);
}

void FillVicie ( int **T, int N ) {
    srand ( time ( NULL ) );
    *T = (int*)malloc(N * sizeof(int));
    if (*T == NULL) {
        printf(" T's memory allocation failed");
        exit (1);
    }
    for ( int *p = *T; p < *T + N; ++p )
        *p = rand() %100;
}

int split ( int *T, int N, int **V1, int **V2 ) {
    *V2 = ( int * ) malloc ( N * sizeof ( int ) );
    *V1 = ( int * ) malloc ( N * sizeof ( int ) );
    if (*V1 == NULL || *V2 == NULL) {
        printf(" one of the Vs's memory allocation failed");
        exit (1);
    }
    int *eve = *V1, *od = *V2;
    for ( int *p = T; p < T + N; ++p ) {
        if ( *p % 2 )
            *od++ = *p;
        else
            *eve++ = *p;
    }
    *V2 = ( int* ) realloc ( *V2, (od  - *V2) * sizeof ( int ) );
    *V1 = ( int* ) realloc ( *V1, (eve - *V1) * sizeof ( int ) );
    if (*V1 == NULL || *V2 == NULL) {
        printf(" one of the Vs's memory re-allocation failed");
        exit (1);
    }
    
    
    return eve - *V1;
}

int main()
{
    int *V, *v1, *v2, n, ev;
    printf(" give the array's elements number: ");
    scanf("%d", &n);
    FillVicie( &V, n );
    printf(" your random array:");
    display(V, n);
    ev = split(V, n, &v1, &v2);
    printf("\n the even in it:");
    display(v1, ev);
    printf("\n its odds:");
    display(v2, n - ev);
    
    free(V);
    free(v1);
    free(v2);
    V = NULL;
    v1 = NULL;
    v2 = NULL;
    return 0;
}
