%{
#include <stdio.h>
%}

%%
[0-9]{10}    { printf("%s is a Valid Mobile Number\n", yytext); }  /* 10-digit number */
\n           ;                                                    /* Ignore newline */
.            { printf("%s is Not a Valid Mobile Number\n", yytext); } /* Anything else */
%%

int yywrap() { return 1; }

int main() {
    printf("Enter mobile number: ");
    yylex();
    return 0;
}
