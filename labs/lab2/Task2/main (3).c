#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
// Написать программу, которая генерирует массив из псевдослучайных целых чисел и 
// записывает в файл в обратном порядке. 
int main() {
    int arr[SIZE];
    srand(time(NULL));
    printf("Numbers: ");
    // Генерация массива
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    // Запись в файл в обратном порядке
    FILE *file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    for (int i = SIZE - 1; i >= 0; i--) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);

    printf("Массив успешно записан в файл в обратном порядке.\n");

    return 0;
}