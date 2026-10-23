/*Write a program that reads an integer and checks whether the entered number is even or odd.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    printf("Inserisci un numero intero n: \n");
    scanf("%d", &n);
    if(n%2==0){
        printf("Il numero %d è pari\n", &n);
    }
    else {
        printf("Il numero %d è dispari\n", &n);
    }
}