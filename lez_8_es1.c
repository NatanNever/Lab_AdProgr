/*Use pointers to solve five equations of order 2*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define flag -9999.9898

void solve(double a, double b, double c, double *s1, double *s2);

int main()
{
    int i, j;
    double **M;
    M = (double **)malloc(5 * sizeof(double *)); // the array of pointers to rows is allocated
    for (i = 0; i < 5; i++)
        M[i] = (double *)malloc(3 * sizeof(double)); // all the arrays of the rows are allocated
    double **sols;
    sols = (double **)malloc(5 * sizeof(double *)); // the array of pointers to rows is allocated
    for (i = 0; i < 5; i++)
        sols[i] = (double *)malloc(2 * sizeof(double)); // all the arrays of the rows are allocated

    for (i = 0; i < 5; i++)
    {
        printf("inserisci coefficienti dell'eq %d (premere enter tra un elemento e il successivo)\n", i);
        for (j = 0; j < 3; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }

    for (int k = 0; k < 5; k++)
    {
        solve(M[k][0], M[k][1], M[k][2], &sols[k][0], &sols[k][1]);
        printf("Sol dell' eq %d\n:", k);
        printf("s1= %lf e s2=%lf\n:", sols[k][0], sols[k][1]);
    }

    for (i = 0; i < 5; i++)
    {
        free(M[i]);
        free(sols[i]);
    }
    free(M);
    free(sols);
    return 0;
}

void solve(double a, double b, double c, double *s1, double *s2)
{
    double delta;
    delta = pow(b, 2) - 4 * a * c;
    if (a == 0)
    {
        if (b == 0)
            *s1 = *s2 = flag;
        else
            *s1 = *s2 = -c / b;
    }
    else
    {
        if (delta > 0)
        {
            *s1 = (-b + sqrt(delta)) / (2 * a);
            *s2 = (-b - sqrt(delta)) / (2 * a);
        }
        if (delta == 0)
        {
            *s1 = *s2 = -b / (2 * a);
        }
        if (delta < 0)
        {

            *s1 = *s2 = flag;
        }
    }
}
