/*
Given a text file, write a lex program to search aninput word in the file. If the word is present then count the total number of its occurrences, and replace every odd occurrenceof the word with your roll number.
*/
%{
#include<stdio.h>
#include<string.h>
char replace[30];
char newword[30];
int z = 1;
int count = 0;
%}
%%
[a-zA-z]+ {
		if(strcmp(yytext,replace)==0){
		count++;
		if(z%2==1){
		fprintf(yyout,"%s",newword);}
		else{
		fprintf(yyout,"%s",replace);}
		z++;
		}else{
		fprintf(yyout,"%s",yytext);
		}
	}
. 	{fprintf(yyout,"%s",yytext);}

%%
int yywrap()
{
	return 1;
}
int main(){
extern FILE *yyin,*yyout;
printf("Enter the word to search:");
scanf("%[^\n]%*c",replace);
printf("Enter the new word to replace:");
scanf("%[^\n]%*c",newword);
yyin = fopen("input.txt","r");
yyout = fopen("output.txt","w");
yylex();
printf("\nthe count of words %s is %d", replace, count);
}

