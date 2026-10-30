/* Write a recursive function that calculates the nth number in the Fibonacci series, in which each number
is the sum of the previous two: 1, 1, 2, 3, 5, 8, 13, 21, 34, …, and test it.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int fibonacci(int n,int r[]);

int main(){
   int n,f;
   printf("inserisci step della sequenza di fibonacci da raggiungere: ");
   scanf("%d",&n);
   int r[n+1];
   for(int i = 0; i <= n; i++) {
       r[i] = 0;
   }
   f=fibonacci(n,r);
printf("\n");
}

int fibonacci(int n,int r[]){
    if (r[n]!=0) return r[n];
    if (n==0 || n==1){
        printf("1 ");
        return r[n]=1;
    }     
    r[n]=fibonacci(n-1,r)+fibonacci(n-2,r);
    printf("%d ",r[n]);
    return r[n];
}