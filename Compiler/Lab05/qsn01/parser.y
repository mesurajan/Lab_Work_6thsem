%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token A B

%%
S : A S B
  | A B
  ;
%%

void yyerror(const char *s)
{
    printf("Invalid string\n");
}

int main()
{
    printf("Enter string: ");
    if (yyparse() == 0)
        printf("Valid string\n");
    return 0;
}
