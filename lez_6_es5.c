/*Verify when overflow occurs during a call to a function which computes the factorial of a number,
depending on the return type assumed for the function*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i_factorial (int n){
    int r=1;
    if (n==0) return 1;
    while(n>1){
        r=r*n;
        n--;
    }
return r;
}

long int li_factorial (int n){
    long int r=1;
    if (n==0) return 1;
    while(n>1){
        r=r*n;
        n--;
    }
return r;
}

int main(){
    int n=0,i_f=1;
    long int li_f=1;
    while (i_f>0){
        n++;
        i_f=i_factorial(n);
        if (i_f/i_factorial(n-1)!=n){
            break;
        }
    }
    printf("int function stops at factorial of %d\n",n);
    n=0;
    while (li_f>0){
        n++;
        li_f=li_factorial(n);
        if (li_f/li_factorial(n-1)!=n){
            break;
        }
    }
    printf("long int function stops at factorial of %d\n",n);
}