/*Write a program that reads an integer from the keyboard and prints the factorial of that value (by
exploiting a while loop)*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long int factorial (int n){
    long int r=1;
    if (n==0) return 1;
    while(n>1){
        r=r*n;
        n--;
    }
return r;
}

int main(){
    int n;
    long int f;
    printf("Insert a number:\n");
    scanf("%d", &n);
    f=factorial(n);
    printf("il fattoriale di %d è: %ld\n", n,f);
}