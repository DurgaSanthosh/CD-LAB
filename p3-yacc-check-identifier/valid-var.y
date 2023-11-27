%{
#include <stdio.h>
int valid = 1;
%}

%token letter digit

%%

start : letter s

s : letter s
  | digit s
  |
  ;

%%
void yyerror(const char *s)
{
    valid = 0;
    printf("\nIt's not a valid identifier!\n");
}

int main()
{
    printf("\nEnter a name to be tested for identifier: ");
    yyparse();
    if(valid)

    {

        printf("\nValid Variable!\n");

    }
    return 0;
}

