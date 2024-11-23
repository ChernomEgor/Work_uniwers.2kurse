// Написать программу, которая в качестве аргумента принимает размер произвольного массива, 
// создает его, заполняет случайными числами с плавающей точкой в интервале (0, 1) и 
// выводит этот массив в консоль. 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int main(){
    printf("Введите размер массива: ");
    int len;
    scanf("%d",&len);
    float mas[len];
    srand(time(NULL));
    printf("Numbers: ");
    // Генерация массива
    for (int i = 0; i < len; i++) {
        mas[i] = rand() % 1000*0.001;
        printf("%0.2f ",mas[i]);
    }
    printf("\n");
    

    return 0;
}