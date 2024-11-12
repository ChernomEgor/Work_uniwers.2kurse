#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[100];
    char info[1000];
    char buffer[1000];
    char nameBuf[100];
    

    printf("Введите имя файла: ");
    scanf("%s", filename);
    printf("Введите имя файла для буфера: ");
    scanf("%s", nameBuf);
    printf("Введите информацию для записи в начало файла: ");
    getchar();
    fgets(info, sizeof(info), stdin);

    // Открываем файл на чтение
    FILE *file = fopen(filename, "r");

    // Считываем исходное содержимое файла
    FILE *FBuf = fopen(nameBuf, "w");   // файл на запись
    if(!file || !FBuf)
    {
        printf("Error occured while opening file\n");
    }
    else
    {
        // пока не дойдем до конца, считываем по 256 байт из файла f1
        while((fgets(buffer, 256, file))!=NULL)
        {
            // записываем строку в файл f2
            fputs(buffer, FBuf);
        }
    }

    // Закрываем файл
    fclose(file);
    fclose(FBuf);

    // Открываем файл на запись
    file = fopen(filename, "w");

    // Записываем информацию в начало файла
    fputs(info, file);

    // Записываем исходное содержимое файла
    FBuf = fopen(nameBuf, "r");
    if(!file || !FBuf)
    {
        printf("Error occured while opening file\n");
    }
    else
    {
        // пока не дойдем до конца, считываем по 256 байт из файла f1
        while((fgets(buffer, 256, FBuf))!=NULL)
        {
            // записываем строку в файл f2
            fputs(buffer, file);
        }
    }

    // Закрываем файл
    fclose(file);
    fclose(FBuf);

    printf("Информация успешно записана в файл\n");

    return 0;
}
