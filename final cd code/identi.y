%{
	#include <stdio.h>
	#include <ctype.h>
%}

%token digit letter

%%
	line:start '\n' {printf("Valid Identifier\n");
							return 0;}
		;
	start:letter s
		;
		s:letter s
   		|digit s
   		|
   		;
%%

yylex()
{
	char c;
	c=getchar();
	if (isdigit(c))
	{
		yylval=c;
		return digit;
	}
	else if (isalpha(c) || c=='_')
	{
		yylval=c;
		return letter;
	}
	return c;
}

int main()
{
	printf("Enter identifier name: ");
	yyparse();
}

int yyerror(char* s) {
    printf("Invalid Identifier\n");
}
