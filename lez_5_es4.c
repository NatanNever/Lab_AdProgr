/*Write a program that reads a series of non-negative integers from the keyboard and prints them.
The program stops when a negative number is entered (which is not printed)*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n,i=0;
    while (i==0){
    printf("Insert a number:\n");
    scanf("%d", &n);
    if (n>=0)
    printf("Numero inserito: %d\n",n);
    else{
    printf("Numero inserito negativo, esco dal ciclo\n");
    break;}
    }
}