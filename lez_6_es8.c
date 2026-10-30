/* Write a program that asks the user for the x and y coordinates of 4 points in the plane, stores them in a
structure, and then calculates the perimeter of the quadrilateral and the minimum distance between the
points*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n_vertices 4
struct vertice
{
    double x, y;
};

int main()
{
    double dist, min_dist[4];
    for (int i = 0; i < 4; i++)
        min_dist[i] = 10000;
    struct vertice p1, p2, p3, p4;
    struct vertice quadrilatero[n_vertices];
    printf("inserisci il primo vertice (x - enter - y)\n");
    scanf("%lf", &p1.x);
    scanf("%lf", &p1.y);
    printf("inserisci il secondo vertice\n");
    scanf("%lf", &p2.x);
    scanf("%lf", &p2.y);
    printf("inserisci il terzo vertice\n");
    scanf("%lf", &p3.x);
    scanf("%lf", &p3.y);
    printf("inserisci il quarto vertice\n");
    scanf("%lf", &p4.x);
    scanf("%lf", &p4.y);
    quadrilatero[0] = p1;
    quadrilatero[1] = p2;
    quadrilatero[2] = p3;
    quadrilatero[3] = p4;
    int i = 0, k = 0, kk, kkk,kkkk;
    for (int j = 0; j < 4; j++)
    {
        dist = sqrt(pow(quadrilatero[k].x - quadrilatero[j].x, 2) + pow(quadrilatero[k].y - quadrilatero[j].y, 2));
        if (min_dist[k] > dist && dist != 0)
        {
            min_dist[k] = dist;
            i = j;
        }
    }
    kk = i;
    printf("Dist minima dal vertice %d al vertice %d = %lf\n", k, i, min_dist[k]);
    for (int j = 0; j < 4; j++)
    {
        if (j != k && j != kk)
        {
            dist = sqrt(pow(quadrilatero[kk].x - quadrilatero[j].x, 2) + pow(quadrilatero[kk].y - quadrilatero[j].y, 2));
            if (min_dist[kk] > dist && dist != 0)
            {
                min_dist[kk] = dist;
                i = j;
                
            }
        }
    }
    kkk = i;
    printf("Dist minima dal vertice %d al vertice %d = %lf\n", kk, i, min_dist[kk]);
    for (int j = 0; j < 4; j++)
    for (int j = 0; j < 4; j++)
    {
        if (j != k && j != kk && j != kkk)
        {
            dist = sqrt(pow(quadrilatero[kkk].x - quadrilatero[j].x, 2) + pow(quadrilatero[kkk].y - quadrilatero[j].y, 2));
            if (min_dist[kkk] > dist && dist != 0)
            {
                min_dist[kkk] = dist;
                i = j;
            }
        }
    }
    kkkk=i;
    printf("Dist minima dal vertice %d al vertice %d = %lf\n", kkk, i, min_dist[kkk]);
    dist = sqrt(pow(quadrilatero[kkkk].x - quadrilatero[0].x, 2) + pow(quadrilatero[kkkk].y - quadrilatero[0].y, 2));
    if (min_dist[kkkk] > dist && dist != 0)
    {
        min_dist[kkkk] = dist;
        i = 0;
    }
    printf("Dist dall'ultimo vertice %d al vertice %d = %lf\n", kkkk, 0, min_dist[kkkk]);
    printf("Il perimetro del quadrilatero è: %lf\n", min_dist[0]+min_dist[1]+min_dist[2]+min_dist[3]);
}
