/*Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next float from input into *pn */
int getfloat(float *pn)
{
    int c, sign;
    float power;
    while (isspace(c = getch())) /* skip white space */
        ;

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c); /* it's not a number */
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.')
    {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
        power *= 10;
    }
    *pn *= sign / power;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    float n;
    int status;

    printf("Inserisci dei numeri interi (ctrl D su riga nuova per concludere):\n");

    // Legge finché non si arriva alla fine dell'input (EOF)
    while ((status = getfloat(&n)) != EOF)
    {
        if (status > 0)
        {
            printf("--> Numero letto con successo: %lf\n", n);
        }
        else
        {
            // Se getint restituisce 0, significa che ha trovato un carattere non valido
            // (es. una lettera o un '+' solitario) e lo ha rimesso nel buffer con ungetch().
            // Leggiamo e scartiamo il carattere per evitare un loop infinito.
            int c = getch();
            printf("--> Carattere non valido o non numerico scartato: '%c'\n", c);
        }
    }

    printf("Fine programma.\n");
    return 0;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/* buffer for ungetch */
/* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
/* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}