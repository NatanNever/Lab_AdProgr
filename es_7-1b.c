/*b)Write a program that estimates the value of π using pseudo-random numbers.
Hint: estimate the area of a circle inscribed within a square and that of the encompassing square. Read
the total number of points to be used from the command line. Output on two different text files the
coordinates of the points lying inside the circle and of those falling outside of it. Then, plot them to
visualise the numbers adopted to make the estimation of π.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

double rand_01()
{
    return (double)rand() / (double)RAND_MAX;
}

int main(int argc, char *argv[])
{
    srand(time(NULL)); // Inizializza il seme casuale
    FILE *square = fopen("square.txt", "w");
    FILE *circle = fopen("cerchio.txt", "w");
    if (circle == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }
    if (square == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }
    int n,p=0;
    double x, y,pi;
    n = atoi(argv[1]);

    if (n <= 0)
    {
        printf("Inserisci un numero di punti maggiore di zero.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        x = rand_01();
        y = rand_01();
        if (sqrt(pow(x - 0.5, 2) + pow(y - 0.5, 2)) > 0.5)
            fprintf(square, "%.5f %.5f\n", x, y);
        else
            {fprintf(circle, "%.5f %.5f\n", x, y);
            p++;}
    }
    pi=4.0*p/n;
    printf("Num punti nel cerchio: %d/%d\n",p,n);
    printf("Pi=%.5f\n",pi);
    fclose(circle);
    fclose(square);
}
