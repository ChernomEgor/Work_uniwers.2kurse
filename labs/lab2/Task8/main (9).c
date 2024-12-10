#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int Operator(char oper) {
        if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
                return 1;
        } else {
                return 0;
        }
}

int Priority(char oper) {
        if (oper == '*' || oper == '/') {
                return 2;
        } else if (oper == '+' || oper == '-') {
                return 1;
        } else {
                return 0;
        }
}

void InfixToPostfix(char infix[], char postfix[]) {
        struct Stack *stk;
        stk = (struct Stack*)malloc(sizeof(struct Stack));
        int i, j;
        char symbol, item;
        push(stk, '(');
        strcat(infix,")");
        i = 0;
        j = 0;
        symbol = infix[i];
        while (symbol != '\0') {
                if (symbol == '(') {
                        push(stk, symbol);
                       

                } else if (symbol >= '0' && symbol <= '9' || symbol == '.') {
                        postfix[j++] = symbol;

                } else if (Operator(symbol)) {
                        item = pop(stk);
                        while (Operator(item) && Priority(item) >= Priority(symbol)) {
                                postfix[j++] = item;
                                item = pop(stk);
                        }
                        
                        push(stk, item);
                        push(stk, symbol);

                } else if (symbol == ')') {
                        item = pop(stk);
                        while (item != '(') {
                                postfix[j++] = item;
                                item = pop(stk);
                        }
                }
                i++;
                symbol = infix[i];
        }
        postfix[j] = '\0';
}

int main() {
        char infix[10],postfix[10];
        printf("Введите выражение в инфиксной форме: ");
        fgets(infix, sizeof(infix), stdin);
        InfixToPostfix(infix, postfix);
        printf("Выражение в постфиксной форме: %s\n", postfix);
        return 0;
}