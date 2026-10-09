/*Write a program which takes a temperature in Celsius degrees (°C) in input, converts it into Fahrenheit
degrees (°F) and displays the computed value.
Then write the program which takes a temperature in °F in input, converts it into °C and shows the result*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
    float Tc;
    float Tf;
    printf("inserisci Temperatura in Celsius: ");
    scanf("%f", &Tc);
    printf("Converto Celsius in Fahrenheit\n");
    Tf=(9*Tc)/5+32;
    printf("Tc: %f => Tf: %f\n", Tc,Tf);

    printf("inserisci Temperatura in Fahrenheit: ");
    scanf("%f", &Tf);
    printf("Converto Fahrenheit in Celsius\n");
    Tc=(Tf-32)*5/9;
    printf("Tf: %f => Tc: %f\n", Tf,Tc);
    return 0;
}