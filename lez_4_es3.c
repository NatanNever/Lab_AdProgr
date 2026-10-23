/* Write a program that calculates the roots of a quadratic equation, taking into account the
possibility that the linear term in the equation ax² + bx + c = 0 may be absent. The coefficients
must be asked to the user at runtime*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double a,b,c,delta;
    double s1,s2,s;
    printf("Inserisci coefficiente a: \n");
    scanf("%lf", &a);
    while (a==0)
        {
        printf("Inserisci a diverso da 0\n");
        scanf("%lf", &a);
        }    
    printf("Inserisci coefficiente b: \n");
    scanf("%lf", &b);
    printf("Inserisci coefficiente c: \n");
    scanf("%lf", &c);
    delta=pow(b,2)-4*a*c;
    if (delta>0){
        s1=(-b+sqrt(delta))/(2*a);
        s2=(-b-sqrt(delta))/(2*a);
        printf("Le soluzioni sono %lf e %lf \n", s1, s2);
    }
    if (delta==0){
        s=-b/(2*a);
        printf("Delta=0, la soluzione è %lf \n", s);
    }
    if (delta<0){
        printf("Delta negativo, non ci sono soluzioni reali\n");
    }
}