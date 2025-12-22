%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);

int result;   // <-- store final value
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
E : E '+' E   { $$ = $1 + $3; result = $$; }
  | E '-' E   { $$ = $1 - $3; result = $$; }
  | E '*' E   { $$ = $1 * $3; result = $$; }
  | E '/' E   { $$ = $1 / $3; result = $$; }
  | '(' E ')' { $$ = $2; result = $$; }
  | NUM       { $$ = $1; result = $$; }
  ;
%%

void yyerror(const char *s) {
    printf("Invalid Expression\n");
}

int main() {
    printf("Enter expression: ");
    if (yyparse() == 0)
        printf("Result = %d\n", result);
    return 0;
}
