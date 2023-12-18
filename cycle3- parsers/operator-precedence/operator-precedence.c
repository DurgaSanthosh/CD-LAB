#include<stdio.h>

void main()
{
	char stack[20],ip[20],opt[10][10][1],ter[10];
	int i,j,k,n,top=0,col,row;
	//Initialization of Arrays
	for(i=0;i<10;i++)
	{
		 stack[i]=NULL;
		 ip[i]=NULL;
		 for(j=0;j<10;j++)
		 {
		 	opt[i][j][1]=NULL;
		 }
	}
	//take in terminal values to ter
	printf("Enter the no.of terminals :\n");
	scanf("%d",&n);
	printf("\nEnter the terminals :\n");
	scanf("%s",&ter);
	//take in precedence values of terminals
	printf("\nEnter the table values :\n");
	for(i=0;i<n;i++)
	{
	 for(j=0;j<n;j++)
	 {
		 printf("Enter the value for %c %c:",ter[i],ter[j]);
		 scanf("%s",opt[i][j]);
	 }
	}
	//display operator precedence table
	printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
	for(i=0;i<n;i++)
	{
		printf("\t%c",ter[i]);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("\n%c",ter[i]);
		for(j=0;j<n;j++){
			printf("\t%c",opt[i][j][0]);
		}
	}
	//setting stack top and getting i/p string
	stack[top]='$';
	printf("\nEnter the input string:");
	scanf("%s",ip);
	i=0;
	printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
	printf("\n%s\t\t\t%s\t\t\t",stack,ip);
	// parsing action
	while(i<=strlen(ip))
	{
		for(k=0;k<n;k++)
		{
			if(stack[top]==ter[k])
				col=k;
			if(ip[i]==ter[k])
				row=k;
		}
		if((stack[top]=='$')&&(ip[i]=='$')){
			printf("String is accepted\n");
			break;
		}
		else if((opt[col][row][0]=='<') ||(opt[col][row][0]=='='))
		{ 
			//shift
			stack[++top]=opt[col][row][0];
			stack[++top]=ip[i];
			printf("Shift %c",ip[i]);
			i++;
		  }
		else{
			if(opt[col][row][0]=='>')
			{
				//reduce
				while(stack[top]!='<')
				{
					--top;
				}
				top=top-1;
				printf("Reduce");
			}
			else
			{
				printf("\nString is not accepted");
				break;
			}
		}
		//display stack and ip contents
		printf("\n");
		for(k=0;k<=top;k++)
		{
			printf("%c",stack[k]);
		}
		printf("\t\t\t");
		for(k=i;k<strlen(ip);k++){
			printf("%c",ip[k]);
		}
		printf("\t\t\t");
	}
}
