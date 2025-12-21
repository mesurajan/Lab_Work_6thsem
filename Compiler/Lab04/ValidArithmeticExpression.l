%{
#include <stdio.h>
%}

%%
^[0-9]+([+\-*/][0-9]+)+$   { printf("Valid Arithmetic Expression\n"); }
.*                         { printf("Invalid Arithmetic Expression\n"); }
%%

int yywrap() {
    return 1;   
}

int main() {
    yylex();
    return 0;
}
