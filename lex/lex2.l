%{
	#include<stdio.h>
%}
%%
if|else|printf {printf("%s is a keyword",yytext);}
[0-9]+ {printf("%s is a number",yytext);}
[a-z,A-Z]+ {printf("%s is a word",yytext);}
.|\n {ECHO;}
%%

int main()
{
	printf("Enter string");
	yylex();

}

int yywrap()
{ 
	return 1;
}

