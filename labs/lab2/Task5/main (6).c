#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

typedef struct {// Определяем структуру для параллельной записи продуктов и цен(создаем новый тип переменных)
    char fructs[50];
    float price;
}Product;

void sort(Product *products, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (products[j].price > products[j + 1].price) {
                Product temp = products[j];
        products[j] = products[j + 1];
    products[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *inputFile = fopen("input.txt", "r"); // Читаем исходный файл с фруктами и ценами, через пробел
    FILE *outputFile = fopen("output.txt", "w"); // Создаем файл для записи и сортировки
    if (inputFile == NULL || outputFile == NULL) { // Проверка на открытие файлов
        printf("Error opening files\n");
        return 1;
    }

    Product products[MAX_PRODUCTS]; // Иницилизируем массив нового типа из структуры
    int len = 0; // Считаем количество фруктов
    // Читаем файл и считываем из файла данные и заполняем массив с продуктами
    while (fscanf(inputFile, "%s %f", products[len].fructs, &products[len].price) == 2) {
        // fprintf(inputFile, "%s %f", products[len].fructs, &products[len].price);
        len++;
    }

    sort(products, len);

    for (int i = 0; i < len; i++) {
        fprintf(outputFile, "%s %.2f\n", products[i].fructs, products[i].price);
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}