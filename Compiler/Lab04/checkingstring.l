%{
#include <stdio.h>
%}

%%
^[a-z]+$        { printf("String contains only lowercase letters\n"); }
^[A-Z]+$        { printf("String contains only uppercase letters\n"); }
^[a-zA-Z]+$     { printf("String contains mixed case letters\n"); }
%%

int yywrap() {
    return 1;   
}

int main() {
    yylex();
    return 0;
}
