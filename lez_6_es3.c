/* Write a program that asks the user for 10 values and calculates the square root of each.
To compute the square root, write a function with the following prototype:
double square_root(double a, double prec);
that calculates the value, rounded to prec decimal places, of the square root of a using Newton's method:
 are successive approximations of the square root of a. Let = a, and iterate until prec.
Ask your program/function to also print the number of iterations needed to converge to the solution.
Then, study (ideally with a plot) how the number of iterations varies as a function of the requested precision
for a given input value a */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long double square_root(long double a, long double prec);

int main(){
   long double a[10];
   long double prec=0.01,rad,prec_new;
   for (int i=0; i<10; i++){
    a[i]=-1;
    while (a[i]<0){
        printf("Inserisci numero positivo di cui ottenere la radice: ");
        scanf("%Lf", &a[i]);
    }
    for (int k=1;k<=5;k++){
        prec_new=prec*pow(0.0001,k);
        rad=square_root(a[i],prec_new);
    }
   }

}

long double square_root(long double a, long double prec){
    long double x=a, diff=1,y;
    int j=0;
    while (diff>=prec){
        y=0.5*(x+a/x);
        diff=fabs(y-x);
        x=y;
        printf("%Lf\n",x);
        j+=1;
    }
    printf("La radice di %Lf è: %.8Lf ottenuta con precisione %.2Le in %d iterazioni\n", a,x,prec,j);
    return x;
}