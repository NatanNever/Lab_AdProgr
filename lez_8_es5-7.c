/*Rewrite readlines to store lines in an array supplied by main, rather than calling alloc to maintain storage.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXLINES 5000    /* max Ilines to be sorted */
#define MAXLEN 1000      /* max length of any input line */
#define ALLOCSIZE 10000  /* size of available space */
char *lineptr[MAXLINES]; /* pointers to text lines */
                         /* note that this is a GLOBAL variable */

int readlines(char *lineptr[], char line_list[][MAXLEN], int nlines);
void writelines(char *lineptr[], int nlines);
void q_sort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int get_line(char *, int);
char *alloc(int);

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char line_list[MAXLINES][MAXLEN];
    if ((nlines = readlines(lineptr, line_list, MAXLINES)) >= 0)

    {
        q_sort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
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
/* readlines: read input lines */

int readlines(char *lineptr[], char line_list[][MAXLEN], int maxlines)
{
    int len, nlines;
    char line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines) /* note that HERE is where each string is allocated */
            return -1;
        else
        {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(line_list[nlines], line);
            lineptr[nlines] = line_list[nlines]; /* ...and HERE is where the POINTER to the string is stored in the array */
            nlines++;
        }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}
/* qsort: sort v[left] ...v[rightl into increasing order */

void q_sort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains */
        return;        /* fewer than two elements */

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0) /* note the strcmp! here is where the double indirection is at work*/
            swap(v, ++last, i);
    swap(v, left, last);
    q_sort(v, left, last - 1);
    q_sort(v, last + 1, right);
}

/* swap with triviaL changes: */
/* interchange v[i] and v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}