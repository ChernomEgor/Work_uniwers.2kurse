%{
#include "/Labs3/task2.tab.h" //Bison output
#include <stdlib.h> //atoi
void yyerror(char *); //функцию обработки ошибок
%}

%%

[0-9]+      { yylval = atoi(yytext); return INTEGER; } // Число → сохраняем в yylval, возвращаем токен INTEGER atoi(yytext) — преобразует строку в число
[-+]        { return *yytext; }
[ \t]       ; // Пробелы и табы игнорируем
\n          { return EOL; }
.           { yyerror("Invalid character"); } // Любой другой символ → ошибка

%%

int yywrap(void) {
    return 1;// Говорим Flex, что больше нет входных данных (можно завершать)
}
