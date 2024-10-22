#include <stdio.h>

/*
Написать программу, которая выводит в терминал набор аргументов вызова исполняемого файла, заданных в консоли.
*/

int main(int argc, char *argv[])
{
    int i;
    for(i = 0;i<argc;i++){
        printf("%s ", argv[i]);
    }
}
