%{
#include "task3.tab.h"
#include <stdlib.h>
void yyerror(char *);
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }
[-+*/()]    { return *yytext; }
[ \t]       ; 
\n          { return EOL; }
.           { yyerror("Invalid character"); }

%%

int yywrap(void) {
    return 1;
}
