%{
	#include <stdio.h>
	#include <ctype.h>
%}

%token DIGIT

%%
	line:expr '\n' 		 {printf("Valid expression\n");
							return 0;}
		;
	expr:expr '+' term
		|expr '-' term
		|term 			 
		;	
	term:term '*' factor
		|term '/' factor
		|factor
		;
	factor:'(' expr ')'
		|DIGIT
		;
%%

yylex()
{
	char c;
	c=getchar();
	if (isdigit(c))
	{
		yylval=c-'0';
		return DIGIT;
	}
	return c;
}

int main()
{
	printf("Enter Exp: ");
	yyparse();
}

int yyerror(char* s) {
    printf("Expression is invalid\n");
}
