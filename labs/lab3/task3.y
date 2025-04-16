%{
#include <stdio.h>
int yylex(void);
void yyerror(char *);
%}

%token NUMBER
%token EOL

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%%

input:
    /* empty */
    | input line
    ;
line:
    expr EOL { printf("\n"); }
    ;
expr:
    NUMBER          { printf("%d ", $1); }
    | expr '+' expr { printf("+ "); }
    | expr '-' expr { printf("- "); }
    | expr '*' expr { printf("* "); }
    | expr '/' expr { printf("/ "); }
    | '(' expr ')'  /* ничего не делаем, скобки в постфиксной не нужны */
    | '-' expr %prec UMINUS { printf("~ "); } /* унарный минус */
    ;

%%
void yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
int main(void) {
    printf("Press Ctrl+D to exit\n");
    yyparse();
    return 0;
}
