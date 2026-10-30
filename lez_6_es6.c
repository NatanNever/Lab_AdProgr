/*Write a program that declares a dynamically allocated matrix, reads its dimensions and then the values of
its elements from the terminal window, and finally calculates and prints the number of elements for which
M[i][j] == i + j*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int **M;
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
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (M[i][j] == i + j)
            {
                printf("M[%d][%d]=%d\n", i, j, M[i][j]);
                k++;
            }
        }
    }
    printf("%d elementi soddisfano M[i][j]=i+j\n",k);
    for (i = 0; i < n; i++)
        free(M[i]);
    free(M);
}