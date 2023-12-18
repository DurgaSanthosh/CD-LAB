/*
Design and implement a lexical analyzer for given language using C. The lexical analyzer should ignore redundant spaces, tabs and newlines.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int kwd(char buffer[]);

int main(){
	char ch, buffer[15], buf[15], operators[] = "+-*/%=,;()";
	FILE *fp;
	int i,j=0;
	int ido=0;	

	char ids[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	


	fp = fopen("input.txt","r");
	
	if(fp == NULL){
		printf("error while opening the file\n");
		exit(0);
	}
	
    // Print the contents of the input file
	printf("Input File Contents:\n");
	while ((ch = fgetc(fp)) != EOF) {
		putchar(ch);
	}
	rewind(fp);  
    // Reset file pointer to the beginning

	printf("\n\nOutput:\n");
	
	while((ch = fgetc(fp)) != EOF){

		for(i=0;i<10;i++)
			{
				if(ch == operators[i] && kwd(buffer) == 0)
					printf("id ");
			
			}
			
   		for(i = 0; i < 10; ++i){

			
   			if(ch == operators[i])
   		//		printf("operator");
				if(operators[i] == '+')
					printf("op-plus ");
				else if(operators[i] == '-')
					printf("op-sub ");
				else if(operators[i] == '*')
					printf("op-mul ");
				else if(operators[i] == '/')
					printf("op-div ");
				else if(operators[i] == '%')
					printf("op-mod ");
				else if(operators[i] == '=')
					printf("op-equ ");
				else if(operators[i] == ';')
					printf(";");
				else if(operators[i] == ',')
					printf(",");
				else if(operators[i] == '(')
					printf(".");
   		}

		
   		
   		if(isalnum(ch))
		{
			
   			buffer[j++] = ch;
			

   		}
   		else if((ch == ' ' || ch == '\n') && (j != 0))
		{
   				
				buffer[j] = '\0';
				
   				j = 0;
   				   				
   				if(kwd(buffer) == 1)
   					printf("kwd ");
				
				
   		}

		
		
	}
	
	fclose(fp);
	printf("\n");
	
	return 0;
}



int kwd(char buffer[]){
	char keywords[32][10] = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","short","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while"};
	int i, flag = 0;
	
	for(i = 0; i < 32; ++i){
		if(strcmp(keywords[i], buffer) == 0){
			flag = 1;
			break;
		}
	}
	
	return flag;
	
}


/* to run:
gcc p1lex.c
./a.out
Input File Contents:
int a,b,c;

a=b+c;


Output:
kwd id ,id ,id ;id op-equ id op-plus id ;
*/
