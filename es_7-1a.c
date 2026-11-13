/*The rand( ) function is used in C to generate random numbers in the range 0 to RAND_MAX.
a)Write a program in which the computer randomly generates an integer between 0 and 99 and asks
the user to guess that number. For each input, the user gets either a “too high” or “too low” message in
the standard output until the correct value is found. Hint: use the rand() function to generate
random values and the modulo operator to gauge the upper limit of the range of generated numbers*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main(){
    srand(time(NULL)); // Inizializza il seme casuale
    int n,r=-1,i=0;
    n=rand()%(100);
    printf("Indovina il numero: ");
    do {
        scanf("%d",&r);
        if (r<n)
        printf("Troppo basso. Riprova: ");
        if (r>n)
        printf("Troppo alto. Riprova: ");
        i++;
    } while (r!=n);
    printf("Corretto. Hai impiegato %d tentativi \n", i);
}