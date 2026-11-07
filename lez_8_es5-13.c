/*Write the program tail, which prints the last n lines of its input. By default, n is 10, let us say, but it can be changed by an optional argument, so that
tail -number
prints the last number lines. The program should also accept the format
tail -n number
The program should behave rationally no matter how unreasonable the input or the value of number. Write the program so it makes the best use of available storage; lines should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of fixed size.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXLINES 5000   /* max Ilines to be sorted */
#define MAXLEN 1000     /* max length of any input line */
#define ALLOCSIZE 10000 /* size of available space */
/* max #lines to be sorted */
char *lineptr[MAXLINES];
/* pointers to text lines */
int readlines(char *lineptr[], int nlines);

char *lineptr[MAXLINES]; /* pointers to text lines */
                         /* note that this is a GLOBAL variable */
void writelines(char *lineptr[], int nlines, int n);
void q_sort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int get_line(char *, int);
char *alloc(int);

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */
/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines, n;
    n = 10;
    if (argc > 1)
    {
        if (strcmp(argv[1], "-n") == 0)
            n = atoi(argv[2]);
        else
            n = atoi(argv[1]);
    }
    if (n < 0)
    {
        printf("Inserisci n positivo: ");
        scanf("%d", &n);
    }
    /* number of input lines read */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        if (n > nlines)
            n = nlines;
        q_sort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines, n);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
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
/* readlines: read input lines */

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
void writelines(char *lineptr[], int nlines, int n)
{
    int i;
    for (i = nlines - n; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
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