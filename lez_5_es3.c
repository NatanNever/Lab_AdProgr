/*Write a program that reads a positive integer n from the keyboard and prints to the terminal a
square of asterisks with side length n:*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n,i,j;
    printf("Insert The number of *:\n");
    scanf("%d", &n);
    for (i=1;i<=n;i++){
    for (j=1;j<=n;j++){
        if(j==n)
        printf("*\n");
        else
        printf("*");
    }
}
}