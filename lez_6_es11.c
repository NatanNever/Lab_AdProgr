/*Write a program to remove all comments from a C program*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore! Sintassi corretta: %s <file_input> <file_output>\n", argv[0]);
        return 1; // Termina con errore
    }
    // 1. Dichiarazione del puntatore a FILE
    FILE *fp = fopen(argv[1], "r");
    int c = 0, end = 0;

    // 2. Apertura del file in modalità lettura ("r")

    // 3. Controllo se l'apertura è avvenuta correttamente
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        return 1;
    }

    // 4. Lettura dei dati (es. carattere per carattere o riga per riga)
    int ch;
    // 1. Apriamo un NUOVO file in modalità scrittura ("w")
    FILE *fp2 = fopen(argv[2], "w");
    // Controlliamo sempre che il file sia stato creato con successo
    if (fp2 == NULL)
    {
        printf("Errore nella creazione del file.\n");
        fclose(fp);
        return 1;
    }

    while (end == 0 && (ch = fgetc(fp)) != EOF)
    {
        if (ch != '\n')
        {
            if (ch != '/')
                fputc(ch, fp2);
            else
            {
                ch = fgetc(fp);
                if (ch == '/')
                {
                    while ((ch = fgetc(fp)) != '\n')
                        if (ch == EOF)
                        {
                            end = 1;
                            break;
                        }

                    fputc('\n', fp2);
                } // Va a capo nel file
                else if (ch == '*')
                {
                    while (c == 0)
                    {
                        if ((ch = fgetc(fp)) == '*')
                        {
                            if ((ch = fgetc(fp)) == '/')
                                c = 1;
                            else if (ch == EOF)
                            {
                                end = 1;
                                break;
                            }
                        }
                        else if (ch == EOF)
                        {
                            end = 1;
                            break;
                        }
                    }
                }
                else
                {
                    fputc('/', fp2);
                    fputc(ch, fp2);
                }
                c = 0;
            }
        }
        else
            fputc('\n', fp2); // Va a capo nel file
    }

    // 3. Chiudiamo il file per salvare definitivamente i dati sul disco
    fclose(fp2);

    printf("File creato e scritto con successo!\n");
    // 5. Chiusura del file
    fclose(fp);

    return 0;
}