/*Modify the sort program to handle a -r flag, which indicates sorting in reverse (decreasing) order. Be sure that -r works with -n Of course try to use pointer to functions!
Add the option -f to fold upper and lower case together, so that case distinctions are not made during sorting; for example, a and A compare equal.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000    /* max #lines to be sorted */
#define MAXLEN 1000      /* max length of any input line */
#define ALLOCSIZE 10000  /* size of available space */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(char *lineptr[], int left, int right, int reverse, int (*comp)(void *, void *)); /*here is where a pointer to a function, "(*comp)(void *, void *)" is used */
int strcomp(char *, char *);
void swap(char *v[], int i, int j);
int numcmp(char *, char *);
int get_line(char *, int);
char *alloc(int);

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

int numeric = 0;   /* 1 se ordinamento numerico (-n) */
int reverse = 0;   /* 1 se ordinamento inverso (-r) */
int fold = 0;      /* 1 se ignore case (-f) */
int directory = 0; /* 1 se directory order (-d) */

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines; /* number of input lines read */
    int c;

    while (--argc > 0 && (*++argv)[0] == '-') /* note the increment of the pointer after "-" is found */
        while (c = *++argv[0])                /* ...and after each character is parsed */
            switch (c)                        /* here you have a very common use of the command "switch" */
            {
            case 'f':
                fold = 1;
                break;
            case 'd':
                directory = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'n':
                numeric = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                return -1;
            }
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        q_sort(lineptr, 0, nlines - 1, reverse, (numeric ? (int (*)(void *, void *))numcmp : (int (*)(void *, void *))strcomp)); /* here is where the pointer to the correct function is passed */
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}
int get_line(char *s, int lim)
{
    int c;
    char *p = s; // Salva l'indirizzo iniziale per calcolare la lunghezza alla fine

    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
    }
    if (c == '\n')
    {
        *s++ = c;
    }
    *s = '\0';

    return s - p; // Sottrazione tra puntatori per ottenere il numero di caratteri letti
}
char *alloc(int n)
/* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    }
    else
        /* not enough room */
        return 0;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left] •..v[right] into increasing order */
void q_sort(char *v[], int left, int right, int reverse, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (reverse == 0)
        {
            if ((*comp)(v[i], v[left]) < 0) /* here the appropriate function is called. */
                swap(v, ++last, i);         /* so no need to write two DIFFERENT versions of qsort */
        }
        if (reverse == 1)
        {
            if ((*comp)(v[i], v[left]) > 0) /* here the appropriate function is called. */
                swap(v, ++last, i);         /* so no need to write two DIFFERENT versions of qsort */
        }
    }
    swap(v, left, last);
    q_sort(v, left, last - 1, reverse, comp);
    q_sort(v, last + 1, right, reverse, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcomp(char *s, char *t)
{
    if (fold)
    {
        if (directory)
        {
            while (!isalnum((unsigned char)*s) && !isblank((unsigned char)*s))
                s++;
            while (!isalnum((unsigned char)*t) && !isblank((unsigned char)*t))
                t++;
            if (*s == '\0')
                return 0;
            while (tolower(*s) == tolower(*t))
            {
                s++;
                t++;
                if (*s == '\0')
                    return 0;
                if (!isalnum((unsigned char)*s) && !isblank((unsigned char)*s))
                    s++;
                if (!isalnum((unsigned char)*t) && !isblank((unsigned char)*t))
                    t++;
                if (*s == '\0')
                    return 0;
            }
            return tolower(*s) - tolower(*t);
        }
        for (; tolower(*s) == tolower(*t); s++, t++)
            if (*s == '\0')
                return 0;
        return tolower(*s) - tolower(*t);
    }
    if (directory)
    {
        while (!isalnum((unsigned char)*s) && !isblank((unsigned char)*s))
        {
            s++;
            if (*s == '\0')
                return 0;
        }
        while (!isalnum((unsigned char)*t) && !isblank((unsigned char)*t))
            t++;

        while (*s == *t)
        {
            s++;
            t++;
            if (*s == '\0')
                return 0;
            while (!isalnum((unsigned char)*s) && !isblank((unsigned char)*s))
            {
                s++;
                if (*s == '\0')
                    return 0;
            }
            while (!isalnum((unsigned char)*t) && !isblank((unsigned char)*t))
                t++;
        }
        return *s - *t;
    }

    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
