// Написать программу, которая в качестве аргумента принимает размер произвольного массива, 
// создает его, заполняет случайными числами с плавающей точкой в интервале (arg1, arg2), 
// где arg1 и arg2 - также аргументы, вводимые при запуске программы, и выводит массив в консоль. 
// Далее программа записывает массив в файл в отсортированном виде. 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(){
    printf("Введите размер массива: ");
    int len;
    scanf("%d",&len);
    printf("Введите минимальную границу: ");
    int arg1;
    scanf("%d",&arg1);
    printf("Введите максимальную границу: ");
    int arg2;
    scanf("%d",&arg2);
    float mas[len];
    srand(time(NULL));
    printf("Numbers: ");
    // Генерация массива
    for (int i = 0; i < len; i++) {
        mas[i] = rand() / (RAND_MAX + 1.0f) * (arg2 - arg1) + arg1;
        printf("%0.2f ",mas[i]);
    }
    printf("\n");
    
    int len2 = len;
    int tmp,k;
    while(len>1) { // проход проверят, не пора ли заканчивать 
		k=0; // нет перестановок
		for (int i=1; i<len;++i) {
			if(mas[i]/10<mas[i-1]/10) {
				tmp=mas[i-1];
				mas[i-1]=mas[i];
				mas[i]=tmp; 	
				k=i; // в к будет последний переставленный элемент
			}
		}
		len=k; // с k все отсортировано
	}
	
	printf("Numbers: ");
    for (int i = 0; i < len2; i++) {
        printf("%0.2f ",mas[i]);
    }
    printf("\n");
    
    // Запись в файл 
    FILE *file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    for (int i = 0; i <= len2; i++) {
        fprintf(file, "%f\n", mas[i]);
    }

    fclose(file);

    printf("Массив успешно записан в файл.\n");


    return 0;
}