%{
#include <stdio.h>
%}

%%
(\+|\-|\*|\/|%)            { printf("Arithmetic Operator: %s\n", yytext); }
(==|!=|<=|>=|<|>)          { printf("Relational Operator: %s\n", yytext); }
(\&\&|\|\|)                { printf("Logical Operator: %s\n", yytext); }
(=|\+=|\-=|\*=|\/=)        { printf("Assignment Operator: %s\n", yytext); }
%%
int yywrap() {
    return 1;   
}


int main() {
    yylex();
    return 0;
}
