/*There is no error checking in day_of_year or month_ day. Remedy this defect.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, /* note: in C the LAST dimension is the fastest to vary */
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  /* in FORTRAN is the opposite */
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month > 12 || day > daytab[leap][month + 1])
    {
        printf("Inserita data non valida\n");
        return -1;
    }
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if ((yearday>365 && leap ==0)||(yearday>366 && leap ==1))
        {
        printf("Inserito numero di giorno non valido\n");
        return -1;
    }
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    return 0;
}

int main()
{
    int year, month, day, yearday, *pmonth, *pday;
    int r=0;
    pmonth = &month;
    pday = &day;
    printf("Inserisci giorno ");
    scanf("%d", &day);
    printf("Inserisci mese ");
    scanf("%d", &month);
    printf("Inserisci anno ");
    scanf("%d", &year);
    yearday = day_of_year(year, month, day);
    if (yearday!=-1)
        printf("E' il giorno numero %d del %d\n", yearday, year);

    printf("Inserisci numero di giorno ");
    scanf("%d", &yearday);
    printf("Inserisci anno ");
    scanf("%d", &year);
    r=month_day(year, yearday, pmonth, pday);
    if (r!=-1)
    printf("Il giorno numero %d del %d era il %d/%d\n", yearday, year, *pday, *pmonth);
}
