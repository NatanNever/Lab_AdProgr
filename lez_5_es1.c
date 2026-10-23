/*Verify that for ( ; ; ) { }
is an infinite loop.
Make examples of infinite loops using while and do-while loops*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int c,i=0;
    for (;;) {
        i++;
        if (i>1000) {
            printf("Cycle for already done 1000 times, breaking out\n");
            break;
        }
    }
    while (i>0) {
        i++;
        if (i>2000) {
            printf("Cycle while already done 1000 times, breaking out\n");
            break;
    }
}
    do  {
        i++;
        if (i>3000) {
            printf("Cycle do while already done 1000 times, breaking out\n");
            break;
    } 
} while (i>0);
}