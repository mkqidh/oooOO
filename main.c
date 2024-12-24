#include <stdio.h>
#include <string.h>	
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    int countO = 0, counto = 0;
    char data[1000];
    int i = 0;

    FILE* file0 = fopen("lab4.txt", "r");
    if (file0 == NULL)
    {
        perror("Ошибка открытия файла lab4.txt");
        return 1;
    }

    FILE* file = fopen("output.txt", "w");
    if (file == NULL)
    {
        perror("Ошибка открытия файла output.txt");
        fclose(file0);
        return 1;
    }
    while ((data[i] = fgetc(file0)) != EOF)
    {
        if (data[i] != '\n')
        {
            if (data[i] == 'O')
            {
                countO++;
            }
            else if (data[i] == 'o')
            {
                counto++;
            }
        }
        else
        {
            fprintf(file, "O - %d o - %d\n", countO, counto);
            countO = 0;
            counto = 0;
        }
        i++;
        if (i >= sizeof(data) - 1)
        {
            i = 0;
        }
    }
    if (countO > 0 || counto > 0)
    {
        fprintf(file, "O - %d o - %d\n", countO, counto);
    }
    fclose(file0);
    fclose(file);

    return 0;
}