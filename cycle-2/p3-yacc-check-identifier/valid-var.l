%{
#include "y.tab.h"
%}

%%

[a-zA-Z_][a-zA-Z_0-9]* { yylval = yytext; return letter; }
[0-9]                 { yylval = yytext; return digit; }
.                     return yytext[0];
\n                    return 0;
%%

int yywrap()
{
    return 1;
}

