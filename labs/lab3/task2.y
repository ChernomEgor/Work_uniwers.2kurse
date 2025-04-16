%{
#include <stdio.h>//printf
int yylex(void);//Объявляем flex
void yyerror(char *);// Функция обработки ошибок
%}

%token INTEGER
%token EOL

%left '+' '-'// Задаём приоритет операторов левоассоциативные

%%

program:
    /* empty */
    | program expr EOL { printf("Result: %d\n", $2); }// Если видим expr + EOL → печатаем результат
    ;

expr:
    INTEGER             { $$ = $1; }// expr → число
    | expr '+' expr     { $$ = $1 + $3; }// expr → expr + expr
    | expr '-' expr     { $$ = $1 - $3; }// expr → expr - expr
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Press Ctrl+D to exit\n");
    yyparse(); //Запрашивает токен у флекса(парсер)
    return 0;
}
