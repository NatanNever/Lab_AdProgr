/*. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s ,t ) copies the string t to the end of s.
Write the function strend (s ,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strconcat(char *s, char *t)
{
    while (*s != '\0') /* find end of s */
        s++;
    while ((*s++ = *t++)) /* copy t */
        ;
}
int strend(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);
    if (len_s>len_t)
    s += (len_s - len_t);
    else
    return 0;
    if (*s != '\0')
    {
        for (; *s != '\0' && *s == *t; s++, t++)
        ;
        if (*s !=*t)
            return 0;
    }
    else
        return 0;
    return 1;
}
int main()
{
    char phrase1[100] = "fraseA"; /* a pointer */
    char phrase2[] = "fraseB";
    int r;
    r=strend(phrase1,phrase2);
    printf("%d %s\n",r,phrase1);
    strconcat(phrase1,phrase2);
    r=strend(phrase1,phrase2);
    printf("%d %s\n",r,phrase1);
    return 0;
}
