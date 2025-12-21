%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
S : 'a' S 'b'
  | 'a' 'b'
  ;
%%
int main() {
    printf("Enter string: ");
    yyparse();
    printf("Valid string\n");
    return 0;
}

int yyerror() {
    printf("Invalid string\n");
    exit(0);
}
