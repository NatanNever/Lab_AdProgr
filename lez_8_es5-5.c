/*Write versions of the library functions strncpy, strncat, and strncmp; which operate on at most the first n characters of their argument strings. For example, strncpy (s,t , n) copies at most n characters of t to s.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
/* strcopy: copy t to s; pointer version 3 */
void strncopy(char *s, char *t, int n)
{
    int i = 0;
    while (*s++ = *t++)
    {
        i++;
        if (i == n)
            break;
    }
}
/* strcomp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strncomp(char *s, char *t, int n)
{
    for (; n > 0; s++, t++, n--)
    {
        if (*s == '\0')
        {
            printf("prima frase più breve di n, fin qui uguale alla seconda frase ");
            return 0;
        }
        if (*t == '\0')
        {
            printf("seconda frase più breve di n, fin qui uguale alla prima frase ");
            return 0;
        }
        if (*s != *t)
            return *s - *t;
    }
    return *s - *t;
}

/* strcat: concatenate t to end of s; s must be big enough */
void strnconcat(char *s, char *t, int n)
{
    int i = 0;
    while (*s != '\0') /* find end of s */
        s++;
    while ((*s++ = *t++)) /* copy t */
    {
        i++;
        if (i == n)
            break;
    }
}

int main()
{
    char phrase1[100] = "fraseA"; /* a pointer */
    char phrase2[] = "fraseABCDE";
    int n = 9;
    printf("%d\n", strncomp(phrase1, phrase2, n));
    strncopy(phrase1, phrase2, n);
    printf("%s\n", phrase1);
    strnconcat(phrase1, phrase2, n);
    printf("%s\n", phrase1);
    return 0;
}
