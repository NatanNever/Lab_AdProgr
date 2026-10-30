/*Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches
any character in the string s2*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void squeeze(char s1[], char s2[]);
int main(){
   char stringa1[]="Tigre contro tigre";
   char stringa2[]="Li vuoi quei kiwi";
   squeeze(stringa1,stringa2);
   printf("%s\n",stringa1);
}

void squeeze(char s1[], char s2[])
{
    int i,j,l;
    for (l=0; s2[l]!='\0';l++){
    for (i=j=0; s1[i] != '\0'; i++){
        if (s1[i]!=s2[l])
            s1[j++]=s1[i];
        }
        s1[j]='\0';
    }
}