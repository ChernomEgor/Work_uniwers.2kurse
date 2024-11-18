// Написать программу, которая генерирует массив из псевдослучайных целых чисел и выводит его 
// в консоль.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    srand(time(NULL));
    int mas[50];
    for(int i = 1;i<=50;i++){
        mas[i] = rand() % 100; //псевдослучайных чисел от 0 до 99
        
    }
    for(int y = 1;y<=50;y++){
        printf("%d ",mas[y]);
    }
    getchar();//Читаем по одному символу из потока
    return 0;
}