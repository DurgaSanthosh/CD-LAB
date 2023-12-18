/* calculator program-lex */
%{
#include<stdio.h>
#include<stdlib.h>
int flag = 0;
int yyerror();
int yylex();
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%%

arithmetic_exp: E { printf("\nEntered exp is valid and the value is %d\n", $$);
return 0;}
;
E 	:	E '+' E {$$ = $1 + $3;}
	|	E '*' E {$$ = $1 * $3;}
	|	E '/' E {$$ = $1 / $3;}
	|	E '%' E {$$ = $1 % $3;}
	|	E '-' E {$$ = $1 - $3;}
	|	'(' E ')' {$$ = $2;}
	|	NUMBER  {$$ = $1;}
	;
	
%%
int main(){
printf("\nEnter the expression: \n");
yyparse();
}
int yyerror(){
 printf("invalid expression\n");
 flag = 1;
}
