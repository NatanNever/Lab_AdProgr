/*Write a program which takes a temperature in Celsius degrees (°C) in input, converts it into Fahrenheit
degrees (°F) and displays the computed value.
Then write the program which takes a temperature in °F in input, converts it into °C and shows the result*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    int Tc;
    int Tf;
    printf("inserisci Temperatura in Celsius: ");
    scanf("%d", &Tc);
    printf("Converto Celsius in Fahrenheit\n");
    Tf=(9*Tc)/5+32;
    printf("Tc: %d => Tf: %d\n", Tc,Tf);

    printf("inserisci Temperatura in Fahrenheit: ");
    scanf("%d", &Tf);
    printf("Converto Fahrenheit in Celsius\n");
    Tc=(Tf-32)*5/9;
    printf("Tf: %d => Tc: %d\n", Tf,Tc);
    return 0;
}