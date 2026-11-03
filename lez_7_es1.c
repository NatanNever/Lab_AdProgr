/*Use pointers and newton bisection method to solve 3x=exp(x) and x^3+x+1=0*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double eq1(double x);
double eq2(double x);

int main(int argc, char *argv[])
{
    int c;
    c = atoi(argv[1]);
    double (*p_eq)(double);
    if (c == 1)
        p_eq = &eq1;
    if (c == 2)
        p_eq = &eq2;

    double x1, x2, x3, f1, f2, f3;
    double prec = 0.001, diff = 0.1;
    int i=0;
    printf("Inserisci estremo inferiore dell'intervallo di partenza: ");
    scanf("%lf",&x1);
    printf("Inserisci estremo superiore dell'intervallo di partenza: ");
    scanf("%lf",&x2);
    while(prec<diff)
    {
        i++;
        f1 = p_eq(x1);
        f2 = p_eq(x2);
        if (f1 * f2 < 0)
        {
            x3 = (x1 + x2) / 2;
            f3 = p_eq(x3);
            if (f3 == 0)
            {
                printf("Raggiunta soluzione in x=%lf\n", x3);
                break;
            }
            if (f1 * f3 < 0)
                x2 = x3;
            else if (f2 * f3 < 0)
                x1 = x3;
            diff = x2 - x1;
            if (prec > diff)
            {
                printf("limite di precisione raggiunto in x=%lf\n", x3);
                break;
            }
            if (i>1000)
            {
                printf("limite di iterazioni raggiunto in x=%lf\n", x3);
                break;
            }
        }
        else
        {
            printf("Non ci sono soluzioni nell'intervallo di partenza inserito\n");
            break;
        }
    }
}

double eq1(double x)
{
    double r;
    r = exp(x) - 3 * x;
    return r;
}

double eq2(double x)
{
    double r;
    r = pow(x, 3) + x + 1;
    return r;
}
