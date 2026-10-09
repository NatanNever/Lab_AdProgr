/* Write a C program that first prompts the user to enter three numbers (e.g., A, B, and C) from the
keyboard, and then displays the results of the following computations:
• A–B
• A–B+C
• A–B+C+C */

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
    printf("inserisci valore C: ");
    scanf("%d", &C);
    printf("A-B: %d\n", A - B);
    printf("A-B+C: %d\n", A - B + C);
    printf("A-B+C-C: %d\n", A - B + C - C);
    return 0;
}