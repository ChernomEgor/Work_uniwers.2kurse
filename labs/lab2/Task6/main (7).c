#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

void push(int num) {//Функция для пополнения стека
    if (top == MAX_SIZE - 1) {
        printf("Стек переполнен\n");
    } else {
        top++;
        stack[top] = num;
        printf("Кладем %d в Стек\n", num);
    }
}

int pop() {//Вытаскиваем элементы стека
    if (top == -1) {
        printf("Стек пуст\n");
        return -1;
    } else {
        int num = stack[top];
        top--;
        return num;
    }
}

int peek() {//Смотрим верхний элемент стека
    if (top == -1) {
        printf("Стек пуст\n");
        return -1;
    } else {
        return stack[top];
    }
}

int main() {
    push(5);
    push(100);
    push(15);
    printf("Вытаскиваем %d из стека\n", pop());
    printf("Вытаскиваем %d из стека\n", pop());
    printf("Вытаскиваем %d из стека\n", pop());
    printf("Вытаскиваем %d из стека\n", pop());
    push(51);
    push(10);
    push(154);
    push(154);
    push(154);
    push(154);
    push(154);
    push(154);
    push(154);
    push(154);
    push(154);
    push(154);
    printf("Верхний элемент стека: %d\n", peek());

    printf("Вытаскиваем %d из стека\n", pop());
    printf("Вытаскиваем %d из стека\n", pop());

    printf("Смотрим Верхний элемент: %d\n", peek());

    return 0;
}
