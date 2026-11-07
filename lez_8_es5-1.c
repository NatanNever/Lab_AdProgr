/*As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch())) /* skip white space */
        ;

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); /* it's not a number */
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    int n;
    int status;

    printf("Inserisci dei numeri interi (ctrl D su riga nuova per concludere):\n");

    // Legge finché non si arriva alla fine dell'input (EOF)
    while ((status = getint(&n)) != EOF)
    {
        if (status > 0)
        {
            printf("--> Numero letto con successo: %d\n", n);
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