/*Write a program that reads two integers and prints:
- an appropriate message if the entered numbers are equal;
- the larger of the two if they are different.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    int m;
    printf("Inserisci un numero intero n: \n");
    scanf("%d", &n);
    printf("Inserisci un numero intero m: \n");
    scanf("%d", &m);
    if(n==m){
        printf("I numeri n: %d e m: %d sono uguali\n", &n, &m);
    }
    else {
        printf("I numeri n: %d e m: %d sono diversi\n", &n, &m);
        if (n>m){
            printf("Il numero n: %d è maggiore di m: %d\n", &n, &m);
        }
        else {
            printf("Il numero m: %d è maggiore di n: %d\n", &m, &n);
        }
    }
}