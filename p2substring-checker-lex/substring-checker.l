%{
#include <stdio.h>
%}

%%
.*[Dd][Uu][Rr][Gg].* {
    printf("Match: %s\n", yytext);
    return 0;
}
.|\n {}

%%

int main() {
    char input[256];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    yy_scan_string(input);
    yylex();
    return 0;
}

