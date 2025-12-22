%{
#include "parser.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*   return ID;
\n                     return 0;
.                      ;
%%

int yywrap() {
    return 1;
}
