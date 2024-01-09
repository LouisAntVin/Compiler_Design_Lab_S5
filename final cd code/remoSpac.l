%{
#include <stdio.h>
char line[200];

%}

%%

[\t,' ']        ;
['//'](.*)		;
.	{ fprintf(yyout, "%s", yytext); }
<<EOF>> 	{return 0;}

%%

int yywrap() {
    return 1;
}

int main(int argc, char* argv[]) {
    FILE* input_file = fopen("input_.txt", "r");
    FILE* output_file = fopen("output_.txt", "w");
    
    
    if (!input_file) {
        printf("Failed to open the input file.\n");
        return 1;
    }
    yyin = input_file;
	yyout= output_file;
    yylex();

    fclose(input_file);
    fclose(output_file);
    return 0;
}

