
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int m, n, **arr1, **arr2, **arr3;

void add_matrix(int,int);
void add_cell(void*);

void main()
{
    printf("THIS IS A PROGRAM TO ADD TWO m*n MATRICES BY USING m*n NUMBER OF THREADS\n\n");
    printf("Enter the value of M: ");
    scanf("%i",&m);
    printf("Enter the value of N: ");
    scanf("%i",&n);
    arr1 = (int**)calloc(m,sizeof(int*));
    arr2 = (int**)calloc(m,sizeof(int*));
    arr3 = (int**)calloc(m,sizeof(int*));
    for(int i=0; i<m; ++i)
    {
        arr1[i] = (int*)calloc(n,sizeof(int));
        arr2[i] = (int*)calloc(n,sizeof(int));
        arr3[i] = (int*)calloc(n,sizeof(int));
    }
    printf("\nEnter the value of the elements of 1st array below -->\n");
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            scanf("%i", *(arr1+i)+j);
        }
    }
    printf("\nEnter the value of the elements of 2nd array below -->\n");
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            scanf("%i", *(arr2+i)+j);
        }
    }
    add_matrix(m,n);
    printf("\n\nSum of the matrices is as follows:\n");
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            printf(" %i", ((arr3+i)+j));
        }
        printf("\n");
    }
    for(int i=0; i<m; ++i)
    {
        free(*(arr1+i));
        free(*(arr2+i));
        free(*(arr3+i));
    }
    free(arr1);
    free(arr2);
    free(arr3);
    arr1 = NULL;
    arr2 = NULL;
    arr3 = NULL;
    printf("\n");
}

void add_matrix(int M, int N)
{
    pthread_t T[M][N];
    for(int i=0; i<M; ++i)
    {
        int tmp[2];
        for(int j=0; j<N; ++j)
        {
            tmp[0] = i;
            tmp[1] = j;
            pthread_create(&T[i][j],NULL,(void*)add_cell,(void*)tmp);
            pthread_join(T[i][j],NULL);
        }
    }
}

void add_cell(void* arg)
{
    int *TMP = (int*)arg;
    arr3[TMP[0]][TMP[1]] = arr1[TMP[0]][TMP[1]] + arr2[TMP[0]][TMP[1]];
}