%{
#include <stdio.h>
int line_number = 1;

%}

%%

[ \t]+ {}
\n {
    line_number++;
}

#					{ printf("%s\t\tSpecial Symbols\t\t%d\n", yytext, line_number); }
[{] 				{ printf("%s\t\tOpening Brackets\t%d\n", yytext, line_number); }
[}] 				{ printf("%s\t\tClosing Brackets\t%d\n", yytext, line_number); }
void|printf 		{ printf("%s\t\tKeyword\t\t\t%d\n", yytext, line_number); }
[<|>] 				{ printf("%s\t\tRelational Operators\t%d\n", yytext, line_number); }
[(]					{ printf("%s\t\tOpening Brackets\t%d\n", yytext, line_number); }
[)]					{ printf("%s\t\tClosing Brackets\t%d\n", yytext, line_number); }
["]					{ printf("%s\t\tdouble quote\t\t%d\n", yytext, line_number); }
[a-z,A-Z,_][a-z,A-Z,0-9,_,.]* 	{ printf("%s\t\tIdentifier\t\t%d\n", yytext, line_number); }
[;] 				{ printf("%s\t\tSemicolon\t\t%d\n", yytext, line_number); }


%%

int yywrap() {
    return 1;
}

int main(int argc, char* argv[]) {
    FILE* input_file = fopen("input_spac.txt", "r");
    
    if (!input_file) {
        printf("Failed to open the input file.\n");
        return 1;
    }
	printf("LEXEME\t\tTOKEN\t\t\tLINE NUMBER\n");
    yyin = input_file;

    while (yylex() != 0) { }

    fclose(input_file);
    return 0;
}

