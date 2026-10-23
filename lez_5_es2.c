/*Write a program that reads an integer n, checks whether the entered number is prime or not, and
prints a corresponding message*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    long int n=0,i;
    int prime=0;
    while(n<2){
    printf("Inserisci numero >=2 da verificare se sia primo \n");
    scanf("%ld", &n);
    }
    if (n%2==0){
        printf("%ld non è primo \n", n);
        prime=1;
    }
    if (prime==0){
    for(i=3;i<=sqrt(n);i+=2){
        if (n%i==0){
            printf("%ld non è primo \n", n);
            prime=1;
            break;
        }
    }
}
if (prime==0)
    printf("%ld è primo \n", n);
}