/*Write a program that calculates and prints the transposed matrix MT of a matrix M read from input*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int **M, **TM;
    int n, m;
    int i, j, k = 0;
    printf("inserisci numero di righe della matrice: ");
    scanf("%d", &n);
    printf("inserisci numero di colonne della matrice: ");
    scanf("%d", &m);
    M = (int **)malloc(n * sizeof(int *)); // the array of pointers to rows is allocated
    for (i = 0; i < n; i++)
        M[i] = (int *)malloc(m * sizeof(int)); // all the arrays of the rows are allocated
    for (i = 0; i < n; i++)
    {
        printf("inserisci elementi della riga %d (premere enter tra un elemento e il successivo)\n", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &M[i][j]);
        }
    }
    printf("Matrice Trasposta:\n");
    TM = (int **)malloc(m * sizeof(int *)); // the array of pointers to rows is allocated
    for (i = 0; i < m; i++)
        TM[i] = (int *)malloc(n * sizeof(int)); // all the arrays of the rows are allocated
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            TM[i][j] = M[j][i];
            printf("%d ", TM[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++)
        free(M[i]);
    free(M);
    for (i = 0; i < m; i++)
        free(TM[i]);
    free(TM);
}