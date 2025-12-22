%{
#include "parser.tab.h"
%}

%%
[0-9]+      return NUM;
[+*/()-]    return yytext[0];
\n          return 0;
[ \t]       ;
%%

int yywrap() {
    return 1;
}
