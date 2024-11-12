#include <stdio.h>

int main(void)
{
    // файл для записи
    char filename[100];
    printf("Введите значение переменной filename: \n");
    scanf("%s",filename);
    // буфер для считавания данных из файла
    char buffer[256];
    // чтение из файла
    FILE *fp = fopen(filename, "r");
    if(fp)
    {
        // пока не дойдем до конца, считываем по 256 байт
        while((fgets(buffer, 256, fp))!=NULL)
        {
            printf("%s", buffer);
        }
        fclose(fp);
    }
}