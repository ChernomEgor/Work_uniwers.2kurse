#include <stdio.h>
#include <stdlib.h>

struct Stack {
        int data[10];
        int top;
};

int isempty(struct Stack *stk) {
        if (stk -> top == -1) {
                return 1;
        } else {
                return 0;
        }
}

int isfull(struct Stack *stk) {
        if (stk -> top == 10) {
                return 1;
        } else {
                return 0;
        }
}

char push(struct Stack *stk, int k) {
        if (!isfull(stk)) {
                stk -> top += 1;
                stk -> data[stk -> top] = k;
        } else {
                printf("Stack is full\n");
        }
}

char pop(struct Stack *stk) {
        int k;
        if (!isempty(stk)) {
                k = stk -> data[stk -> top];
                stk -> top -= 1;
                return k;
        } else {
                printf("Stack is empty\n");
        }
}

int main() {
        struct Stack *stk;
        stk = (struct Stack*)malloc(sizeof(struct Stack));
        FILE *file = fopen("data.txt", "r");
        char c;

        while ((c = fgetc(file)) != EOF) {
                if (c >= '0' && c <= '9') {
                        push(stk, c - '0');
                } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                        int b = pop(stk);
                        int a = pop(stk);
                        int res;

                        switch(c) {
                                case '+':
                                        res = a + b;
                                        break;
                                case '-':
                                        res = a - b;
                                        break;
                                case '*':
                                        res = a * b;
                                        break;
                                case '/':
                                        res = a / b;
                                        break;
                        }
                        push(stk, res);
                }
        }
        printf("%d\n", pop(stk));
        fclose(file);
        free(stk);
}