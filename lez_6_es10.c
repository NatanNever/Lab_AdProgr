/*Review the exercise 9., and replicate it by using the typedef mechanism wherever possible.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI acos(-1)
typedef struct
{
    int n_sides;
    double side_length;
}polygon;

polygon createPolygon(void);
double calculateArea( polygon p);
double peripoli( polygon p);
void doubleperi( polygon *pp);

int main()
{
    polygon poli, *pp;
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

polygon createPolygon(void)
{
    polygon poli;
    printf("inserisci numero di lati del poligono: ");
    scanf("%d", &poli.n_sides);
    printf("inserisci lunghezza del lato: ");
    scanf("%lf", &poli.side_length);
    return poli;
}
double calculateArea(polygon p)
{
    double A;
    A = p.n_sides * pow(p.side_length, 2) / (4 * tan(PI / p.n_sides));
    return A;
}
double peripoli(polygon p)
{
    double peri;
    peri = p.n_sides * p.side_length;
    return peri;
}
void doubleperi(polygon *pp)
{
    double dperi;
    pp->side_length *= 2;
}