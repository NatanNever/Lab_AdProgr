/*Write a program that asks the user an integer number for 8 times, that counts the number of digits in
the input number and that shows the result. The result has to be displayed after each input value. To
compute the number count, write a function whose prototype is: int count_digits(int n); */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count_digits(int n); 
int main(){
    int n;
    for (int i=1; i<=8; i++){
        printf("Inserisci un numero intero:\n");
        scanf("%d",&n);
        printf("numero di cifre del numero inserito: %d\n",count_digits(n));
    }
}

int count_digits(int  n)
{
    int r=0;
    char s[20];
    sprintf(s,"%d", n);
    for (int i=0; s[i]!='\0';i++){
    r++;
    }
    return r;
}