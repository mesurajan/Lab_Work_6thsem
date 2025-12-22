%{
#include <stdio.h>
int yylex(void);
void yyerror(const char *s);
%}

%token ID

%%
S : ID ;
%%

void yyerror(const char *s) {
    printf("Invalid Variable\n");
}

int main() {
    printf("Enter variable: ");
    if (yyparse() == 0)
        printf("Valid Variable\n");
    return 0;
}
