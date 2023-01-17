#include <stdio.h>
#include <pthread.h>

#define M 4
#define N 5

int A[M][N] = {{1,0,1,0,1},{0,1,0,1,0},{1,0,1,0,1},{0,1,0,1,0}};
int B[M][N] = {{0,2,2,0,0},{2,2,0,0,2},{2,0,0,2,2},{0,0,2,2,0}};
int C[M][N] = {{0}};

void *matrix_add(void *arg) 
{
    int i = *(int*)arg;

    for (int j = 0; j < N; j++)
    {
        C[i][j] = A[i][j] + B[i][j];
    }

	pthread_exit(NULL);
}

int main()
{
    pthread_t thread[M];
    int tid[M];
	int i, j;

	/*printf("Enter values for 1st matrix:\n");

    for(i=0; i<M; i++) 
    {
        for(j=0;j<N;j++) 
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter values for 2nd matrix:\n");

    for(i=0; i<M; i++) 
    {
        for(j=0;j<N;j++) 
        {
            scanf("%d", &B[i][j]);
        }
    }*/

    for (i = 0; i < M; i++) 
    {
		tid[i] = i;
        pthread_create(&thread[i], NULL, matrix_add, &tid[i]);
        pthread_join(thread[i], NULL);
	}

	printf("\nSum of matrices:\n");

    for (i = 0; i < M; i++)
    {
		for (j = 0; j < N; j++)
        {
			printf((j < N-1) ? "%d\t" : "%d\n", C[i][j]);
        }
    }

	return 0;
}