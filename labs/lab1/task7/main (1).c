#include <stdio.h>

int main(void)
{
    // строка для записи
    char * message = "Hello METANIT.COM!\nAn apple a day keeps the doctor away";
    // файл для записи
    char * filename = "data.txt";
    // запись в файл
    FILE *fp = fopen(filename, "a");//a записывает текст в конец содержимого файла
    if(fp)
    {
        // записываем строку
        fputs(message, fp);
        fclose(fp);
        printf("File has been written\n");
    }
}
