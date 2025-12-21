%{
#include <stdio.h>
%}

%%
[0-9]    { printf("%s is a Digit\n", yytext); }  /* Single digit */
\n       ;                                      /* Ignore newline */
.        { printf("%s is Not a Digit\n", yytext); } /* Anything else */
%%

int yywrap() { return 1; }

int main() {
    printf("Enter a character: ");
    yylex();
    return 0;
}
