/*
YACC program to convert base 2 digit to base 10 digit.
*/

%{
  #include<stdio.h>
  #include<stdlib.h>
  int yylex();
  void yyerror(char *s);
%}
 %token ZERO ONE 
  
%%
N: L {printf("\nIts equivalent base 10 number is: %d\n", $$);}
L: L B {$$=$1*2+$2;}
| B {$$=$1;}
B:ZERO {$$=$1;}
|ONE {$$=$1;};
%%
  
int main()
{
 printf("Enter base 2 number:\n");
yyparse();
}
  
void yyerror(char *s)
{
 fprintf(stdout, "%s", s);
}
