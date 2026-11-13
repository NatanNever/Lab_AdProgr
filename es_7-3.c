/*a) Write a program that counts the number of characters in a text file.
b) Write a program that counts the number of words in a text file. Note: a "word'' is any sequence of
non-white-space characters.
c) Write a program that counts the number of lines in a text file.
Have each program obtain the file name from the command line*/
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
    int ch, nc = 0, nw = 0, nl = 0;
    int parola = 0;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch != '\n')
        {
            if (isspace((unsigned char)ch))
            {
                parola = 0;
            }
            else if (!parola)
            {
                parola = 1;
                nw++;
            }
        }
        else
            nl++;
        nc++;
    }
    // 5. Chiusura del file
    fclose(fp);
    printf("Num. di caratteri: %d - Num. di parole: %d - Num. di linee: %d\n", nc, nw, nl);
    return 0;
}