/*Write a program that converts all letters in a file to upper case. Characters other than letters
shouldn't be changed.
The program should obtain the file name from the command line and write its output to stdout.
You may want to profit from the function toupper() included in the library <ctype.h>*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Errore! Sintassi corretta: %s <file_input>\n", argv[0]);
        return 1; // Termina con errore
    }
    
    // 1. Dichiarazione del puntatore a FILE
    FILE *fp = fopen(argv[1], "r");

    // 2. Apertura del file in modalità lettura ("r")

    // 3. Controllo se l'apertura è avvenuta correttamente
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    // 4. Lettura dei dati (es. carattere per carattere o riga per riga)
    int ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch != '\n')
        {

            fputc(toupper(ch), stdout);
        }
        else
            fputc('\n', stdout); // Va a capo nel file
    }
    // 5. Chiusura del file
    fclose(fp);

    return 0;
}