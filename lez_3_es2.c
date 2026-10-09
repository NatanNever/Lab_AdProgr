/*Write a program that reads two numbers from the keyboard, stores them in the variables A and B, and
then swaps the variable content*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int A;
    int B;
    int C;
    printf("inserisci valore A: ");
    scanf("%d", &A);
    printf("inserisci valore B: ");
    scanf("%d", &B);
    C=B;
    B=A;
    A=C;
    printf("Scambio A e B\n");
    printf("A: %d\n", A);
    printf("B: %d\n", B);
    return 0;
}