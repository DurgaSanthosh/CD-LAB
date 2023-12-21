/*Write a lex program to design a DFA over input {0,1}, which accept odd no. of 0s or even no. of 1s but not both together.
*/
%{
#include <stdio.h>
int zeroCount = 0;
int oneCount = 0;
%}

%%
0 { zeroCount++; }
1 { oneCount++; }

%%
int main() {
    yylex();
    
    if ((zeroCount % 2 == 1 && oneCount % 2 == 0) || (zeroCount % 2 == 0 && oneCount % 2 == 1)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}

