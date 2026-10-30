/*Write a program that declares the following data type, which describes a generic regular polygon
Write the following functions and call them from a test main function*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI acos(-1)
struct polygon
{
    int n_sides;
    double side_length;
};

struct polygon createPolygon(void);
double calculateArea(struct polygon p);
double peripoli(struct polygon p);
void doubleperi(struct polygon *pp);

int main()
{
    struct polygon poli, *pp;
    pp = &poli;
    double peri, area, dperi;
    poli = createPolygon();
    area = calculateArea(poli);
    peri = peripoli(poli);
    doubleperi(pp);
    printf("Area: %.2f\n", area);
    printf("Perimeter: %.2f\n", peri);
    printf("Double side length: %.2f\n", poli.side_length);
}

struct polygon createPolygon(void)
{
    struct polygon poli;
    printf("inserisci numero di lati del poligono: ");
    scanf("%d", &poli.n_sides);
    printf("inserisci lunghezza del lato: ");
    scanf("%lf", &poli.side_length);
    return poli;
}
double calculateArea(struct polygon p)
{
    double A;
    A = p.n_sides * pow(p.side_length, 2) / (4 * tan(PI / p.n_sides));
    return A;
}
double peripoli(struct polygon p)
{
    double peri;
    peri = p.n_sides * p.side_length;
    return peri;
}
void doubleperi(struct polygon *pp)
{
    double dperi;
    pp->side_length *= 2;
}