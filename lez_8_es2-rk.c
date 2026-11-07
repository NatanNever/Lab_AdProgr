/*Write a midpoint integrator and apply it to solving the followind ODE*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double starform(double x, double y, double *params);
double rog_t(double x, double y, double *params);
double kg2(double x, double y, double h, double *errp, double *params, double (*eq)(double, double, double *));
void kg4(double x, double y, double h, double *k, double *errp, double *params, double (*eq)(double, double, double *));

int main(int argc, char *argv[])
{
    double rog, tg, c, ros, tf, t;
    int n;
    double h, k1, k2, err, *errp;
    double sol[2];
    double param[3], *params;
    double k[4], *kp;
    double (*eq)(double, double, double *);
    params = param;
    kp = k;
    t = sol[0] = 0;
    ros = sol[1] = 0;
    c = param[0] = 0.02;
    tg = param[2] = 1.5; // Gyr
    rog = param[1] = 10; // Msun/Kpc^3
    h = atof(argv[1]) * tg;
    tf = atof(argv[2]) * tg;
    n = round(tf / h);
    printf("%d\n",n);
    err = 0;
    errp = &err;

    for (int i = 1; i <= n; i++)
    {
        eq = &rog_t;
        k2 = kg2(sol[0], param[1], h, errp, params, eq);
        param[1] += k2;
        eq = &starform;
        k2 = kg2(sol[0], sol[1], h, errp, params, eq);
        // k1 = h * starform(sol[0], sol[1], params);
        // k2 = h * starform(sol[0] + 0.5 * h, sol[1] + 0.5 * k1, params);
        sol[1] += k2;
        sol[0] += h;
        printf("Step %d : y=%lf x=%lf | err=%lf\n", i, sol[1], sol[0], err);
    }
    return 0;
}

double starform(double x, double y, double *params)
{
    double r;
    r = params[0] * params[1] / params[2];
    return r;
}
double rog_t(double x, double y, double *params)
{
    double r;
    r = -params[0] * params[1] / params[2];
    return r;
}

double kg2(double x, double y, double h, double *errp, double *params, double (*eq)(double, double, double *))
{
    double k1, k2;
    k1 = h * eq(x, y, params);
    k2 = h * eq(x + 0.5 * h, y + 0.5 * k1, params);
    *errp += pow(h, 3);
    return k2;
}

void kg4(double x, double y, double h, double *k, double *errp, double *params, double (*eq)(double, double, double *))
{
    k[0] = h * eq(x, y, params);
    k[1] = h * eq(x + 0.5 * h, y + 0.5 * k[0], params);
    k[2] = h * eq(x + 0.5 * h, y + 0.5 * k[1], params);
    k[3] = h * eq(x + h, y + k[2], params);
    *errp += pow(h, 5);
}