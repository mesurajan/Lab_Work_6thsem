%{
// Write a lex program to check whether given input is negative or positive.
#include <stdio.h>
%}

%%
"-"[0-9]+   { printf("%s is Negative\n", yytext); }
[0-9]+      { printf("%s is Positive\n", yytext); }
\n          ;
.           { printf("Invalid input\n"); }
%%

int yywrap() {
    return 1;   
}

int main() {
    printf("Enter a number: ");
    yylex();
    return 0;
}